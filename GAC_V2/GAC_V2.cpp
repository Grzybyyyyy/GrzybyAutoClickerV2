// AutoClicker By Grzybyyyyy
#include <iostream>
#include <windows.h>
#include <thread>
#include "click.h"
#include "menu.h"
#include "config.h"

using namespace std;

HWND pid;
int cpslmin = 10, cpslmax = 10, cpsrmin = 10, cpsrmax = 10, lbind=-1, rbind=-1;
string slbind = "NONE", srbind = "NONE";
bool boost = true;

int main()
{
//	system("title GAC_V2");
	system("title GrzybyAutoClicker_V2");
	pid = GetConsoleWindow();
	load();
	slbind = keys(lbind);
	srbind = keys(rbind);
	// USTAWIANIE WIELKOSCI OKNA
	if (pid != NULL)
		MoveWindow(pid, 200, 200, 300, 300, TRUE);

	thread menu (smenu);

	thread click1(click);

	bool MV = true;
	while (true)
	{
		Sleep(10);
		// SHOW/HIDE CONSOLE
		if (GetAsyncKeyState(VK_INSERT) == -32767)
		{
			MV = !MV;
			if (MV)
				ShowWindow(pid, SW_SHOW);
			else
				ShowWindow(pid, SW_HIDE);
		}

	}
}