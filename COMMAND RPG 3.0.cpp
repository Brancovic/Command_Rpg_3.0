#include <iostream>
#include <algorithm>
#include <windows.h>


using namespace std;

bool answered;

string Player1;
string Player2;

//HP
int HPP1 = 100;
int HPP2 = 100;
int HealCountP1 = 0;
int HealCountP2 = 0;

//damage
int DmgP1 = 10;
int DmgP2 = 10;

int P1Sch = rand() % 40;
int P2Sch = rand() % 40;

//odpove?
string P1Answer;
string P2Answer;
string Attack = "attack";
string Heal = "heal";

/*color

	#define color_black      0
	#define color_dark_blue  1
	#define color_dark_green 2
	#define color_light_blue 3
	#define color_dark_red   4
	#define color_magenta    5
	#define color_orange     6
	#define color_light_gray 7
	#define color_gray       8
	#define color_blue       9
	#define color_green     10
	#define color_cyan      11
	#define color_red       12
	#define color_pink      13
	#define color_yellow    14
	#define color_white     15

	colors are 0=black 1=blue 2=green and so on to 15=white  
	colorattribute = foreground + background * 16
	 to get red text on yellow use 4 + 14*16 = 228
	 light red on yellow would be 12 + 14*16 = 236
*/

/*HANDLE  hConsole;

//changing color of console
void SetConsoleColor(int txtcolor, int BGcolor) {

	int finalcolor;

	finalcolor = txtcolor + BGcolor*16;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, finalcolor);
}
*/

//function for picking name of players
void namePickingF() {

	//SetConsoleColor(30,0);

	cout << "Enter name of the first Player: ";
	cin >> Player1;
	cout << endl;

	cout << "Enter name of the second Player: ";
	cin >> Player2;
	cout << endl;
};
	
//function for didplaying stats
void statsDisplayF() {

	cout << endl;
	cout << "   P1	Name: " << Player1 << "  HP: " << HPP1 << "  Damage:" << DmgP1<< endl;
	cout << "   P2	Name: " << Player2 << "  HP: " << HPP2 << "  Damage:" << DmgP2 << endl;
	cout << endl;
}

//this is function of attack for P1 make function for P2
void AttackF(string HittingP){
	
	if (HittingP == Player1) {
		cout << Player1 << " hit " << Player2 << " for " << DmgP1 << endl;
		*&HPP2 = HPP2-DmgP1;
		cout << endl;
	}

	else {
		cout << Player2 << " was hit " << Player1 << " for " << DmgP2 << endl;
		*&HPP1 = HPP1 - DmgP2;
		cout << endl;
	}
}

//
void HealF(string Player) {
	

	if (Player == Player1) {

		if (HealCountP1 <= 3 ) {

			cout << Player1 << " was healed for 30 HP";
			*&HPP1 = HPP1 + 30;
			cout << endl;
			++HealCountP1;
		}
		else if (HealCountP1 >= 3)
		{
			cout << Player1 << " has been heald too much you can't heal no more";
			cout << endl;
		}
	}

	if (Player == Player2) {

		if (HealCountP2 <= 3) {

			cout << Player2 << " was healed for 30 HP";
			*&HPP2 = HPP2 + 30;
			cout << endl;
			++HealCountP2;
		}
		
		else if (HealCountP2 >= 3)
		{
			cout << Player2 << " has been heald too much you can't heal no more";
			cout << endl;
		}
	}
}

//defend function of P1
void DefendF(string Player) {
	int DefendP1 = rand() % 21;
	int DefendP2 = rand() % 21;

	if (Player == Player1) {

		if (P1Sch == 1 || P1Sch == 2 || P1Sch == 3) {

			DefendP1 = rand() % 21;

			cout << Player1 << " blocked attack for: " << DefendP1 << endl;
			cout << DefendP1 << " - "<< DmgP2 << " = " << DefendP1 - DmgP2 << endl;
			*&HPP1 = HPP1 + DefendP1;
		}
		else {
		
		
		}

		if (P2Sch == 1 || P2Sch == 2 || P2Sch == 3) {

			DefendP2 = rand() % 21;

			cout << Player2 << " blocked attack for: " << DefendP2 << endl;
			cout << DefendP2 << "-" << DmgP1 << "= " << DefendP2 - DmgP1 << endl;
			*&HPP2 = HPP2 + DefendP2;
		}
	}
}

//Crit. attack function for P1
void CritAttackF(string Player) {
	int CritDmgP1 = rand() % 26;
	int CritDmgP2 = rand() % 26;

	if (Player == Player1) {

		if (P1Sch == 1) {

			cout << Player1 << " hitted with critical demage with power: " << CritDmgP1 << endl;
			cout << DmgP1<< " + " << CritDmgP1 <<" = " << DmgP1 + CritDmgP1 << endl;
			*&HPP2 = HPP2 - (DmgP1 + CritDmgP1);
		}
	}

	if (Player == Player2) {

		if (P2Sch == 1) {

			cout << Player2 << " hitted with critical demage with power: " << CritDmgP2 << endl;
			cout << DmgP2 << " + " << CritDmgP2 << " = " << DmgP2 + CritDmgP2 << endl;
			*&HPP1 = HPP1 - (DmgP2 + CritDmgP2);
		}
	}
}

void LowerCasingF(string string){
	
	if (string == P1Answer) {

		std::for_each(P1Answer.begin(), P1Answer.end(), [](char& c) {
			c = ::tolower(c);
		});
	}

	else if  (string == P2Answer){

		std::for_each(P2Answer.begin(), P2Answer.end(), [](char& c) {
			c = ::tolower(c);
		});
	}
}

void Error(string ErrorMessage) {

	//SetConsoleColor(12,0);
	cout << "ERROR" << endl;
	cout << ErrorMessage << endl;
	cout << "ERROR" << endl;
	cout << endl;
	//SetConsoleColor(15, 0);

}



int main() {

	//SetConsoleColor(3,15);
	
	cout << "Welcome to COMMAND RPG ";
	system("pause");
	//cin.get();
	namePickingF();

	cout << endl;
	cout << endl;

	statsDisplayF();

	do
	{
            do{
				
				if (0 >= HPP1 || 0 >= HPP2)
				{
					break;
				}

                cout << Player1 << " is on turn. type Attack or Heal: ";
                cin >> P1Answer;
                cout << endl;

                LowerCasingF(P1Answer);

                if (P1Answer == Attack) {

					P1Sch = rand() % 40;

					if (P1Sch != 1) {
						AttackF(Player1);
						DefendF(Player2);

						answered = true;
					}

					else if (P1Sch == 1){

						CritAttackF(Player1);
					}
                }

                else if (P1Answer == Heal)
                {
                    HealF(Player1);
                    answered = true;
                }

                else {
                    Error("Answer P1 not found");
                }
            }while(answered == false);

			
            statsDisplayF();
            
			if (0 >= HPP1 || 0 >= HPP2)
			{
				break;
			}

			do {
                cout << Player2 << " is on turn. type Attack or Heal: ";
                cin >> P2Answer;
                cout << endl;

                LowerCasingF(P2Answer);
                
				if ( P2Answer == Attack) {
                
					P2Sch = rand() % 40;

					if (P2Sch != 1) {
						AttackF(Player2);
						DefendF(Player1);

						answered = true;
					}

					else if (P2Sch == 1) {

						CritAttackF(Player2);

					}
                }

                else if (P2Answer == Heal)
                {
                    HealF(Player2);
                    answered = true;
                }

                else    {
                    Error("Answer P2 not found");
                }
            }while(answered == false);
			
			statsDisplayF();

	} while(0 <= HPP1 || 0 <= HPP2);
	

	if (HPP1 > HPP2) {
		cout << "!!! " << Player1 << " won CONGRATULATION!!!" << endl << "have a great day" << endl;
	}

	else if (HPP2 > HPP1)
	{
		cout << "!!! " << Player2 << " won CONGRATULATION!!!" << endl << "have a great day" << endl;
	}

}