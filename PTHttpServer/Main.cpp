#include <StdAfx.h>
#include "CCharacter.h"
#include "CHttp.h"
#include "CSession.h"

void StartAcceptingAndReadingSessions(boost::asio::ip::tcp::acceptor& acceptor, boost::asio::io_service& io_service)
{
    auto session = std::make_shared<CSession>(io_service);
    acceptor.async_accept(session->socket, [session, &acceptor, &io_service](const  boost::system::error_code& accept_error)
        {
            StartAcceptingAndReadingSessions(acceptor, io_service);
            if (!accept_error)
            {
                session->Initialize(session);
            }
        });
}

int main()
{
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint{ boost::asio::ip::tcp::v4(), 8080 };
    boost::asio::ip::tcp::acceptor acceptor{ io_service, endpoint };

    acceptor.listen();
    StartAcceptingAndReadingSessions(acceptor, io_service);
    io_service.run();
}

