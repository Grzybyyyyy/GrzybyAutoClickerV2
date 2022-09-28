#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "config.h"

using namespace std;

extern int cpslmin, cpslmax, cpsrmin, cpsrmax, lbind, rbind;
extern HWND pid;
extern string slbind, srbind;

void cursor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << ">";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//============ 12-5=7
void menu(int s)
{
	system("cls");
	cout << "==============================" << endl;
	cout << "= Grzybyyyyy Auto Clicker V2 =" << endl;
	cout << "==========[Left CPS]==========" << endl;
	cout << "= ";
	for (int i = 0; i < 6 - to_string(cpslmin).size(); i++)
		cout << " ";
	cout << "MIN: " << cpslmin << " == MAX: " << cpslmax;
	for (int i = 0; i < 6 - to_string(cpslmax).size(); i++)
		cout << " ";
	cout << " =" << endl;
	cout << "==========[Right CPS]=========" << endl;
	cout << "= ";
	for (int i = 0; i < 6 - to_string(cpsrmin).size(); i++)
		cout << " ";
	cout << "MIN: " << cpsrmin << " == MAX: " << cpsrmax;
	for (int i = 0; i < 6 - to_string(cpsrmax).size(); i++)
		cout << " ";
	cout << " =" << endl;
	cout << "==============================" << endl;
	cout << "= ";
	if (s == 0)
		cursor();
	else
		cout << " ";
	cout << " = SET LEFT CPS           =" << endl;
	cout << "= ";

	if (s == 1)
		cursor();
	else
		cout << " ";

	cout << " = SET RIGHT CPS          =" << endl;

	cout << "= ";
	if (s == 2)
		cursor();
	else
		cout << " ";
	cout << " = BIND KEY               =" << endl;
	/*
	cout << "= ";
	if (s == 3)
		cursor();
	else
		cout << " ";
	cout << " = BOOST: [";
	if (boost)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "ON";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		cout << "ON";
	}
	cout << "] | [";
	if (!boost)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "OFF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		cout << "OFF";
	}
	cout << "]    =" << endl;
	*/
	cout << "==============================" << endl;
	cout << "= [INSERT] = Hide/Show Menu  =" << endl;
	cout << "==============================" << endl;
}

string keys(int ikey)
{
	switch (ikey)
	{
	case -1:
		return "NONE";
		break;
	case 0xBA:
		return ";";
		break;
	case 0xBB:
		return "+";
		break;
	case 0xBC:
		return ",";
		break;
	case 0xBD:
		return "-";
		break;
	case 0xBE:
		return ".";
		break;
	case 0xBF:
		return "/";
		break;
	case 0xDB:
		return "[";
		break;
	case 0xDD:
		return "]";
		break;
	case 0xDE:
		return "'";
		break;
	case 0x05:
		return "M4";
		break;
	case 0x06:
		return "M5";
		break;
	default: 
		string r;
		r = char(ikey);
		return r;
	}
}

void setcpsmenu(int s, int s2)
{//30-23
	system("cls");
	cout << "==============================" << endl;
	cout << "= Grzybyyyyy Auto Clicker V2 =" << endl;
	if (s == 0)
	{
		cout << "==========[MIN CPS]===========" << endl;
		cout << "= ";
		if (s2 == 0)
			cursor();
		else
			cout << " ";
		cout << " = [";
		for (int i = 0; i < cpslmin / 10; i++)
			cout << "#";
		for (int i = 0; i < 10 - (cpslmin / 10); i++)
			cout << " ";
		cout << "] = [" << cpslmin << "]";
		for (int i = 0; i < 5 - to_string(cpslmin).size(); i++)
			cout << " ";
		cout << " =" << endl;

		cout << "==========[MAX CPS]===========" << endl;
		cout << "= ";
		if (s2 == 1)
			cursor();
		else
			cout << " ";
		cout << " = [";
		for (int i = 0; i < cpslmax / 10; i++)
			cout << "#";
		for (int i = 0; i < 10 - (cpslmax / 10); i++)
			cout << " ";
		cout << "] = [" << cpslmax << "]";
		for (int i = 0; i < 5 - to_string(cpslmax).size(); i++)
			cout << " ";
		cout << " =" << endl;

	}
	else if (s == 1)
	{
		cout << "==========[MIN CPS]===========" << endl;
		cout << "= ";
		if (s2 == 0)
			cursor();
		else
			cout << " ";
		cout << " = [";
		for (int i = 0; i < cpsrmin / 10; i++)
			cout << "#";
		for (int i = 0; i < 10 - (cpsrmin / 10); i++)
			cout << " ";
		cout << "] = [" << cpsrmin << "]";
		for (int i = 0; i < 5 - to_string(cpsrmin).size(); i++)
			cout << " ";
		cout << " =" << endl;

		cout << "==========[MAX CPS]===========" << endl;
		cout << "= ";
		if (s2 == 1)
			cursor();
		else
			cout << " ";
		cout << " = [";
		for (int i = 0; i < cpsrmax / 10; i++)
			cout << "#";
		for (int i = 0; i < 10 - (cpsrmax / 10); i++)
			cout << " ";
		cout << "] = [" << cpsrmax << "]";
		for (int i = 0; i < 5 - to_string(cpsrmax).size(); i++)
			cout << " ";
		cout << " =" << endl;

	}
	else if (s == 2)
	{
		cout << "==============================" << endl;
		cout << "= ";
		if (s2 == 0)
			cursor();
		else
			cout << " ";
		cout << " = On/Off LClick [\"" << slbind << "\"]";
		for (int i = 0; i < 4 - slbind.size(); i++)
			cout << " ";
		cout << " ="<<endl;
		cout << "= ";
		if (s2 == 1)
			cursor();
		else
			cout << " ";
		cout << " = On/Off RClick [\"" << srbind << "\"]";
		for (int i = 0; i < 4 - srbind.size(); i++)
			cout << " ";
		cout << " =" << endl;
	}

	cout << "==============================" << endl;
	cout << "= ";
	if (s2 == 2)
		cursor();
	else
		cout << " ";
	cout << " =          BACK          =" << endl;
	cout << "==============================" << endl;
}

int binds()
{
	while (true)
	{
		Sleep(10);
		if (pid == GetForegroundWindow())
		{
			for (int KEY = 65; KEY <= 90; KEY++)
				if (GetAsyncKeyState(KEY) == -32767)
					return KEY;
			for (int KEY = 48; KEY <= 57; KEY++)
				if (GetAsyncKeyState(KEY) == -32767)
					return KEY;
			if (GetAsyncKeyState(0x1B) == -32767)
				return -1;
			if (GetAsyncKeyState(0xBA) == -32767)
				return 0xBA;
			if (GetAsyncKeyState(0xBB) == -32767)
				return 0xBB;
			if (GetAsyncKeyState(0xBC) == -32767)
				return 0xBC;
			if (GetAsyncKeyState(0xBD) == -32767)
				return 0xBD;
			if (GetAsyncKeyState(0xBE) == -32767)
				return 0xBE;
			if (GetAsyncKeyState(0xBF) == -32767)
				return 0xBF;
			if (GetAsyncKeyState(0xDB) == -32767)
				return 0xDB;
			if (GetAsyncKeyState(0xDD) == -32767)
				return 0xDD;
			if (GetAsyncKeyState(0xDE) == -32767)
				return 0xDE;
			if (GetAsyncKeyState(0x05) == -32767)
				return 0x05;
			if (GetAsyncKeyState(0x06) == -32767)
				return 0x06;
		}
	}
}

void setcps(int s)
{
	int s2 = 0;
	setcpsmenu(s, s2);
	while (true)
	{
		Sleep(10);
		if ((GetAsyncKeyState(VK_UP) == -32767) && (s2 > 0))
		{
			s2--;
			setcpsmenu(s, s2);
		}
		if ((GetAsyncKeyState(VK_DOWN) == -32767) && (s2 < 2))
		{
			s2++;
			setcpsmenu(s, s2);
		}
		if (s == 0)
		{
			if (s2 == 0)
			{
				if ((GetAsyncKeyState(VK_RIGHT) == -32767) && (cpslmin < 100))
				{
					cpslmin++;
					if (cpslmin > cpslmax)
						cpslmax = cpslmin;
					setcpsmenu(s, s2);
				}
				if ((GetAsyncKeyState(VK_LEFT) == -32767) && (cpslmin > 1))
				{
					cpslmin--;
					setcpsmenu(s, s2);
				}
			}
			else if (s2 == 1)
			{
				if ((GetAsyncKeyState(VK_RIGHT) == -32767) && (cpslmax < 100))
				{
					cpslmax++;
					setcpsmenu(s, s2);
				}
				if ((GetAsyncKeyState(VK_LEFT) == -32767) && (cpslmax > 1))
				{
					cpslmax--;
					if (cpslmin > cpslmax)
						cpslmin = cpslmax;
					setcpsmenu(s, s2);
				}
			}
		}
		else if (s == 1)
		{
			if (s2 == 0)
			{
				if ((GetAsyncKeyState(VK_RIGHT) == -32767) && (cpsrmin < 100))
				{
					cpsrmin++;
					if (cpsrmin > cpsrmax)
						cpsrmax = cpsrmin;
					setcpsmenu(s, s2);
				}
				if ((GetAsyncKeyState(VK_LEFT) == -32767) && (cpsrmin > 1))
				{
					cpsrmin--;
					setcpsmenu(s, s2);
				}
			}
			else if (s2 == 1)
			{
				if ((GetAsyncKeyState(VK_RIGHT) == -32767) && (cpsrmax < 100))
				{
					cpsrmax++;
					setcpsmenu(s, s2);
				}
				if ((GetAsyncKeyState(VK_LEFT) == -32767) && (cpsrmax > 1))
				{
					cpsrmax--;
					if (cpsrmin > cpsrmax)
						cpsrmin = cpsrmax;
					setcpsmenu(s, s2);
				}
			}
		}
		else if (s == 2)
		{
			if (s2 == 0)
			{
				if (GetAsyncKeyState(VK_RETURN) == -32767)
				{
					slbind = "...";
					setcpsmenu(s, s2);
					lbind = binds();
					slbind = keys(lbind);
					setcpsmenu(s, s2);
				}
			}
			else if (s2 == 1)
			{
				if (GetAsyncKeyState(VK_RETURN) == -32767)
				{
					srbind = "...";
					setcpsmenu(s, s2);
					rbind = binds();
					srbind = keys(rbind);
					setcpsmenu(s, s2);
				}
			}
		}

		if ((GetAsyncKeyState(VK_RETURN) == -32767) && (s2 == 2))
		{
			menu(s);
			save();
			break;
		}
	}
}

void smenu()
{
	int s = 0;
	bool pidmenu = false;
	menu(s);
	while (true)
	{
		Sleep(10);
		if (pid == GetForegroundWindow())
		{
			if ((GetAsyncKeyState(VK_UP) == -32767) && (s > 0))
			{
				s--;
				menu(s);
			}
			if ((GetAsyncKeyState(VK_DOWN) == -32767) && (s < 2)) //3
			{
				s++;
				menu(s);
			}
			if (GetAsyncKeyState(VK_RETURN) == -32767)
			{
//				if (s == 3)
//					boost = !boost;
//				else
				setcps(s);
				menu(s);
			}
			pidmenu = false;
		}
		else
		{
			if (!pidmenu)
			{
				pidmenu = true;
				menu(s);
			}
		}
	}
}
