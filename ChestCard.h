#ifndef CHESTCARD_H
#define CHESTCARD_H

#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <string>

class ChestCard : public Card {
public:
    /// Construct a ChestCard with a value
    ChestCard(int value);

    /// Chest has no immediate effect when played
    void play(Game& game, Player& player) override;

    /// If banked with a Key card, draw bonus cards from the Discard Pile
    /// equal to the number of cards moved into the bank
    void willAddToBank(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
