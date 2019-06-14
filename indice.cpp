#include "indice.h"

Indice::Indice(const int tam){
	_tam = tam;
	_hash = new int[tam*tam+3];
	for(int i = 0;i <147;i++)
		_hash[i] = 0;
};
int Indice::Hash(string palavra, Arquivo arq){
	return(_hash[funcaoHash(Vx[palavra],Vy[arq.end()])]);
};

int Indice::funcaoHash(int x, int y){
	return(x*_tam+y);
};
map <string,int> Indice::getVx(){
	return (Vx);
};
map <string,int> Indice::getVy(){
	return (Vy);
};

map <string,set<string>*> Indice::getm(){
	return (this->m);
};
void Indice::setVocabulario(Arquivo& arq){
		arq.open();
		arq.to_map(m);
		arq.close();
};

void Indice::setDocumento(Arquivo& arq){
	arq.open();
	fstream inFile(arq.end());
	string palavra;
	map<string,int> repeat;
	map<string,set<string>*>::iterator itm;
	int r = 1;
	setVector();
	while(!inFile.eof()){
		getline(inFile,palavra);
		if(palavra != ""){
			m[palavra]->insert(arq.end());
			repeat[palavra]+=r;
			_hash[funcaoHash(Vx[palavra],Vy[arq.end()])] = repeat[palavra];
		}
	inFile.close();
	arq.close();
}
};

void Indice::setVector(){
	map<string,set<string>*>::iterator it;
	set<string>::iterator its;
	int i = 0;
	for (it=m.begin(); it!=m.end(); ++it){
		Vx[it->first] = i;
		i++;
	}
  	string doc[3] = {"d1voc.txt","d2voc.txt","d3voc.txt"};
  	for(int j =0; j<3;j++) Vy[doc[j]] = j;
}

void Indice::printMap(){
	map<string,set<string>*>::iterator it;
	set<string>::iterator its;
	for (it=m.begin(); it!=m.end(); ++it){
		cout << it->first << " ";
		for(auto f : (*(it->second))) {
  			cout << f << " ";
		}
		cout << endl;  
	}
};

void Indice::printHash(){
	for(int i = 0; i < 147;i++){
		cout << "[ " << i << "]" << _hash[i] << " ";
	}
};
