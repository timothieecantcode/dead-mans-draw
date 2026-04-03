#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

class Game;
class Player;

/// Represents the type of card
enum class CardType {
    Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken
};

/// Abstract base class for all cards
class Card {
protected:
    int _value;
    CardType _type;

public:
    /// Construct a card with a value and a type
    Card(int value, CardType type);

    /// Virtual destructor for proper cleanup
    virtual ~Card() = default;

    /// Play the card's ability
    virtual void play(Game& game, Player& player) = 0;

    /// Called before the card is added to the bank
    virtual void willAddToBank(Game& game, Player& player);

    /// Return a string representation of the card
    virtual std::string getStr() const = 0;

    /// Return the cardtype of a card
    const CardType& getType() const;

    /// Return all card types
    static const std::vector<CardType>& getAllCardTypes();

    /// Return card value
    int getValue() const;

};

#endif