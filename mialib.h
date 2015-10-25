#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILETXT "nomi&ruoli.txt"
#define MAX_STRLEN 30

//Singolo blocco della lista.
struct s_elemento{
    struct s_elemento* next;
    char nome[MAX_STRLEN + 1];
    char ruolo[MAX_STRLEN + 1];
};

//Record per scambiare blocchi nel BubbleSort.
struct s_record{
    char nome[MAX_STRLEN + 1];
    char ruolo[MAX_STRLEN + 1 ];
};

typedef struct s_elemento elemento;
typedef struct s_record record;

// Funzione per controllare la correttezza dell'ordinamento.
void stampaLista(elemento* primo);
//Calcolo lunghezza lista, utile per effettuare l'ordinamento.
int lunghezzaLista(elemento* primo);
//Lettura da file.txt e scrittura su lista.
elemento* leggiCreaLista(void); 
//Ordinamento della lista per ruoli.
void ordinaRuoliLista(elemento* primo,int contaElementi);
//Creazione paginaHTML + script e popolamento select.
FILE* popolaSelect(elemento* primo);
//Memorizzazione nomi su pagina HTML.
void memorizzaNomi(FILE* pf,elemento* primo);
//Deallocazione lista dalla memoria HEAP.
void svuotaLista(elemento* primo);
