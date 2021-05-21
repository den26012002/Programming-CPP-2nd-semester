#include"RingBufferException.h"

RingBufferException::RingBufferException(std::string _errorMessage) {
	errorMessage = _errorMessage;
}

const char* RingBufferException::what() noexcept {
	errorMessage = "Error" + errorMessage;
	return errorMessage.c_str();
}