/* -------------------------------------------------------------------------------*/
/*                               PROJETO 2 IAED                                   */
/*                                   ITEM.c                                       */
/*                                 Maio 2015                                      */
/*                                                                                */
/*                  81530 - Renato Paulo Da Costa Cardoso                         */
/*                    81186 - Stephane Oliveira Duarte                            */
/*                  81858 - Joao Ricardo Caseiro Oliveira                         */
/* -------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "adt.h"
#include "main.h"

/* -------------------------------------------------------------------------------*/
/*      Funcao newItem: cria novo elemento                                        */
/*      Recebe: dados para o elemento                                             */
/*      Devolve: elemento                                                         */
/* -------------------------------------------------------------------------------*/
Item2 newItem(long int ref, int nche, int vche, int nchb, int vchb)
{	
	Item2 item;
	Item2* x = (Item2*) malloc(sizeof(struct cliente));
	x-> ref = ref;
	x-> nche = nche;
	x-> vche = vche;
	x-> nchb = nchb;
	x-> vchb = vchb;
	item = *x;
	return item;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao deleteItem: apaga elemento                                         */
/*      Recebe: apontador para o elemento                                         */
/*      Devolve: -                                                                */
/* -------------------------------------------------------------------------------*/
void deleteItem(Item2* a)
{
	free(a);
}

/* -------------------------------------------------------------------------------*/
/*      Funcao visita: imprime dados do elemento                                  */
/*      Recebe: elemento                                                          */
/*      Devolve: -                                                                */
/* -------------------------------------------------------------------------------*/
void visita(Item2 a)
{
	long int ref = a.ref;
	long int nche = a.nche;
	long int vche = a.vche;
	long int nchb = a.nchb;
	long int vchb = a.vchb;
	printf("*%ld %ld %ld %ld %ld\n", ref, nche, vche, nchb, vchb);
}