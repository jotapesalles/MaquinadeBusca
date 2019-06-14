#include "coordenada.h"
#include "math.h"
Coordenada::Coordenada(Arquivo& arq, string palavra, Indice& ind){
	_arq = &arq;
	_ind = &ind;
	_palavra = palavra;
};
double Coordenada::idf(map<string,int> Vy, map <string,set<string>*> m, string palavra){
	return(log(((double)Vy.size()/m[palavra]->size())));
};

int Coordenada::tf(string palavra, Arquivo& arq, Indice& ind){
	cout << (ind.Hash(palavra,arq));
	return(ind.Hash(palavra,arq));
};

double Coordenada::modulo(){
	cout << (tf(_palavra,*_arq,*_ind)*idf(_ind->getVy(),_ind->getm(),_palavra));
	return (tf(_palavra,*_arq,*_ind)*idf(_ind->getVy(),_ind->getm(),_palavra));
};
double Coordenada::SomatorioW(Arquivo& arq){
	map<string,int>::iterator it;
	map<string,int> vx = _ind->getVx();
	double soma = 0;
	for(it=vx.begin();it!=vx.end(); ++it){
		Coordenada aux(arq,it->first,*_ind);
		soma+=(pow(aux.modulo(),2));
	}
	return soma;
}
