#pragma once
#include <direct.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

extern int cpslmin, cpslmax, cpsrmin, cpsrmax, lbind, rbind;

void save()
{
	int check = _chdir("C:/.GAC");
	if (check)
	{
		_mkdir("C:/.GAC");
		_chdir("C:/.GAC");
	}
	ofstream config;
	config.open("config.ini", ios::out);
	config << cpslmin << endl;
	config << cpslmax << endl;
	config << cpsrmin << endl;
	config << cpsrmax << endl;
	config << lbind << endl;
	config << rbind << endl;
	config.close();
}

void load()
{
	int check = _chdir("C:/.GAC");
	if (check)
		save();
	ifstream config;
	config.open("config.ini", ios::in);
	if (config.good())
	{
		for (int i = 0; i < 6; i++)
		{
			string x="";
			switch (i)
			{
			case 0:
				getline(config, x);
				cpslmin = stoi(x);
				break;
			case 1:
				getline(config, x);
				cpslmax = stoi(x);
				break;
			case 2:
				getline(config, x);
				cpsrmin = stoi(x);
				break;
			case 3:
				getline(config, x);
				cpsrmax = stoi(x);
				break;
			case 4:
				getline(config, x);
				lbind = stoi(x);
				break;
			case 5:
				getline(config, x);
				rbind = stoi(x);
				break;
			}
		}
	}
	else
	{
		config.close();
		save();
	}
	config.close();

}