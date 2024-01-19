Algoritmo TodoListo
	Definir tipo Como Caracter
	Definir horas Como Entero
	Definir precio Como Real
	Escribir ' [Pago a un mecanico de TodoListo] '
	Escribir ' '
	Escribir 'Tipo de servicio (R:reparación, M: Mantenimiento, A: Acondicionamiento): '
	Leer tipo
	Escribir 'Numero de horas: '
	Leer horas
	Escribir ' '
	Si (tipo=='R' Y horas>=48) Entonces
		precio <- 200*0.85
	SiNo
		Si (tipo=='M' Y horas>=48) Entonces
			precio <- 100*0.85
		SiNo
			Si (tipo=='A' Y horas>=48) Entonces
				precio <- 400*0.85
			SiNo
				Si (tipo=='R' Y horas>=0 Y horas<48) Entonces
					precio <- 200
				SiNo
					Si (tipo=='M' Y horas>=0 Y horas<48) Entonces
						precio <- 100
					SiNo
						Si (tipo=='A' Y horas>=0 Y horas<48) Entonces
							precio <- 400
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
	Escribir 'El pago será de: ',precio,' soles'
FinAlgoritmo
