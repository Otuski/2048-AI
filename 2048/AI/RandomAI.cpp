#include "RandomAI.h"
#include <cstdlib>
#include <iostream>


char RandomAI::move() {
	int select = rand()%4;
		
	while (!m_table.isGameOver()) {
		switch (select) {
		case 0:
			return 'a';
		case 1:
			return 's';
		case 2:
			return 'w';
		case 3:
			return 'd';
		}
	}
			
	return 0;
};