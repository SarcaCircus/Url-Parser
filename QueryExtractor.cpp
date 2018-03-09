#include "QueryExtractor.h"

QueryExtractor::QueryExtractor(const std::string & value) {
	std::string query = " ";
	std::string based = " ";
	int k;
	for (int i = 0; i < value.size(); i++) {
		
		if (value.at(i) == '?') {
			for (int j = i+1; j < value.size(); ++j) {
				if (value.at(j) == '#') {
					i = j+1;
					break;
				}
				else
				query += value.at(j);
			}
		}
		based += value.at(i);
	
	}
	_base = based;
	_component = query;


}
bool QueryExtractor::HasComponent() const
{
	if (_base == ""&&_component=="") {
		return true;
	}
	else if(_component=="")return false;
	else return true;
}
const std::string & QueryExtractor::GetBase() const
{
	return _base;
}
const std::string & QueryExtractor::GetComponent() const
{
	return _component;
}
const std::vector<std::string>& QueryExtractor::GetQueryParameters() const {
	std::string rem = _component;
	std::vector<std::string> _parameters;

	for (int i = 0; i <rem.size(); ++i) {
		std::string temp = "";
		if (rem.at(i) != '&') {
			for (int j = i; j < rem.size(); ++j) {
				temp += rem.at(j);
				if (rem.at(i) == '/')
					break;

			}
			_parameters[i] = temp;
			i++;
		}

	}
	return  _parameters;
}


