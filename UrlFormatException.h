#pragma once

#include <stdexcept>
#include <string>

class UrlFormatException : public std::runtime_error {
public:
	UrlFormatException(const std::string& message);
};

