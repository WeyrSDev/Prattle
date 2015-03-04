/**

    Prattle/Server/System.hpp
    =========================

    Contains various constants related to handling the server.

*/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
#include <random>
#include "../src/SHA256/SHA256.h"
#include "../include/ErrorLog.hpp"

namespace prattle
{
    /* Constants */
    const int         OPEN_PORT         = 19999;            // The port to which the server listens for connections/communication
    const std::string SERVER_IP_ADDRESS = "127.0.0.1";      // The IP address of the server
                                                            // Remember to change it to your desired host's IP
    const std::string USER_LIST         = "resources/members.db";    // The user database

    /* Functions */
    std::string       getCurrentTimeAndDate();                                    // Returns the current date & time in the host machine
    std::string       generate_salt(int length = 5);                              // Generates a salt to add to the hashed password
    std::string       pwd_hash(const std::string& str,const std::string& salt);   // Hashes the password using the SHA256
}

#endif // SYSTEM_HPP_INCLUDED