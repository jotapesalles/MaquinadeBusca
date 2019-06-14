#ifndef USUARIO_H
#define USUARIO_H
#include "coordenada.h"
class Usuario{
	private:
		Arquivo* _arq;
	public:
		Usuario();
		void Menu();
		void Pesquisa();
		void MostrarResultados(Indice* ind);
};

#endif
