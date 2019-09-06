#pragma once
#include <Windows.h>

//process
extern int pID = 0;
extern HANDLE pHandle = 0;

//modules
extern DWORD client = 0;
extern DWORD engine = 0;

//other
extern DWORD client_state = 0;
extern DWORD glow_manager = 0;

//settings
extern bool choke_packets = false;