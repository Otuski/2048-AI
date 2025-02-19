#include "RobinAI.h"

RobinAI::RobinAI(Table2048 table) : m_table(table) {}

char RobinAI::move()
{
	if (m_table.isValidMoveA()) {
		return 'a';
	}
	if (m_table.isValidMoveS()) {
		return 's';
	}
	if (m_table.isValidMoveD()) {
		return 'd';
	}
	if (m_table.isValidMoveW()) {
		return 'w';
	}
	return 0;
}
