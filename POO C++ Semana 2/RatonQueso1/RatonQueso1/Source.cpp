#include "Raton.h"
#include "Queso.h"

int main() {
	Console::SetWindowSize(ANCHO, ALTO);
	Console::CursorVisible = false;
	srand(time(NULL));
	Raton* raton1 = new Raton();
	Queso* queso1 = new Queso();
	bool queso = false;
	int xq;
	int yq;

	while (true)
	{
		raton1->clear();
		if (_kbhit()) {
			char tecla = toupper(getch());
			if (tecla == 'Q') {
				xq = rand() % (ANCHO - queso1->getAncho());
				yq = rand() % (ALTO - queso1->getAlto());
				queso1->setX(xq);
				queso1->setY(yq);
				queso1->draw();
				queso = true;
			}
		}
		raton1->mover(queso1->getX(), queso1->getY(), queso);

		if (raton1->getX() == queso1->getX() && raton1->getY() == queso1->getY()) {
			queso1->clear();
			queso = false;
		}
		raton1->draw();
		_sleep(250);
	}
}