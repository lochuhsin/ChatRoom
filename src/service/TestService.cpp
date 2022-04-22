#include "TestService.hpp"

int TestService::getUserCount() {
    auto dbResult = m_database->getUserCount();
    if(!dbResult->isSuccess())
        return 0;

    auto resultVec = dbResult->fetch<oatpp::Vector<oatpp::Object<TestDto>>>();
    auto count = resultVec[0]->count;

    oatpp::String json = m_jsonObjectMapper_ptr->writeToString(count);
    OATPP_LOGD("convert object to json test", "value='%s'", json->c_str());
    return count;
}
