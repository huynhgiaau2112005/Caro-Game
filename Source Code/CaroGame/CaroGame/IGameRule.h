#ifndef _I_GAME_RULE_H_
#define _I_GAME_RULE_H_

#include <string>
class IGameRule {
public:
	virtual std::string gameName() = 0;
};

#endif