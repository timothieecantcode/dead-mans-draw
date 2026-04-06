#include "ChestCard.h"
#include <iostream>

ChestCard::ChestCard(int value) : Card(value, CardType::Chest) {}

void ChestCard::play(Game& game, Player& player) {
    std::cout << "\tNo immediate effect. If banked with a key, draw as many bonus cards from the Discard Pile as you moved into your Bank." << std::endl;
}

std::string ChestCard::getStr() const {
    return "Chest(" + std::to_string(getValue()) + ")";
}