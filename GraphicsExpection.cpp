#include "GraphicsExpection.h"
#include "dxerr.h"

// Graphics exception stuff
GraphicsExpection::HrException::HrException(int line, const char* file, HRESULT hr, std::vector<std::string> infoMsgs) noexcept
	:
	Exception(line, file),
	hr(hr)
{
	// join all info messages with newlines into single string
	for (const auto& m : infoMsgs)
	{
		info += m;
		info.push_back('\n');
	}
	// remove final newline if exists
	if (!info.empty())
	{
		info.pop_back();
	}
}

GraphicsExpection::HrException::HrException(int line, const char* file, HRESULT hr, const std::wstring& functionName) noexcept
	:
	Exception(line, file),
	hr(hr)
{
	// join all info messages with newlines into single string
	for (const auto& m : functionName)
	{
		info += m;
		info.push_back('\n');
	}
}

const char* GraphicsExpection::HrException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< "[Error Code] 0x" << std::hex << std::uppercase << GetErrorCode()
		<< std::dec << " (" << (unsigned long)GetErrorCode() << ")" << std::endl
		<< "[Error String] " << GetErrorString() << std::endl
		<< "[Description] " << GetErrorDescription() << std::endl;
	if (!info.empty())
	{
		oss << "\n[Error Info]\n" << GetErrorInfo() << std::endl << std::endl;
	}
	oss << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* GraphicsExpection::HrException::GetType() const noexcept
{
	return "Chili Graphics Exception";
}

HRESULT GraphicsExpection::HrException::GetErrorCode() const noexcept
{
	return hr;
}

std::string GraphicsExpection::HrException::GetErrorString() const noexcept
{
	return DXGetErrorStringA(hr);
}

std::string GraphicsExpection::HrException::GetErrorDescription() const noexcept
{
	char buf[512];
	DXGetErrorDescriptionA(hr, buf, sizeof(buf));
	return buf;
}

std::string GraphicsExpection::HrException::GetErrorInfo() const noexcept
{
	return info;
}


const char* GraphicsExpection::DeviceRemovedException::GetType() const noexcept
{
	return "Chili Graphics Exception [Device Removed] (DXGI_ERROR_DEVICE_REMOVED)";
}
GraphicsExpection::InfoException::InfoException(int line, const char* file, std::vector<std::string> infoMsgs) noexcept
	:
	Exception(line, file)
{
	// join all info messages with newlines into single string
	for (const auto& m : infoMsgs)
	{
		info += m;
		info.push_back('\n');
	}
	// remove final newline if exists
	if (!info.empty())
	{
		info.pop_back();
	}
}


const char* GraphicsExpection::InfoException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< "\n[Error Info]\n" << GetErrorInfo() << std::endl << std::endl;
	oss << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* GraphicsExpection::InfoException::GetType() const noexcept
{
	return "Chili Graphics Info Exception";
}

std::string GraphicsExpection::InfoException::GetErrorInfo() const noexcept
{
	return info;
}
