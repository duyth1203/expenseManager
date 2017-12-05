#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "expenseList.h"
#include "convertor.h"

using namespace std;

struct expense {
	int iTypeItm;
	unsigned long long ullAmount;
	string sContent;
};

/*	Return a vector of expense structure data type 
	storing data imported from default "em.db" database file
	If checking for size of the vector is 0:
	+ error reading/ extracting data from the file
	+ or no data/file (maybe newly created) existed
*/
vector<expense> importDB();

/*	Return 0 if exporting to database file is succeeded
	Otherwise, return -1
*/
int exportDB(int, TCHAR *content, TCHAR *amount);