#ifndef CHATROOM_TESTSERVICE_HPP
#define CHATROOM_TESTSERVICE_HPP

#include "db/TestDb.hpp"
#include "dto/TestDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

class TestService {
public:
    int getUserCount();

private:
    typedef oatpp::web::protocol::http::Status Status;
    std::shared_ptr<oatpp::parser::json::mapping::ObjectMapper> m_jsonObjectMapper_ptr{
            oatpp::parser::json::mapping::ObjectMapper::createShared()};
private:
    OATPP_COMPONENT(std::shared_ptr<TestDb>, m_database);
};


#endif //CHATROOM_TESTSERVICE_HPP
