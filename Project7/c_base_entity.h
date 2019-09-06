#pragma once
#include "functions.hpp"


//from sdk
#define	FL_ONGROUND				(1<<0)	// At rest / on the ground
#define FL_DUCKING				(1<<1)	// Player flag -- Player is fully crouched
#define	FL_WATERJUMP			(1<<2)	// player jumping out of water
#define	FL_INWATER				(1<<9)	// In water

class c_base_entity
{
public:
	c_base_entity(DWORD addy)
	{
		address = addy;
	}

	int get_health()
	{
		return rpm<int>(address + netvars::m_iHealth);
	}

	int get_classid()
	{
		return rpm<int>(rpm<DWORD>(rpm<DWORD>(rpm<DWORD>(address + 0x8) + 0x8) + 0x1) + 0x14);
	}

	bool is_alive()
	{
		return get_health() > 0;
	}

	int get_team()
	{
		return rpm<int>(address + netvars::m_iTeamNum);
	}

	bool is_defusing()
	{
		return rpm<bool>(address + netvars::m_bIsDefusing);
	}

	int get_armor()
	{
		return rpm<int>(address + netvars::m_ArmorValue);
	}

	bool is_spotted()
	{
		return rpm<bool>(address + netvars::m_bSpotted);
	}

	int get_comp_wins()
	{
		return rpm<int>(address + netvars::m_iCompetitiveWins);
	}

	bool has_kit()
	{
		return rpm<bool>(address + netvars::m_bHasDefuser);
	}

	bool is_scoped()
	{
		return rpm<bool>(address + netvars::m_bIsScoped);
	}

	bool has_helmet()
	{
		return rpm<bool>(address + netvars::m_bHasHelmet);
	}

	int get_lifestate()
	{
		return rpm<int>(address + netvars::m_lifeState);
	}

	int get_flags()
	{
		return rpm<int>(address + netvars::m_fFlags);
	}

	bool get_dm_immunity()
	{
		return rpm<bool>(address + netvars::m_bGunGameImmunity);
	}

	bool is_dormant()
	{
		return rpm<bool>(address + signatures::m_bDormant);
	}

	vector get_pos()
	{
		return rpm<vector>(address + netvars::m_vecOrigin);
	}

	vector get_eye_position()
	{
		return rpm<vector>(address + netvars::m_vecViewOffset);
	}

	DWORD get_ent_bone_matrix()
	{
		return rpm<DWORD>(address + netvars::m_dwBoneMatrix);
	}

	vector get_bone_pos(int bone_id)
	{
		matrix3x4 bone_matrix = rpm<matrix3x4>(get_ent_bone_matrix() + bone_id * 0x30);
		return { bone_matrix.matrix[0][3],bone_matrix.matrix[1][3], bone_matrix.matrix[2][3] };
	}

	int get_glow_index()
	{
		return rpm<int>(address + netvars::m_iGlowIndex);
	}

	vector get_angles()
	{
		return rpm<vector>(client_state + signatures::dwClientState_ViewAngles);
	}

	DWORD address = 0;
};
