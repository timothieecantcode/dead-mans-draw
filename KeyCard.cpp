#include "KeyCard.h"
#include <iostream>

KeyCard::KeyCard(int value) : Card(value, CardType::Key) {}

void KeyCard::play(Game& game, Player& player) {
    std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.";
}

std::string KeyCard::getStr() const {
    return "Key(" + std::to_string(getValue()) + ")";
}