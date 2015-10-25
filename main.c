#include "mialib.h"


int main(int argc, char** argv) {
    int contaElementi = 0; // Conta quanti sono gli elementi della lista.
    FILE* pf;               //Dichiarazione del puntatore a file. 
    elemento* primo = NULL;     // Puntatore da cui ha inizio la lista.
   

    primo = leggiCreaLista(); // Leggo dal file e memorizzo i record in una lista concatenata.
    contaElementi = lunghezzaLista(primo); // Conto gli elementi della lista per gestire meglio l'ordinamento.
    ordinaRuoliLista(primo,contaElementi); // Ordino la lista in base ai ruoli.
    pf = popolaSelect(primo); //Popolo una select con i ruoli.
    memorizzaNomi(pf,primo); // Memorizzo i nomi nel file HTML.
    stampaLista(primo); // Stampo la lista per vedere se tutto è andato a buon fine.
    svuotaLista(primo);
   
    return (EXIT_SUCCESS);
}
