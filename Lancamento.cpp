/*
 * Lancamento.cpp
 *
 *  Created on: Sep 29, 2012
 *      Author: xad
 */

#include "Lancamento.h"

Lancamento :: Lancamento(){

}

Lancamento :: ~Lancamento(){

}

void Lancamento::mudarValor(int nvalor){
	valor = nvalor;
}

void Lancamento::mudarNome(char *_nome){

	nome = _nome;
}

char Lancamento::retornarNome(){

	return *nome;
}

int Lancamento:: retornarValor(){
	return valor;
}
