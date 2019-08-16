/* -------------------------------------------------------------------------------*/
/*                               PROJETO 2 IAED                                   */
/*                                   ADT.h                                        */
/*                                 Maio 2015                                      */
/*                                                                                */
/*                  81530 - Renato Paulo Da Costa Cardoso                         */
/*                    81186 - Stephane Oliveira Duarte                            */
/*                  81858 - Joao Ricardo Caseiro Oliveira                         */
/* -------------------------------------------------------------------------------*/


#ifndef ADT_H
#define ADT_H

/*--------------------------------------------------------------------------------*/
/*-----------------------------------avl.h----------------------------------------*/
/*--------------------------------------------------------------------------------*/


link2 STinit();
link2 max(link2 h);
long int count(link2 h);
link2 freeR(link2 h);

Item2* search(link2 h, Key v);
int height(link2 h);
link2 rotL(link2 h);
link2 rotR(link2 h);
link2 rotLR(link2 h);
link2 rotRL(link2 h);
int Balance(link2 h);
link2 AVLbalance(link2 h);
link2 insert(link2 h, Item2* item);
link2 delete(link2 h, Key k);

/*--------------------------------------------------------------------------------*/
/*------------------------------fila.h--------------------------------------------*/
/*--------------------------------------------------------------------------------*/

FILA* FILAinit();
long int FILAtamanho(FILA* F);
int FILAvazia(FILA* F);
link1 NEWFnode(Item1 item, link1 next);
FILA* FILAput(FILA* F, Item1 item);
FILA* FILAget(FILA* F);
Item1 PrimElem(FILA* F);
Item1* FILAprocura(FILA* F, Key k);
Item1 FILAremove(FILA* F, Key k);
void FILAapaga(FILA* F);


/*--------------------------------------------------------------------------------*/
/*-------------------------------item.h-------------------------------------------*/
/*--------------------------------------------------------------------------------*/

Item2 newItem(long int ref, int nche, int vche, int nchb, int vchb);
void deleteItem(Item2* a);
void visita(Item2 a); 

#endif