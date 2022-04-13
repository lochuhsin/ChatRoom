#ifndef CHATROOM_USERDTO_HPP
#define CHATROOM_USERDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class UserDto : public oatpp::DTO {
    DTO_INIT(UserDto, DTO)

    DTO_FIELD_INFO(id) {
        info->description = "This field is for consistency, no need to insert any value"; //<-- Fields description is integrated with Swagger-UI.
    }
    DTO_FIELD(Int32, id)= -1;

    DTO_FIELD(String, name, "name");

    DTO_FIELD(String, password, "password");
};

#include OATPP_CODEGEN_END(DTO) ///< End DTO codegen section
#endif //CHATROOM_USERDTO_HPP
