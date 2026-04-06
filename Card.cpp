#include "Card.h"

Card::Card(int value, CardType type) : _value(value), _type(type) {}

const CardType& Card::getType() const {
    return _type;
}

int Card::getValue() const {
    return _value;
}

const std::vector<CardType>& Card::getAllCardTypes() {
    static std::vector<CardType> types = {
        CardType::Cannon,
        CardType::Chest,
        CardType::Key,
        CardType::Sword,
        CardType::Hook,
        CardType::Oracle,
        CardType::Map,
        CardType::Mermaid,
        CardType::Kraken };

    return types;
}