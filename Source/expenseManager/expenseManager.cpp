#include "stdafx.h"
#include "expenseManager.h"


void updateReport(vector<expense> & e, unsigned long long & ullExpenseTotal, unsigned long long ullExpenseByType[6])
{
	while (!e.empty())
	{
		ullExpenseByType[e.back().iTypeItm] += e.back().ullAmount;
		ullExpenseTotal += e.back().ullAmount;
		e.pop_back();
	}
}

void drawChart(HDC hDC, unsigned long long ullExpenseTotal, unsigned long long ullExpenseByType[6])
{
	HBRUSH hBrush[NUMBER_OF_EXPENSE_TYPES];
	int i = 0;
	// Draw note (which color is which expense type
	RECT sqr[NUMBER_OF_EXPENSE_TYPES];
	// Rect 00
	sqr[0].left = 40;
	sqr[0].top = 310;
	sqr[0].right = sqr[0].left + iSquareEdge;
	sqr[0].bottom = sqr[0].top + iSquareEdge;
	// Rect 01
	sqr[1].left = 40;
	sqr[1].top = 340;
	sqr[1].right = sqr[1].left + iSquareEdge;
	sqr[1].bottom = sqr[1].top + iSquareEdge;
	// Rect 02
	sqr[2].left = 185;
	sqr[2].top = 310;
	sqr[2].right = sqr[2].left + iSquareEdge;
	sqr[2].bottom = sqr[2].top + iSquareEdge;
	// Rect 03
	sqr[3].left = 185;
	sqr[3].top = 340;
	sqr[3].right = sqr[3].left + iSquareEdge;
	sqr[3].bottom = sqr[3].top + iSquareEdge;
	// Rect 04
	sqr[4].left = 340;
	sqr[4].top = 310;
	sqr[4].right = sqr[4].left + iSquareEdge;
	sqr[4].bottom = sqr[4].top + iSquareEdge;
	// Rect 05
	sqr[5].left = 340;
	sqr[5].top = 340;
	sqr[5].right = sqr[5].left + iSquareEdge;
	sqr[5].bottom = sqr[5].top + iSquareEdge;

	for (i = 0; i < NUMBER_OF_EXPENSE_TYPES; i++)
	{
		hBrush[i] = CreateSolidBrush(colorRect[i]);
		SelectObject(hDC, hBrush[i]);
		Rectangle(hDC, sqr[i].left, sqr[i].top, sqr[i].right, sqr[i].bottom);
	}

	// Draw statistics bar. It won't if there was no pre-existed database.
	// ullExpenseTotal = -1 was sent as a flag 
	if (ullExpenseTotal != -1)
	{
		float fPercent[NUMBER_OF_EXPENSE_TYPES] = { 0.0 };
		int iWidth[NUMBER_OF_EXPENSE_TYPES] = { 0 };
		for (i = 0; i < NUMBER_OF_EXPENSE_TYPES; i++)
		{
			fPercent[i] = (float)ullExpenseByType[i] / (float)ullExpenseTotal;
		}
		for (i = 0; i < NUMBER_OF_EXPENSE_TYPES; i++)
		{
			iWidth[i] = (int)((float)iFullWidth * fPercent[i]);
		}

		RECT rect[NUMBER_OF_EXPENSE_TYPES];
		// Rect 00
		rect[0].left = 40;
		rect[0].top = 370;
		rect[0].right = rect[0].left + iWidth[0];
		rect[0].bottom = 405;
		// Rect 01
		rect[1].left = rect[0].right;
		rect[1].top = 370;
		rect[1].right = rect[1].left + iWidth[1];
		rect[1].bottom = 405;
		// Rect 02
		rect[2].left = rect[1].right;
		rect[2].top = 370;
		rect[2].right = rect[2].left + iWidth[2];
		rect[2].bottom = 405;
		// Rect 03
		rect[3].left = rect[2].right;
		rect[3].top = 370;
		rect[3].right = rect[3].left + iWidth[3];
		rect[3].bottom = 405;
		// Rect 04
		rect[4].left = rect[3].right;
		rect[4].top = 370;
		rect[4].right = rect[4].left + iWidth[4];
		rect[4].bottom = 405;
		// Rect 05
		rect[5].left = rect[4].right;
		rect[5].top = 370;
		rect[5].right = iFullWidth + 40;
		rect[5].bottom = 405;

		for (i = 0; i < NUMBER_OF_EXPENSE_TYPES; i++)
		{
			SelectObject(hDC, hBrush[i]);
			Rectangle(hDC, rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
			DeleteObject(hBrush[i]);
		}
	}
}