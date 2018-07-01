#include <stdio.h>
#include <stdlib.h>

#include "list-definitions.h"
#include "list.h"


List *
listCreate()
{
    List *l=(List *)malloc(sizeof(List));
    if(l==NULL)
        return NULL;
    l->p=NULL;
    l->n=0;
    return l;
}

void
listDestroy(List *l)
{
    Node *aux;
    while(l->p!=NULL)
    {
        free(((Node *)l->p)->i);
        aux=((Node *)l->p)->next;
        free(l->p);
        l->p=aux;

    }
    free(l);
}

List *
listIns(void *i,int p,List *l)
{
    int j=0;

    Node *x=(Node *)malloc(sizeof(Node));
    Node *m=NULL;

    if(x==NULL)

        return NULL;

    x->i=i;
    if(p==1)
    {

        x->next=l->p;
        l->p=x;
    }
    else
    {
        if(p>l->n)
            p=l->n;

        for(m=l->p,j=1;j<p-1;m=m->next,j++);
        x->next=m->next;
        m->next=x;
    }
    l->n++;
    return l;

}
void
listDel (void *i, List *l)
{
    Node * atual=NULL;
    Node * past=NULL;
    for(atual=l->p;atual!=NULL&&atual->i!=i;atual=atual->next)
        past=atual;
    if(past==NULL)
        l->p=atual->next;
    else
        past->next=atual->next;
    free(atual->i);
    free(atual);

}


void *
listGetI(List *l,int p)
{
    int j;
    Node *m=NULL;

    if(p>l->n)
        return NULL;

    for(m=l->p,j=1;j<p;m=m->next,j++);

    return m->i;
}
//   listSearch
// ----------
// Search for an item in l whose key matches to the one in k.
//
// Return a pointer to the item that matches k,
// or return NULL, if there was no match.
//
// cmp is a pointer to a comparison function provided by
// the application. This function returns 0, if x == y,
// or return a number != 0, otherwise.
void *
listSearch (void *k, List *l, int (*cmp) (const void *x, const void *y))
{
    Node *aux=NULL;

    for(aux=(Node * )l->p;aux!=NULL;aux=aux->next)
    {
        if(cmp(aux->i,k)==0)
            return aux->i;
    }

    return NULL;

}


// listSort
// --------
// Sort the content of l.
//
// Return a pointer to an ordered list whose items are the
// ones in l; or return NULL, if the new list could not be created.
//
// cmp is a pointer to a comparison function provided by
// the application. This function compares whether x is less than,
// equal to, or greater than y. It returns, respectively,
// a number less than, equal to, or greater than zero.
List * listSort (List *l, int (*cmp) (const void *x, const void *y))
{
    int i,j;
    List *ol=NULL;
    Node *aux=NULL;
    void **vetor=NULL;
    int menor=0;
    void *auxTroca=NULL;
    //aloca vetor
    vetor=(void **)malloc(sizeof(void *) * l->n);
    if(vetor==NULL)
        return NULL;

    //copia l para o vetor
    for(aux=(Node *)l->p,i=0;aux!=NULL;aux=aux->next,i++)
        vetor[i]=aux->i;

    //ordena utilizando selection sort
    for(i=0;i<l->n;i++)
    {
        menor=i;
        for(j=i+1;j<l->n;j++)
        {
            if(cmp(vetor[menor],vetor[j])<0)
                menor=j;
        }
        if(i!=menor)
        {
            auxTroca=vetor[i];
            vetor[i]=vetor[menor];
            vetor[menor]=aux;
        }
    }

    //aloca ol
    ol=listCreate();
    if(ol==NULL)
        return NULL;
    //insere em ol o vetor já ordenado
    for(i=l->n-1;i>=0;i--)
        if(!listIns(vetor[i],1,ol))
            break;

    if(i>=0)
        return NULL;

    return ol;



}
