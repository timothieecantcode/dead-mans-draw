#include "ChestCard.h"

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

    int count = player.getPlayArea().size();
    std::cout << " Chest and Key activated. Added ";
    for (int i = 0; i < count; ++i) {
        Card* c = game.drawFromDiscardPile();
        if (c == nullptr) {
            break;
        }
        player.addToBank(c);
    }
}

std::string ChestCard::getStr() const {
    return " Chest(" + std::to_string(getValue()) + ")";
}