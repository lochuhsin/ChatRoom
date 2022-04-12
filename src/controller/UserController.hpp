//
// Created by albertlo on 2022/4/12.
//

#ifndef CHATROOM_USERCONTROLLER_HPP
#define CHATROOM_USERCONTROLLER_HPP

#include "service/UserService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
public:
    UserController(const std::shared_ptr<ObjectMapper> &objectMapper) : oatpp::web::server::api::ApiController(
            objectMapper) {}

private:
    UserService m_userService;

public:
    static std::shared_ptr<UserController> createShared (OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,objectMapper)) {
        return std::make_shared<UserController>(objectMapper);
    }

    ENDPOINT("POST", "users", createUser,
             BODY_DTO(Object < UserDto > , userDto)) {
        return createDtoResponse(Status::CODE_200, m_userService.createUser(userDto));
    }

    ENDPOINT("PUT", "users/{userId}", putUser,
             PATH(String, userId),
             BODY_DTO(Object < UserDto > , userDto)) {
        userDto->id = userId;
        return createDtoResponse(Status::CODE_200, m_userService.updateUser(userDto));
    }

    ENDPOINT("GET", "users/{userId}", getUserById,
             PATH(String, userId)) {
        return createDtoResponse(Status::CODE_200, m_userService.getUserById(userId));
    }


    ENDPOINT("DELETE", "users/{userId}", deleteUser,
             PATH(String, userId)) {
        return createDtoResponse(Status::CODE_200, m_userService.deleteUserById(userId));
    }


};

#endif //CHATROOM_USERCONTROLLER_HPP
