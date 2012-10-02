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
	ListaContabil();
	~ListaContabil();

	bool listaCheia ();
	bool listaVazia ();
	bool contem(const Lancamento &dado);


	void inicializar();
	void destruir();
	int adicionar(const Lancamento &dado);
	int adicionarNoInicio(const Lancamento &dado);
	int adicionaNaPosicao(const Lancamento &dado, int pos_destino);
	int adicionarEmOrdem(const Lancamento &dado);
	int retirar();
	int retirarDoInicio();
	int retirarDaPosicao(int pos);
	int retirarEspecifico(const Lancamento &lancamento);
	int posicao(const Lancamento &dado);
	int retornarUltimo();
	Lancamento retornarLancamento(int pos);
};

#endif /* LISTACONTABIL_H_ */
