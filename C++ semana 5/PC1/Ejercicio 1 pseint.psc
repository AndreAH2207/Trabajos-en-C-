Algoritmo Compania_de_seguros
	Definir poliza,alcohol,lentes,enfermedad Como Caracter
	Definir costo_poliza Como Real
	Definir edad Como Entero
	Escribir 'Cobertura amplia (A) o daños a terceros (B): '
	Leer poliza
	Escribir 'Tiene por hábito beber alcohol (S: sí; N: no): '
	Leer alcohol
	Escribir 'Usa lentes (S: sí; N: no): '
	Leer lentes
	Escribir 'Padece alguna enfermedad (S: sí; N: no): '
	Leer enfermedad
	Escribir 'Edad: '
	Leer edad
	Si (poliza='A' O poliza='a') Entonces
		costo_poliza <- 1200
	SiNo
		Si (poliza='B' O poliza='b') Entonces
			costo_poliza <- 950
		SiNo
			Escribir 'Error'
		FinSi
	FinSi
	Si (alcohol='S' O alcohol='s') Entonces
		costo_poliza <- trunc((costo_poliza*0.1)+costo_poliza)
	SiNo
		Si (alcohol='N' O alcohol='n') Entonces
			costo_poliza <- trunc(costo_poliza)
		SiNo
			Escribir 'Error'
		FinSi
	FinSi
	Si (lentes='S' O lentes='s') Entonces
		costo_poliza <- trunc((costo_poliza*0.05)+costo_poliza)
	SiNo
		Si (lentes='N' O lentes='n') Entonces
			costo_poliza <- trunc(costo_poliza)
		SiNo
			Escribir 'Error'
		FinSi
	FinSi
	Si (enfermedad='S' O enfermedad='s') Entonces
		costo_poliza <- trunc((costo_poliza*0.05)+costo_poliza)
	SiNo
		Si (enfermedad='N' O enfermedad='n') Entonces
			costo_poliza <- trunc(costo_poliza)
		SiNo
			Escribir 'Error'
		FinSi
	FinSi
	Si (edad>40) Entonces
		costo_poliza <- trunc((costo_poliza*0.2)+costo_poliza)
	SiNo
		Si (edad<=40 Y edad>=0) Entonces
			costo_poliza <- trunc((costo_poliza*0.1)+costo_poliza)
		SiNo
			Escribir 'Error'
		FinSi
	FinSi
	Escribir 'Costo de la poliza: ',trunc(costo_poliza)
FinAlgoritmo
