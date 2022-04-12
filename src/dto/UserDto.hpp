#ifndef CHATROOM_USERDTO_HPP
#define CHATROOM_USERDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class UserDto : public oatpp::DTO {
    DTO_INIT(UserDto, DTO)

    DTO_FIELD(Int32, id);

    DTO_FIELD(String, name, "name");

    DTO_FIELD(String, password, "password");

};

#endif //CHATROOM_USERDTO_HPP
