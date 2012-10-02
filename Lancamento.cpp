/*
 * Lancamento.cpp
 *
 *  Created on: Sep 29, 2012
 *      Author: xad
 */

#include "Lancamento.h"

Lancamento :: Lancamento()
	: valor(0)
{

}

Lancamento :: ~Lancamento(){

}

void Lancamento::mudarValor(int nvalor){
	valor = nvalor;
}

void Lancamento::mudarNome(const char *_nome)
{

	nome = _nome;
}

std::string Lancamento::retornarNome() const
{
	return nome;
}

int Lancamento::retornarValor() const
{
	return valor;
}
