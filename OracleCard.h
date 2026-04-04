#ifndef ORACLECARD_H
#define ORACLECARD_H

#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <string>

class OracleCard : public Card {
public:
    /// Construct an OracleCard with a value
    OracleCard(int value);

    /// Peek at the top card of the deck before choosing whether to draw
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
