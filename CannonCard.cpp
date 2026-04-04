#include "CannonCard.h"
#include <iostream>
#include <string>

CannonCard::CannonCard(int value) : Card(value, CardType::Cannon) {}

void CannonCard::play(Game& game, Player& player) {
    int input;
    int i = 1;
    std::vector<Card*> selectableCards;
    Player* opponent = game.getOpponent(player);
    selectableCards = opponent->getTopCardsPerSuit();
    if (selectableCards.empty()) {
        std::cout << "        No cards in other player's Bank. Play continues." << std::endl;
        return;
    }
    std::cout << "        Shoot the top card of any suit from the other player's Bank into the Discard Pile:" << std::endl;
    for (Card* card : selectableCards) {
        std::cout << "        (" << i << ") " << card->getStr() << std::endl;
        ++i;
    }
    std::cout << "        Which card do you pick? ";
    std::cin >> input;
    while (input < 1 || input > selectableCards.size()) {
        std::cout << "        Which card do you pick? ";
        std::cin >> input;
    }
    Card* selectedCard = selectableCards[input - 1];
    std::cout << "        You shoot the " << selectedCard->getStr() << " out of the other player's Bank" << std::endl;
    opponent->removeFromBank(selectedCard);
    game.addToDiscardPile(selectedCard);
}

std::string CannonCard::getStr() const {
    return "Cannon(" + std::to_string(getValue()) + ")";
}