#ifndef _CARO_H_
#define _CARO_H_

#include "IGame.h"
#include "CaroGamePlay.h"

class Caro : public IGame {
private:
	CaroGamePlay* _gamePlay;
public:
	Caro();
	Caro(Caro&);
	~Caro();
	Caro& operator= (Caro&);
	CaroGamePlay* gamePlay();
public:
	std::string gameName() override;
};

#endif