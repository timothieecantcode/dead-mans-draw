#include "KrakenCard.h"
#include <iostream>

KrakenCard::KrakenCard(int value) : Card(value, CardType::Kraken) {}

void KrakenCard::play(Game& game, Player& player) {
    std::cout << "        Draw 3 cards from the deck and play each:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        Card* c = game.drawCard();
        if (c == nullptr) {
            return;
        }
        std::cout << player.getName() << " draws a " << c->getStr() << std::endl;
        bool bust = player.playCard(c);
        if (bust) {
            return;
        }
        c->play(game, player);
    }
}

std::string KrakenCard::getStr() const {
    return "Kraken(" + std::to_string(getValue()) + ")";
}