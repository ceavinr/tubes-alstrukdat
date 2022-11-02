#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
  
void main()  
{  
    FILE *f;
    f = fopen("trial.txt", "r");
    
    int i,random;
    char str1[3];
    char str2[3];  
    
    fgets(str1, 3, f);

    i = atoi(str1);

    srand(i);
    random = rand() % 101;

    sprintf(str2, "%d", random + 2);
    fclose(f);   

    FILE *fw;
    fw = fopen("trial.txt", "w+");
    
    fprintf(fw, "%s", str2);
    fclose(fw);

    printf("Random Numbers are: %d\n", random);   

}  