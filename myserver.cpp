#include<iostream>
#include"Socket.hpp"

using namespace std;

//run server first, then send to serve, or else won't work
int main(void){
    try{
        Socket::UDP sock;
        sock.bind(2000);
        Socket::Datagram received=sock.receive();
        sock.send("127.0.0.1",3000,"response");
        cout<<received.data<<endl;
        sock.close();
    }
    catch(Socket::Exception &e){
        cout<<e.what()<<endl;
    }
    return 0;
}