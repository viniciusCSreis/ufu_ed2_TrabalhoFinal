#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list-definitions.h"
#include "list.h"

#define maxString 255

void alertFalhaMemoria();

int main()
{


    setlocale(LC_ALL,"portuguese");

    FILE *f;            //ponteiro para o arquivo que armazena o grafo
    char * fname;       //nome do arquivo que armazena o grafo
    List * l = NULL:    //lista que armazena o grafo

    //aloca memoria para o fname
    fname=(char * )malloc(sizeof(char)* maxString);
    if(fname==NULL)
    {
        alertFalhaMemoria();
        return 0;

    }
    //abre o arquivo
    do
    {
        printf("Digite o nome do arquivo:");
        scanf("%s",fname);
        f=fopen(fname,"r");
        if(f==NULL)
            fprintf(stderr,"Arquivo não encontrado\n");
    }while(f==NULL);

    //le o arquivo e armazena na lista
    l=readFile(f);

    return 0;
}

List * readFile(File * f)
{
    int i=0;
    int j=0;
    int a,b;
    List * l = listCreate();

    if(l==NULL)
        return NULL;

    while(1)
    {
        fscanf("%c",&a)!=EOF);
        if()

    }
    ftell(f);
    fseek(f,)



}

void alertFalhaMemoria()
{
    fprintf(stderr,"Falha ao alocar memoria\n");
}
