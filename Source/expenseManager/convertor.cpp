#include "stdafx.h"
#include "convertor.h"


TCHAR * stow(string sStr)
{
	TCHAR * wStr = new TCHAR[sStr.size() + 1];

	if (!wStr)
	{
		return nullptr;
	}

	copy(sStr.begin(), sStr.end(), wStr);
	wStr[sStr.size()] = 0;
	return wStr;
}

TCHAR * ulltow(unsigned long long ullNum)
{
	string sNum = to_string(ullNum);
	return stow(sNum);
}