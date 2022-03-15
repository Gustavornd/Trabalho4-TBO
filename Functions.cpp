#include "Functions.h"




/*
* Fun��o usada para criar o arquivo de entrada de dados;
*/
void CreateInputFile() {
	fstream output;
	output.open("dados.txt", ios::out);

	if (!output)
		abort();

	output << "20" << endl;
	output << "70 1 12 8 99 72 5 15 20 91 14 61 66 41 81 88 16 21 34 90";

	output.close();
}


/*
* Fun��o usada para criar um aquivo de entrada com dados
* aleat�rios, mas n�o foi utilizado;
*/
void CreateRandomInputFile() {
	fstream output;
	output.open("dadosRadom.txt", ios::out);

	if (!output)
		abort();

	output << 100 << endl;

	for (unsigned i = 1; i <= 100; i++)
	{
		output << 1 + rand() % 1000 << " ";
	}

	output.close();
}




/*
* Fun��o que realiza a ordena��o da lista pelo m�todo 
* Bubble Sort, ordenando a lista ordem crescente.
* 
* @param le					Lista encadeada est�tica que ser� ordenada
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
int BubbleSort(ListaEstatica &le, bool imprime_lista) {

	bool mudou = true;
	int n = le.tamanho;
	int aux = le.tamanho - 1;
	int acessos = 1;

	while (mudou) {
		mudou = false;
		for (int j = 0; j < n-1; j++) {
			if (le.dados[j] > le.dados[j + 1]) {
				mudou = true;
				aux = j;
				le.Swap(j, j + 1);
				acessos += 3;
			}
			acessos += 2;
		}
		n = aux + 1;
		if(imprime_lista)
			le.print();
	}

	if (!imprime_lista) {
		le.print();
	}
	return acessos;
}



/*
* Fun��o que realiza a ordena��o da lista pelo m�todo
* Insertion Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
int InsertionSort(ListaEstatica &le, bool imprie_lista) {
	int acessos = 1;
	for (unsigned i = 1; i < le.tamanho; i++) {
		int j = i - 1;
		int valor = le.dados[i];
		acessos++;
		while ((j >= 0) && (valor < le.dados[j])) {
			le.dados[j + 1] = le.dados[j];
			acessos += 2;
			j--;
		}
		le.dados[j + 1] = valor;
		acessos++; 
		if(imprie_lista)
			le.print();
	}
	if (!imprie_lista)
		le.print();
	return acessos;
}




/*
* Fun��o de chamada recursiva que realiza a ordena��o da lista pelo m�todo
*  Quick Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param left				Primeira posi��o da lista � esquerda do piv�
* @param right				Primeira posi��o da lista � direita do piv�
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
void QuickSort(ListaEstatica &le, int left, int right, int &acessos, bool imprime_lista) {
	acessos++;
	if (left < right) {
		int c = Partition(le, left, right, acessos, imprime_lista);
		QuickSort(le, left, c - 1, acessos, imprime_lista);
		QuickSort(le, c + 1, right, acessos, imprime_lista);
		acessos += 3;
	}
}



/*
* Fun��o divide a lista em duas � partir do piv� e realiza 
* a troca das posi��es dos elementos da lista pelo m�todo
* para orden�-la pelo Quick Sort, ordenando a lista ordem crescente.
*
* @param le					Lista encadeada est�tica que ser� ordenada
* @param left				Primeira posi��o da lista � esquerda do piv�
* @param right				Primeira posi��o da lista � direita do piv�
* @param acessos			Vari�vel externa para a contagem de acessos de mem�ria
* @param imprime_lista		Indica se deve ser printada cada execu��o
*							da ordena��o ou apenas a lista ordenada no
*							final da execu��o.
*/
int Partition(ListaEstatica &le, int left, int right, int &acessos, bool imprime_lista)//1
{
	int c, i, pivo = le.dados[right];//1
	bool swap = false;
	acessos += 2; 

	c = (left - 1);

	for (i = left; i <= right - 1; i++){
		if (le.dados[i] < pivo){//1
			c++;
			swap = le.Swap(c, i);

			if (swap) {
				acessos = +3;
			}
			else {
				acessos++;
			}

			swap = false;
		}
	}
	swap = le.Swap(c+1,right);
	if (swap) {
		acessos += 3;
	}
	if (imprime_lista) {
		cout << pivo << "\t";
		le.print();
	}

	return c + 1;
}
