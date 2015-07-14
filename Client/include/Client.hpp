/**

    Prattle/Client/Client.hpp
    =========================

*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <SFML/Network.hpp>
#include "../include/Logger.hpp"
#include "../include/Network.hpp"
#include "../include/UserInterface.hpp"
#include "../include/GraphicalUI.hpp"

namespace prattle
{
    class Client
    {
        public:

            enum State
            {
                Login,
                Signup,
                Connecting,
                Chatting,
                Exit
            };

            // Stores basic configuration info
            struct Configuration
            {
                std::string addr;
                int port;
                std::string ui;
            };

        public:

            Client();
            void update();
            void draw();
            void run();

        private:
            void parseConfigFile();
            void doLogin();
            void doSignup();
            void sendUserMessage();
            void processServerReply();
            void changeState(State s);
            bool isStringWhitespace(const std::string& str);

            const std::string m_configFilePath = "resources/config/client.conf";
            State m_state;

            Network m_network;
            Network::RequestId m_loginReqId;

            std::unique_ptr<UserInterface> m_ui;
            Configuration m_clientConf;
    };
}

#endif // CLIENT_HPP
