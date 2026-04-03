#include "KeyCard.h"

KeyCard::KeyCard(int value) : Card(value, CardType::Key) {}

void KeyCard::play(Game& game, Player& player) {
    //no effect
}

std::string KeyCard::getStr() const {
    return "Key(" + std::to_string(getValue()) + ")";
}