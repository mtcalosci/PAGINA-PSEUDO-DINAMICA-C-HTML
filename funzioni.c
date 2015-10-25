#include "mialib.h"


void stampaLista(elemento* primo){
    while(primo!=NULL){
        printf("NOME: %s RUOLO: %s\n",primo->nome,primo->ruolo);
        primo = primo->next;
    }
    return;
}

int lunghezzaLista(elemento* primo){ 
    int conta = 0;
    while(primo != NULL){
        conta++; 
        primo = primo->next;   
    }
    return conta;
}

elemento* leggiCreaLista(void){
    elemento* temp = NULL;  //Dichiarazione puntatore temporaneo per inserimento in testa.
    elemento* primo = NULL; //Inizializzo puntatore al primo elemento della lista.
    FILE* pf;
    pf = fopen(FILETXT,"r"); //Verifico che il puntatore a file sia diverso da NULL
    if(pf == NULL){
        fprintf(stderr,"Impossibile aprire il file.");
    }
    else{
        // Leggo dal file e memorizzo nel 1°elemento della lista.
        primo = (elemento*)malloc(sizeof(elemento));
        fscanf(pf,"%[^;];%[^\n]\n",primo->nome,primo->ruolo);
        // Inizializzo il puntatore dell'ultimo elemento a NULL.
        primo->next = NULL; 
        // Ciclo per la lettura e scrittura lista.
        while(!feof(pf)){ 
            temp = (elemento*)malloc(sizeof(elemento));
            fscanf(pf,"%[^;];%[^\n]\n",temp->nome,temp->ruolo);
            temp->next = primo;
            primo = temp;
        }
    }
    fclose(pf);
    return primo;   
}

void ordinaRuoliLista(elemento* primo,int contaElementi){
    int i = 0;
    record recordScambio;
    elemento* corrente = NULL;
    elemento* prossimo = NULL;
    while(contaElementi-1){
        corrente = primo;
        prossimo = corrente -> next;
        while(prossimo != NULL){
            if(strcmp(corrente->ruolo,prossimo->ruolo) >= 0){
                //Copio l'elemento da scambiare in un record temporaneo.
                strcpy(recordScambio.nome,prossimo->nome);
                strcpy(recordScambio.ruolo,prossimo->ruolo);
                //Copio gli elementi del blocco precedente in quello successivo.
                strcpy(prossimo->nome,corrente->nome);
                strcpy(prossimo->ruolo,corrente->ruolo);
                //Copio nel blocco precedente il contenuto del record temporaneo.
                strcpy(corrente->nome,recordScambio.nome);
                strcpy(corrente->ruolo,recordScambio.ruolo);
                }
            corrente = prossimo;
            prossimo = prossimo->next;
            }
        contaElementi --;
        }
    return;
}

FILE* popolaSelect(elemento* primo){
    char idDiv[MAX_STRLEN + 1];
    char opzione[MAX_STRLEN + 1];
    elemento* scorri = NULL;
    FILE* pf;
    pf = fopen("index.html","w");
    if(pf != NULL){
        //Intestazione HTML.
        fprintf(pf,"<html>\n\t\t<head>\n\t\t\t<script type=\"text/javascript\" src=\"script.js\">\n\t\t\t</script>\n\t\t</head>\n\t\t<select id=\"lista\" onchange=\"miafunzione()\">\n");
        scorri = primo;
        //Popolamento select con i ruoli.
        while(scorri->next != NULL){
            strcpy(opzione,scorri->ruolo);
            while(!strcmp(scorri->ruolo,opzione)){
                scorri = scorri->next;
            }
            fprintf(pf,"\t\t\t<option> %s </option>\n",opzione);
            strcpy(opzione,scorri->ruolo);
        }
        fprintf(pf,"\t\t\t<option> %s </option>\n",opzione); 
        fprintf(pf,"\t\t</select>\n\n");

    }
    return pf;
}

void memorizzaNomi(FILE* pf,elemento* primo){ 
    elemento* scorri;
    char idDiv [MAX_STRLEN + 1];
    fprintf(pf,"\t\t<div id=\"out\"></div>\n"); 
    scorri = primo;
        //Scorro la lista e memorizzo i nomi nel file HTML (nascosti).
        while(scorri -> next!= NULL){
            strcpy(idDiv,scorri->ruolo);
            fprintf(pf,"\t\t<div id=\"%s\"style=\"display:none\">\n",idDiv);
            //Fin quando il ruolo non cambia scrivi i nomi nel file HTML con id ruolo.
            while(!(strcmp(scorri->ruolo,idDiv))){
                fprintf(pf,"\t\t\tNome = %s<br>\n",scorri->nome);
                scorri = scorri->next;
            }
            fprintf(pf,"\t\t</div>\n");
            
        }
        strcpy(idDiv,scorri->ruolo);
        fprintf(pf,"\t\t<div id=\"%s\"style=\"display:none\">\n",idDiv);
        fprintf(pf,"\t\t\tNome = %s<br>\n",scorri->nome);
        fprintf(pf,"\t\t</div>\n");
        fprintf(pf,"\n\t</body>\n</html>");
        fclose(pf);
        return;
    }

 void svuotaLista(elemento* primo){
        elemento* temp = NULL;
        while(primo != NULL){
            temp = primo->next;
            free(primo);
            primo = temp;
        }
    }
    