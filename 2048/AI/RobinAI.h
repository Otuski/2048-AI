#pragma once

#include "AI.h"
#include "Table2048.h"

class RobinAI : AI {
public:
	Table2048 m_table;

	//costruttore implicito sufficiente perch� costruisce Table2048
	virtual char move();

};