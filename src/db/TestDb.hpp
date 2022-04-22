
#ifndef CHATROOM_TESTDB_HPP
#define CHATROOM_TESTDB_HPP

#include "dto/UserDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class TestDb : public oatpp::orm::DbClient {
public:
    explicit TestDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {
        oatpp::orm::SchemaMigration migration(executor);

        OATPP_LOGD("TestDb", "Testing database");
    }
    // Instead of using DTO objects, i use raw parameters
    QUERY(getUserCount,
          "SELECT COUNT(id) as count FROM member")
};


#include OATPP_CODEGEN_END(DbClient)

#endif //CHATROOM_TESTDB_HPP
