#ifndef INDICE_H
#define INDICE_H
#include "arquivo.h"
class Indice{
	private:
		map <string,set<string>*> m;
		map <string,int> Vx,Vy;
		int _tam;
		int* _hash;
	public:
		Indice(int tam);
		int Hash(string palavra, Arquivo arq);
		int funcaoHash(int x, int y);
		void setVector();
		map<string,int> getVx();
		map<string,int> getVy();
		map <string,set<string>*> getm();
		void setVocabulario(Arquivo& arq);
		void setDocumento(Arquivo& arq);
		void printMap();
		void printHash();
};
#endif
