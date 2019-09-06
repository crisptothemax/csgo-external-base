#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

#include "offsets.hpp"
#include "globals.hpp"
#include "structures.hpp"

using namespace hazedumper;
using std::cout;
using std::endl;
using std::hex;
using std::dec;


template <class dataType>
void wpm(dataType value, DWORD addy)
{
	WriteProcessMemory(pHandle, (PVOID)addy, &value, sizeof(dataType), 0);
}

template <class dataType>
dataType rpm(DWORD addy)
{
	dataType data;
	ReadProcessMemory(pHandle, (PVOID)addy, &data, sizeof(dataType), 0);
	return data;
}

bool attach()
{
	const char* processName = "csgo.exe";

	PROCESSENTRY32 procEntry32;
	procEntry32.dwSize = sizeof(PROCESSENTRY32);

	HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcSnap == INVALID_HANDLE_VALUE)
		return false;

	while (Process32Next(hProcSnap, &procEntry32))
	{
		if (!strcmp(processName, procEntry32.szExeFile))
		{
			HANDLE temp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procEntry32.th32ProcessID);
			if (temp == INVALID_HANDLE_VALUE) {
				CloseHandle(hProcSnap);
				return false;
			}

			pID = procEntry32.th32ProcessID;
			pHandle = temp;

			CloseHandle(hProcSnap);
			return true;
		}
	}

	CloseHandle(hProcSnap);
	return false;
}

DWORD get_module(const char* moduleName)
{
	HANDLE hSnapShot;
	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);

	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(MODULEENTRY32);

	if (hSnapShot == INVALID_HANDLE_VALUE) {
		CloseHandle(hSnapShot);
		return 0;
	}

	if (Module32First(hSnapShot, &mEntry))
	{
		if (!strcmp(moduleName, mEntry.szModule))
		{
			CloseHandle(hSnapShot);
			return (DWORD)mEntry.modBaseAddr;
		}
	}

	while (Module32Next(hSnapShot, &mEntry))
	{
		if (!strcmp(moduleName, mEntry.szModule))
		{
			CloseHandle(hSnapShot);
			return (DWORD)mEntry.modBaseAddr;
		}
	}
	CloseHandle(hSnapShot);
	return false;
}