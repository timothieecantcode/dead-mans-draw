#include "Game.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include "KrakenCard.h"

#include <algorithm>
#include <random>
#include <ctime>

Game::Game() : currentPlayerIndex(0), round(1) {}

void Game::startGame() {
    srand(time(nullptr));
    _deck.clear();
    _discardPile.clear();
    _players.clear();
    std::cout << "Starting Dead Man's Draw++!" << std::endl;
    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
    Player* player1 = new Player(names[rand() % 10]);
    _players.push_back(player1);
    Player* player2 = new Player(names[rand() % 10]);
    _players.push_back(player2);

    for (CardType type : Card::getAllCardTypes()) {
        for (int i = 2; i <= 7; ++i) {
            switch (type) {
            case CardType::Cannon:
                _deck.push_back(new CannonCard(i));
                break;
            case CardType::Chest:
                _deck.push_back(new ChestCard(i));
                break;
            case CardType::Key:
                _deck.push_back(new KeyCard(i));
                break;
            case CardType::Sword:
                _deck.push_back(new SwordCard(i));
                break;
            case CardType::Hook:
                _deck.push_back(new HookCard(i));
                break;
            case CardType::Oracle:
                _deck.push_back(new OracleCard(i));
                break;
            case CardType::Map:
                _deck.push_back(new MapCard(i));
                break;
            case CardType::Mermaid:
                _deck.push_back(new MermaidCard(i + 2));
                break;
            case CardType::Kraken:
                _deck.push_back(new KrakenCard(i));
                break;
            }
        }
    }
    shuffleDeck(_deck);
    currentPlayerIndex = 0;
    round = 1;
    turn = 1;

    while (!_deck.empty()) {
        playTurn();
    }
    
    Player* winner;
    if (_players[0]->calculateScore() > _players[1]->calculateScore()) {
        winner = _players[0];
    }
    else {
        winner = _players[1];
    }

    std::cout << "--- Game Over ---" << std::endl;
    std::cout << _players[0]->name() << "'s Bank:" << std::endl;
    _players[0]->printDescendingCardsPerSuit();
    std::cout << _players[0]->calculateScore() << std::endl;
    std::cout << _players[1]->name() << "'s Bank:" << std::endl;
    _players[1]->printDescendingCardsPerSuit();
    std::cout << _players[1]->calculateScore() << std::endl;
    std::cout << winner->name() << " wins!" << std::endl;

    for (Player* p : _players) {
        delete p;
    }
    _players.clear();

    for (Card* c : _deck) {
        delete c;
    }
    _deck.clear();
    for (Card* c : _discardPile) {
        delete c;
    }
    _discardPile.clear();
}

void Game::shuffleDeck(std::vector<Card*>& cards) {
    std::vector<Card*> shuffleDeck(cards.begin(), cards.end());
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
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