#include "SwordCard.h"

SwordCard::SwordCard(int value) : Card(value, CardType::Sword) {}

void SwordCard::play(Game& game, Player& player) {
    int input;
    int i = 1;
    std::vector<Card*> selectableCards;
    Player* opponent = game.getOpponent(player);
    selectableCards = opponent->getTopCardsPerSuit();
    if (selectableCards.empty()) {
        std::cout << "No cards in other player's Bank. Play continues" << std::endl;
        return;
    }
    std::cout << "Steal the top card of any suit from the other player's Bank into your playArea:" << std::endl;
    for (Card* card : selectableCards) {
        std::cout << "(" << i << ") " << card->getStr() << std::endl;
        ++i;
    }
    std::cout << "Which card do you pick? ";
    std::cin >> input;
    while (input < 1 || input > selectableCards.size()) {
        std::cout << "Which card do you pick? ";
        std::cin >> input;
    }
    std::cout << std::endl;
    Card* selectedCard = selectableCards[input - 1];
    opponent->removeFromBank(selectedCard);
    player.playCard(selectedCard);
}

std::string SwordCard::getStr() const {
    return "Sword(" + std::to_string(getValue()) + ")";
}