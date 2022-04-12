//
// Created by albertlo on 2022/4/12.
//

#ifndef CHATROOM_DATABASECOMPONENT_HPP
#define CHATROOM_DATABASECOMPONENT_HPP

#include "db/UserDb.hpp"
#include "dto/ConfigDto.hpp"

class DatabaseComponent{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<UserDb>, userDb)([] {

        OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

        /* Create database-specific ConnectionProvider */
        auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

        /* Create database-specific ConnectionPool */
        auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                              10 /* max-connections */,
                                                                              std::chrono::seconds(5) /* connection TTL */);
        /* Create database-specific Executor */
        auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

        /* Create MyClient database client */
        return std::make_shared<UserDb>(executor);

    }());
};

#endif //CHATROOM_DATABASECOMPONENT_HPP
