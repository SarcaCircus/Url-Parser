#pragma once

#include "UrlComponentExtractor.h"

#include "SchemeType.h"

class SchemeExtractor : public UrlComponentExtractor {
public:
	SchemeExtractor(const std::string& value);

	bool HasComponent() const override;
	const std::string & GetBase() const override;
	const std::string & GetComponent() const override;
	SchemeType GetType() const;

private:
	std::string _base;
	std::string _component;
	SchemeType _type = SchemeType::Unknown;
};