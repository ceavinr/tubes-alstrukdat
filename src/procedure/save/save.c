#include <stdio.h>
#include "save.h"

void save(char* savefile, ArrayDin arrGame, ArrayDin arrHistory){
    FILE*pita;
    pita=fopen(savefile,"w");
    fprintf(pita,"%c\n",(char)(arrGame.Neff+48));
    for (int i=0;i<arrGame.Neff;i++){
        fprintf(pita,"%s\n",arrGame.A[i].TabWord);
    }
    fprintf(pita,"%c\n",(char)(arrHistory.Neff+48));
    for (int j=0;j<arrHistory.Neff-1;j++){
        fprintf(pita,"%s\n",arrHistory.A[j].TabWord);
    }
    fprintf(pita,"%s",arrHistory.A[arrHistory.Neff-1].TabWord);
    fclose(pita);
}

