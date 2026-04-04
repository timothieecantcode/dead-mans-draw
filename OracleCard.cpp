#include "OracleCard.h"
#include <vector>
#include <iostream>
#include <string>

OracleCard::OracleCard(int value) : Card(value, CardType::Oracle) {}

void OracleCard::play(Game& game, Player& player) {
    Card* card = game.getTopCardInDeck();
    if (card == nullptr) {
        return;
    }
    std::cout << "The Oracle sees a " << card->getStr() << std::endl;
}

std::string OracleCard::getStr() const {
    return "Oracle(" + std::to_string(getValue()) + ")";
}