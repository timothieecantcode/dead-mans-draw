#ifndef MERMAIDCARD_H
#define MERMAIDCARD_H

#include "Game.h"
#include "Card.h"
#include "Player.h"

class MermaidCard : public Card {
public:
    /// Construct a MermaidCard with a value
    MermaidCard(int value);

    /// Mermaid has no effect when played
    void play(Game& game, Player& player) override;

    std::string getStr() const override;
};

#endif
