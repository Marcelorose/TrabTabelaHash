// TabelaHash.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include "THash.h"
#include <fstream>
#include <string>
#include <stdlib.h>     
#include <time.h>


using namespace std;

void gravar(string th, string op,int ocup, int instr) {
	ofstream arq("saida.csv", fstream::app);
	arq << th << ", " << op << ", " << ocup << ", " << instr << "\n";
}


int main()
{
	srand(time(NULL));
	THash h;
	inicializarTHash(h); 
	int instr;
	for (int i = 1; i <= 2000; i++)
	{
		int chave = rand() % 32000 + 1;
		instr = 1;
		inserirTHash(h, chave, instr);
		if (i == 90 || i == 240 || i == 740 || i == 990 || i == 1990)
		{
			for (int k = 0; k < 10; k++)
			{
				int c = rand() % 32000 + 1;
				instr = 1;
				inserirTHash(h, c, instr);
				cout << "EA," << " INS" << ", " << (i + 10) / 10 << ", " << instr << endl;
				gravar("Es", "ins", (i + 10) / 10, instr);
			}

			for (int k = 0; k < 10; k++)
			{
				int c = rand() % 32000 + 1;
				instr = 1;
				pesquisa(h, c, instr);
				cout << "EA," << " PESQ" << ", " << (i + 10) / 10 << ", " << instr << endl;
				gravar("Es", "pesq", (i + 10)/10, instr);
			}
			i += 10;
		}	
	}
	return 0;
}

