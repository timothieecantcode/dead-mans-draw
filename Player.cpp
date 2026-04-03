#include "Player.h"

Player::Player(const std::string& name) : _name(name) {}

bool Player::playCard(Card* card) {
    _playArea.push_back(card);
    return isBust();
}

bool Player::isBust() const {
    //double loop to compare every pair of cards to check for duplicate
    for (size_t i = 0; i < _playArea.size(); i++) {
        for (size_t j = i + 1; j < _playArea.size(); j++) {
            if (_playArea[i]->type() == _playArea[j]->type()) {
                return true;
            }
        }
    }
    return false;
}

void Player::bankCards() {
    for (Card* card : _playArea) {
        _bank.push_back(card);
    }
    clearPlayArea();
}

void Player::clearPlayArea() {
    _playArea.clear();
}

const std::string& Player::getName() const {
    return _name;
}

const std::vector<Card*>& Player::getPlayArea() const {
    return _playArea;
}

const std::vector<Card*>& Player::getBank() const {
    return _bank;
}

void Player::removeFromBank(Card* targetCard) {
    for (auto i = _bank.begin(); i != _bank.end(); ++i) {
        if (*i == targetCard) {
            _bank.erase(i);
            break;
        }
    }
}

void Player::printPlayArea() const {
    for (Card* c : _playArea) {
        std::cout << c->str() << std::endl;
    }
}

void Player::printDescendingCardsPerSuit() const {
    for (CardType type : Card::getAllCardTypes()) {
        std::vector<Card*> tempBank;
        for (Card* card : _bank) {
            if (card->type() == type) {
                tempBank.push_back(card);
            }
        }
        if (!tempBank.empty()) {
            //sort the suit in descending order based on card value
            std::sort(tempBank.begin(), tempBank.end(), [](const Card* a, const Card* b) {
                return a->value() > b->value();});
            for (Card* card : tempBank) {
                std::cout << card->str() << " ";
            }
            std::cout << std::endl;
        }
    }
}

std::vector<Card*> Player::getTopCardsPerSuit() const {
    std::vector<Card*> selectableCards;
    for (CardType type : Card::getAllCardTypes()) {
        std::vector<Card*> tempBank;
        for (Card* card : _bank) {
            if (card->type() == type) {
                tempBank.push_back(card);
            }
        }
        if (!tempBank.empty()) {
            //sort the suit in descending order based on card value
            std::sort(tempBank.begin(), tempBank.end(), [](const Card* a, const Card* b) {
                return a->value() > b->value();});
            selectableCards.push_back(tempBank[0]);
        }
    }
    return selectableCards;
}