//
//  Poker.cpp
//  Poker
//
//  Created by Trip Creighton on 11/1/17.
//  Copyright © 2017 Trip Creighton. All rights reserved.
//

#include "PokerManager.hpp"

void Player::addCard(Card c) {
    _ownedCards.push_back(c);
}

Poker::Poker(int cardCount) {
    _cardCount = cardCount;
    
    // Build the dealer:
    Player dealer;
    dealer.isDealer = true;
    dealer.name = "Dealer";
    dealer.id = 0;
    _dealer = dealer;
}

void Poker::addPlayer(string name) {
    // Check if the player already exists:
    for (int i = 0; i < _playerList.size(); i++) {
        // Convert name to uppercase:
        string playerName = _playerList[i].name;
        for (auto & c: playerName) c = toupper(c);
        string requestedName = name;
        for (auto & c: requestedName) c = toupper(c);
        
        // Compare names:
        if (playerName == requestedName) {
            cout << "That player already exists!" << endl;
            return;
        }
    }
    
    Player player;
    player.name = name;
    player.id = (int)_playerList.size();
    _playerList.push_back(player);
    _playerCount++;
}

void Poker::checkCards(Player &player) {
    vector<Card> ownedCards = player.getOwnedCards();
    vector<int> cardNumbers;
    
    // Get all card numbers:
    for (int i = 0; i < ownedCards.size(); i++) {
        Card card = ownedCards[i];
        cardNumbers.push_back(card.cardNumber);
    }
    
    // Get all basic matchs out of the way:
    if (find(cardNumbers.begin(), cardNumbers.end(), 1) != cardNumbers.end() && find(cardNumbers.begin(), cardNumbers.end(), 13) != cardNumbers.end() && find(cardNumbers.begin(), cardNumbers.end(), 12) != cardNumbers.end() && find(cardNumbers.begin(), cardNumbers.end(), 11) != cardNumbers.end() && find(cardNumbers.begin(), cardNumbers.end(), 10) != cardNumbers.end()) {
        player.handType = HandType::RoyalFlush;
        return;
    } else {
        player.handType = HandType::NoPair;
    }
}

void Poker::dealCards() {
    if (_playerCount <= 1 || _cardCount <= 0) {
        cout << "There is not enough players or cards to play!" << endl;
        return;
    }
    
    // Begin dealing cards:
    srand(time(NULL));
    for (int i = 0; i < _playerCount; i++) {
        for (int j = 0; j < _cardCount; j++) {
            Card card;
            card.cardOwner = _playerList[i];
            
            // Generate random number for card:
            int cardNumber = (rand() % 13) + 1;
            if (cardNumber == 1) {
                if (_aceCount == 4) {
                    i--;
                    continue;
                }
                card.cardType = CardType::Ace;
                card.cardNumber = 1;
                card.identifier = 'A';
                _aceCount++;
            } else if (cardNumber == 11) {
                if (_jackCount == 4) {
                    i--;
                    continue;
                }
                card.cardType = CardType::Jack;
                card.cardNumber = 11;
                card.identifier = 'J';
                _jackCount++;
            } else if (cardNumber == 12) {
                if (_queenCount == 4) {
                    i--;
                    continue;
                }
                card.cardType = CardType::Queen;
                card.cardNumber = 12;
                card.identifier = 'Q';
                _queenCount++;
            } else if (cardNumber == 13) {
                if (_kingCount == 4) {
                    i--;
                    continue;
                }
                card.cardType = CardType::King;
                card.cardNumber = 13;
                card.identifier = 'K';
                _kingCount++;
            } else if (cardNumber <= 10 || cardNumber >= 2) {
                card.cardType = CardType::Number;
                card.cardNumber = cardNumber;
                card.identifier = cardNumber;
            }
            _playerList[i].addCard(card);
        }
    }
}


