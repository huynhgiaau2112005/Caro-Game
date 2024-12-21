#include "main.h"

int main() {
	Caro* caro = new Caro();
	caro->gamePlay()->play();

	delete caro;
	return 0;
}