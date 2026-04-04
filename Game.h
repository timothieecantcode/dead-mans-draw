#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Player.h"
#include <vector>

class Game {
protected:
    std::vector<Card*> _deck;
    std::vector<Card*> _discardPile;
    std::vector<Player*> _players;
    int currentPlayerIndex;
    int round;
    int turn;
public:
    Game();
    ~Game();
    /// Initialise the game with a deck of cards and 2 players
    void startGame();

    /// Runs one player's turn
    void playTurn();

    /// Give the player the card on top of the deck
    Card* drawCard();

    /// Change te current player to the next player
    void switchPlayer();

    /// End the game
    void endGame();

    /// Shuffle the deck
    void shuffleDeck(std::vector<Card*>& cards);

    /// Return opponent player
    Player* getOpponent(Player&);

    /// Add a card to the discard pile
    void addToDiscardPile(Card* card);

    /// Draw a card from the discard pile
    Card* drawFromDiscardPile();

    /// Return a top card of the deck
    Card* getTopCardInDeck();
};

#endif
