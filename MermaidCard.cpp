#include "MermaidCard.h"
#include <string>
#include <iostream>

MermaidCard::MermaidCard(int value) : Card(value, CardType::Mermaid) {}

void MermaidCard::play(Game& game, Player& player) {
    std::cout << "\tNo effect but Mermaids are worth more." << std::endl;
}

std::string MermaidCard::getStr() const {
    return "Mermaid(" + std::to_string(getValue()) + ")";
}