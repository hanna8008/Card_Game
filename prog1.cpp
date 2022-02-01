/*
Programmer: Hanna Zelis
Date: 9 December 2021
Program: CSC1720 Program 5 - Standard Template Library
Filename: ZelisProgram5.cpp

Description: This program implements a Card Guessing Game where a deck of cards, 52 cards created with a vector, is shuffled and the user can either
	     chose whether to guess the suit or the value of the top card in the deck. Whether or not their suit or value
	     guess is correct, they are told after their first guess what that top card in the deck is and then proceed to the next
	     card in the deck, which becomes the next "top" card (as the last card is then "removed" from the top of the deck).
	     They proceed this guessing game until they have attempted guessing the value or suit of all 52 cards or they tell the 
	     program to stop (by entering 0). 

Assistance Received: N/A

How to compile: g++ ZelisProgram5.cpp -o prog5

How to execute: ./prog5
*/



#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//struct created so that a vector can be created from this data type "createCardDeck" to help create the deck of 52 cards
struct createCardDeck
{
    string cardSuits;
    string cardValues;
};
    vector<createCardDeck> cardDeck(52);








int main()
{
    string value, suit;

    for (int i = 0; i < 52; i++)
    {

        //these if statements determine the suit of the card
        if ((i >= 0) && (i < 13))
            suit = "Hearts";
        if ((i >= 13) && (i < 26))
            suit = "Clubs";
        if ((i >= 26) && (i < 39))
            suit = "Spades";
        if ((i >= 39) && (i < 52))
            suit = "Diamonds";   

 	
        //these if statements give the values for each suit of the card deck
        if ((i >= 0) && (i < 10))
            value = to_string((i + 2));
        if ((i >= 13) && (i < 22))
            value = to_string((i - 11));
        if ((i >= 26) && (i < 35))
            value = to_string((i - 24));
        if ((i >= 39) && (i < 48))
            value = to_string((i - 37));


        if ((i == 10) || (i == 22) || (i == 35) || (i == 48))
            value = "Jack";
        if ((i == 11) || (i == 23) || (i == 36) || (i == 49))
            value = "Queen";
        if ((i == 12) || (i == 24) || (i == 37) || (i == 50))
       	    value = "King";
        if ((i == 13) || (i == 25) || (i == 38) || (i == 51))
    	    value = "Ace";

	//assigns the suit and value of each index of the vector that is type struct "createCardDeck"
  	cardDeck[i].cardValues = value;
        cardDeck[i].cardSuits = suit;

    }




    //this function randomly shuffles the deck of cards
    random_shuffle(cardDeck.begin(), cardDeck.end());



    //this prints out the deck of cards
    /*
    for (int i = 0; i < 52; i++)
    	cout << cardDeck[i].cardValues << " " << cardDeck[i].cardSuits << endl;
    */





    int i = 0;
    
    //This while loop helps ensure that all 52 cards in the deck are ran through if
    //    that is what the user would like to do, go through the whole deck of 52 cards
    //    guessing.
    while (i < 52)
    {    


     	int userChoice;


 	//Every time there is a new card on top to be guessed, the user
	//    will get one of these two options for guessing or the option
	//    to exit the program and finish this card guessing face/value game
	cout << "You have two options (type 1 or 2)" << endl;
	cout << "1. Guess the suit of the top card" << endl;
	cout << "2. Guess the face value of the top card" << endl;
        cout << "0. End/Exit the program" << endl;
        cin >> userChoice;


        cout << endl;


        string userSuit;





	//This while loop is when the user choses they want to guess the top card's
	//    suit. They are told of four options and how they have to be written
	//    If the user gets it right, the card value and suit are revealed and 
	//    the program moves onto the next card in the deck. 
	//    If the user gets it wrong, the card value and suit are still revealed 
	//    but the user just continues onto the next card in the deck (they do not 
	//    keep guessing until they get the correct suit of the top card).
        while (userChoice == 1)
        {
            cout << "Guess suit (Options = Hearts, Clubs, Spades, Diamonds): " << endl;
            cin >> userSuit;
       
	    //This is the part of the suit guessing portion if they get the suit correct
            if (userSuit == cardDeck[i].cardSuits)
	    {
                cout << "You got it! The face of the top (correct) card is: ";
	        cout << cardDeck[i].cardValues << " of " << cardDeck[i].cardSuits << endl;
	        cout << "Time to go to the next card." << endl;
	        i++;
		
		//this helps with spacing to make the output program look nicer
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;

	        break;
   	    } //end of the if statement that is if the user's suit guess is correct
	

	    //This is part of the suit guessing portion if they get the suit wrong
   	    else
	    {
	        cout << "Your guess was incorrect. The face of the top (correct) card is: ";
	        cout << cardDeck[i].cardValues << " of " << cardDeck[i].cardSuits << endl;
	        cout << "Time to go to the next card." << endl;
	        i++;

		//this helps with spacing
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;

	        break;
	    } //end of the if statement that is if the user's suit guess is wrong

        } //end of the while loop: while (userChoice == 1)





        string userValue;

        //This while loop is when the user choses they want to guess the top card's
        //    value. They are told of the 13 options and how they have to be written
        //    If the user gets it right, the card value and suit are revealed and
        //    the program moves onto the next card in the deck.
        //    If the user gets it wrong, the card value and suit are still revealed
        //    but the user just continues onto the next card in the deck (they do not
        //    keep guessing until they get the correct value of the top card).
        while (userChoice == 2)
        {
	    cout << "Guess value (Options: values from 2-10, Jack, Queen, King, Ace): " << endl;
	    cin >> userValue;

            //This is the part of the value guessing portion if they get the value correct
	    if (userValue == cardDeck[i].cardValues)
	    {
	        cout << "You got it! The face of the top (correct) card is: ";
	        cout << cardDeck[i].cardValues << " of " << cardDeck[i].cardSuits << endl;
	        cout << "Time to go to the next card." << endl;
	        i++;

                //this helps with spacing
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
	
	        break;
	    } //end of the if statement that is if the user's value guess is correct



            //This is the part of the value guessing portion if they get the value incorrect
	    else
	    {
	        cout << "Your guess was incorrect. The face of the top (correct) card is: ";
	        cout << cardDeck[i].cardValues << " of " << cardDeck[i].cardSuits << endl;
	        i++;

                //this helps with spacing
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;

	        break;
	    } //end of else statement that is if user the user's value guess is wrong

        } //end of the while loop: while (userChoice == 2)





	//this if statement is a part of the whole while loop that has (i < 52) 
	//    as the argument. If the user inputs 0, the user is saying they want
	//    to be done guessing and so the whole while loop, and hence program, 
	//    will stop.
        if (userChoice == 0)
	    break;

    } //end of the while loop: while (i < 52)



  return 0;

} //end of main function
