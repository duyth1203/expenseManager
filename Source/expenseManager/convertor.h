#pragma once

#include <string>

using namespace std;

/*	Return pointers of TCHAR type to the converted string 
	from a string of std::string data type.
	Return nullptr if failed.
*/
TCHAR * stow(string s);

/*	Return pointers of TCHAR type to the converted string
	from a number of unsigned long long data type.
	Return nullptr if failed.
*/
TCHAR * ulltow(unsigned long long n);