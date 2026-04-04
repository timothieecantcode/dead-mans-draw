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
#include <vector>
#include <iostream>

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
    std::cout << _players[0]->getName() << "'s Bank:" << std::endl;
    _players[0]->printDescendingCardsPerSuit();
    std::cout << _players[0]->calculateScore() << std::endl;
    std::cout << _players[1]->getName() << "'s Bank:" << std::endl;
    _players[1]->printDescendingCardsPerSuit();
    std::cout << _players[1]->calculateScore() << std::endl;
    std::cout << winner->getName() << " wins!" << std::endl;

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

void Game::playTurn() {
    std::cout << "--- Round " << round << ", Turn " << turn << " ---" << std::endl;
    Player* player = _players[currentPlayerIndex];

    while (true) {
        std::cout << player->getName() << "'s turn," << std::endl;
        player->printDescendingCardsPerSuit();
        std::cout << " |  Score: " << player->calculateScore() << std::endl;

        Card* card = drawCard();
        std::cout << player->getName() << " draws a " << card->getStr() << std::endl;
        bool bust = player->playCard(card);

        if (bust) {
            std::cout << "BUST! " << player->getName() << " loses all cards in play area." << std::endl;
            for (Card* c : player->getPlayArea()) {
                addToDiscardPile(c);
            }
            player->clearPlayArea();
            switchPlayer();
            ++turn;
            if (turn % 2 == 1) {
                ++round;
            }
            return;
        }
        card->play(*this, *player);
        std::cout << player->getName() << "'s Play Area:" << std::endl;
        player->printPlayArea();

        char choice;
        std::cout << "Draw again? (y/n) : ";
        std::cin >> choice;
        while (choice != 'n' && choice != 'y') {
            std::cin >> choice;
        }
        if (choice == 'n') {
            player->bankCards();
            switchPlayer();
            ++turn;
            if (turn % 2 == 1) {
                ++round;
            }
            return;
        }
    }
}

Card* Game::drawCard() {
    if (_deck.empty()) {
        return nullptr;
    }
    Card* card = _deck.back();
    _deck.pop_back();
    return card;
}

void Game::shuffleDeck(std::vector<Card*>& cards) {
    std::vector<Card*> shuffleDeck(cards.begin(), cards.end());
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

void Game::switchPlayer() {
    currentPlayerIndex = 1 - currentPlayerIndex;
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

Card* Game::drawFromDiscardPile() {
    if (_discardPile.empty()) {
        return nullptr;
    }

    Card* card = _discardPile.back();
    _discardPile.pop_back();
    return card;
}

Card* Game::getTopCardInDeck() {
    if (_deck.empty()) {
        return nullptr;
    }
    return _deck.back();
}