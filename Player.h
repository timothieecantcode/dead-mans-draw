#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "Game.h"

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

    /// Check if play area has any duplicate suit (is busted)
    bool isBust() const;

    /// Move all cards from playArea to bank
    void bankCards(Game& game);

    /// Cauculate score based on highest card per suit
    int calculateScore() const;

    /// Clears playArea after bust or banking
    void clearPlayArea();

    /// Return player's name
    const std::string& getName() const;

    /// Return playArea
    const std::vector<Card*>& getPlayArea() const;

    /// Return bank
    const std::vector<Card*>& getBank() const;

    /// Remove a card from the player's bank
    void removeFromBank(Card* targetCard);

    /// Print player's Play Area
    void printPlayArea() const;

    /// Print the descending order of cards of each suit in the player's bank
    void printDescendingCardsPerSuit() const;

    /// Return the highest value card of each suit in the player's bank
    std::vector<Card*> getTopCardsPerSuit() const;

    /// Add a card to bank (use for ability like chest + key)
    void addToBank(Card* card);
};

#endif