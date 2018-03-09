#include "LocationExtractor.h"

LocationExtractor::LocationExtractor(const std::string & value) {
	int count;
	auto location = " ";
	auto rest = " ";
	for (int i = 0; i <  value.size(); i++) {
		if (value.at(i) == '/'&&value.at(i + 1) == '/') {
			count=i+ 2;
			while (value.at(count)!='/') {
				location += value.at(count);
				count++;
			}
			i = count;
		}
		rest += value.at(i);

	}
	_component = location;
	_base = rest;
}

bool LocationExtractor::HasComponent() const
{
	if (_component == " ") {
		return false;
	}  
	else return true;
}

const std::string & LocationExtractor::GetBase() const
{
	return _base;
}

const std::string & LocationExtractor::GetComponent() const
{
	return _component;
}