#pragma once

#include <random>

constexpr auto WHITE_ = 0;
constexpr auto BLACK_ = 1;

inline unsigned __int64 rand64() {
	return ((unsigned __int64)rand()) xor ((unsigned __int64)rand() << 15) xor ((unsigned __int64)rand() << 31)
		xor ((unsigned __int64)rand() << 47) xor ((unsigned __int64)rand() << 59);
}

const static unsigned __int64 KEY[6][2][8][8] = {
	{
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
	},
	
	{
		{ {rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
	},

	{
		{ {rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
	},

	{
		{ {rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
	},
{
		{ {rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
	},

    {
		{ {rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
		{{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}},
	}
};

