#pragma once
#include <windows.h>
#include <time.h>
//#include <iostream>
//using namespace std;

extern int cpslmin, cpslmax, cpsrmin, cpsrmax, lbind, rbind;
extern bool boost, rpower = true, lpower = true;

bool is_cursor_visible()
{
	CURSORINFO ci{ sizeof(CURSORINFO) };
	if (!GetCursorInfo(&ci))
		return false;

	const auto handle = ci.hCursor;
	if ((handle > (HCURSOR)50000) && (handle < (HCURSOR)100000))
		return true;

	return false;
}


int randcps(int min, int max)
{
	int cps;
	if (min != max)
	{
		// RANDOM CPS SEED
		// RANDOM CPS
		cps = rand() % (max + 1 - min);
		cps += min;
	}
	else
		cps = min;
//    cout << cps << endl;
	return cps;
}

void click()
{
	//
	bool debug = false;
	clock_t start, stop;
	double times;
	//
	bool debug2 = false;
	clock_t start2, stop2;
	double times2;

	srand(time(NULL));
	while (true)
	{
		if (FindWindowA(("LWJGL"), nullptr) == GetForegroundWindow() && (!is_cursor_visible()))
		{
			if (GetAsyncKeyState(lbind) == -32767)
				lpower = !lpower;
			if (GetAsyncKeyState(rbind) == -32767)
				rpower = !rpower;
			if (GetAsyncKeyState(VK_LBUTTON) && (lpower))
			{
				if (!debug)
				{
					start = clock();
					debug = true;
				}
				stop = clock();
				times = double(stop - start) / CLOCKS_PER_SEC;
				if ((times * 1000) > (1000 / randcps(cpslmin, cpslmax)))
				{
					debug = false;

					PostMessageW(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
					PostMessageW(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
					//				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					//				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				}
			}

			if (GetAsyncKeyState(VK_RBUTTON) && (rpower))
			{
				if (!debug2)
				{
					start2 = clock();
					debug2 = true;
				}
				stop2 = clock();
				times2 = double(stop2 - start2) / CLOCKS_PER_SEC;
				if ((times2 * 1000) > (1000 / randcps(cpsrmin, cpsrmax)))
				{
					debug2 = false;
					PostMessageW(GetForegroundWindow(), WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
					PostMessageW(GetForegroundWindow(), WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
				}
			}
		}
		else
			Sleep(10);
	}
}