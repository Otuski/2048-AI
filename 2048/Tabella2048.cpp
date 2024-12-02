#include "Tabella2048.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

static int findlen(int);
static void clearScreen();
static bool confrontaMatrici(const int[4][4], const int[4][4]);

void Tabella2048::aggiungiNumero()
{
    std::vector<std::pair<int, int>> celleVuote;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrice[i][j] == 0) {
                celleVuote.emplace_back(i, j);
            }
        }
    }

    if (!celleVuote.empty()) {
        std::pair<int, int> scelta = celleVuote[rand() % celleVuote.size()];
        matrice[scelta.first][scelta.second] = (rand() % 10 < 9) ? 2 : 4; // 90% per 2, 10% per 4
    }
}

Tabella2048::Tabella2048(): 
    matrice{0}, punteggio(0)

    {
        srand(unsigned int(time(nullptr))); // Inizializza il generatore casuale
        aggiungiNumero();
        aggiungiNumero(); // Inizia con due numeri casuali
}

void Tabella2048::moveW()
{
    //copia la matrice
    int copia[4][4];
    std::memcpy(&copia, &matrice, sizeof(int) * 16);

    for (int i = 0; i < 4; i++) {
        int p = 0;
        bool merged[4] = { false, false, false, false };

        for (int j = 0; j < 4; j++) {
            if (matrice[j][i] != 0) {
                int num = matrice[j][i];
                matrice[j][i] = 0;

                if (p > 0 && matrice[p - 1][i] == num && !merged[p - 1]) {
                    matrice[p - 1][i] *= 2;
                    punteggio += matrice[p - 1][i];
                    merged[p - 1] = true;
                }
                else {
                    matrice[p][i] = num;
                    p++;
                }
            }
        }
    }
    //controllo mossa valida
    if (!confrontaMatrici(copia, matrice)) {
        aggiungiNumero();
    }
    stampa();
}

void Tabella2048::moveA()
{
    //copia la matrice
    int copia[4][4];
    std::memcpy(&copia, &matrice, sizeof(int) * 16);

    for (int i = 0; i < 4; i++) {
        int p = 0;
        bool merged[4] = { false, false, false, false };

        for (int j = 0; j < 4; j++) {
            if (matrice[i][j] != 0) {
                int num = matrice[i][j];
                matrice[i][j] = 0;

                if (p > 0 && matrice[i][p - 1] == num && !merged[p - 1]) {
                    matrice[i][p - 1] *= 2;
                    punteggio += matrice[i][p - 1];
                    merged[p - 1] = true;
                }
                else {
                    matrice[i][p] = num;
                    p++;
                }
            }
        }
    }
    //controllo mossa valida
    if (!confrontaMatrici(copia, matrice)) {
        aggiungiNumero();
    }
    stampa();
}

void Tabella2048::moveS() {

    //copia la matrice
    int copia[4][4];
    std::memcpy(&copia, &matrice, sizeof(int) * 16);

    for (int i = 0; i < 4; i++) {
        int p = 3;
        bool merged[4] = { false, false, false, false };

        for (int j = 3; j >= 0; j--) {
            if (matrice[j][i] != 0) {
                int num = matrice[j][i];
                matrice[j][i] = 0;

                if (p < 3 && matrice[p + 1][i] == num && !merged[p + 1]) {
                    matrice[p + 1][i] *= 2;
                    punteggio += matrice[p + 1][i];
                    merged[p + 1] = true;
                }
                else {
                    matrice[p][i] = num;
                    p--;
                }
            }
        }
    }
    //controllo mossa valida
    if (!confrontaMatrici(copia, matrice)) {
        aggiungiNumero();
    }
    stampa();
}

void Tabella2048::moveD()
{
    //copia la matrice
    int copia[4][4];
    std::memcpy(&copia, &matrice, sizeof(int)*16);

    for (int i = 0; i < 4; i++) {
        int p = 3;
        bool merged[4] = { false, false, false, false };

        for (int j = 3; j >= 0; j--) {
            if (matrice[i][j] != 0) {
                int num = matrice[i][j];
                matrice[i][j] = 0;

                if (p < 3 && matrice[i][p + 1] == num && !merged[p + 1]) {
                    matrice[i][p + 1] *= 2;
                    punteggio += matrice[i][p + 1];
                    merged[p + 1] = true;
                }
                else {
                    matrice[i][p] = num;
                    p--;
                }
            }
        }
    }
    //controllo mossa valida
    if (!confrontaMatrici(copia, matrice)) { 
        aggiungiNumero(); 
    }
    stampa();
}

void Tabella2048::stampa() const
{
    std::cout << "\n\t\t\t\t\t============== 2048 ==============\n\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "\t\t\t\t\t---------------------------------\n";
        std::cout << "\t\t\t\t\t";
        for (int j = 0; j < 4; j++) {
            std::cout << "|";

            // Calcolo degli spazi per l'allineamento
            int padding = 4 - findlen(matrice[i][j]) + 1;
            for (int k = 0; k < padding; k++) {
                std::cout << " ";
            }

            std::cout << matrice[i][j] << "  ";
        }
        std::cout << "|\n";
    }

    std::cout << "\t\t\t\t\t---------------------------------\n";
    std::cout << "\n\t\t\t\t\tCtrl+Z -> P(non implementato)\n";
    std::cout << "\t\t\t\t\tEsci -> Q\n";
    std::cout << "\t\t\t\t\tInserisci una mossa -> W, A, S, D\n";
    std::cout << "\t\t\t\t\t---------------------------------\n";
    std::cout << "\t\t\t\t\tPunteggio: " << punteggio << "\n";
}

void Tabella2048::avviaGioco()
{
    stampa();
    std::string scelta;
    while (true) {
        std::cout << "\t\t\t\t\t-> ";
        std::cin >> scelta;

        clearScreen();

        switch (tolower(scelta[0])) {
        case 'a': moveA(); break;
        case 'd': moveD(); break;
        case 'w': moveW(); break;
        case 's': moveS(); break;
        case 'q': return; // Esce dal gioco
        default:
            std::cout << "Mossa non valida. Riprova.\n";
        }
    }
}

bool Tabella2048::equals(const int matrice2[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrice[i][j] != matrice2[i][j]) {
                return false; // Le matrici non sono uguali
            }
        }
    }
    return true; // Le matrici sono uguali
}


static int findlen(int num) {
    if (num == 0) return 1; // Gestisce il caso di 0
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}
static void clearScreen() {
#ifdef _WIN32
    system("cls"); // Comando per Windows
#else
    system("clear"); // Comando per Unix/Linux/Mac
#endif
}

bool confrontaMatrici(const int matrice1[4][4], const int matrice2[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrice1[i][j] != matrice2[i][j]) {
                return false; // Una differenza trovata
            }
        }
    }
    return true; // Nessuna differenza trovata
}
