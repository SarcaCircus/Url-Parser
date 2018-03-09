#pragma once
#include "UrlComponentExtractor.h"

class LocationExtractor : public UrlComponentExtractor {
public:
	LocationExtractor(const std::string& value);

	bool HasComponent() const override;
	const std::string & GetBase() const override;
	const std::string & GetComponent() const override;

private:
	bool _hasLocation;
	std::string _base;
	std::string _component;
};