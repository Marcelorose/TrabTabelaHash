#ifndef THASH_H
#define THASH_H
#include <iostream>

using namespace std;

#define MAX 1000

struct THash {
	int TabelaHash[MAX];
	int qtd;
};

void inicializarTHash(THash &t) {
	for (int i = 0; i < 1000; i++)
	{
		t.TabelaHash[i] = 0;
	}
	t.qtd = 0;
}

bool inserirTHash(THash &t, int chave, int &instr) {
	if (t.qtd >= MAX)
	{
		return false;
	}
	int posicao = chave % MAX;

	for (int i = posicao; i < MAX; i++)
	{
		if (t.TabelaHash[i] == 0)
		{
			t.TabelaHash[i] = chave;
			t.qtd++;
			return true;
		}
		else if (t.TabelaHash[i] == chave)
		{
			return false;
		}
		else if (i == MAX - 1)
		{
			return false;
		}
		instr++;		
	}
}

void pesquisa(THash &t, int chave, int &instr) {
	int posicao = chave % MAX;
	
	for (int i = posicao; i < MAX; i++)
	{
		if (t.TabelaHash[i] == 0)
		{
			return;
		}
		else if (t.TabelaHash[i] == chave)
		{
			return;			
		}		
		instr++;
	}	
	return;
}



#endif
