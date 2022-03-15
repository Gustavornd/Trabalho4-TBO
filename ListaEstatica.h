#pragma once
#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#define TAM_LINHA 5000
#define MAX_TAM 1000

using namespace std;

/*
* Classe que guarda uma lista Estatica de elementos do
* tipo Int;
*/
class ListaEstatica {
public:
	/*
	* Função de incialização de lista vazia.
	*/
	ListaEstatica() { tamanho = 0; };

	/*
	* Função que inicializa uma lista com dados lidos em aquivo
	* 
	* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
	*/
	ListaEstatica(string file_name);

	/*
	* Função que inicializa uma lista com dados aleatórios, com o
	* tamanho definido;
	* 
	* @param tam		Número de elementos da lista (tamanho) que deve ser gerada
	*/
	ListaEstatica(unsigned tam);

	/*
	* Função destrutora da classe (Não Implementada)
	*/
	~ListaEstatica();

	/*
	* Função que faz a inserção de um novo elemento na lista,
	* na posição indicada.
	* 
	* @param posicao		Posição onde o elemento deve ser inserido;
	* @param valor			Valor do elemento que será inserido na lista;
	*/
	void Inserir(unsigned posicao, int valor);

	/*
	* Função que realiza uma busca na lista por um valor especificado,
	* retornando sua posição;
	* 
	* @param valor		Valor que deve ser buscado na lista 
	*/
	int Buscar(int valor);

	/*
	* Função que realiza a busca pelo menor elemento da lista,
	* retornando sua posição.
	*/
	int BuscarMenor();

	/*
	* Função que realiza a troca de elementos nas posições indicadas
	* 
	* @param posicao1		Posição do primeiro elemento;
	* @patam posicao2		Posição do segundo elemento;
	*/
	bool Swap(unsigned posicao1, unsigned posicao2);

	/*
	* Função que faz a impressão dos elementos na tela
	*/
	void print();

	/*
	* Função que faz a impressão dos elementos na tela em sentido inverso.
	*/
	void printInvertido();

	/*
	* Atributos da classe ListaEstatica;
	*/
	int dados[MAX_TAM] = {0};
	unsigned tamanho;
};

#endif // !LISTA_ESTATICA_H

