#pragma once
#include "UrlComponentExtractor.h"

class FragmentExtractor : public UrlComponentExtractor {
public:
	FragmentExtractor(const std::string& value);

	bool HasComponent() const override;
	const std::string & GetBase() const override;
	const std::string & GetComponent() const override;

private:
	std::string _base;
	std::string _component;
};