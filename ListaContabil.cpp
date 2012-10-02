/*
 * ListaContabil.cpp
 *
 *  Created on: Sep 29, 2012
 *      Author: xad
 */

#include "ListaContabil.h"

ListaContabil::ListaContabil() {

	ultimo = -1;
}

ListaContabil::~ListaContabil() {
	ultimo = -1;
}

void ListaContabil::inicializar() {
	ultimo = -1;
}

bool ListaContabil::listaCheia() {
	if (ultimo + 1 == MAXLISTA) {
		return true;
	}
	return false;
}

bool ListaContabil::listaVazia() {
	if (ultimo == -1) {
		return true;
	}
	return false;
}

int ListaContabil::adicionar(const Lancamento &lancamento) {

	if (listaCheia()) {
		return '\0';
	}

	ultimo++;
	lista[ultimo] = lancamento;
	return (ultimo);

}

int ListaContabil::adicionarNoInicio(const Lancamento &lancamento) {

	int pos;
	if (listaCheia()) {
		return '\0';

	}

	ultimo++;
	pos = ultimo;

	while (pos > 0) {
		lista[pos] = lista[pos - 1];
		pos--;
	}

	lista[0] = lancamento;

	return ultimo;

}

int ListaContabil::retirar() {
	if (listaVazia()) {
		return '\0';
	}
	ultimo--;
	return ultimo;

}

int ListaContabil::retirarDoInicio() {

	int pos, valor;

	if (listaVazia()) {
		return '\0';
	}
	ultimo--;
	valor = lista[0].retornarValor();
	pos = 0;

	while (pos <= ultimo) {
		lista[pos] = lista[pos + 1];
		pos++;

	}

	return valor;

}

int ListaContabil::adicionaNaPosicao(const Lancamento &lancamento, int pos_destino) {

	int pos;

	if (listaCheia())
		return '\0';
	else if (pos_destino > ultimo + 1 || pos_destino < 0) {
		return '\0';
	}

	ultimo++;
	pos = ultimo;

	while (pos > pos_destino) {
		lista[pos] = lista[pos - 1];

		pos--;
	}

	lista[pos_destino] = lancamento;

	return pos_destino;

}

int ListaContabil::retirarDaPosicao(int pos_fonte) {

	int valor, pos;
	if (pos_fonte > ultimo || pos_fonte < 0) {
		return '\0';
	} else if (listaVazia()) {
		return '\0';
	}

	ultimo--;
	valor = lista[pos_fonte].retornarValor();
	pos = pos_fonte;

	while (pos <= ultimo) {
		lista[pos] = lista[pos + 1];

		pos++;
	}

	return valor;

}

bool ListaContabil::contem(const Lancamento &lancamento)
{
	for (int i = 0; i <= ultimo; i++)
	{
		if (lancamento == lista[i])
			return true;
	}

	return false;
}

int ListaContabil::adicionarEmOrdem(const Lancamento &lancamento) {
	int pos;

	if (listaCheia())
		return '\0';

	pos = 0;
	while (pos <= ultimo && lancamento.retornarValor() > lista[pos].retornarValor()) {
		pos++;
	}

	return adicionaNaPosicao(lancamento, pos);
}

int ListaContabil::posicao(const Lancamento &lancamento) {

	int pos = 0;

	while (pos <= ultimo && (lancamento !=  lista[pos])) {
		pos++;
	}
	if (pos > ultimo)
		return '\0';

	return pos;

}

int ListaContabil::retirarEspecifico(const Lancamento &lancamento) {

	int pos;
	if (listaVazia())
		return '\0';

	pos = posicao(lancamento);
	if (pos < 0)
		return '\0';

	return retirarDaPosicao(pos);

}

int ListaContabil::retornarUltimo() {
	return ultimo;
}
Lancamento ListaContabil::retornarLancamento(int pos) {
	return lista[pos];
}
