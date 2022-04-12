#ifndef CHATROOM_USERCONTROLLER_HPP
#define CHATROOM_USERCONTROLLER_HPP

#include "service/UserService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
public:
    explicit UserController(const std::shared_ptr<ObjectMapper> &objectMapper) : oatpp::web::server::api::ApiController(
            objectMapper) {}

private:
    UserService m_userService;

public:
    static std::shared_ptr<UserController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<UserController>(objectMapper);
    }

    ENDPOINT("POST", "users", createUser,
             BODY_DTO(Object < UserDto > , userDto)) {
        return createDtoResponse(Status::CODE_200, m_userService.createUser(userDto));
    }

    ENDPOINT("PUT", "users/{userName}", putUser,
             PATH(String, userName),
             BODY_DTO(Object < UserDto > , userDto)) {
        userDto->name = userName;
        return createDtoResponse(Status::CODE_200, m_userService.updateUser(userDto));
    }

    ENDPOINT("GET", "users/{userName}", getUserByName,
             PATH(String, userName)) {
        return createDtoResponse(Status::CODE_200, m_userService.getUserByName(userName));
    }

    ENDPOINT("DELETE", "users/{userName}", deleteUser,
             PATH(String, userName)) {
        return createDtoResponse(Status::CODE_200, m_userService.deleteUserByName(userName));
    }
};

#endif //CHATROOM_USERCONTROLLER_HPP
