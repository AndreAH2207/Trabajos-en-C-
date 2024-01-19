#include <iostream>
#include <conio.h>

using namespace std;

char Fase()
{
	char f;
	do {
		cout << "El partido en que fase es (G: Grupos, C: Cuartos S:semifinales): "; cin >> f;
		f = toupper(f);
	} while (f != 'G' && f != 'C' && f != 'S');
	return f;
}

char Zona()
{
	char z;
	do {
		cout << "Zona (N:Norte; S:Sur; R:Oriente; O:Occidente): "; cin >> z;
		z = toupper(z);
	} while (z != 'N' && z != 'S' && z != 'R' && z != 'O');
	return z;
}

char ValidarTarjeta()
{
	char t;

	do {
		cout << "Pagara con tarjeta (S:Si; N:No): "; cin >> t;
		t = toupper(t);
	} while (t != 'S' && t != 'N');
	return t;
}

char Ciudadano()
{
	char c;

	do {
		cout << "Es ciudadano Qatari (S:Si; N:No): "; cin >> c;
		c = toupper(c);
	} while (c != 'S' && c != 'N');
	return c;
}

char Discapacitado()
{
	char discp;

	do {
		cout << "Es un ciudadano que utiliza silla de ruedas (S:Si; N:No): "; cin >> discp;
		discp = toupper(discp);
	} while (discp != 'S' && discp != 'N');
	return discp;
}
 
float Pago_por_Fases(char fase, char tarjeta, float precio)
{

	if (fase == 'G' && tarjeta == 'S')
	{
		precio = precio + (precio * 0.085);
	}
	else if (fase == 'C' && tarjeta == 'S')
	{
		precio = precio + (precio * 0.1175);
	}
	else if (fase == 'S' && tarjeta == 'S')
	{
		precio = precio + (precio * 0.15);
	}
	return precio;
}

float Validar_Descuento(char discapacitado, char ciudadano, float precio)
{

	if (discapacitado == 'N' && ciudadano == 'N')
	{
		precio = precio;
	}
	else if (discapacitado == 'S' && ciudadano == 'N')
	{
		precio = precio - (precio * 0.25);
	}
	else if (discapacitado == 'N' && ciudadano == 'S')
	{
		precio = precio - (precio * 0.5);
	}
	else if (discapacitado == 'S' && ciudadano == 'S')
	{
		precio = precio - (precio * 0.5);
		precio = precio - (precio * 0.25);
	}

	return precio;
}


float ValidarPrecio(char fase, char zona, char tarjeta, char ciudadano, char discapacitado)
{
	float precio;

	fase = Fase();
	zona = Zona();
	tarjeta = ValidarTarjeta();
	ciudadano = Ciudadano();
	discapacitado = Discapacitado();


	switch (fase)
	{
		case 'G':

			if (zona == 'N')
			{
				precio = 200;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'S')
			{
				precio = 200;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'R')
			{
				precio = 350;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'O')
			{
				precio = 450;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			break;

		case 'C':

			if (zona == 'N')
			{
				precio = 300;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'S')
			{
				precio = 300;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'R')
			{
				precio = 400;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'O')
			{
				precio = 500;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			break;

		case 'S':

			if (zona == 'N')
			{
				precio = 350;
				precio = Pago_por_Fases(fase, tarjeta,precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'S')
			{
				precio = 350;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'R')
			{
				precio = 450;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			else if (zona == 'O')
			{
				precio = 550;
				precio = Pago_por_Fases(fase, tarjeta, precio);
				precio = Validar_Descuento(discapacitado, ciudadano, precio);
			}
			break;
		default:
			break;
	}	
	return precio;
}


int main()
{
	char fase, zona, tarjeta, discapacitado, ciudadano;
	float precio;

	precio = ValidarPrecio(fase, zona, tarjeta, discapacitado, ciudadano);

	cout << endl;
	cout << "El precio a pagar es: " << precio << endl;
	cout << endl;

	_getch();
	return 0;

}