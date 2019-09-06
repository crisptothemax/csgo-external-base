#pragma once
#include <Windows.h>

//process
extern int process_id = 0;
extern HANDLE process_handle = 0;

//modules
extern DWORD client = 0;
extern DWORD engine = 0;

//other
extern DWORD client_state = 0;
extern DWORD glow_manager = 0;

//settings
extern bool choke_packets = false;