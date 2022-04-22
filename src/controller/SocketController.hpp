//
// Created by albertlo on 2022/4/21.
//

#ifndef CHATROOM_SOCKETCONTROLLER_HPP
#define CHATROOM_SOCKETCONTROLLER_HPP

#include "oatpp-websocket/Handshaker.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/network/ConnectionHandler.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController) //<-- codegen begin

/**
 * Controller with WebSocket-connect endpoint.
 */
class SocketController : public oatpp::web::server::api::ApiController {
private:
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler, "websocket");
public:
    explicit SocketController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

public:
    static std::shared_ptr<SocketController>
    createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<SocketController>(objectMapper);
    }

    ENDPOINT("GET", "websocket/test", websocketTest) {
        const char *pageTemplate = "Hello ~ this socket is ok "
                                   "websocket endpoint is: localhost:8000/ws";
        return createResponse(Status::CODE_200, pageTemplate);
    };

    ENDPOINT("GET", "ws", ws, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
        return oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), websocketConnectionHandler);
    };
};

#include OATPP_CODEGEN_END(ApiController) //<-- codegen end


#endif //CHATROOM_SOCKETCONTROLLER_HPP
