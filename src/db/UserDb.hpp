//
// Created by albertlo on 2022/4/12.
//

#ifndef CHATROOM_USERDB_HPP
#define CHATROOM_USERDB_HPP

#include "dto/UserDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class UserDb : public oatpp::orm::DbClient {
public:
    explicit UserDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {
        oatpp::orm::SchemaMigration migration(executor);
        migration.addFile(1, DATABASE_MIGRATIONS "/t_member.sql");
        migration.migrate();

        // Write log
        auto version = executor->getSchemaVersion();
        OATPP_LOGD("UserDb", "Migration - OK. Version=%d.", version);
    }

    QUERY(createUser,
          "INSERT INTO member"
          "(name, password) VALUES "
          "(:user.name, :user.password)"
          "RETURNING *;",
          PREPARE(true), // user prepared statement!
          PARAM(oatpp::Object<UserDto>, user))


    QUERY(updateUser,
          "UPDATE member "
          "SET "
          " password=:user.password "
          "WHERE "
          " name=:user.name "
          "RETURNING *;",
          PREPARE(true),
          PARAM(oatpp::Object<UserDto>, user))

    QUERY(getUserByName,
          "SELECT * FROM member WHERE name=:name;",
          PREPARE(true),
          PARAM(oatpp::String, name))

    QUERY(getAllUsers,
          "SELECT * FROM member LIMIT :limit OFFSET :offset;",
          PREPARE(true),
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(deleteUserByName,
          "DELETE FROM member WHERE name=:name;",
          PREPARE(true),
          PARAM(oatpp::String, name))

    // Without using DTO objects, using raw params
    QUERY(getUserCount,
          "SELECT COUNT(id) FROM member")
};


#include OATPP_CODEGEN_END(DbClient)
#endif //CHATROOM_USERDB_HPP
