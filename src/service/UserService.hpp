//
// Created by albertlo on 2022/4/12.
//

#ifndef CHATROOM_USERSERVICE_HPP
#define CHATROOM_USERSERVICE_HPP

#include "db/UserDb.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class UserService{
public:
  oatpp::Object<UserDto> createUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<UserDto> updateUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<UserDto> getUserByName(const oatpp::String& name);
  oatpp::Object<StatusDto> deleteUserByName(const oatpp::String& name);

private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<UserDb>, m_database);
};

#endif //CHATROOM_USERSERVICE_HPP
