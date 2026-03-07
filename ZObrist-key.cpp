#include "Global-Defines.h"

std::mt19937_64 rand64;

const uint64_t KEY[6][2][128] = {
	{
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},

		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}
	},

	{
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},

		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()}
	},

	{
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},

		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
	},

	{
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},

		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
	},
{
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},

		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
	},

	{
		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},

		{rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),	rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),
		 rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(),    rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64(), rand64()},
	}
};