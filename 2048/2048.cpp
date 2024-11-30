#include <iostream>

void printTable(const int table[4][4]);
int findlen(int n);
void menu();

bool aggiornaMatrice(int table[4][4]);

int main() {

    menu();

    int table[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            table[i][j] = 0;
        }
    }

    aggiornaMatrice(table);

    printTable(table);
}

void menu() {
    std::cout << "\n\t\t\t\t\t===============2048==============\n\n";
    printf("\t\t\t\t\tWELCOME TO PUZZLE 2048\n");
    printf("\t\t\t\t\t> CONTROLS\n");
    printf("\t\t\t\t\t  FOR MOVES:- 'W','S','A','D'\n");
    printf("\t\t\t\t\t  GO BACKWARD:- 'P'\n");
    printf("\t\t\t\t\t  RESTAT THE GAME:- 'R'\n");
    printf("\t\t\t\t\t  EXIT:-'U'\n");

    printf("\t\t\t\t\tPRESS ANY KEY TO START THE GAME....");
    getchar();
    system("clear || cls");
}

static void printTable(const int table[4][4]) {
    
    std::cout << "\n\t\t\t\t\t===============2048==============\n\n";
    for (int i = 0; i < 4; i++) {
        printf("\t\t\t\t\t---------------------------------\n");
        printf("\t\t\t\t\t");
        for (int j = 0; j < 4; j++) {
            
            printf("|");
            
            for (int k = 0; k < 4 - findlen(table[i][j]) ; k++) { printf(" "); }

            printf("%d",table[i][j]);

            printf("  ");
        }
        printf("|");
        std::cout << std::endl;
    }
    printf("\t\t\t\t\t---------------------------------\n");
    printf("\t\t\t\t\tPREV-> P\t\t\t\t\t\n");
    printf("\t\t\t\t\tRESTART-> R\t\t\t\t\t\n");
    printf("\t\t\t\t\tEXIT-> U\t\t\t\t\t\n");
    printf("\t\t\t\t\tENTER YOUR CHOISE -> "
        "W,S,A,D\n\t\t\t\t\t");

}//fine printTable

// Function to find the length of a number (count of digits)
int findlen(int n){
    int len = 0;

    while (n >= 10) {
        len++;
        n /= 10;
    }
    return len;
    
}

bool aggiornaMatrice(int matrice[4][4]) {
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