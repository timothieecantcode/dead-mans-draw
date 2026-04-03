#include "MermaidCard.h"

MermaidCard::MermaidCard(int value) : Card(value, CardType::Mermaid) {}

void MermaidCard::play(Game& game, Player& player) {
    //no effect
}

std::string MermaidCard::getStr() const {
    return "Mermaid(" + std::to_string(getValue()) + ")";
}