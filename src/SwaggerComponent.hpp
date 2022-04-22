#ifndef SWAGGERCOMPONENT_HPP
#define SWAGGERCOMPONENT_HPP

#include "dto/ConfigDto.hpp"

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include "oatpp/core/macro/component.hpp"

class SwaggerComponent {
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
        OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

        oatpp::swagger::DocumentInfo::Builder builder;
        builder
        .setTitle("Example: Chatroom User Api")
        .setDescription("Service which stores and reads user info to/from postgresql database")
        .setVersion("1.0")
        .setContactName("AlbertLo")
        .setContactUrl("https://google.com/")
        .addServer("http://localhost:" + oatpp::utils::conversion::int32ToStr(config->port), "server on localhost");
        return builder.build();

    }());
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
        // Make sure to specify correct full path to oatpp-swagger/res folder !!!
        return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
    }());
};

#endif /* SWAGGERCOMPONENT_HPP */
