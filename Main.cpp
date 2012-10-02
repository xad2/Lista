/*
 * Main.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: xad
 */

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "ListaContabil.h"

static const char SELCREDIT_STR[] = "(CREDITOS) Seleciona Lista de Créditos";
static const char SELDEB_STR[] = "(DEBITOS) Seleciona Lista de Débitos";
static const char LANCAR_STR[] = "(INSERIR ) Lançar Transação";
static const char LISTAR_STR[] = "(t) Listar Transações";
static const char REMOVER_STR[] = "(r) Remover Transações";
static const char SALDO_STR[] = "(s) Mostrar Saldo";
static const char SAIR_STR[] = "(x) Sair";

static void comandoRemoverDaPosicao(std::istream &stream, std::istream &file,
		ListaContabil &listaContabil) {

	int pos;
	stream >> pos;

	listaContabil.retirarDaPosicao(pos);

}
static void comandoRemoverMembro(std::istream &stream, std::istream &file,
		ListaContabil &listaContabil) {

	int qtd;
	stream >> qtd;

	std::string line;

	Lancamento lancamento;

	for (int i = 0; i < qtd; i++) {
		std::getline(file, line);
		std::stringstream stream(line);
		std::string element;
		stream >> element;
		char *nome = new char[element.size() + 1];
		nome[element.size()] = 0;
		memcpy(nome, element.c_str(), element.size());
		lancamento.mudarNome(nome);

		int element2;
		stream >> element2;
		lancamento.mudarValor(element2);

		if (listaContabil.contem(lancamento)) {
			listaContabil.retirarEspecifico(lancamento);
		} else {
			break;
		}

	}

}

static void comandoMostrar(ListaContabil &listaContabil) {

	for (int i = 0; i < listaContabil.retornarUltimo(); i++) {

		std::cout << listaContabil.retornarLancamento(i).retornarNome()
				<< std::endl
				<< listaContabil.retornarLancamento(i).retornarValor()
				<< std::endl;
	}

}

static void comandoInserirEmOrdem(std::istream &stream, std::istream &file,
		ListaContabil &lista) {

	int qtd;
	stream >> qtd;

	std::string line;

	Lancamento lancamento;

	for (int i = 0; i < qtd; i++) {
		std::getline(file, line);
		std::stringstream stream(line);
		std::string element;
		stream >> element;
		char *nome = new char[element.size() + 1];
		nome[element.size()] = 0;
		memcpy(nome, element.c_str(), element.size());
		lancamento.mudarNome(nome);

		int element2;
		stream >> element2;
		lancamento.mudarValor(element2);

		lista.adicionarEmOrdem(lancamento);

	}

}
static void comandoInserirNaPosicao(std::istream &stream, std::istream &file,
		ListaContabil &lista) {

	int qtd;
	stream >> qtd;

	int pos;
	stream >> pos;

	std::string line;

	Lancamento lancamento;

	for (int i = 0; i < qtd; i++) {
		std::getline(file, line);
		std::stringstream stream(line);
		std::string element;
		stream >> element;
		char *nome = new char[element.size() + 1];
		nome[element.size()] = 0;
		memcpy(nome, element.c_str(), element.size());
		lancamento.mudarNome(nome);

		int element2;
		stream >> element2;
		lancamento.mudarValor(element2);

		lista.adicionaNaPosicao(lancamento, pos);

	}

}
static void comandoInserir(std::istream &stream, std::istream &file,
		ListaContabil &lista) {

	int qtd;
	stream >> qtd;

	std::string line;

	Lancamento lancamento;

	for (int i = 0; i < qtd; i++) {
		std::getline(file, line);
		std::stringstream stream(line);
		std::string element;
		stream >> element;
		char *nome = new char[element.size() + 1];
		nome[element.size()] = 0;
		memcpy(nome, element.c_str(), element.size());
		lancamento.mudarNome(nome);

		int element2;
		stream >> element2;
		lancamento.mudarValor(element2);

		lista.adicionar(lancamento);

	}

}

static void printPrompt() {
	std::cout << "Comando: ";
}

static void printInitialHelp() {
	std::cout << "Supported commands: " << std::endl << "\t\"" << SELCREDIT_STR
			<< "\"" << std::endl << "\t\"" << SELDEB_STR << "\"" << std::endl
			<< "\t\"" << SAIR_STR << "\"" << std::endl;
}

static void printHelp(std::string &listaSelecionada) {

	std::cout << "Menu: " << std::endl << "\t\"" << SELCREDIT_STR << "\" "
			<< std::endl << "\t\"" << SELDEB_STR << "\"" << std::endl << "\t\""
			<< LANCAR_STR << "\"" << std::endl << "\t\"" << LISTAR_STR << "\""
			<< std::endl << "\t\"" << REMOVER_STR << "\"" << std::endl << "\t"
			<< SALDO_STR << "\"" << std::endl << "\t\"" << "\t" << SAIR_STR
			<< "\"" << std::endl << "\t\"" << "Lista Selecionada : "
			<< listaSelecionada << "\"" << std::endl;

}
static void execucaoInterativa() {

	bool foiSelecionada = false;

	ListaContabil debitos;
	ListaContabil creditos;
	ListaContabil *listaAtual = NULL;
	std::string listaSelecionada;

	while (true) {

		if (!foiSelecionada)
			printInitialHelp();
		else
			printHelp(listaSelecionada);

		printPrompt();

		std::string comando;
		std::getline(std::cin, comando);

		if (strcasecmp(comando.c_str(), "c") == 0) {

			listaSelecionada = "CRÉDITOS";
			foiSelecionada = true;
			listaAtual = &creditos;

		} else if (strcasecmp(comando.c_str(), "d") == 0) {
			listaSelecionada = "DÉBITOS";
			foiSelecionada = true;
			listaAtual = &debitos;

		} else if (strcasecmp(comando.c_str(), "x") == 0) {
			continue;
		} else if (strcasecmp(comando.c_str(), "t") == 0) {

		}

	}

}

static void execucaoDeTestes(const std::string &filename) {


	std::ifstream file(filename.c_str());
	std::istream input;
	std::string line;
	ListaContabil listaAtual;
	bool foiCriado;

	//While file is not finished
	while (std::getline(input, line)) {
		std::stringstream stream(line);
		std::string command = line;
		stream >> command;

		if (command == "CREDITOS") {
			listaAtual = creditos;
			foiCriado = true;
		} else if (command == "DEBITOS") {
			listaAtual = debitos;
			foiCriado = true;
		} else if (command == "CRIAR") {
			listaAtual.inicializar();

		} else if (foiCriado) {

			if (command == "INSERIR") {
				comandoInserir(stream, input, listaAtual);
			} else if (command == "INSERIR_EM_ORDEM") {
				comandoInserirEmOrdem(stream, input, listaAtual);
			} else if (command == "INSERIR_NA_POSICAO") {
				comandoInserirNaPosicao(stream, input, listaAtual);
			} else if (command == "MOSTRAR") {
				comandoMostrar(listaAtual);
			} else if (command == "REMOVER") {
				listaAtual.retirar();
			}

		} else if (command == "SAIR") {
			break;
		}
	}
}

int main(int argc, char** argv) {

	if (argc < 2) {
		execucaoInterativa();
	} else {
		execucaoDeTestes(argv[1]);
	}

}

