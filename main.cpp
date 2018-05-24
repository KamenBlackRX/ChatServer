#include <iostream>

using namespace std;

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
        cerr << "Usage: ChatServer <client/server> host port" << endl;
        return 1;
    }
        
}