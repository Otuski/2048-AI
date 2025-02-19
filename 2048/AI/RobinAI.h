#pragma once

#include "AI.h"
#include "Table2048.h"

class RobinAI : AI {
public:
	Table2048 m_table;

	RobinAI(Table2048 table);
	virtual char move();

};