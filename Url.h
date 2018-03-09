#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "FragmentExtractor.h"
#include "SchemeExtractor.h"
#include "LocationExtractor.h"
#include "QueryExtractor.h"
#include "PathExtractor.h"

class Url {
public:
	Url(const std::string& url);

	std::string GetScheme() const;
	std::string GetLocation() const;
	std::string GetPath() const;
	std::string GetQuery() const;
	std::string GetFragment() const;

	friend std::ostream& operator<<(std::ostream& stream, const Url& url);

private:
	std::unique_ptr<SchemeExtractor> _schemeExtractor;
	std::unique_ptr<LocationExtractor> _locationExtractor;
	std::unique_ptr<FragmentExtractor> _fragmentExtractor;
	std::unique_ptr<QueryExtractor> _queryExtractor;
	std::unique_ptr<PathExtractor> _pathExtractor;
};