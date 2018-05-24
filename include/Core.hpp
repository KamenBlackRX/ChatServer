#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <boost/asio.hpp>

/**
 * NameSpace for Core system, who contains Server / Client Libs
 */ 
namespace Core
{
    /**
     * Main Server class.
     * This class create all async operations for Chat.
     */
    class Server
    {
        Server();
        ~Server();

        void do_connection();
        void do_checkAuth(string* Nick);


    };

    class Log
    {
        Log();
        ~Log();       

        template< typename ...Args>
        inline std::ofstream& operator << (Args&&... args)
        {
            std::f
        }
    };

    class Client
    {
        
    };

    class MemoryAlocation()
    {

    };
}

#endif