#include "CaroGamePlay.h"
#include "IObjectHandler.h"
#include "ObjectHandlerFactory.h"

#include <map>

CaroGamePlay* CaroGamePlay::_instance = nullptr;

CaroGamePlay::CaroGamePlay() {
	_players.push_back(new CaroPlayer('X', RED));
	_players.push_back(new CaroPlayer('O', BLUE));

	_playBoard = new CaroBoard(20, 20, { 42.0f, 50.0f, 40.0f, 40.0f }, ' ');
	_playerTurnTextBox = new CaroPlayerTurnTextBox();
	_playerInTurn = nullptr;
	_gameStatus = CARO_IS_PLAYING;
	_turnCount = 0;
	_winningLine = {};
	_resetButton = new CaroResetButton();
	_exitButton = new CaroExitButton();
}

CaroGamePlay::CaroGamePlay(CaroGamePlay& other) {
	for (int i = 0; i < other._players.size(); i++) {
		_players.push_back(new CaroPlayer(*other._players[i]));
	}
	_playerTurnTextBox = new CaroPlayerTurnTextBox(*other._playerTurnTextBox);
	_playBoard = new CaroBoard(*other._playBoard);
	_playerInTurn = new CaroPlayer(*other._playerInTurn);
	_gameStatus = other._gameStatus;
	_turnCount = other._turnCount;
	_winningLine = other._winningLine;
	_resetButton = new CaroResetButton(*other._resetButton);
	_exitButton = new CaroExitButton(*other._exitButton);
}
CaroGamePlay::~CaroGamePlay() {
	while (!_players.empty()) {
		delete _players.back();
		_players.pop_back();
	}
	delete _playBoard;
	delete _resetButton;
}
CaroGamePlay& CaroGamePlay::operator= (CaroGamePlay& other) {
	if (this == &other) return *this;

	while (!_players.empty()) {
		delete _players.back();
		_players.pop_back();
	}
	delete _playBoard;
	delete _resetButton;
	delete _exitButton;

	for (int i = 0; i < other._players.size(); i++) {
		_players.push_back(new CaroPlayer(*other._players[i]));
	}
	_playBoard = new CaroBoard(*other._playBoard);
	_playerInTurn = new CaroPlayer(*other._playerInTurn);
	_gameStatus = other._gameStatus;
	_turnCount = other._turnCount;
	_winningLine = other._winningLine;
	_resetButton = new CaroResetButton(*other._resetButton);
	_exitButton = new CaroExitButton(*other._exitButton);

	return *this;
}
CaroGamePlay::CaroGamePlay(std::vector<CaroPlayer> players, CaroBoard playBoard) {
	for (int i = 0; i < players.size(); i++) {
		_players.push_back(new CaroPlayer(players[i]));
	}
	_playBoard = new CaroBoard(playBoard);
	_playerTurnTextBox = new CaroPlayerTurnTextBox();
	_playerInTurn = nullptr;
	_gameStatus = CARO_IS_PLAYING;
	_turnCount = 0;
	_winningLine = {};
	_resetButton = new CaroResetButton();
	_exitButton = new CaroExitButton();
}

CaroGamePlay* CaroGamePlay::instance() {
	if (_instance == nullptr) {
		_instance = new CaroGamePlay();
	}

	return _instance;
}

CaroPlayer* CaroGamePlay::playerInTurn() {
	return _playerInTurn;
}

CaroBoard* CaroGamePlay::playBoard() {
	return _playBoard;
}

int CaroGamePlay::gameStatus() {
	return _gameStatus;
}

void CaroGamePlay::setGameStatus(int status) {
	_gameStatus = status;
}

void CaroGamePlay::increaseTurnCount(int value) {
	_turnCount += value;
}

void CaroGamePlay::setWinningLine(const std::vector<std::pair<int, int>>& winningLine) {
	_winningLine = winningLine;
}

std::vector<std::pair<int, int>> CaroGamePlay::winningLine() {
	return instance()->_winningLine;
}

void CaroGamePlay::reset() {
	for (int i = 0; i < _playBoard->height(); i++) {
		for (int j = 0; j < _playBoard->width(); j++) {
			_playBoard->setValue(i, j, ' ');
		}
	}

	_playerTurnTextBox;
	_playerInTurn = nullptr;
	_gameStatus = CARO_IS_PLAYING;
	_turnCount = 0;
	_winningLine = {};
}

void CaroGamePlay::play() {
	InitWindow(1200, 900, "Caro Game");
	std::string backgroundSource = "textures\\main_background.png";
	Texture2D background = LoadTexture(backgroundSource.c_str());

	ObjectHandlerFactory::config();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, WHITE);

		_playerInTurn = _players[_turnCount % _players.size()];

		_playerTurnTextBox->onGamePlay();
		_playBoard->onGamePlay();
		_resetButton->onGamePlay();
		_exitButton->onGamePlay();

		EndDrawing();

		if (_gameStatus == CARO_EXIT) {
			quit();
			break;
		}
	}

	UnloadTexture(background);
	CloseWindow();
}

void CaroGamePlay::quit() {
	while (!_players.empty()) {
		delete _players.back();
		_players.pop_back();
	}
	delete _playBoard;
	delete _resetButton;
	delete _exitButton;
}

std::string CaroGamePlay::gameName() {
	return "Caro";
}