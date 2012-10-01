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

int ListaContabil::adicionar(int dado) {

	if (listaCheia()) {
		return '\0';
	}

	ultimo++;
	lista[ultimo].mudarValor(dado);
	return (ultimo);

}

int ListaContabil::adicionarNoInicio(int dado) {

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
	lista[0].mudarValor(dado);

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
	valor = lista[0].valor;
	pos = 0;

	while (pos <= ultimo) {
		lista[pos] = lista[pos + 1];
		pos++;

	}

	return valor;

}

int ListaContabil::adicionaNaPosicao(int dado, int pos_destino) {

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

	lista[pos_destino].mudarValor(dado);

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
	valor = lista[pos_fonte].valor;
	pos = pos_fonte;

	while (pos <= ultimo) {
		lista[pos] = lista[pos + 1];

		pos++;
	}

	return valor;

}

bool ListaContabil::maior(int dado1, int dado2) {

	if (dado1 > dado2)
		return true;

	return false;

}

bool ListaContabil::menor(int dado1, int dado2) {

	if (dado1 < dado2)
		return true;

	return false;

}
bool ListaContabil::igual(int dado1, int dado2) {

	if (dado1 == dado2)
		return true;

	return false;

}

bool ListaContabil::contem(int dado) {

	for (int i = 0; i < lista[ultimo] + 1; i++) {
		if (dado == lista[i]) {
			return true;
		}
	}

	return false;

}

int ListaContabil::adicionarEmOrdem(int dado) {
	int pos;

	if (listaCheia())
		return '\0';

	pos = 0;
	while (pos <= ultimo && maior(dado, lista[pos].valor)) {
		pos++;
	}

	return adicionaNaPosicao(dado, pos);
}

int ListaContabil::posicao(int dado) {

	int pos = 0;

	while (pos <= ultimo && !(igual(dado, lista[pos].valor))) {
		pos++;
	}
	if (pos > ultimo)
		return '\0';

	return pos;

}

int ListaContabil::retirarEspecifico(int dado) {

	int pos;
	if (listaVazia())
		return '\0';

	pos = posicao(dado);
	if (pos < 0)
		return '\0';

	return retirarDaPosicao(pos);

}
