#pragma once
#include<exception>
#include<string>

class RingBufferException : std::exception {
public:
	explicit RingBufferException(std::string);

	const char* what() noexcept;

private:
	std::string errorMessage;
};