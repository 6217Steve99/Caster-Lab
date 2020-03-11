#include "CasterException.h"
#include <sstream>


CasterException::CasterException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* CasterException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* CasterException::GetType() const noexcept
{
	return "Chili Exception";
}

int CasterException::GetLine() const noexcept
{
	return line;
}

const std::string& CasterException::GetFile() const noexcept
{
	return file;
}

std::string CasterException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}