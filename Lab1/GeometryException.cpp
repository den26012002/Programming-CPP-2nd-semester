#include "GeometryException.h"

namespace geometry {
	GeometryException::GeometryException(const std::string _errorMessage) : errorMessage(_errorMessage) {}

	const char* GeometryException::what() noexcept {
		errorMessage = "Error: you've tried to create a non-" + errorMessage;
		return errorMessage.c_str();
	}
}