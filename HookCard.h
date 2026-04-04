#ifndef HOOKCARD_H
#define HOOKCARD_H

#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <string>

class HookCard : public Card {
public:
    /// Construct a HookCard with a value
    HookCard(int value);

    /// Play a highest value card of any suit in the player's bank to play area
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
