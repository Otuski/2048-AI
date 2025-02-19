#pragma once

#include "AI.h"
#include "Table2048.h"

class RandomAI : AI {
public:
	Table2048 m_table;

	RandomAI(Table2048 table);
	virtual char move();

};