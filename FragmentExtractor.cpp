#include "FragmentExtractor.h"

FragmentExtractor::FragmentExtractor(const std::string & value)
{
	std::string fragment = " ";
	std::string based = " ";
	int k;
	for (int i = 0; i < value.size(); i++) {
		based += value.at(i);
		if (value.at(i) == '#') {
			k = i;
			break;
		}
	}
			for (int j = k; j <  value.size(); j++) {
				fragment += value.at(j);
			}
			_base = based;
			_component = fragment;

 
	// look for '#' character
	// if exists, _component = everything to the right of '#'
	// _base = evertyhing to the left of '#', or the entire value string if '#' doens't exist
}

bool FragmentExtractor::HasComponent() const
{
	if (_component == " ") {
		return false;
	} // TODO return true if a fragment 
	else return true;
}

const std::string & FragmentExtractor::GetBase() const
{
	return _base;
}

const std::string & FragmentExtractor::GetComponent() const
{
	return _component;
}
