#pragma once
#include "UrlComponentExtractor.h"

#include <vector>

class PathExtractor : public UrlComponentExtractor {
public:
	PathExtractor(const std::string& value);

	bool HasComponent() const override;
	const std::string& GetBase() const override;
	const std::string& GetComponent() const override;
	bool IsAbsolute() const;
	const std::vector<std::string>& GetPathComponents() const;

private:
	std::string _base;
	std::string _component;
	bool _isAbsolute;
	std::vector<std::string> _pathComponents;
};