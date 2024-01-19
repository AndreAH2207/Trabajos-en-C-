#pragma once
#include <string>
using namespace std;

class Auto {
private:
	int codigo;
	string marca;
	string modelo;
	double precio;
	int stock;
public:
	Auto(int codigo, string marca, string modelo, double precio, int stock) {
		this->codigo = codigo;
		this->marca = marca;
		this->modelo = modelo;
		this->precio = precio;
		this->stock = stock;
	}

	double calcularDescuento() {
		double descuento = 0.0;
		if (stock > 100) {
			descuento = 0.20 * precio;
		}
		return descuento;
	}

	double calcularIgv() {
		return precio * 0.18;
	}
	double calcularPrecioFinal() {
		return precio - calcularDescuento() + calcularIgv();
	}
	double getPrecio() {
		return precio;
	}
	double getCodigo() {
		return codigo;
	}
	string getMarca() {
		return marca;
	}
	string getModelo() {
		return modelo;
	}
};
