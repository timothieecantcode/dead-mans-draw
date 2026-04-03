#ifndef CANNONCARD_H
#define CANNONCARD_H

#include "Game.h"
#include "Card.h"
#include "Player.h"

class CannonCard : public Card {
public:
    /// Construct a CannonCard with a value
    CannonCard(int value);

    /// Discard the highest value of any suit from the other player's Bank to the Discard Pile
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
