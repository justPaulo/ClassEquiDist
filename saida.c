#include <math.h>
#include "saida.h"

void Saida(char *buffer[kMaxAlunos], int numAlunos)
{
    int i=0;
    int excesso, numTurmas, novoN=0;
    int nTurma=1;

    numTurmas=ceil( (float) numAlunos / KMaxAlunosPorTurma); // tem de se forçar cast para ceil não realizar ceil de int... ceil(int)=int...
    excesso= numAlunos % KMaxAlunosPorTurma;
    novoN = KMaxAlunosPorTurma-(KMaxAlunosPorTurma-excesso)/numTurmas;

    for (i=0;i<numAlunos;i++)
    {
        if ( i % novoN ==0 )
            printf("\nTURMA %d:\n",nTurma++);
        
        printf("%s", buffer[i]);
    }

    printf("\n\nNumero de alunos: %d\n",numAlunos);
    printf("Número de turmas necessárias: %d\n", numTurmas);
    printf("Última turma ficaria com: %d alunos\n", excesso);
    printf("Novo número ideal de alunos por turma: %d\n", novoN );
}
