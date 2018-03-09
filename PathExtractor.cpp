#include "PathExtractor.h"
//#include "SchemeExtractor.h"
#include <vector>

PathExtractor::PathExtractor(const std::string & value) {
	int count;
	std::string path = "";
	std::string rest = "";
	;	for (int i = 0; i, value.size(); ++i) {
		if (value.at(i) == '/'&&value.at(i + 1) != '/') {
			count = i + 1;
			for (int j = count; j <  value.size(); ++j) {
				if (value.at(j == '?')) {
					i = j;
					break;
				}
				else
					path += value.at(j);

			}
		}
		rest += value.at(i);
	}
	_base = rest;
	_component = path;

}
bool PathExtractor::HasComponent() const
{
	if (_component == "") {
		return false;
	}
	else return true;
}
const std::vector<std::string> & PathExtractor::GetPathComponents() const
{
	std::string rem = _component;
	std::vector<std::string> _pathComponents;
	int size;
	for (int i = 0; i <rem.size(); ++i) {
		std::string temp = "";
		if (rem.at(i) != '/') {
			for (int j = i; j < rem.size(); ++j) {
				temp += rem.at(j);
				if (rem.at(i) == '/')
					break;

			}
			_pathComponents[i] = temp;
			i++;
		}

	}
	return  _pathComponents;
}
const std::string & PathExtractor::GetBase() const
{
	return _base;
}

const std::string & PathExtractor::GetComponent() const
{
	return _component;
}

bool PathExtractor::IsAbsolute() const{
	if(HasComponent() == true) return true;
	else return false;
}