#include<cstdlib>
#include<cstring>
#include<iostream>
#include<boost/asio.hpp>

using boost::asio::ip::tcp;

enum{max_length = 1024};

int main(int argc, char *argv[])
{
    try{
        if(argc!=3)
        {
            std::cout<<"argc error";
            return 1;
        }
        boost::asio::io_service io_service;
        tcp::socket s(io_service);
        tcp::resolver resolver(io_service);
        boost::asio::connect(s, resolver.resolve({argv[1],argv[2]}));

        while(true)
        {
            std::cout<<"enter message"<<std::endl;
            char request[max_length];
            std::cin.getline(request, max_length);
            size_t request_length = std::strlen(request);
            if(request_length<=0)
                break;
            boost::asio::write(s, boost::asio::buffer(request, request_length));
            char reply[max_length];
            size_t reply_length =
            boost::asio::read(s, boost::asio::buffer(reply, request_length));

            std::cout<<"reply is: "<<reply<<std::endl;
        }
    }catch(std::exception &e)
    {
        std::cout<<"Exception"<<std::endl;
    }

}
