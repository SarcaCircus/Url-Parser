#pragma once
#include <string>

class UrlComponentExtractor {
public:
	virtual bool HasComponent() const = 0;
	virtual const std::string& GetBase() const = 0;
	virtual const std::string& GetComponent() const = 0;
};