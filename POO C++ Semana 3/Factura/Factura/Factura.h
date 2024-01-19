#pragma once
#include <string>
#include <vector>
#include "Item.h"

class CFactura
{
private:
	int numeroFactura;
	int numeroRuc;
	string razonSocial;
	string fecha;
	vector<CItem*> arregloItems;

public:
	CFactura(int numeroFactura, int numeroRuc, string razonSocial, string fecha)
	{
		this->numeroFactura = numeroFactura;
		this->numeroRuc = numeroRuc;
		this->razonSocial = razonSocial;
		this->fecha = fecha;
	}

	void registrar(int id, int cantidad, int codigo, string descripcion, float precio)
	{
		CItem* item = new CItem(id, cantidad, codigo, descripcion, precio);
		arregloItems.insert(arregloItems.begin(), item);
	}

	float calcularMontoTotal()
	{
		float suma = 0;
		for (int i = 0; i < arregloItems.size(); i++)
		{
			suma += arregloItems[i]->calcularMontoParcial();
		}
	}

	vector<CItem*> getItems() {
		return arregloItems;
	}

};
