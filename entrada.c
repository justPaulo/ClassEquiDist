#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "saida.h"

void Entrada(void);

int numAlunos=0;
char linha[kMaxColunasPorLinhas];
char *buffer[kMaxAlunos];
FILE *fp=NULL;

int main(int argc, const char * argv[])
{
    Entrada();
    Saida(buffer, numAlunos);
 
    return EXIT_SUCCESS;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Entrada()
{
    int i=0;
    
    if ( (fp=fopen(ficheiroAlunos,"r")) == NULL )
    {
        printf("\nFile not found\n");
        exit (EXIT_FAILURE);
    }
    
    for (i=0;i<kMaxAlunos;i++)
        buffer[i]= (char *) malloc(kMaxColunasPorLinhas * sizeof (char) );

    // se chega até aqui, tudo bem então...
    
    i=0; // reset ao contador
    
    while ( fgets(linha, sizeof linha, fp) != NULL )
        strncpy(buffer[i++], linha, sizeof linha);
    
    fclose(fp);

    numAlunos=i;
}

