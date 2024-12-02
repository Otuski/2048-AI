#pragma once
class Tabella2048
{
private:
	void aggiungiNumero();
public:
	int matrice[4][4];
	int punteggio;

	Tabella2048();
	void moveW();
	void moveA();
	void moveS();
	void moveD();
	void stampa() const;
	void avviaGioco();
	bool equals(const int[4][4]);
};

