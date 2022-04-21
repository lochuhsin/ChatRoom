cmake_minimum_required(VERSION 3.1)

set(project_name chatroom) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 20)

add_library(${project_name}-lib
        src/websocket/WSListener.cpp
        src/websocket/WSListener.hpp
        src/AppComponent.hpp
        src/controller/UserController.hpp
        src/SwaggerComponent.hpp
        src/dto/ConfigDto.hpp
        src/db/UserDb.hpp
        src/dto/UserDto.hpp
        src/DatabaseComponent.hpp
        src/service/UserService.hpp
        src/service/UserService.cpp
        src/dto/StatusDto.hpp
        src/ServiceComponent.hpp
        src/ErrorHandler.cpp
        src/ErrorHandler.hpp)

## link libs

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-swagger      1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)
find_package(oatpp-websocket    1.3.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-postgresql
        PUBLIC oatpp::oatpp-websocket
)

add_definitions(
        # Path to swagger-ui resources #
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        src/App.cpp
        src/controller/SocketController.hpp)

target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

set_target_properties(${project_name}-lib ${project_name}-exe PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)
