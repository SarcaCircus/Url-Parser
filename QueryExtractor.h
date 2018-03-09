#pragma once
#include "UrlComponentExtractor.h"

#include <vector>

class QueryExtractor : public UrlComponentExtractor {
public:
	QueryExtractor(const std::string& value);

	bool HasComponent() const override;
	const std::string & GetBase() const override;
	const std::string & GetComponent() const override;
	const std::vector<std::string>& GetQueryParameters() const;

private:
	std::string _base;
	std::string _component;
	std::vector<std::string> _parameters;

	void FindParameters();
};