#pragma once
#include <string>
#include <vector>
#include "Chofer.h"

using namespace std;

class CUber
{
private:
	string nombreEmpresa;
	vector<CChofer*> arregloChoferes;
public:
	
	void registrar(CChofer* chofer)
	{
		arregloChoferes.push_back(chofer);
	}

	vector<CChofer*>getLista()
	{
		return arregloChoferes;
	}

	vector<CChofer*>getListaConAutosMas2020()
	{
		vector<CChofer*>tempo;
		for (int i = 0; i < arregloChoferes.size(); i++)
		{
			if (arregloChoferes[i]->getAuto()->getAnioFabricacion() > 2020)
			{
				tempo.push_back(arregloChoferes[i]);
			}
		}
		return tempo;
	}

	vector<CChofer*>getLista()
	{
		return arregloChoferes;
	}

	CUber()
	{}

	~CUber()
	{}


};
