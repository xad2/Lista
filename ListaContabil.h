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
	bool igual(Lancamento dado1, Lancamento dado2);
	bool contem(Lancamento dado);


	void inicializar();
	void destruir();
	int adicionar(Lancamento dado);
	int adicionarNoInicio(Lancamento dado);
	int adicionaNaPosicao(Lancamento dado, int pos_destino);
	int adicionarEmOrdem(Lancamento dado);
	int retirar();
	int retirarDoInicio();
	int retirarDaPosicao(int pos);
	int retirarEspecifico(Lancamento lancamento);
	int posicao(Lancamento dado);
	int retornarUltimo();
	Lancamento retornarLancamento(int pos);
};

#endif /* LISTACONTABIL_H_ */
