#include "Tabella2048.h"
#include <cstdlib>
#include <iostream>

class RandomAI{

public:
	Tabella2048 m_table;
	RandomAI(Tabella2048 table)
		:m_table(table)
	{}

	void move() {
		int select = rand()%4;
		
		switch (select) {
			case 0:
				m_table.moveA();
				std::cout << "a";
				break;
			case 1:
				m_table.moveS();
				std::cout << "s";
				break;
			case 2:
				m_table.moveW();
				std::cout << "w";
				break;
			case 3:
				m_table.moveD();
				std::cout << "d";
				break;
			default:
				m_table.stampa();
				std::cout << "i dunno :(";
		}
	}
};