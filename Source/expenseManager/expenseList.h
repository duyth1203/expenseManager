#pragma once

#include <commctrl.h>

// Create a listview control with given columns
void initListViewColumn(HWND hwnd);

// Add newly data as a row to the listview
void addRowToListView(HWND hwnd, const int & nRow, LPWSTR type, LPWSTR content, LPWSTR amount);