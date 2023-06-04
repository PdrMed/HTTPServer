#pragma once

class CHttp
{
public:
    CHttp();
    ~CHttp() {};

    std::string BuildHttpResponse();
    int ExtractContentLengthFromHeaders();
    void ProcessHeaderLine(std::string);
    void ProcessRequestLine(std::string);
private:
    std::string method;
    std::string url;
    std::string version;
    std::unordered_map<std::string, std::string> headers;
    std::shared_ptr< CCharacter> character;
};