#ifndef CHATROOM_ROOMSCONTROLLER_HPP
#define CHATROOM_ROOMSCONTROLLER_HPP

#include "oatpp-websocket/Handshaker.hpp"

#include "oatpp/web/server/api/ApiController.hpp"

#include "oatpp/network/ConnectionHandler.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController) //<-- codegen begin


class RoomsController : public oatpp::web::server::api::ApiController {
private:
    typedef RoomsController __ControllerType;
private:
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, asyncWebSocketConnectionHandler, "asyncWebSocket");
public:
    RoomsController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

    static std::shared_ptr<RoomsController>
    createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<RoomsController>(objectMapper);
    }

public:

    ENDPOINT_ASYNC("GET", "/chat", roomchat) {

    ENDPOINT_ASYNC_INIT(roomchat)

        const char *pageTemplate =
                "<html lang='en'>"
                "<head>"
                "<meta charset=utf-8/>"
                "</head>"
                "<body>"
                "<p>Hello Async WebSocket Rooms Server!</p>"
                "<p>Connect to chat room:</p>"
                "<code>localhost:8000/ws/chat/{room_name}/?nickname={nickname}</code>"
                "</body>"
                "</html>";

        Action act() override {
            return _return(controller->createResponse(Status::CODE_200, pageTemplate));
        }

    };

    ENDPOINT_ASYNC("GET", "ws/chat/{room-name}/*", WS) {

    ENDPOINT_ASYNC_INIT(WS)

        Action act() override {

            auto roomName = request->getPathVariable("room-name");
            auto nickname = request->getQueryParameter("nickname");

            OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "No nickname specified.");

            /* Websocket handshake */
            auto response = oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(),
                                                                              controller->asyncWebSocketConnectionHandler);

            auto parameters = std::make_shared<oatpp::network::ConnectionHandler::ParameterMap>();

            (*parameters)["roomName"] = roomName;
            (*parameters)["nickname"] = nickname;

            /* Set connection upgrade params */
            response->setConnectionUpgradeParameters(parameters);

            return _return(response);
        }
    };
};

#include OATPP_CODEGEN_END(ApiController) //<-- codegen end

#endif //CHATROOM_ROOMSCONTROLLER_HPP
