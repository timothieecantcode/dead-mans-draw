#include "ChestCard.h"
#include <iostream>

ChestCard::ChestCard(int value) : Card(value, CardType::Chest) {}

void ChestCard::play(Game& game, Player& player) {
    std::cout << " No immediate effect. If banked with a key, draw as many bonus cards from the Discard Pile as you moved into your Bank." << std::endl;
    willAddToBank(game, player);
}

void ChestCard::willAddToBank(Game& game, Player& player) {
    bool withKey = false;
    for (Card* c : player.getPlayArea()) {
        if (c->getType() == CardType::Key) {
            withKey = true;
            break;
        }
    }

    if (!withKey) {
        return;
    }
    std::cout << " Chest and Key activated. Added ";

    for (size_t i = 0; i < player.getPlayArea().size(); ++i) {
        Card* c = game.drawFromDiscardPile();
        if (c == nullptr) {
            break;
        }
        player.addToBank(c);
    }
}

std::string ChestCard::getStr() const {
    return "Chest(" + std::to_string(getValue()) + ")";
}