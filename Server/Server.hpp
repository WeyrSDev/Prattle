/*

The server which hosts the chat process.

For clients to start chatting, they need to connect to the server.

*/

#ifndef SERVER_HPP
#define SERVER_HPP


#include <ctime>
#include <map>
#include <fstream>
#include <exception>
#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include "System.hpp"

namespace chat
{
    class Server
    {
        public:
            Server();

            bool isRunning();
            bool wait();
            bool newConnectionRequest();
            bool addNewClient();
            bool receive();
            bool send(const std::string &senderUserName, const std::string &receiverUserName, const sf::Packet& dataPacket);
            void openDatabase(const std::string& userList = chat::USER_LIST);
            void shutdown();
            std::vector<std::string> getRecords();
            bool isUserRegistered(const std::string& userName, const std::string& password);
            bool addNewUser(const std::string& userName, const std::string& password);

        protected:
            sf::Time timeOut;

        private:
            sf::TcpListener m_listener;
            std::map<std::string, std::unique_ptr<sf::TcpSocket>> m_clients;
            sf::SocketSelector m_selector;
            bool m_running;
            std::vector<std::string> m_members;
            std::fstream m_userDatabase;
            std::multimap<std::string, std::pair<std::string,sf::Packet> > m_messages;
    };
}

#endif // SERVER_HPP
