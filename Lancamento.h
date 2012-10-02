/*
 * Lancamento.h
 *
 *  Created on: Sep 29, 2012
 *      Author: xad
 */

#ifndef LANCAMENTO_H_
#define LANCAMENTO_H_

#include <string>

class Lancamento {

private:
	std::string nome;
	int valor;

public:
	Lancamento();
	~Lancamento();

	void mudarValor(int valor);
	int retornarValor() const;
	std::string retornarNome() const;
	void mudarNome(const char *nome);
};

inline bool operator==(const Lancamento &lhs, const Lancamento &rhs)
{
	return lhs.retornarNome() == rhs.retornarNome() && lhs.retornarValor() == rhs.retornarValor();
}

inline bool operator!=(const Lancamento &lhs, const Lancamento &rhs)
{
	return !operator==(lhs, rhs);
}

#endif /* LANCAMENTO_H_ */
