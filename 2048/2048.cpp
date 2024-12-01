#include <iostream>
#include <cstdlib>

void printTable(const int table[4][4]);
int findlen(int n);
void menu();
void clearScreen();
bool nextTurn(int table[4][4]);
char processInput();
void moveW(int table[4][4]);
void moveA(int table[4][4]);
void moveS(int table[4][4]);
void moveD(int table[4][4]);

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Comando per Windows
#else
    system("clear"); // Comando per Unix/Linux/Mac
#endif
}

int main() {

    menu();

    int table[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            table[i][j] = 0;
        }
    }
    
    nextTurn(table);

    while (true) {
        nextTurn(table);
        clearScreen();
        printTable(table);
        char letter = processInput();//DA FARE: bisogna anche verificare la validità della mossa

        switch (letter) {
        case 'A':
        case 'a':
            moveA(table);
            break;
        case 'W':
        case 'w':
            moveW(table);
            break;
        case 'S':
        case 's':
            moveS(table);
            break;
        case 'D':
        case 'd':
            moveD(table);
        }
            
    }
    
    

    
}

void menu() {
    std::cout << "\n\t\t\t\t\t=============== 2048 ===============\n\n";
    std::cout << "\t\t\t\t\tWELCOME TO PUZZLE 2048\n";
    std::cout << "\t\t\t\t\t> CONTROLS\n";
    std::cout << "\t\t\t\t\t  FOR MOVES: 'W', 'S', 'A', 'D'\n";
    std::cout << "\t\t\t\t\t  GO BACKWARD: 'P'\n";
    std::cout << "\t\t\t\t\t  RESTART THE GAME: 'R'\n";
    std::cout << "\t\t\t\t\t  EXIT: 'U'\n";
    std::cout << "\n\t\t\t\t\tPRESS ANY KEY TO START THE GAME....\n";
    processInput();
    clearScreen();
}

// Funzione di utilità per calcolare la lunghezza di un numero
int findlen(int num) {
    if (num == 0) return 1; // Gestisce il caso di 0
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

void printTable(const int table[4][4]) {
    std::cout << "\n\t\t\t\t\t=============== 2048 ===============\n\n";

    for (int i = 0; i < 4; i++) {
        std::cout << "\t\t\t\t\t---------------------------------\n";
        std::cout << "\t\t\t\t\t";
        for (int j = 0; j < 4; j++) {
            std::cout << "|";

            // Calcolo degli spazi per l'allineamento
            int padding = 4 - findlen(table[i][j]) + 1;
            for (int k = 0; k < padding; k++) {
                std::cout << " ";
            }

            std::cout << table[i][j] << "  ";
        }
        std::cout << "|\n";
    }

    std::cout << "\t\t\t\t\t---------------------------------\n";
    std::cout << "\n\t\t\t\t\tPREV -> P(non implementato)\n";
    std::cout << "\t\t\t\t\tRESTART -> R\n";
    std::cout << "\t\t\t\t\tEXIT -> U\n";
    std::cout << "\n\t\t\t\t\tENTER YOUR CHOICE -> W, S, A, D\n";
}


bool nextTurn(int matrice[4][4]) {
    // Trova le posizioni degli zeri nella matrice
    int posizioniZero[16][2]; // Al massimo ci sono 16 posizioni per una matrice 4x4
    int conteggioZero = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrice[i][j] == 0) {
                posizioniZero[conteggioZero][0] = i;
                posizioniZero[conteggioZero][1] = j;
                ++conteggioZero;
            }
        }
    }

    // Se non ci sono zeri, ritorna falso
    if (conteggioZero == 0) {
        return false;
    }

    // Scegli una posizione casuale tra quelle degli zeri
    std::srand(std::time(nullptr)); // Inizializza il generatore di numeri casuali
    int indiceCasuale = std::rand() % conteggioZero;

    int i = posizioniZero[indiceCasuale][0];
    int j = posizioniZero[indiceCasuale][1];

    // Imposta la posizione scelta a 2
    matrice[i][j] = 2;

    return true;
}

char processInput() {
    std::string input;
    std::cout << "\t\t\t\t\t";
    std::cin >> input;

    // Verifica che l'input non sia vuoto
    if (input.empty()) {
        std::cout << "Input non valido: stringa vuota.\n";
        return 'n';
    }

    // Prendi il primo carattere della stringa
    return input[0];
}

void moveA(int matrice[4][4]) {
    for (int i = 0; i < 4; i++) { // Itera per ogni riga
        int p = 0;  // Posizione in cui mettere il prossimo numero non nullo
        bool merged[4] = { false, false, false, false }; // Array per tenere traccia delle fusioni

        for (int j = 0; j < 4; j++) { // Scorre le colonne della riga
            if (matrice[i][j] != 0) { // Se il valore non è zero
                int num = matrice[i][j];
                matrice[i][j] = 0; // Pulisce la cella originale

                if (p > 0 && matrice[i][p - 1] == num && !merged[p - 1]) { // Verifica se si possono fondere
                    matrice[i][p - 1] *= 2; // Fonde i numeri
                    merged[p - 1] = true; // Segna la cella come fusa
                }
                else {
                    matrice[i][p] = num; // Altrimenti sposta il numero nella posizione libera
                    p++;
                }
            }
        }
    }
}


void moveD(int matrice[4][4]) {
    for (int i = 0; i < 4; i++) { // Itera per ogni riga
        int p = 3;  // Posizione in cui mettere il prossimo numero non nullo (partendo dalla fine della riga)
        bool merged[4] = { false, false, false, false }; // Array per tenere traccia delle fusioni

        for (int j = 3; j >= 0; j--) { // Scorre le colonne della riga da destra a sinistra
            if (matrice[i][j] != 0) { // Se il valore non è zero
                int num = matrice[i][j];
                matrice[i][j] = 0; // Pulisce la cella originale

                if (p < 3 && matrice[i][p + 1] == num && !merged[p + 1]) { // Verifica se si possono fondere
                    matrice[i][p + 1] *= 2; // Fonde i numeri
                    merged[p + 1] = true; // Segna la cella come fusa
                }
                else {
                    matrice[i][p] = num; // Altrimenti sposta il numero nella posizione libera
                    p--;
                }
            }
        }
    }
}


//chatgpt
void moveW(int matrice[4][4]) {
    for (int i = 0; i < 4; i++) { // Itera per ogni colonna
        int p = 0;  // Posizione in cui mettere il prossimo numero non nullo
        bool merged[4] = { false, false, false, false }; // Array per tenere traccia delle fusioni

        for (int j = 0; j < 4; j++) { // Scorre le righe
            if (matrice[j][i] != 0) { // Se il valore non è zero
                int num = matrice[j][i];
                matrice[j][i] = 0; // Pulisce la cella originale

                if (p > 0 && matrice[p - 1][i] == num && !merged[p - 1]) { // Verifica se si possono fondere
                    matrice[p - 1][i] *= 2; // Fonde i numeri
                    merged[p - 1] = true; // Segna la cella come fusa
                }
                else {
                    matrice[p][i] = num; // Altrimenti sposta il numero nella posizione libera
                    p++;
                }
            }
        }
    }
}


void moveS(int matrice[4][4]) {
    for (int i = 0; i < 4; i++) { // Itera per ogni colonna
        int p = 3;  // Posizione in cui mettere il prossimo numero non nullo (partendo dal basso)
        bool merged[4] = { false, false, false, false }; // Array per tenere traccia delle fusioni

        for (int j = 3; j >= 0; j--) { // Scorre le righe dalla parte inferiore verso l'alto
            if (matrice[j][i] != 0) { // Se il valore non è zero
                int num = matrice[j][i];
                matrice[j][i] = 0; // Pulisce la cella originale

                if (p < 3 && matrice[p + 1][i] == num && !merged[p + 1]) { // Verifica se si possono fondere
                    matrice[p + 1][i] *= 2; // Fonde i numeri
                    merged[p + 1] = true; // Segna la cella come fusa
                }
                else {
                    matrice[p][i] = num; // Altrimenti sposta il numero nella posizione libera
                    p--;
                }
            }
        }
    }
}
