//
// Created by albertlo on 2022/4/12.
//

#ifndef CHATROOM_SERVICECOMPONENT_HPP
#define CHATROOM_SERVICECOMPONENT_HPP

#include "dto/ConfigDto.hpp"
#include "ErrorHandler.hpp"

#include "oatpp/web/server/AsyncHttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/component.hpp"

class ServiceComponent {
public:

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor)([] {
        return std::make_shared<oatpp::async::Executor>(
                4 /* Data-Processing threads */,
                1 /* I/O threads */,
                1 /* Timer threads */
        );
    }());

    /**
     *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
        auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        mapper->getSerializer()->getConfig()->useBeautifier = true;
        mapper->getSerializer()->getConfig()->escapeFlags = 0;
        return mapper;
    }());

    /**
     *  Create ConnectionProvider component which listens on the port
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([] {
        OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component
        return oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", config->port, oatpp::network::Address::IP_4});
    }());

    /**
     *  Create Router component
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
        return oatpp::web::server::HttpRouter::createShared();
    }());

    /**
     *  Create ConnectionHandler component which uses Router component to route requests
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)([] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper); // get ObjectMapper component
        OATPP_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor); // get Async executor component

        auto connectionHandler = oatpp::web::server::AsyncHttpConnectionHandler::createShared(router, executor);
        connectionHandler->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));
        return connectionHandler;
    }());



    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, asyncWebSocketConnectionHandler)("asyncWebSocket", [] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor);
        auto connectionHandler = oatpp::websocket::AsyncConnectionHandler::createShared(executor);
        connectionHandler->setSocketInstanceListener(std::make_shared<Lobby>());
        return connectionHandler;
    }());
};

#endif //CHATROOM_SERVICECOMPONENT_HPP
