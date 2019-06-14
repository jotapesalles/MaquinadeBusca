#include "usuario.h"
Usuario::Usuario() {
}
void Usuario::Menu(){
	int i;
	cout << "Bem vindo a maquina de busca. \n Deseja fazer o que? " << endl;
	cout << "[1] Pesquisar. [x]Mostrar Documentos. [2] Sair " << endl;
	cin >> i;
	switch(i){
		case 1:
			Pesquisa();
			break;
		case 2:
			break;
	}
};
void Usuario::Pesquisa(){
	cout << "Digite a frase ou palavra que deseja consultar:" << endl;
	string palavra;
	cin.ignore();
	getline(cin,palavra);
	ofstream ofFile("usuario.txt");
	ofFile << palavra << endl;
	ofFile.close();
	
	
	Arquivo aux("usuario.txt","r+");
	aux.open();
	aux.vocabulary("usuariovoc.txt");
	aux.close();
	Indice ind(12);
	Arquivo voca("vocabulary.txt","r+");
	Arquivo voc("usuariovoc.txt","r+");
	ind.setVocabulario(voca);
	ind.setDocumento(voc);
	cout << "deu";
	Coordenada coo(voc,"",ind);
	cout << coo.SomatorioW(voc);
};
void MostrarResultados(Indice* ind);
