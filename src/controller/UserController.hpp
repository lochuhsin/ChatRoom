#ifndef CHATROOM_USERCONTROLLER_HPP
#define CHATROOM_USERCONTROLLER_HPP

#include "service/UserService.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
public:
    explicit UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(
            objectMapper) {}

private:
    typedef UserController __ControllerType;

public:
    static std::shared_ptr<UserController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<UserController>(objectMapper);
    }

    ENDPOINT_ASYNC("POST", "users", createUser) {
    ENDPOINT_ASYNC_INIT(createUser)

        Action act() override {
            return request->readBodyToDtoAsync<oatpp::Object<UserDto>>(controller->getDefaultObjectMapper())
                    .callbackTo(&createUser::onBodyObtained);
        }

        Action onBodyObtained(const oatpp::Object<UserDto> &dto) {
            auto userService = UserService();
            auto result = userService.createUser(dto);
            return _return(controller->createResponse(Status::CODE_200));
        }
    };

    ENDPOINT_ASYNC("PUT", "users/updateUser", updateUser) {
    ENDPOINT_ASYNC_INIT(updateUser)

        Action act() override {
            return request->readBodyToDtoAsync<oatpp::Object<UserDto>>(controller->getDefaultObjectMapper())
                    .callbackTo(&updateUser::onBodyObtained);
        }

        Action onBodyObtained(const oatpp::Object<UserDto> &dto) {
            auto userService = UserService();
            auto result = userService.updateUser(dto);
            return _return(controller->createResponse(Status::CODE_200));
        }
    };

    ENDPOINT_ASYNC("PUT", "users/{username}", getUserByName) {
    ENDPOINT_ASYNC_INIT(getUserByName)

    public:
        std::string userName;

        Action act() override {
            userName = request->getPathVariable("username");
            return request->readBodyToStringAsync().callbackTo(&getUserByName::returnRespond);
        }

        Action returnRespond(const oatpp::String &body) {
            auto userService = UserService();
            auto obj = userService.getUserByName(userName);
            return _return(controller->createDtoResponse(Status::CODE_200, obj));
        }
    };

    ENDPOINT_ASYNC("DELETE", "users/{username}", deleteUserByName) {
    ENDPOINT_ASYNC_INIT(deleteUserByName)

    public:
        std::string userName;

        Action act() override {
            userName = request->getPathVariable("username");
            return request->readBodyToStringAsync().callbackTo(&deleteUserByName::returnRespond);
        }

        Action returnRespond(const oatpp::String &body) {
            auto userService = UserService();
            auto obj = userService.deleteUserByName(userName);
            return _return(controller->createDtoResponse(Status::CODE_200, obj));
        }
    };
};

#endif //CHATROOM_USERCONTROLLER_HPP
