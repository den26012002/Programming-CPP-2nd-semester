#pragma once
#include<exception>
#include<string>

namespace geometry {
	class GeometryException : public std::exception {
	public:
		explicit GeometryException(const std::string);

		const char* what() noexcept;

	private:
		std::string errorMessage;
	};
}