#pragma once

struct vector
{
	float x, y, z;
};

struct map
{
	char name[64];
};

typedef struct
{
	float matrix[3][4];
}matrix3x4;

struct color
{
	float r, g, b;
};

struct glow
{
	color clr;
	float m_flGlowAlpha = 1.f;
	char m_unk[4];
	float m_flUnk;
	float m_flBloomAmount = 1.f; //1 max
	float m_flUnk1;
	bool m_bRenderWhenOccluded = true;
	bool m_bRenderWhenUnoccluded = false;
	bool m_bFullBloomRender = false; //outline or inline
	char m_unk1;
	int m_nFullBloomStencilTestValue;
	int m_nGlowStyle = 0; //3 - flicker, 2 - inline glow , 1 - inline+flicker, 0 - full body glow
};