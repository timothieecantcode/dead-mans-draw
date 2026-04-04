#include "HookCard.h"
#include <vector>
#include <iostream>

HookCard::HookCard(int value) : Card(value, CardType::Hook) {}

void HookCard::play(Game& game, Player& player) {
    std::vector<Card*> selectableCards = player.getTopCardsPerSuit();
    int i = 1;
    int choice;
    if (selectableCards.empty()) {
        std::cout << "No cards in your Bank. Play continues." << std::endl;
        return;
    }
    std::cout << "Select a highest-value card from any of the suits in your Bank:" << std::endl;
    for (Card* card : selectableCards) {
        std::cout << "(" << i << ") " << card->getStr() << std::endl;
        ++i;
    }
    std::cout << "Which card do you pick? ";
    std::cin >> choice;
    while (choice < 1 || choice > static_cast<int>(selectableCards.size())) {
        std::cout << "Which card do you pick? ";
        std::cin >> choice;
    }
    std::cout << std::endl;
    Card* selectedCard = selectableCards[choice - 1];
    std::cout << player.getName() << " draws a " << selectedCard->getStr() << std::endl;
    player.removeFromBank(selectedCard);
    player.playCard(selectedCard);
}

std::string HookCard::getStr() const {
    return "Hook(" + std::to_string(getValue()) + ")";
}