#include "CaroGameRule.h"
#include "CaroGamePlay.h"

#include <iostream>

bool CaroGameRule::isValidMove(CaroPlayer* player, int i, int j, CaroBoard* playBoard) {
	if (playBoard->cell(i, j)->value() != ' ') return false;
	else return true;
}

bool CaroGameRule::isWinningMove(CaroPlayer* player, int i, int j, CaroBoard* playBoard) {
    return CaroGameRuleUtils::checkDirection(player, i, j, 0, 1, playBoard) ||
        CaroGameRuleUtils::checkDirection(player, i, j, 1, 0, playBoard) ||
        CaroGameRuleUtils::checkDirection(player, i, j, 1, 1, playBoard) ||
        CaroGameRuleUtils::checkDirection(player, i, j, 1, -1, playBoard);
}

bool CaroGameRule::CaroGameRuleUtils::checkDirection(CaroPlayer* player, int row, int col, int dRow, int dCol, CaroBoard* playBoard) {
    CaroGameRule* gameRule = new CaroGameRule();

    std::vector<std::pair<int, int>> winningLine = { {row, col} };

    int count = 1;

    for (int i = 1; i < 5; i++) {
        int newRow = row + i * dRow;
        int newCol = col + i * dCol;
        if (newRow < 0 || newRow >= playBoard->height() || newCol < 0 || newCol >= playBoard->width()) break;
        if (playBoard->cell(newRow, newCol)->value() == player->symbol()) {
            winningLine.push_back({ newRow, newCol });
            count++;
        }
        else {
            break;
        }
    }

    for (int i = 1; i < 5; i++) {
        int newRow = row - i * dRow;
        int newCol = col - i * dCol;
        if (newRow < 0 || newRow >= playBoard->height() || newCol < 0 || newCol >= playBoard->width()) break;
        if (playBoard->cell(newRow, newCol)->value() == player->symbol()) {
            winningLine.push_back({ newRow, newCol });
            count++;
        }
        else {
            break;
        }
    }

    delete gameRule;

    if (count >= 5) {
        CaroGamePlay::instance()->setWinningLine(winningLine);
        return true;
    }

    return false;
}

std::string CaroGameRule::gameName() {
    return "Caro";
}