#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;
/*

1: Ace - needs to be a 1 if the sum will break 21 and 11 otherwise
2: 2 card - value of 2
3: 3 card - value of 3
4: 4 card - value of 4
5: 5 card - value of 5
6: 6 card - value of 6
7: 7 card - value of 7
8: 8 card - value of 8
9: 9 card - value of 9
10: 10 card - value of 10
11: Jack - value of 10
12: Queen - value of 10
13: King - value of 10

RULES:
Blackjack is played with 1-8 decks; typically this is left up to the casinos, but
in this version the player will select.

*/

int main()
{
vector <string> card;
vector <string> suit;
int num_decks;
int gamestart;
int current[15];
int outcome[2];
int difficulty = 0;
double cash;
double chance_hit = 0;

cout << "How many Decks? Enter a number 1-8: " << endl;
cin >> num_decks;
while ((num_decks > 8) || (num_decks < 1))
	{
		cout << "Invalid input; enter a number 1-8" << endl;
		cin >> num_decks;
	}

srand(time(0));
int deck[52*num_decks];

/* 
Now, we create several different for loops to create, shuffle, and organize the 
deck. We first create the deck in an array with however many spaces we will need, 
each with its own numerical value. We then iterate through the deck and adjust 
each number to be between 1 and 52 (thus, each represents a unique card & suit 
combination). We then shuffle the deck with these values, and thus are left with
a deck full of specific card values 1-52. We then take these values and assign
them each a card and suit value. These are the values that we will call when 
playing the game. Face card values are all reassigned to 10.
*/
for (int i=0; i<(52*num_decks); i++) 
 	{
 		deck[i] = (i+1);
 	}
for (int x=0; x<(52*num_decks); x++)
	{
 		while (deck[x] > 52)
 			{
 				deck[x] = deck[x] - 52;
 			}
 	}		
for (int k=0; k<(52*num_decks); k++) 
 	{
        int r = rand() % 52; 
        int temp = deck[k]; 
        deck[k] = deck[r]; 
        deck[r] = temp;
 	}	
 	 		
for (int a=0; a<(52*num_decks); a++)
	{
		int suit_count = 0;
		while (deck[a] > 13)
			{
				deck[a] = deck[a] - 13;
				suit_count++;
			}	
// Assigning Suit value based on place in the deck (determined in above loop)
		if (suit_count == 3) {suit.push_back("Clubs");}
		else if (suit_count == 2) {suit.push_back("Spades");}
		else if (suit_count == 1) {suit.push_back("Diamonds");}
		else if (suit_count == 0) {suit.push_back("Hearts");}

//	Assigning a string card value based on how we adjusted deck[a]
		if (deck[a] == 1) {card.push_back("Ace"); deck[a]=11;}
		else if (deck[a] == 2) {card.push_back("Two");}
		else if (deck[a] == 3) {card.push_back("Three");}
		else if (deck[a] == 4) {card.push_back("Four");}
		else if (deck[a] == 5) {card.push_back("Five");}
		else if (deck[a] == 6) {card.push_back("Six");}
		else if (deck[a] == 7) {card.push_back("Seven");}
		else if (deck[a] == 8) {card.push_back("Eight");}
		else if (deck[a] == 9) {card.push_back("Nine");}
		else if (deck[a] == 10) {card.push_back("Ten");}
		else if (deck[a] == 11) {card.push_back("Jack"); deck[a]=10;}
		else if (deck[a] == 12) {card.push_back("Queen"); deck[a]=10;}
		else if (deck[a] == 13) {card.push_back("King"); deck[a]=10;}
	}
cout << "Please Select Difficulty:" << endl;
cout << "1. Easy (start w/ $100)" << endl;	
cout << "2. Intermediate (start w/ $75)" << endl;	
cout << "3. Hard (start w/ $50)" << endl;	
cout << "4. Shark (start w/ $20)" << endl;	
cin >> difficulty;

while ((difficulty > 4) || (difficulty < 1))
	{cout << "Invalid Input. Please Select difficulty 1-4." << endl; cin >> difficulty;}
if (difficulty == 1) {cash = 100.00;}
else if (difficulty == 2) {cash = 75.00;}
else if (difficulty == 3) {cash = 50.00;}
else if (difficulty == 4) {cash = 20.00;}

cout << "Press 1 to start game, press 0 to quit" << endl;
cin >> gamestart;
while (gamestart != 1)
	{
		if (gamestart == 0) {return 0;}
		else {cout << "Invalid input; enter 1 to play or 0 to quit" << endl;}
	}

int n = 0; // n = number of cards that have been cycled through

//ENTIRE GAMEPLAY == ALL GAMEPLAY AND LOGIC IS CONTAINED WITHIN THIS WHILE LOOP
while ((n != (52*num_decks)) && (cash > 0))
{
	int hit;
	int bet = 0;
	int betval;
	int next_hand = 0;
	int player_aces = 0;
	int dealer_aces = 0;
	
	cout << "*************************************" << endl;
	cout << "*************************************" << endl;
	cout << "How much would you like to bet?" << endl;
	if (cash >= 2) {cout << "1. $2" << endl;}
	if (cash >= 5) {cout << "2. $5" << endl;}
	if (cash >= 10) {cout << "3. $10" << endl;}
	if (cash >= 15) {cout << "4. $15" << endl;}
	if (cash >= 20) {cout << "5. $20" << endl;}
	if (cash >= 50) {cout << "6. $50" << endl;}
	if (cash >= 100) {cout << "7. $100" << endl;}
	cout << "8. All-in" << endl;
	cin >> bet;
	
	while ((bet<1) || (bet>8))
		{
			cout << "Please Enter a Valid Bet." << endl;
			cin >> bet;
		}
		
	if (bet == 1) {betval = 2.00;}
	else if (bet == 2) {betval = 5.00;}
	else if (bet == 3) {betval = 10.00;}
	else if (bet == 4) {betval = 15.00;}
	else if (bet == 5) {betval = 20.00;}
	else if (bet == 6) {betval = 50.00;}
	else if (bet == 7) {betval = 100.00;}
	else if (bet == 8) {betval = cash;}

    cout << "--Dealer has:--" << endl;
    cout << card[n+2] << " of " << suit[n+2] << endl;	
    if (deck[n+2] > 9) {cout << card[n+3] << " of " << suit[n+3] << endl;}
    else {cout << "Card Faced Down." << endl;}
    cout << endl;
    cout << "--Player has:--" << endl;
    cout << card[n] << " of " << suit[n] << endl;	
    cout << card[n+1] << " of " << suit[n+1] << endl;
    cout << endl;
    cout << "Current Cash: $" << cash << endl;
    cout << "Current Bet: $" << betval << endl;
    cout << endl;
        
    outcome[0] = deck[n] + deck[n+1];
    	if (deck[n] == 11) {player_aces++;}
    	if (deck[n+1] == 11) {player_aces++;}
    outcome[1] = deck[n+2] + deck[n+3];
   		if (deck[n+2] == 11) {dealer_aces++;}
    	if (deck[n+3] == 11) {dealer_aces++;}
    	
	if (player_aces == 2)
		{outcome[0] = outcome[0] - 10;}
	if (dealer_aces == 2)
		{outcome[1] = outcome[1] - 10;}
// INSERT CODE FOR STATS ALGORITHM HERE
	
	for (int v = (n+4); v < (52*num_decks); v++)
		{
			if ((outcome[0] + deck[v]) < 22)
				{chance_hit++;}
		}
	chance_hit = (chance_hit/(52*num_decks));

//Initial Play wins - maps out what occurs with naturals
	if ((outcome[0] == 21) && (outcome[1] == 21))
		{
			cout << "Standoff - all bets stand." << endl;
			n = n + 4;
		}
	else if ((outcome[0] != 21) && (outcome[1] == 21))
		{
			cout << "Dealer has 21 - dealer wins." << endl;
			cash = cash - betval;
			n = n + 4;
		}
	else
	{	
	cout << "Press 1 to hit, 2 to stay. Press 0 to quit." << endl;
	cout << "Press 8 for a hint." << endl;
	cin >> hit;
	
	while (((hit < 0) || (hit > 2)) || (hit == 8))
		{
			if (hit == 8)
				{
					cout << "Chance of a successful hit: %" << (chance_hit*100) << endl;
					cout << "Press 1 to hit, 2 to stay. Press 0 to quit." << endl;
				}
			else 
				{cout << "Invalid Input. Please Enter a value 0, 1, 2, or 8." << endl;}
			cin >> hit;
		}	
	
	///////////////////////////////////
	//// PLAY 1: Player chooses to hit
	if (hit == 1)
		{
			int h = 5;
			int hit2 = 1; 
			
			while ((hit2 != 2) && (outcome[0]<22))
				{
					cout << "You draw: " << card[n+h] << " of " << suit[n+h] << endl;
					outcome[0]= outcome[0] + deck[n+h];
				  	if (deck[n+h] == 11) {player_aces++;}
				  	
				  	for (int f = (n+h); f < (52*num_decks); f++)
						{if ((outcome[0] + deck[f]) < 22) {chance_hit++;}}	
					chance_hit = (chance_hit/(52*num_decks));
					h++;
					if (outcome[0] > 21)
						{
							while ((player_aces > 0) && (outcome[0]>21))
								{
									outcome[0] = outcome[0] - 10;
									player_aces--;
								}
							if (outcome[0] > 21)
								{cout << "You bust - Dealer wins." << endl;
								cash = cash - betval;}
						}
					if (outcome[0] < 22)
						{
							cout << "Press 1 to hit (again), 2 to stay" << endl;
							cout << "Press 8 for another hint." << endl;
							cin >> hit2;
							while ((hit2 != 1) && (hit2 != 2))
							{
								if (hit2 == 8)
									{
										cout << "Chance of a successful hit: %" << (chance_hit*100) << endl;
										cout << "Press 1 to hit (again), 2 to stay" << endl;
										cin >> hit2;
									}
								else 
									{
										cout << "Invalid Input. Please Enter a value of either 1 or 2." << endl;
										cin >> hit2;
									}
							}
						}
				}
			if ((deck[n+2] < 10) && (outcome[0] < 22))
				{cout << "Dealer's face-down card is: " << card[n+3] << " of " << suit[n+3] << endl;}
			while ((outcome[1] < 17) && (outcome[0] < 22))
				{
					cout << "Dealer draws: " << card[n+h] << " of " << suit[n+h] << endl;
					outcome[1] = outcome[1] + deck[n+h];
					if (deck[n+h] == 11) {dealer_aces++;}
					h++;
					if (outcome[1] > 21)
						{
							while ((dealer_aces > 0) && (outcome[1]>21))
								{
									outcome[1] = outcome[1] - 10;
									dealer_aces--;
								}
							if (outcome[1] > 21)
								{cout << "Dealer Busts - You win." << endl;
								cash = cash + (betval*1.5);}						
						}
				}
			if ((outcome[0] < 22) && (outcome[1] < 22))
				{
					if (outcome[0] == outcome[1])
						{cout << "Standoff - all bets stand." << endl;}
					else if (outcome[0] > outcome[1])
						{cout << outcome[0] << " beats " << outcome[1] << ". You Win!" << endl;
						cash = cash + (betval*1.5);}
					else
						{cout << outcome[1] << " beats " << outcome[0] << ". Dealer Wins!" << endl;
						cash = cash - betval;} 
				}
			n = n + h;
		}
	////////////////////////////////////
	//// PLAY 2: Player chooses to stay
	if (hit == 2)
		{
			int s = 5;
			if ((deck[n+2] < 10) && (outcome[0] < 22))
				{cout << "Dealer's face-down card is: " << card[n+3] << " of " << suit[n+3] << endl;}
			while ((outcome[1] < 17) && (outcome[0] < 22))
				{
					cout << "Dealer draws: " << card[n+s] << " of " << suit[n+s] << endl;
					outcome[1] = outcome[1] + deck[n+s];
					if (deck[n+s] == 11) {dealer_aces++;}
					s++;
					if (outcome[1] > 21)
						{
							while ((dealer_aces > 0) && (outcome[1]>21))
								{
									outcome[1] = outcome[1] - 10;
									dealer_aces--;
								}
							if (outcome[1] > 21)
								{cout << "Dealer Busts - You win." << endl;
								cash = cash + (betval*1.5);}						
						}
				}
			if ((outcome[0] < 22) && (outcome[1] < 22))
				{
					if (outcome[0] == outcome[1])
						{cout << "Standoff - all bets stand." << endl;}
					else if (outcome[0] > outcome[1])
						{cout << outcome[0] << " beats " << outcome[1] << ". You Win!" << endl;
						cash = cash + (betval*1.5);}
					else
						{cout << outcome[1] << " beats " << outcome[0] << ". Dealer Wins!" << endl;
						cash = cash - betval;} 
				}
			n = n + s;
		}
	///////////////////////////////////
	//// PLAY 3: Player Quits the game	
	if (hit == 0)
		{return 0;}
	}
if (cash <= 0)
	{
		cout << "You're broke! Better luck next time." << endl;
		break;
	}
if (n >= ((52*num_decks)-8)) {n = 0;}
cout << "New Cash: $" << cash << endl;
cout << "Press 1 for next hand." << endl;
cin >> next_hand;
while (next_hand != 1)
	{cout << "Press 1 for next hand." << endl; cin >> next_hand;}	
}
return 0;
}

