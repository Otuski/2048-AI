#pragma once

class Table2048
{
private:
public:
	int matrice[4][4];
	int punteggio;

	Table2048();
	bool moveW();
	bool moveA();
	bool moveS();
	bool moveD();
	bool move(char move);

	bool isValidMoveW();
	bool isValidMoveA();
	bool isValidMoveS();
	bool isValidMoveD();
	bool isValidMove(char move);

	void aggiungiNumero();
	bool isGameOver();
	void print() const;
	void avviaGioco();
	bool equals(const int[4][4]);
};

