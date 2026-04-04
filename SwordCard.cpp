#include "SwordCard.h"
#include <vector>
#include <iostream>

SwordCard::SwordCard(int value) : Card(value, CardType::Sword) {}

void SwordCard::play(Game& game, Player& player) {
    int choice;
    int i = 1;
    std::vector<Card*> selectableCards;
    Player* opponent = game.getOpponent(player);
    selectableCards = opponent->getTopCardsPerSuit();
    if (selectableCards.empty()) {
        std::cout << "        No cards in other player's Bank. Play continues." << std::endl;
        return;
    }
    std::cout << "        Steal the top card of any suit from the other player's Bank into your playArea:" << std::endl;
    for (Card* card : selectableCards) {
        std::cout << "        (" << i << ") " << card->getStr() << std::endl;
        ++i;
    }
    std::cout << "        Which card do you pick? ";
    std::cin >> choice;
    while (choice < 1 || choice > static_cast<int>(selectableCards.size())) {
        std::cout << "        Which card do you pick? ";
        std::cin >> choice;
    }
    std::cout << std::endl;
    Card* selectedCard = selectableCards[choice - 1];
    std::cout << player.getName() << " draws a " << selectedCard->getStr() << std::endl;
    opponent->removeFromBank(selectedCard);
    bool bust = player.playCard(selectedCard);
    if (bust) {
        return;
    }
    selectedCard->play(game, player);
}

std::string SwordCard::getStr() const {
    return "Sword(" + std::to_string(getValue()) + ")";
}