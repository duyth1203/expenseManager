#include "stdafx.h"
#include "expenseAdd.h"

void initComboBox(HWND hwnd, const int & nCbbItms)
{
	TCHAR* cbbItms[] = {
		L"Ăn uống (Sáng, trưa, chiều, xế, tối, khuya, trà sữa…)",
		L"Di chuyển (bus, đổ xăng, taxi, bơm xe, tàu…)",
		L"Nhà cửa (tiền thuê nhà, nước, điện, nước lau nhà…)",
		L"Xe cộ (đổ xăng, vá xe, bảo dưỡng, gởi xe…)",
		L"Nhu yếu phẩm (xà bông, sữa tắm, dao cạo râu…)",
		L"Dịch vụ (intenet, thẻ cào điện thoại…)"
	};

	for (int i = 0; i < nCbbItms; i++)
	{
		SendMessage(hwnd, CB_ADDSTRING, 0, (LPARAM)cbbItms[i]);
	}
	// Select first item in the combobox
	SendMessage(hwnd, CB_SETCURSEL, 0, 0);
}
