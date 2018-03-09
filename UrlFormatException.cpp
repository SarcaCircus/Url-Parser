#include "UrlFormatException.h"
using namespace std;

UrlFormatException::UrlFormatException(const string& message)
	: runtime_error(message)
{
}