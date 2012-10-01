/*
 * ListaContabil.h
 *
 *  Created on: Sep 29, 2012
 *      Author: xad
 */

#ifndef LISTACONTABIL_H_
#define LISTACONTABIL_H_

#include "Lancamento.h"

const int MAXLISTA = 100;

class ListaContabil {

private:
	Lancamento lista[MAXLISTA];
	int ultimo;
public:

	bool listaCheia ();
	bool listaVazia ();
	bool maior(int dado1, int dado2);
	bool menor(int dado1, int dado2);
	bool igual(int dado1, int dado2);
	bool contem(int dado);


	void inicializarLista();
	void destruirLista();
	int adicionar(int dado);
	int adicionarNoInicio(int dado);
	int adicionaNaPosicao(int dado, int pos_destino);
	int adicionarEmOrdem(int dado);
	int retirar();
	int retirarDoInicio();
	int retirarDaPosicao(int pos);
	int retirarEspecifico(int);
	int posicao(int dado);
};

#endif /* LISTACONTABIL_H_ */
