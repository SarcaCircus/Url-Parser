#include "SchemeExtractor.h"


SchemeExtractor::SchemeExtractor(const std::string & value) {
	std::string scheme = "";
	std::string rest = "";
	int j;
	for (int i = 0; i < value.size(); i++) {
		if (value.at(i) == ':') {
			j = i;
			break;
		}
		else
		scheme += value.at(i);
		
	}
	for (int k = j + 1; k <  value.size(); ++k) {
		rest += value.at(k);
	}
	_base = rest;
	_component = scheme;
}
bool SchemeExtractor::HasComponent() const
{
	if (_component == " ") {
		return false;
	} // TODO return true if a fragment 
	else return true;
}

const std::string & SchemeExtractor::GetBase() const
{
	return _base;
}

const std::string & SchemeExtractor::GetComponent() const
{
	return _component;
}
SchemeType SchemeExtractor::GetType() const
{
if (_component == "http" || _component == "https") 
	return  SchemeType::Net;

else if (_component == "file") 
	return SchemeType::Local;

else  return SchemeType::Unknown; 
	
}