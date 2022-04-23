#include "./controller/UserController.hpp"
#include "./controller/TestController.hpp"
#include "./controller/RoomsController.hpp"

#include "./AppComponent.hpp"
#include "./DatabaseComponent.hpp"
#include "./SwaggerComponent.hpp"
#include "./ServiceComponent.hpp"

#include "oatpp/network/Server.hpp"
#include "oatpp-swagger/Controller.hpp"
#include "oatpp-swagger/AsyncController.hpp"
#include <iostream>

void run(const oatpp::base::CommandLineArguments &args) {

    /* Register Components in scope of run() method */
    AppComponent components(args);
    DatabaseComponent databaseComponent;
    SwaggerComponent swaggerComponent;
    ServiceComponent serviceComponent;

    /* Get router component */
    auto router = serviceComponent.httpRouter.getObject();
    oatpp::web::server::api::Endpoints docEndpoints;

    auto testEndpoints = router->addController(TestController::createShared())->getEndpoints();
    auto userEndpoints = router->addController(UserController::createShared())->getEndpoints();
    auto roomEndpoints = router->addController(RoomsController::createShared())->getEndpoints();

    docEndpoints.append(testEndpoints);
    docEndpoints.append(userEndpoints);
    docEndpoints.append(roomEndpoints);
    // bind controller to swagger controllers
    router->addController(oatpp::swagger::AsyncController::createShared(docEndpoints));

    auto connectionProvider = serviceComponent.serverConnectionProvider.getObject();
    auto connectionHandler = serviceComponent.serverConnectionHandler.getObject();
    oatpp::network::Server server(connectionProvider,
                                  connectionHandler);

    OATPP_LOGI("chatroom", "Server running on port %s", connectionProvider->getProperty("port").getData())

    /* Run server */
    server.run();

}

/**
 *  main
 */
int main(int argc, const char *argv[]) {

    oatpp::base::Environment::init();

    run(oatpp::base::CommandLineArguments(argc, argv));

    /* Print how much objects were created during app running, and what have left-probably leaked */
    /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

    oatpp::base::Environment::destroy();

    return 0;
}
