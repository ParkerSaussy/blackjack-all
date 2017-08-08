// So I got really coked out in Vegas and started getting super analytical at the blackjack table. I kept muttering
// under my breath about counting cards and using math to trip up the game and I think they got weirded out about it.
// Whipped this up in a few days and have been enjoying the hell out of it so far. 

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

int decks;
int cards_current[4][2];
int pile[52][2];
int n = 0;
int input = 0;

//Suits:
//	1: Hearts
//	2: Diamonds
//	3: Spades
//	4: Clubs
 
//Cards:
//	1-10: Same w/e
//	11: Jack
//	12: Queen
//	13: King
//	14: Ace

int rand_cards()
{
srand((unsigned)time(0));
int rand_int = 0;
int rand_int2 = 0;
int num_dealt[4];

vector <string> suit_dealt;
vector <string> face_card;

for (int i=0; i<4; i++)
	{
		rand_int = (rand()%14) + 2;
		num_dealt[i] = rand_int;
		rand_int2 = (rand()%4) + 1;
		
		for (int z = 0; z<(52*n); z++) 
		{
			if ((num_dealt[i] == pile[z][0]) && (rand_int2 == pile[z][1]))
				{
					rand_int = (rand()%14) + 2;
					num_dealt[i] = rand_int;
					rand_int2 = (rand()%4) + 1;
				}
		}
			
			if (rand_int == 11)
				{face_card.push_back("Jack");}
			else if (rand_int == 12)
				{face_card.push_back("Queen");}
			else if (rand_int == 13)
				{face_card.push_back("King");}
			else if (rand_int == 14)
				{face_card.push_back("Ace");}
			else
				{face_card.push_back("NULL");}
				
			if (rand_int2 == 1)
				{suit_dealt.push_back("Hearts");}
			else if (rand_int2 == 2)
				{suit_dealt.push_back("Diamonds");}
			else if (rand_int2 == 3)
				{suit_dealt.push_back("Spades");}
			else if (rand_int2 == 4)
				{suit_dealt.push_back("Clubs");}
		
			cards_current[i][0] = num_dealt[i];
			cards_current[i][1] = rand_int2;
	}

	cout << "Dealer has: " << endl;
	if (num_dealt[0]<11) {cout << num_dealt[0] << " of " << suit_dealt[0] << endl;}
	else {cout << face_card[0] << " of " << suit_dealt[0] << endl;}
		
	if (num_dealt[1]<11) {cout << num_dealt[1] << " of " << suit_dealt[1] << endl;}
	else {cout << face_card[1] << " of " << suit_dealt[1] << endl;}	
	
	cout << endl;
	
	cout << "Player has: " << endl;
	if (num_dealt[2]<11) {cout << num_dealt[2] << " of " << suit_dealt[2] << endl;}
	else {cout << face_card[2] << " of " << suit_dealt[2] << endl;}
		
	if (num_dealt[3]<11) {cout << num_dealt[3] << " of " << suit_dealt[3] << endl;}
	else {cout << face_card[3] << " of " << suit_dealt[3] << endl;}	
}

int main ()
{
cout << "How Many Decks?" << endl;
cin >> decks;
cout << "# of Decks: " << decks << endl;

while (n<16)
{
rand_cards();

for (int x=0; x<2; x++) 
{
	for (int y=0; y<4; y++)
		{
			pile[y+n][x+n] = cards_current[y][x];
		}
}
n = n+4;

cout << endl;
cout << "Press 1 to Hit" << endl;
cout << "Press 2 to Stay" << endl;
cin >> input;

}
}