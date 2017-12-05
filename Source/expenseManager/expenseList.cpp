#include "stdafx.h"
#include "expenseList.h"

void initListViewColumn(HWND hwnd)
{
	LVCOLUMN lvCol;
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
	lvCol.fmt = LVCFMT_LEFT;

	// First column
	lvCol.cx = 95;
	lvCol.pszText = L"Loại chi tiêu";
	SendMessage(hwnd, LVM_INSERTCOLUMN, 0, (LPARAM)&lvCol);

	// Second column
	lvCol.cx = 235;
	lvCol.pszText = L"Nội dung";
	SendMessage(hwnd, LVM_INSERTCOLUMN, 1, (LPARAM)&lvCol);

	// Third column
	lvCol.cx = 95;
	lvCol.pszText = L"Số tiền";
	SendMessage(hwnd, LVM_INSERTCOLUMN, 2, (LPARAM)&lvCol);
}

void addRowToListView(HWND hwnd, const int & nRow, LPWSTR wType, LPWSTR wContent, LPWSTR wAmount)
{
	LVITEM lvItm;
	lvItm.mask = LVIF_TEXT;
	lvItm.iItem = nRow;
	lvItm.cchTextMax = 256;
	lvItm.iSubItem = 0;
	lvItm.pszText = wType;
	SendMessage(hwnd, LVM_INSERTITEM, 0, (LPARAM)&lvItm);
	lvItm.iSubItem = 1;
	lvItm.pszText = wContent;
	SendMessage(hwnd, LVM_SETITEM, 0, (LPARAM)&lvItm);
	lvItm.iSubItem = 2;
	lvItm.pszText = wAmount;
	SendMessage(hwnd, LVM_SETITEM, 0, (LPARAM)&lvItm);
}