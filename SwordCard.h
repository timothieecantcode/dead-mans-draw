#ifndef SWORDCARD_H
#define SWORDCARD_H

#include "Game.h"
#include "Card.h"
#include "Player.h"

class SwordCard : public Card {
public:
    /// Construct a SwordCard with a value
    SwordCard(int value);

    /// Steal the highest value of any suit from the other player's Bank and add it to your playArea
    void play(Game& game, Player& player) override;
};

#endif
