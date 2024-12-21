#ifndef _CARO_GAME_RULE_H_
#define _CARO_GAME_RULE_H_

#include "CaroBoard.h"
#include "CaroPlayer.h"
#include "IGameRule.h"

class CaroGameRule: public IGameRule {
public:
	static bool isValidMove(CaroPlayer* player, int i, int j, CaroBoard* playBoard);
	static bool isWinningMove(CaroPlayer* player, int i, int j, CaroBoard* playBoard);
	std::string gameName() override;
private:
	class CaroGameRuleUtils {
	public:
		static bool checkDirection(CaroPlayer* player, int row, int col, int dRow, int dCol, CaroBoard* playBoard);
	};
};

#endif