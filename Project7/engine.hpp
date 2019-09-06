#pragma once
#include "functions.hpp"
#include "c_base_entity.h"

class c_engine
{
public:
	DWORD get_localplayer()
	{
		return rpm<DWORD>(client + signatures::dwLocalPlayer);
	}

	DWORD get_entity_from_index(int idx)
	{
		return rpm<DWORD>(client + signatures::dwEntityList + (idx * 0x10));
	}

	int get_max_players()
	{
		return rpm<int>(client_state + signatures::dwClientState_MaxPlayer);
	}
	
	map get_map_name()
	{
		return rpm<map>(client_state + signatures::dwClientState_Map);
	}

	bool is_ingame()
	{
		return rpm<int>(client_state + signatures::dwClientState_State) == 6;
	}

	void force_jump()
	{
		wpm<int>(6, client + signatures::dwForceJump);
	}

	void force_attack()
	{
		wpm<int>(6, client + signatures::dwForceAttack);
	}

	void force_attack_secondary()
	{
		wpm<int>(6, client + signatures::dwForceAttack2);
	}

	void send_packets(bool state)
	{
		wpm<bool>(state, engine + signatures::dwbSendPackets);
	}

	void set_angles(vector angles)
	{
		wpm<vector>(angles, client_state + signatures::dwClientState_ViewAngles);
	}

	void glow_entity(c_base_entity entity, glow settings)
	{
		wpm<glow>(settings, glow_manager + ((entity.get_glow_index() * 0x38) + 0x4));
	}

};

extern c_engine g_engine;