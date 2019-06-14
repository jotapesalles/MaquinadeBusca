#include "usuario.h"

void Imprimir(vector<string> &v){
	for(int i = 0; i< v.size();i++) {
		cout << "[" << i << "]" << v[i] << endl;
	}
}	

int main(){
	Arquivo aux("d1.txt","r+");
	aux.open();
	aux.vocabulary("d1voc.txt");
	aux.close();
	Arquivo aux2("d2.txt","r+");
	aux2.open();
	aux2.vocabulary("d2voc.txt");
	aux2.close();
	Arquivo aux3("d3.txt","r+");
	aux3.open();
	aux3.vocabulary("d3voc.txt");
	aux3.close();
	Arquivo voc("vocabulary.txt","r+");
	Indice ind(12);
	ind.setVocabulario(voc);
	Arquivo voc2("d1voc.txt","r+");
	Arquivo voc3("d2voc.txt","r+");
	Arquivo voc4("d3voc.txt","r+");
	ind.setDocumento(voc2);
	ind.setDocumento(voc3);
	ind.setDocumento(voc4);
	Coordenada coo(voc2,"apartamento",ind);
	cout << coo.SomatorioW(voc2);
	voc.close();
	voc2.close();
	voc3.close();
	voc4.close();
}
