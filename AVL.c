/* -------------------------------------------------------------------------------*/
/*                               PROJETO 2 IAED                                   */
/*                                   AVL.c                                        */
/*                                 Maio 2015                                      */
/*                                                                                */
/*                  81530 - Renato Paulo Da Costa Cardoso                         */
/*                    81186 - Stephane Oliveira Duarte                            */
/*                  81858 - Joao Ricardo Caseiro Oliveira                         */
/* -------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "adt.h"
#include "main.h"

#define key(a) (a.ref) //chave
#define less(a,b) (a < b) //comparação (menor)
#define eq(a,b) (a == b) //comparação(igual)

/* -------------------------------------------------------------------------------*/
/*      Funcao STinit: inicializa a arvore                                        */
/*      Recebe: -                                                                 */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 STinit()
{	
	link2 link  = NULL; //Comeca uma arvore vazia
	return link;
} 

/* -------------------------------------------------------------------------------*/
/*      Funcao count: conta o numero de elementos da arvore                       */
/*      Recebe: arvore                                                            */
/*      Devolve: inteiro longo com o valor pretendido                             */
/* -------------------------------------------------------------------------------*/
long int count(link2 h)
{
	if(h==NULL)
		return 0;
	else
		return count(h->r) + count(h->l) + 1;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao freeR: apaga arvore                                                */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 freeR(link2 h)
{
	if (h==NULL)
		return h;
	h->l = freeR(h->l);
	h->r = freeR(h->r);
	return delete(h,key(h->item));
}

/* -------------------------------------------------------------------------------*/
/*      Funcao max: maximo elemento da arvore                                     */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore com o elemento maximo                                     */
/* -------------------------------------------------------------------------------*/
link2 max(link2 h) 
{
	if (h==NULL || h->r==NULL) 
		return h;
	else 
		return max(h->r);
} 

/* -------------------------------------------------------------------------------*/
/*      Funcao search: procura atraves da chave o elemento                        */
/*      Recebe: arvore                                                            */
/*      Devolve: elemento pretendido                                              */
/* -------------------------------------------------------------------------------*/
Item2* search(link2 h, Key v) 
{	
	if (h == NULL)
		return NULL;
	if (eq(v, key(h->item))) //se a chave procurada for encontrada
	{
		return (&(h->item)); //retorna o conteudo
	}
	if (less(v, key(h->item))) //se a chave procurada for menor
		return search(h->l, v); //procura a esquerda
	else
		return search(h->r, v); //procura a direita
} 

/* -------------------------------------------------------------------------------*/
/*      Funcao NEW: cria um novo elemento na arvore                               */
/*      Recebe: elemento, left e righ                                             */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 NEW(Item2* item, link2 l, link2 r)
{
	link2 x = (link2) malloc(sizeof(struct STnode));
	x->item = *item;
	x->l = l;
	x->r = r;
	x->height=1;
	return x;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao height: altura da arvore                                           */
/*      Recebe: arvore                                                            */
/*      Devolve: inteiro com o valor pretendido                                   */
/* -------------------------------------------------------------------------------*/
int height(link2 h)
{
	if (h == NULL) return 0;
	return h->height;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao rotL: rotacao a esquerda                                           */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 rotL(link2 h)
{
	int height_left, height_right;
	link2 x = h->r;
	h->r = x->l;
	x->l = h;
	height_left = height(h->l);
	height_right = height(h->r);
	h->height = 
		height_left > height_right ? height_left + 1 :height_right + 1;
	height_left = height(x->l);
	height_right = height(x->r);
	x->height =
		height_left > height_right ? height_left + 1 : height_right+ 1;
	return x;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao rotR: rotacao a direita                                            */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 rotR(link2 h)
{
	int height_left,height_right;
	link2 x = h->l;
	h->l = x->r;
	x->r = h;
	height_left = height(h->l);
	height_right = height(h->r);
	h->height =
		height_left > height_right ? height_left + 1 : height_right + 1;
	height_left = height(x->l);
	height_right = height(x->r);
	x->height =
		height_left > height_right ? height_left + 1 : height_right + 1;
	return x;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao rotLR: rotacao dupla esquerda direita                              */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 rotLR(link2 h)
{
	if (h==NULL) return h;
	h->l = rotL(h->l);
	return rotR(h);
}

/* -------------------------------------------------------------------------------*/
/*      Funcao rotRL: rotacao dupla direita esquerda                              */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 rotRL(link2 h)
{
	if (h==NULL) return h;
	h->r = rotR(h->r);
	return rotL(h);
}

/* -------------------------------------------------------------------------------*/
/*      Funcao Balance: auxiliar da funcao AVLBalance                             */
/*      Recebe: arvore                                                            */
/*      Devolve: inteiro                                                          */
/* -------------------------------------------------------------------------------*/
int Balance(link2 h)
{
	if(h == NULL) return 0;
	return height(h->l) - height(h->r);
}

/* -------------------------------------------------------------------------------*/
/*      Funcao AVLbalance: balanceia a arvore                                     */
/*      Recebe: arvore                                                            */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 AVLbalance(link2 h) {
	int balanceFactor;
	if (h==NULL) return h;

	balanceFactor= Balance(h);
	if(balanceFactor>1) {
		if (Balance(h->l)>0) h=rotR(h);
		else h=rotLR(h);
	}
	else if(balanceFactor<-1){
		if (Balance(h->r)<0) h = rotL(h);
		else h = rotRL(h);
	}
	else{
		int height_left = height(h->l);
		int height_right = height(h->r);
		h->height = 
		height_left > height_right ? height_left + 1 : height_right + 1;
	}
	return h;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao insert: insere um elemento na arvore                               */
/*      Recebe: arvore e o elemento                                               */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 insert(link2 h, Item2* item)
{
	Item2 item1;
	item1 = *item; 
	if (h == NULL) //Se a arvore estiver vazia cria novo
		return NEW(item, NULL, NULL);
	if (less(key(item1), key(h->item))) //se a chave for menor insere a esquerda
		h->l = insert(h->l, item);
	else
		h->r = insert(h->r, item); //insere a direita
	h = AVLbalance(h); //balanceia a arvore
	return h;
}

/* -------------------------------------------------------------------------------*/
/*      Funcao delete: apaga um elemento da arvore                                */
/*      Recebe: arvore e chave do elemento                                        */
/*      Devolve: arvore                                                           */
/* -------------------------------------------------------------------------------*/
link2 delete(link2 h, Key k) 
{
	if (h == NULL){ //Se a arvore for nula nao ha nada a apagar
		return h;
	}
	else if (less(k, key(h->item))) h->l = delete(h->l,k); //Se a chave for menor apaga a esquerda
	else if (less(key(h->item), k)) h->r = delete(h->r,k); //Se nao apaga a direita
	else //Quando forem iguais
		{
		if (h->l !=NULL && h->r !=NULL){ //Se tiver elementos a esquerda e a direita, reorganiza
		link2 aux = max(h->l);
		{Item2 x; x = h->item; h->item = aux->item; aux->item = x;}
		h->l = delete(h->l, key(aux->item));
		}
		else 
			{
			link2 aux = h;
			if (h->l == NULL && h->r == NULL) h=NULL;
			else if (h->l == NULL) h = h->r;
			else h = h->l;
			free(aux);
			}
		}
	h = AVLbalance(h); //Balanceia a arvore
	return h;
}