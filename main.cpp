#include <iostream>
#include "include\Core.hpp"

using namespace std;
using namespace Core;

enum FD_FLAGS : int
{
    OPEN_SOCK,
    CLOSE_SOCK,
    ACK_RESPONSE,
    ACK_REQUEST,
    SEND_RESPONSE,
    SEND_SIGNAL_DISC,

};


FD_FLAGS flags;


int main (int argc, char* argv[])
{
    cout << "=======================================" << endl;
    cout << "           ChatBot Server              " << endl;
    cout << "=======================================" << endl;

    if ( argc < 4 )
    {
        cerr << "Usage: ChatServer --<client/server> host port" << endl;
        return 1;
    }

	if (argv[1] == "--client")
	{
		try
		{
			boost::asio::io_service io_service;

			tcp::resolver resolver(io_service);
			auto endpoint_iterator = resolver.resolve({ argv[1], argv[2] });
			chat_client c(io_service, endpoint_iterator);

			std::thread t([&io_service]() { io_service.run(); });

			char line[chat_message::max_body_length + 1];
			while (std::cin.getline(line, chat_message::max_body_length + 1))
			{
				chat_message msg;
				msg.body_length(std::strlen(line));
				std::memcpy(msg.body(), line, msg.body_length());
				msg.encode_header();
				c.write(msg);
			}

			c.close();
			t.join();
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
        
}