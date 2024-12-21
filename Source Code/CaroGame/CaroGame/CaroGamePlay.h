#ifndef _CARO_GAME_PLAY_H_
#define _CARO_GAME_PLAY_H_

#include "CaroBoard.h"
#include "CaroCell.h"
#include "CaroPlayer.h"
#include "CaroResetButton.h"
#include "CaroExitButton.h"
#include "IGamePlay.h"
#include "CaroPlayerTurnTextBox.h"

#include <vector>

#define CARO_IS_PLAYING 1
#define CARO_WIN 2
#define CARO_EXIT 3

class CaroGamePlay: public IGamePlay {
private:
	std::vector<CaroPlayer*> _players;
	CaroBoard* _playBoard;
	CaroPlayerTurnTextBox* _playerTurnTextBox;
	CaroResetButton* _resetButton;
	CaroExitButton* _exitButton;
private:
	CaroPlayer* _playerInTurn;
	int _gameStatus;
	int _turnCount;
	std::vector<std::pair<int, int>> _winningLine; // {int: row, int: col} in CaroBoard
private:
	static CaroGamePlay* _instance;
	CaroGamePlay();
	CaroGamePlay(CaroGamePlay& other);
	CaroGamePlay& operator= (CaroGamePlay& other);
	CaroGamePlay(std::vector<CaroPlayer> players, CaroBoard playBoard);
public:
	~CaroGamePlay();
	static CaroGamePlay* instance();
public:
	CaroPlayer* playerInTurn();
	CaroBoard* playBoard();
	int gameStatus();
	void setGameStatus(int status);
	void increaseTurnCount(int value = 1);
	std::vector<std::pair<int, int>> winningLine();
	void setWinningLine(const std::vector<std::pair<int,int>>& winningLine);
	void reset();
public:
	void play() override;
	void quit() override;
	std::string gameName() override;
};

#endif