#include "Game.h"

Game::Game() : currentPlayerIndex(0), round(1) {}

void Game::startGame() {

    for (CardType type : types) {
        
    }

}







Player* Game::getOpponent(Player& player) {
    if (&player == _players[0]) {
        return _players[1];
    }
    return _players[0];
}

void Game::addToDiscardPile(Card* card) {
    _discardPile.push_back(card);
}