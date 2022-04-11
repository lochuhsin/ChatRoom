//
// Created by albertlo on 2022/4/11.
//

#ifndef CHATROOM_CONFIGDTO_HPP
#define CHATROOM_CONFIGDTO_HPP

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ConfigDto : public oatpp::DTO {

    DTO_INIT(ConfigDto, DTO)

    DTO_FIELD(String, host);
    DTO_FIELD(UInt16, port);
    DTO_FIELD(String, swaggerHost);
    DTO_FIELD(String, dbConnectionString);

};

#endif //CHATROOM_CONFIGDTO_HPP
