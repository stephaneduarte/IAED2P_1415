/* -------------------------------------------------------------------------------*/
/*                               PROJETO 2 IAED                                   */
/*                                ESTRUTURAS.h                                    */
/*                                 Maio 2015                                      */
/*                                                                                */
/*                  81530 - Renato Paulo Da Costa Cardoso                         */
/*                    81186 - Stephane Oliveira Duarte                            */
/*                  81858 - Joao Ricardo Caseiro Oliveira                         */
/* -------------------------------------------------------------------------------*/

#ifndef ESTRUTURAS
#define ESTRUTURAS

/*--------------------------------------------------------------------------------*/
/*-----------------------------Estruturas cliente---------------------------------*/
/*--------------------------------------------------------------------------------*/

typedef struct cliente{
	long int ref; //referencia do cliente
	int nche; //numero de cheques emitidos
	int vche; //valor de cheques emitidos
	int nchb; //numero de cheques beneficiario
	int vchb; //valor de cheques beneficiario
}Cliente;

typedef Cliente Item2; /* De modo a manter a abstracao da arvore binaria*/


/*--------------------------------------------------------------------------------*/
/*-----------------------------Estrutura Cheque-----------------------------------*/
/*--------------------------------------------------------------------------------*/

typedef struct cheque{
	int valor; //valor do cheque
	long int refe; //referencia do cliente emissor
	long int refb; //referencia do cliente beneficiario
	long int ref; //referencia do cheque
}Cheque;

typedef Cheque Item1; /* De modo a manter a abstracao da fila */


/*--------------------------------------------------------------------------------*/
/*------------------------Estruturas da FILA--------------------------------------*/
/*--------------------------------------------------------------------------------*/

typedef struct Fnode *link1;

struct Fnode{
	Item1 item; //conteudo
	link1 next; //ponteiro para o proximo
};

typedef struct
{
	link1 head; //primeiro elemento
	link1 tail; //cauda
	long int tamanho;
	int valortotal; //valor total de cheques emitidos
}FILA;

/*--------------------------------------------------------------------------------*/
/*-----------------------Estruturas da arvore binaria-----------------------------*/
/*--------------------------------------------------------------------------------*/

typedef long int Key;

typedef	struct STnode* link2;

struct STnode
{
	Item2 item; //conteudo
	link2 l, r; //ponteiro para a esquerda e a direita
	int height; //tamanho
}; 

#endif