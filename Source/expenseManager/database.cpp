#include "stdafx.h"
#include "database.h"

vector<expense> importDB()
{
	vector<expense> e;
	ifstream fi;
	fi.open("emdb.txt", ios::in);

	if (fi.is_open())
	{
		TCHAR* expenseItms[] = {
			L"Ăn uống",
			L"Di chuyển",
			L"Nhà cửa",
			L"Xe cộ",
			L"Nhu yếu phẩm",
			L"Dịch vụ"
		};
		// line format is [type]&&[content]&&&[amount],
		// So use std::string::find(), std::string::substr() and 
		// std::string::erase() to split them into 3 parts
		string strLine, strTypeIndex, strContent, strAmount;
		while (!fi.eof())
		{
			getline(fi, strLine);
			if (strLine.size() > 5)
			{
				strTypeIndex = strLine.substr(0, strLine.find("&&"));
				strContent = strLine.substr(strLine.find("&&") + 2, strLine.find("&&&") - 3);
				strAmount = strLine.erase(0, strLine.find("&&&", 0) + 3);
				// Convert them into TCHAR*
				TCHAR *wContent = new TCHAR[strContent.size() + 1],
					*wAmount = new TCHAR[strAmount.size() + 1];
				copy(strContent.begin(), strContent.end(), wContent);
				copy(strAmount.begin(), strAmount.end(), wAmount);
				wContent[strContent.size()] = 0;
				wAmount[strAmount.size()] = 0;
				// Add them to a vector storing data to import to listview later
				TCHAR *wTypeItm = expenseItms[stoi(strTypeIndex, nullptr, 10)];
				expense aE;
				aE.iTypeItm = stoi(strTypeIndex, nullptr, 10);
				aE.sContent = strContent;
				aE.ullAmount = stoll(strAmount, nullptr, 10); // int overflowwwwwwwwww
				e.push_back(aE);
				// Release pointers
				delete wContent;
				delete wAmount;
			}
		}

		fi.close();
	}

	return e;
}

int exportDB(int curIndex, TCHAR *content, TCHAR *amount)
{
	wofstream fo;
	fo.open("emdb.db", ios::out | ios::app);
	if (fo.is_open())
	{
		fo << curIndex << "&&" << content << "&&&" << amount << endl;
		fo.close();
		return 0;
	}

	return -1;
}
