//
//  main.cpp
//  Poker
//
//  Created by Trip Creighton on 11/1/17.
//  Copyright © 2017 Trip Creighton. All rights reserved.
//

#include <iostream>
#include "PokerManager.hpp"

int main(int argc, const char * argv[]) {
    Poker poker;
    poker.addPlayer("trip");
    poker.addPlayer("bob");
    poker.addPlayer("bossb");
    poker.dealCards();
    std::vector<Player> playerList = poker.getPlayerList();
    
    for (int i = 0; i < playerList.size(); i++) {
        Player p = playerList[i];
        poker.checkCards(p);
        std::vector<Card> cardList = p.getOwnedCards();
        std::cout << "Name: " << p.name << " / dealer? " << p.isDealer << " / Card Count: " << cardList.size() << " / Match count: " << p.matchCount << endl;
        for (int j = 0; j < cardList.size(); j++) {
            Card card = cardList[j];
            std::cout << "Owner of card: " << card.cardOwner.name << " Card number: " << card.cardNumber << " Identifier: " << card.identifier << std::endl;
        }
    }
    return 0;
}
