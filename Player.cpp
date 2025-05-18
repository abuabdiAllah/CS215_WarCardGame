/* File: player.cpp
 * Course: CS215-00x
 * Project: Project 3
 * Purpose: the implementation of member functions for the player class.
 * Author: (your name)
 */
#include "Player.h"

Player::Player()
{
	numCards = 26;
}


Player::Player(vector<Card> ini_cards)
{
	numCards = ini_cards.size(); //should be always 26, but just trying to be formal
	copy(ini_cards.begin(), ini_cards.end(), std::back_inserter(cards)); //should copy the input vector entries into the player class' "cards" list (https://www.techiedelight.com/convert-vector-list-cpp/)

}

int Player::getNumCards() const
{
	return numCards;
}

Card Player::play_a_card()
{
	//the list cannot be empty to use .front(), I used to use an if statement here to check that but I don't think it is necessary because the program already ends if the size if zero 
		Card faceup(cards.front()); //make object with the first card in the list
		cards.pop_front(); //removes this first card from the list
		numCards = cards.size(); //should be equalivalent to: numCards = numCards - 1;
		return faceup;
	
	/*else
	{
		numCards = 0; //if this doesn't work and it requires a return of card type: have it make an object with the default contructor and return that
	}
	*/
}

void Player::addCards(vector<Card> winningCards)
{
	auto pos = cards.end();
	for (int i = 0; i < winningCards.size(); i++) //the "insert" points to the location after the "end" of the list, so we input the cards in the vector into the end of the list and, thus, make the list bigger by five cards in shaa Allah
	{
		cards.insert(pos, winningCards[i]);
		numCards = cards.size();
	}
}


vector<Card> Player::dropCards()
{
	vector<Card> dropCards(3);//fill the vector with the first three cards from the list while removing them from the list, as long as the list is not empty, return the vector of three cards (an empty vector)
	for (int i = 0; i < 3; i++)
	{
		if (cards.empty()) //the list becomes empty in one of the iterations
		{	
			numCards = i; //numCards are the amount of runs it ran before being empty. 
			dropCards.clear(); //clears one or two cards that may have been added before the list went empty. Now the list is of size zero in shaa Allah
			//cout << "Not enough cards to drop!" << endl;
			break;
		}
		dropCards[i] = cards.front();
		cards.pop_front();
		numCards = cards.size();
	}
	return dropCards;
}

void Player::print() const //prints all cards in hand
{
	for (auto pos = cards.begin(); pos != cards.end(); pos++)
	{
		Card c(*pos); //makes a card object with the card value from the list (suits and points) using constructor
		c.print(); //use print function in Card class
		cout << "\t";
	}
}
