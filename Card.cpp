#include "Card.h"

Card::Card(int value, CardType type) : _value(value), _type(type) {}

void Card::willAddToBank(Game& game, Player& player) {
    //default: do nothing, can be overridden by derived classes
}

const CardType& Card::type() const {
    return _type;
}

int Card::value() const {
    return _value;
}