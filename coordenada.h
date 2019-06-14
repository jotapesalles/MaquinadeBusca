#ifndef COORDENADA_H
#define COORDENADA_H
#include "indice.h"
class Coordenada{
	private:
		Arquivo* _arq;
		Indice* _ind;
		string _palavra;
	public:
		Coordenada(Arquivo& arq, string palavra, Indice& ind);
		double modulo();
		double idf(map<string,int> Vy, map <string,set<string>*>m, string palavra);
		int tf(string palavra, Arquivo& arq, Indice& ind);
		double SomatorioW(Arquivo& arq);
};
#endif
