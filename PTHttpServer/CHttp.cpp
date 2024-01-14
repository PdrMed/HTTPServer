#include <StdAfx.h>
#include "CCharacter.h"
#include "CHttp.h"
#include "CCharacter.h"
CHttp::CHttp()
{
    character = std::make_shared<CCharacter>();
}
std::string CHttp::BuildHttpResponse()
{
    std::stringstream ssOut;
    std::string characterRoute = "/character/";
    if (auto pos = url.rfind(characterRoute) != std::string::npos)
    {
        std::string characterName = url.substr(pos + characterRoute.size()-1);
        std::string json = character->GetCharacterInfoAsJsonString(characterName);
        ssOut << "HTTP/1.1 200 OK" << "\r\n";
        ssOut << "content-type: text/html" << "\r\n";
        ssOut << "content-length: " << json.size() << "\r\n";
        ssOut << "\r\n";
        ssOut << json;
        return ssOut.str();
    }

    std::string sHTML = "<html><body><h1>Erro 404 Not Found</h1></body></html>";
    ssOut << "HTTP/1.1 404 Not Found" << "\r\n";
    ssOut << "content-type: application/json" << "\r\n";
    ssOut << "content-length: " << sHTML.length() << "\r\n";
    ssOut << "\r\n";
    ssOut << sHTML;
    return ssOut.str();
}

int CHttp::ExtractContentLengthFromHeaders()
{
    auto request = headers.find("content-length");
    if (request != headers.end())
    {
        std::stringstream ssLength(request->second);
        int content_length;
        ssLength >> content_length;
        return content_length;
    }
    return 0;
}

void CHttp::ProcessHeaderLine(std::string line)
{
    std::stringstream ssHeader(line);
    std::string headerName;
    std::getline(ssHeader, headerName, ':');

    std::string value;
    std::getline(ssHeader, value);
    headers[headerName] = value;

#ifdef _DEBUG
    std::cout << "Header: " << line << std::endl;
#endif
}

void CHttp::ProcessRequestLine(std::string line)
{
    std::stringstream ssRequestLine(line);
    ssRequestLine >> method;
    ssRequestLine >> url;
    ssRequestLine >> version;

#ifdef _DEBUG
    std::cout << "Resource: " << url << std::endl;
#endif
}