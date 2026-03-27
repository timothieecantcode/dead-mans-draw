#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Player {
protected:
    std::string _name;
    std::vector<Card*> _playArea;
    std::vector<Card*> _bank;
public:
    /// Construct a player with a name
    Player(const std::string& name);

    /// Add a card to playArea
    /// Return true if player busts otherwise return false
    bool playCard(Card* card);

    /// Check if play area has duplicate card types
    bool isBust() const;

    /// Move all cards from playArea to bank
    void bankCards();

    /// Cauculate score based on highest card per suit
    int calculateScore() const;

    /// Clears playArea after bust or banking
    void clearPlayArea();

    /// Return player's name
    const std::string& name() const;

    /// Return playArea
    const std::vector<Card*>& playArea() const;

    /// Return bank
    const std::vector<Card*>& bank() const;
};

#endif