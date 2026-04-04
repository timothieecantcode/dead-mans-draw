#include "MapCard.h"
#include <iostream>

MapCard::MapCard(int value) : Card(value, CardType::Map) {}

void MapCard::play(Game& game, Player& player) {
    std::vector<Card*> selectableCards;
    int choice;
    for (int i = 0; i < 3; ++i) {
        Card* card = game.drawFromDiscardPile();
        if (card == nullptr) break;
        selectableCards.push_back(card);
    }
    if (selectableCards.empty()) {
        std::cout << "No cards in the discard. Play continues." << std::endl;
        return;
    }
    for (size_t i = 0; i < selectableCards.size(); ++i) {
        Card* c = selectableCards[i];
        std::cout << "(" << i + 1 << ") " << c->getStr() << std::endl;
    }
    std::cout << "Which card do you pick? ";
    std::cin >> choice;
    while (choice < 1 || choice > static_cast<int>(selectableCards.size())) {
        std::cout << "Which card do you pick? ";
        std::cin >> choice;
    }
    std::cout << std::endl;
    Card* selectedCard = selectableCards[choice - 1];
    for (Card* c : selectableCards) {
        if (c != selectedCard) {
            game.addToDiscardPile(c);
        }
    }
    std::cout << player.getName() << " draws a " << selectedCard->getStr() << std::endl;
    player.playCard(selectedCard);
}

std::string MapCard::getStr() const {
    return "Map(" + std::to_string(getValue()) + ")";
}