#include <fstream>
#include "include/Server.hpp"
#include "include/Logger.hpp"
#include "include/TeeStream.hpp"

//If POSIX compliant OS, bind a function to the SIGINT signal (^C) so that the server closes gracefully
#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
    #include <signal.h>
namespace
{
    //Undesirable but there is no other way around this :(
    //Except the signal handler, no object should access this
    prattle::Server* serverPtr = nullptr;
}

using std::to_string;
#endif

int main()
{
    try
    {
        std::ofstream logFile("prattle_server_log.txt");
        prattle::TeeStream tee(std::cerr, logFile);
        prattle::Logger::getLogger()->setStream(&tee);
        prattle::Logger::getLogger()->setLoggingLevel(prattle::Logger::Debug);

        prattle::Server server;

        //If POSIX compliant OS
#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
        //Set the global ptr for the handler
        serverPtr = &server;

        struct sigaction sa; //struct keyword required to remove ambiguity
        //Shutdown server when SIGINT or SIGTERM is received
        sa.sa_handler = [](int sig){ if(serverPtr) serverPtr->shutdown(); };
        sa.sa_flags = 0;
        sigaction(SIGINT, &sa, NULL);
        sigaction(SIGTERM, &sa, NULL);
#endif // defined

        server.run();
    }
    catch (std::exception& e)
    {
        ERR_LOG(std::string("Exception occurred.\nwhat(): ") + e.what());
    }

    return 0;
}
