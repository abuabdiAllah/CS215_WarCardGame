/*
* NOTE: Card games are usually a waste of time and not befitting for someone
* to use their time with. This program is assumming that this card game DOES NOT have images of living
* beings like kings and queens. Otherwise, I would never play such a game as a Muslim, thanks!
* 
* 
* 
 * Course: CS215-006
 * Project: Project 3
 * Purpose: To simulate "war" card game between two players. Read Note above. 
 *
 */
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main()
{
    // Avoid invalid numbers
    const int HANDS = 26;    // each player holds 52/2 = 26 cards to begin the game

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // remove comment from line 47 to shuffle in shaa Allah
    Deck testDeck;
    testDeck.createDeck();
    //testDeck.shuffleDeck();

    
    vector<Card> cards_for_Player1;
    vector<Card> cards_for_Player2;
    vector<Card> pile;

    //Deal half of the cards to each player
    for (int i = 0; i < HANDS; i++)
    {
        cards_for_Player1.push_back(testDeck.deal_a_card());
        cards_for_Player2.push_back(testDeck.deal_a_card());
    }

    // create objects for both players, play one card, and display it
    Player testPlayer1(cards_for_Player1);
    Player testPlayer2(cards_for_Player2);

    string nextRound;
    bool endGame = false;
    do
    {
        cout << "Player 1 plays: ";
        Card faceup1 = testPlayer1.play_a_card();
        faceup1.print();
        cout << endl;

        cout << "Player 2 plays: ";
        Card faceup2 = testPlayer2.play_a_card();
        faceup2.print();
        cout << endl<<endl;

        cout << "--------------------------------------------------------------------" << endl<<endl;

        //put inital two cards in pile vector and out put size of pile
        pile.push_back(faceup1);
        pile.push_back(faceup2);
        cout << "There are " << pile.size() << " cards on the pile!" << endl<<endl;
        
        cout << "--------------------------------------------------------------------" <<endl;

        //decide winner/tie
        if (faceup1.compareTo(faceup2) != 0) //not a tie
        {
            if (faceup1.compareTo(faceup2) == 1) //player 1 wins
            {
                cout << "Player 1 wins...they get all cards from the pile in shaa Allah!" << endl;
                testPlayer1.addCards(pile); //player1 adds the two cards in the pile to their cards
                pile.clear(); //empty pile
            }
            else //==-1, player 2 wins
            {
                cout << "Player 2 wins...they get all cards from the pile in shaa Allah!" << endl;
                testPlayer2.addCards(pile); //player2 adds the two cards in the pile to their cards
                pile.clear();
            }
        }
        else //is a tie
        {
            cout << "It is a tie...for this round!" << endl;
            cout << "Each player drops three cards (face down) on the pile, then " << endl << "play one more card (face up)" << endl;
            vector<Card> player1Drop = testPlayer1.dropCards(); //make a vector that saves the returned vector from the dropCards()
            vector<Card> player2Drop = testPlayer2.dropCards(); //do same thing for player two^
            if (player1Drop.size() == 0 || player2Drop.size() == 0) //check if the game ended by one or both player not having enough cards to complete war, meaning they either have 2,1, or 0 cards
            {
                cout << "Game is over!" << endl;
                if (player1Drop.size() == 0 && player2Drop.size() == 0)
                {
                    cout << "It is a tie game!" << endl;
                }
                else if (player1Drop.size() == 0)//player2 still had enough to complete war
                {
                    cout << "Player 2 wins the game!" << endl;
                }
                else //player2 did not have enough
                {
                    cout << "Player 1 wins the game!" << endl;
                }
                cout << "Player1 has " << testPlayer1.getNumCards() << " cards in hand!" << endl; //according to them, these cards that were not sufficient for war are still considered in your hand! However, in reality, the numCards should be zero because you would have put down any cards you had. 
                cout << "Player2 has " << testPlayer2.getNumCards() << " cards in hand!" << endl;
                break; //ends program bi idni Allah 
            }
            for (int i = 0; i < 3; i++) //add the cards dropped by player1 into the pile vector
            {
                pile.push_back(player1Drop[i]);
            }
            for (int i = 0; i < 3; i++)//""
            {
                pile.push_back(player2Drop[i]);
            }
            cout << "--------------------------------------------------------------------" << endl << endl;
            cout << "There are " << pile.size() << " cards on the pile!" << endl << endl;
            cout << "--------------------------------------------------------------------" << endl << endl;
        }

        cout << "Player1 has " << testPlayer1.getNumCards() << " cards in hand!" << endl;
        cout << "Player2 has " << testPlayer2.getNumCards() << " cards in hand!" << endl;
        cout << endl << endl;


        //check if game ended by one of players running out of cards normally
        if (testPlayer1.getNumCards() == 0 || testPlayer2.getNumCards() == 0) //game ended as a tie
        {
            cout << "Game is over!" << endl;
            if (testPlayer1.getNumCards() == 0 && testPlayer2.getNumCards() == 0)
            {
                cout << "It is a tie game!" << endl;
            }
            else if (testPlayer1.getNumCards() == 0) //Player 1 loses
            {
                cout << "Player 2 wins the game!" << endl;
            }
            else //Player 2 loses
            {
                cout << "Player 1 wins the game!" << endl;
            }
            break;
        }


        //Comment out block for TestingCase Three: 
        ///*
        cout << "Do you want to continue...for the next round? (N or n to quit) ";
        getline(cin,nextRound);
        if ((nextRound == "n") || (nextRound == "N"))
        {
            cout << "You chose to quit the game!" << endl;
            cout << "Player1 has " << testPlayer1.getNumCards() << " cards left!" << endl;
            cout << "Player2 has " << testPlayer2.getNumCards() << " cards left!" << endl;
            endGame = true;
        }
        //*/

    } while (!endGame);
    return 0;
}
