#ifndef MAPCARD_H
#define MAPCARD_H

#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <string>

class MapCard : public Card {
public:
    /// Construct a MapCard with a value
    MapCard(int value);

    /// Draw 3 cards from the player's discard pile. Must play one of those card
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};
#endif
