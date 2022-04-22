//
// Created by albertlo on 2022/4/22.
//

#ifndef CHATROOM_TESTDTO_HPP
#define CHATROOM_TESTDTO_HPP
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class TestDto : public oatpp::DTO {

    DTO_INIT(TestDto, DTO)
    DTO_FIELD(UInt16, count);
};


#endif //CHATROOM_TESTDTO_HPP
