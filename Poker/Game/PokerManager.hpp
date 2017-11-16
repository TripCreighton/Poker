//
//  Poker.hpp
//  Poker
//
//  Created by Trip Creighton on 11/1/17.
//  Copyright © 2017 Trip Creighton. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
//#include <algorithm>
#include "Serializer.hpp"

using namespace std;

// Create templates so I can use them throughout every class:
class Player;
class Card;
class Poker;

enum HandType {
    RoyalFlush,
    StraightFlush,
    FourPairs,
    FullHouse,
    Flush,
    Straight,
    ThreePairs,
    TwoPairs,
    SinglePair,
    NoPair
};

class Player {
private:
    vector<Card> _ownedCards;
public:
    HandType handType;
    bool isDealer = false;
    int matchCount = 0;
    string name = "";
    int id = 0;
    void addCard(Card);
    void updateOwnedCards(vector<Card> newCards) { _ownedCards = newCards; }
    vector<Card> getOwnedCards() { return _ownedCards; }
};

enum CardType {
    King,
    Queen,
    Number,
    Jack,
    Joker,
    Ace
};

class Card {
public:
    CardType cardType;
    Player cardOwner;
    int cardNumber = -1;
    char identifier;
    bool hasMatch = false;
};

class Poker {
private:
    int _queenCount = 0;
    int _kingCount = 0;
    int _aceCount = 0;
    int _jackCount = 0;
    int _playerCount = 0;
    int _cardCount = 5;
    Player _dealer;
    vector<Player> _playerList;
    vector<Card> _cardList;
public:
    Poker(int = 5);
    void dealCards();
    void checkCards(Player&);
    void addPlayer(string);
    vector<Player> getPlayerList() { return _playerList; }
};
