#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

int num_decks;
int startgame;
int next_hand;

//void shuffle()

int main () 
{
cout << "Enter # of Decks, 1-8:" << endl;
cin >> num_decks;
cout << "# of Decks: " << num_decks << endl;
cout << "Got it... Press 1 to Start Game, or any other key to Quit." << endl;
cin >> startgame;
int deck[52*(num_decks)];
int current[15];

if ((startgame != 1) || (num_decks == 0) || (num_decks > 8)) {return 0;}
	
else 
	{
 		cout << "game started!" << endl;
 		int play;
 		srand(time(0));
 		 		
  		for (int i=0; i<(52*num_decks); i++) 
 			{
 				deck[i] = i+1;
 				if (deck[i] > 52)
 					{
 					while (deck[i] > 52)
 						{
 							deck[i] = (deck[i] - 52);
 						}
 					}
 			}
 			
 		for (int i=0; i<(52*num_decks); i++) 
 			{
            	int r = rand() % 52; 
            	int temp = deck[i]; 
            	deck[i] = deck[r]; 
            	deck[r] = temp;
 			}		 		
 	
        int n=0;
       for (int x=0; x<(52*num_decks); x++) 
 			{
            	cout << deck[x] << " ";  
        	}
        cout << endl;
        	 	 // cout the entire un-adjusted deck
        
        while (n != (52*num_decks))
        	{
        	vector <string> face_card;
//Turns every card into a card 1 thru Ace
       		for (int g=0; g<16; g++)
        		{
        			current[g] = deck[n+g];
        			while (current[g] > 14)
        				{
        					current[g]=current[g] - 14;
    					}
    			} 
        	
//Push every face card back into a universally declared vector. Only need to call this 
        	for (int q=0; q<16; q++)
        		{
        			if (current[q] == 11)
        				{
        					face_card.push_back("Jack");
        				}
        			if (current[q] == 12)
        				{
        					face_card.push_back("Queen");
        				}
        			if (current[q] == 13)
        				{
        					face_card.push_back("King");
        				}
        			if (current[q] == 14)
        				{
        					face_card.push_back("Ace");
        				}
        			if (current[q] == 1)
        				{
        					face_card.push_back("Ace");
        				}
        		} 
// NOTE: also need to turn all face cards into 10s while also retaining 
// which face card they are... will come back to this later.     		
        		cout << "*************************************" << endl;
        		cout << "Dealer has: " << endl;
//Dealer's first card:
        		if (current[2]>10)
        			{
        				cout << face_card[2] << endl;
        				if (current[2] < 14)
        					{
        						current[2] = 10;
        					}
        				else {current[2]=11;}
        			}
        		else 
        			{
        				cout << current[2] << endl;
        			}
//Dealer's second card:
        		if (current[2]>9)
        			{
        				if (current[3]>10)
        					{
        						cout << face_card[3] << endl;
        						if (current[3] < 14)
        							{
        								current[3] = 10;
        							}
        						else {current[3]=11;}
        					} 
        				else {cout << current[3] << endl;}
        			}
        		else
        			{
        				cout << "Card Faced Down." << endl;
        			}
        		cout << endl;
        		cout << "You have: " << endl;
//Player's first card:
				if (current[0]>10)
        			{
        				cout << face_card[0] << endl;
        				if (current[0] < 14)
        					{
        						current[0] = 10;
        					}
        				else {current[0]=11;}
        			}
        		else 
        			{
        				cout << current[0] << endl;
        			}
//Player's second card:
				if (current[1]>10)
        			{
        				cout << face_card[1] << endl;
        				if (current[1] < 14)
        					{
        						current[1] = 10;
        					}
        				else {current[1]=11;}
        			}
        		else 
        			{
        				cout << current[1] << endl;
        			}
        		cout << endl;

		for (int e=0; e<16; e++) 
 			{
            	cout << current[e] << " ";  
        	}
        cout << endl; 
        cout << "n = " << n << endl;

//Assigning the actual outcomes from the initial card.        		
        		int outcome[2];
        		outcome[0] = current[0]+current[1];
        		outcome[1] = current[2]+current[3];
//Outcomes
//First Outcome: Dealer gets 21 natural, player doesn't - Dealer wins.	
        		if ((outcome[1]>20) && (outcome[0]<21) && (current[2]<10))
        			{
        				cout << "Dealer Wins!" << endl;
        				n = n + 4;
        			}
//Second Outcome: Player gets 21 natural, dealer doesn't - Player Wins.
        		else if ((outcome[0]>20) && (outcome[1]<21))
        			{
        				cout << "Blackjack! You Win!" << endl;
        				n = n + 4;
        			}
//Third Outcome: Player and Dealer both get 21 - standoff.
				else if ((outcome[0]>20) && (outcome[1]>20))
					{
						cout << "Stand-off. Bets Remain." << endl;
						n = n + 4;
					}
//Fourth Outcome: Neither has 21 - hit and stay. Next Options are highlighted below
//in several different stages. 
				else 
					{
        				cout << "Press 1 to Hit, 2 to Stay" << endl;
        				cin >> play;
        				int b = 5;
        				
        				// Player Hits (goes until they choose to stay)
        				if (play == 1)
        					{
           						outcome[0] = outcome[0] + current[4];
           						cout << "You draw a: " << current[4] << endl;
           						if (outcome[0]>21)
           							{
           								cout << "Bust - Dealer wins!" << endl;
           							}
           						else 
           							{
           								int hit = 1;           								
           								while ((hit != 0) && (outcome[0]<21))
           									{
           										cout << "Press 1 to hit again, 0 to stay" << endl;
           										cin >> hit;
           										if (hit == 1)
           											{
           												outcome[0] = outcome[0] + current[b];
           												cout << "You drew a: ";
        												if (current[b]>10)
        													{
        														cout << face_card[b] << endl;
        														if (current[b] < 14)
        															{
        																current[b] = 10;
        															}
        														else {current[b]=11;}
        													} 
        												else {cout << current[b] << endl;} 
           												b++;      										
           											}	
           										else if (hit != 0)
           											{
           												cout << "Invalid Input." << endl;
           											}       
           									}	
           								if (outcome[0]>21)
           									{
           										cout << "Bust - Dealer Wins!" << endl;
           									}     
           								else 
           									{      														        									
        										if (current[2] < 10)
        											{
        												cout << "Dealer's 2nd card: ";   											
        												if (current[3]>10)
        													{
        														cout << face_card[3] << endl;
        														if (current[3] < 14)
        															{
        																current[3] = 10;
        															}
        														else {current[3]=11;}
        													} 
        												else {cout << current[3] << endl;}         												
        											}
        										while (outcome[1]<17)
        											{
        												outcome[1]=outcome[1]+current[b];
														cout << "Dealer's Next card: ";   											
        												if (current[b]>10)
        													{
        														cout << face_card[b] << endl;
        														if (current[b] < 14)
        															{
        																current[b] = 10;
        															}
        														else {current[b]=11;}
        													} 
        												else {cout << current[b] << endl;}         												
        												b++;
        											}
        									//Outcomes of each hand
        										if (outcome[1] > 21)
        											{
        												cout << "Dealer Busts - You Win!" << endl;
        											}
        										else if (outcome[0] > outcome[1])
        											{
        												cout << outcome[0] << " beats " << outcome[1] << endl;       								
        												cout << "You Win!" << endl;
        											}
        										else if (outcome[0] == outcome[1])
        											{
        												cout << "Both Players have " << outcome[0] << endl;
        												cout << "Stand-off. Bets Stand" << endl;
        											}
        										else
        											{
         												cout << outcome[1] << " beats " << outcome[0] << endl;       					
        												cout << "Dealer Wins." << endl;       							
        											}
        									}
        							}
        						n = n + b;
        					}
        				else if (play == 2)
        					{
        						int y = 4;
        						if (current[2]<10)
        							{
        								cout << "Dealer's 2nd card: " << current[3] << endl;
        							}
        						while (outcome[1]<17)
        							{
        								outcome[1]=outcome[1]+current[y];
        								cout << "Dealer's Next Card: " << current[y] << endl;
        								y++;
        							}
        						if (outcome[1] > 21)
        							{
        								cout << "Dealer Busts - You Win!" << endl;     						
        							}
        						else if (outcome[1]>outcome[0])
        							{
										cout << outcome[1] << " beats " << outcome[0] << endl;       					
        								cout << "Dealer Wins." << endl;          							
        							}
        						else if (outcome[0] > outcome[1])
        							{
        								cout << outcome[0] << " beats " << outcome[1] << endl;       								
        								cout << "You Win!" << endl;
        							}
        						else if (outcome[0] == outcome[1])
        							{
        								cout << "Both Players have " << outcome[0] << endl;
        								cout << "Stand-off. Bets Stand" << endl;
        							}
        						n = n + y;
        					}
        				else 
        					{
        						cout << "Invalid Input." << endl;
        					}
        			}
        		cout << "Press 1 for Next Hand, or press 0 to quit." << endl;
        		cin >> next_hand;
        		if (next_hand == 0)
        			{
        				return 0;
        			}
          	}
    }	
}