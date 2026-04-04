#ifndef KEYCARD_H
#define KEYCARD_H

#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <string>

class KeyCard : public Card {
public:
    /// Construct a KeyCard with a value
    KeyCard(int value);

    /// Key has no immediate effect when played
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
