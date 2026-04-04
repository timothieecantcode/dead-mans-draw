#ifndef KRAKENCARD_H
#define KRAKENCARD_H

#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <string>

class KrakenCard : public Card {
public:
    /// Construct a KrakenCard with a value
    KrakenCard(int value);

    /// Draw and play 3 cards consecutively
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
