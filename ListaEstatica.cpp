#pragma warning(disable: 4996)
#include "ListaEstatica.h"

/*
* Função destrutora da classe (Não Implementada)
*/
ListaEstatica::~ListaEstatica(){}


/*
* Função que inicializa uma lista com dados lidos em aquivo
*
* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
*/
ListaEstatica::ListaEstatica(string file_name) {
	fstream input;
	input.open(file_name, ios::in);

	if (!input)
		abort();

	char linha[TAM_LINHA + 1];
	input.getline(linha, TAM_LINHA);
	tamanho = atoi(strtok(linha,"endl"));

	input.getline(linha, TAM_LINHA);
	dados[0] = atoi(strtok(linha, " "));
	for (unsigned i = 1; i < tamanho; i++){
		dados[i] = atoi(strtok(NULL, " "));
	}

	input.close();
}


/*
* Função que inicializa uma lista com dados aleatórios, com o
* tamanho definido;
*
* @param tam		Número de elementos da lista (tamanho) que deve ser gerada
*/
ListaEstatica::ListaEstatica(unsigned tam){
	tamanho = tam;
	int seed = 107140;
	cout << "Semente de geração da lista: " << seed << endl;
	srand(seed);

	for (unsigned i=0; i < tamanho; i++){
		dados[i] = 1 + rand() % 1000;
	}
}

/*
	* Função que faz a inserção de um novo elemento na lista,
	* na posição indicada.
	*
	* @param posicao		Posição onde o elemento deve ser inserido;
	* @param valor			Valor do elemento que será inserido na lista;
	*/
void ListaEstatica::Inserir(unsigned posicao, int valor) {
	if (posicao > tamanho){
		cout << "Posição Inválida!!!" << endl;
		return;
	}
	
	if (MAX_TAM == tamanho) {
		cout << "Lista Cheia!!!" << endl;
		return;
	}

	for (unsigned i = tamanho; i > posicao; i--) {
		dados[i] = dados[i - 1];
	}

	dados[posicao] = valor;
	tamanho++;
}

/*
	* Função que realiza uma busca na lista por um valor especificado,
	* retornando sua posição;
	*
	* @param valor		Valor que deve ser buscado na lista
	*/
int ListaEstatica::Buscar(int valor) {
	unsigned acesso = 0;
	unsigned posicao = 0;

	if (tamanho == 0) {
		cout << "Lista Vazia!!!" << endl;
		return -1;
	}

	while(posicao<tamanho){
		acesso++;
		if (dados[posicao] == valor) {
			cout << "Posição: " << posicao << endl;
			cout << "Acessos: " << acesso << endl << endl;
			return posicao;
		}
		posicao++;
	}

	cout << "Não encontrado!!" << endl;
	cout << "Acessos: " << acesso << endl << endl;
	return -1;
}

/*
	* Função que realiza a busca pelo menor elemento da lista,
	* retornando sua posição.
	*/
int ListaEstatica::BuscarMenor() {
	unsigned acesso = 0;
	unsigned posicao = 1;
	int menorValor, posicaoMenorValor = -1;

	if (tamanho == 0) {
		cout << "Lista Vazia!!!" << endl;
		return -1;
	}

	acesso++;
	menorValor = dados[0];

	while (posicao < tamanho) {
		acesso++;
		if (menorValor > dados[posicao]) {
			menorValor = dados[posicao];
			posicaoMenorValor = posicao;
		}
		posicao++;
	}

	cout << "Menor valor: " << menorValor << endl;
	cout << "Posição: " << posicaoMenorValor << endl;
	cout << "Acessos: " << acesso << endl;
	return posicaoMenorValor;

}

/*
	* Função que realiza a troca de elementos nas posições indicadas
	*
	* @param posicao1		Posição do primeiro elemento;
	* @patam posicao2		Posição do segundo elemento;
	*/
bool ListaEstatica::Swap(unsigned posicao1, unsigned posicao2) {
	int aux;

	if (tamanho == 0) {
		cout << "Lista Vazia!!!" << endl;
		return false;
	}

	if (posicao1 == posicao2) {
		//cout << "As posições informadas são iguais!!!" << endl;
		return false;
	}

	if (posicao1 < tamanho && posicao2 < tamanho) {
		aux = dados[posicao1];
		dados[posicao1] = dados[posicao2];
		dados[posicao2] = aux;
		return true;
	}
	else {
		cout << "Posições Inválidas!!!" << endl;
		return false;
	}

}

/*
	* Função que faz a impressão dos elementos na tela
	*/
void ListaEstatica::print(){
	for (unsigned i = 0; i < tamanho; i++){
		cout << dados[i] << " ";
	}
	cout << endl;
}


/*
* Atributos da classe ListaEstatica;
*/
void ListaEstatica::printInvertido() {
	if (tamanho == 0){
		cout << "Lista Vazia!!" << endl;
	}
	else{
		for (unsigned i = tamanho; i > 0; i--){
			cout << dados[i - 1] << " ";
		}

		cout << endl;
	}
}
