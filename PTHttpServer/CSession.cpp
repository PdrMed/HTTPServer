#include <StdAfx.h>
#include "CCharacter.h"
#include "CHttp.h"
#include"CSession.h"

void CSession::Initialize(std::shared_ptr<CSession> This)
{
	ProcessFirstLine(This);
}

void CSession::BeginReadingBody(std::shared_ptr<CSession> This)
{
	const auto sizeBuffer = 1024;
	std::shared_ptr<std::vector<char>> bufptr = std::make_shared<std::vector<char>>(sizeBuffer);
	boost::asio::async_read(This->socket, boost::asio::buffer(*bufptr, sizeBuffer), [This](const boost::system::error_code& error, std::size_t size)
		{
		});
}

void CSession::ProcessNextLine(std::shared_ptr<CSession> This)
{
	boost::asio::async_read_until(This->socket, This->buffer, '\r', [This](const boost::system::error_code& error, std::size_t size)
		{
			std::string line, ignore;
			std::istream stream{ &This->buffer };
			std::getline(stream, line, '\r');
			std::getline(stream, ignore, '\n');
			This->headers.ProcessHeaderLine(line);

			if (line.length() == 0)
			{
				if (This->headers.ExtractContentLengthFromHeaders() == 0)
				{
					std::shared_ptr<std::string> str = std::make_shared<std::string>(This->headers.BuildHttpResponse());
					boost::asio::async_write(This->socket, boost::asio::buffer(str->c_str(), str->length()), [This, str](const boost::system::error_code& error, std::size_t size)
						{
						});
				}
				else
				{
					This->BeginReadingBody(This);
				}
			}
			else
			{
				This->ProcessNextLine(This);
			}
		});
}

void CSession::ProcessFirstLine(std::shared_ptr<CSession> This)
{
	boost::asio::async_read_until(This->socket, This->buffer, '\r', [This](const boost::system::error_code& error, std::size_t size)
		{
			std::string line, ignore;
			std::istream stream{ &This->buffer };
			std::getline(stream, line, '\r');
			std::getline(stream, ignore, '\n');
			This->headers.ProcessRequestLine(line);
			This->ProcessNextLine(This);
		});
}