#pragma once

class CSession
{
public:
    CSession(boost::asio::io_service& io_service) : socket(io_service) { };
    ~CSession() {};

    boost::asio::ip::tcp::socket socket;

    void BeginReadingBody(std::shared_ptr<CSession>);
    void ProcessNextLine(std::shared_ptr<CSession>);
    void ProcessFirstLine(std::shared_ptr<CSession>);
    void Initialize(std::shared_ptr<CSession>);
private:
    CHttp headers;
    boost::asio::streambuf buffer;

}; 