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
    UserDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {
        oatpp::orm::SchemaMigration migration(executor);
        migration.addFile(1, DATABASE_MIGRATIONS "/001_init.sql");
        migration.migrate();

        // Write log
        auto version = executor->getSchemaVersion();
        OATPP_LOGD("UserDb", "Migration - OK. Version=%d.", version);
    }

    QUERY(createUser,
          "INSERT INTO User"
          "(id, username, password) VALUES "
          "(uuid_generate_v4(), :user.username, :user.password)"
          "RETURNING *;",
          PREPARE(true), // user prepared statement!
          PARAM(oatpp::Object<UserDto>, user))


    QUERY(updateUser,
          "UPDATE User"
          "SET "
          " username=:user.username, "
          " password=:user.password, "
          "WHERE "
          " id=:user.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<UserDto>, user))

    QUERY(getUserById,
          "SELECT * FROM User WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getAllUsers,
          "SELECT * FROM User LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(deleteUserById,
          "DELETE FROM User WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

};

#include OATPP_CODEGEN_END(DbClient)

#endif //CHATROOM_USERDB_HPP
