#ifndef CHATROOM_TESTCONTROLLER_HPP
#define CHATROOM_TESTCONTROLLER_HPP

#include "service/TestService.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TestController : public oatpp::web::server::api::ApiController {
public:
    explicit TestController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(
            objectMapper) {}

private:
    TestService m_testService;

public:
    static std::shared_ptr<TestController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<TestController>(objectMapper);
    }

    ENDPOINT("GET", "test", test) {
        auto result = m_testService.getUserCount();
        return createResponse(Status::CODE_200, std::to_string(result));
    }

};

#endif //CHATROOM_TESTCONTROLLER_HPP
