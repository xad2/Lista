/*
 * Lancamento.h
 *
 *  Created on: Sep 29, 2012
 *      Author: xad
 */

#ifndef LANCAMENTO_H_
#define LANCAMENTO_H_

class Lancamento {

private:
	char *nome;
	int valor;

public:

	void mudarValor(int valor);
	int retornarValor();
	char retornarNome();
	void mudarNome(char *nome);
};

#endif /* LANCAMENTO_H_ */
