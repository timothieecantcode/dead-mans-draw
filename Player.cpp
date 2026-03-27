#include "Player.h"

Player::Player(const std::string& name) : _name(name) {}

bool Player::playCard(Card* card) {
    _playArea.push_back(card);
    return isBust();
}

bool Player::isBust() const {
    //double loop to compare every pair of cards to check for duplicate
    for (size_t i = 0; i < _playArea.size(); i++) {
        for (size_t j = i+1; j < _playArea.size(); j++) {
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

const std::string& Player::name() const {
    return _name;
}

const std::vector<Card*>& Player::playArea() const {
    return _playArea;
}

const std::vector<Card*>& Player::bank() const {
    return _bank;
}
