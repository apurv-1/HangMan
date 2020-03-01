#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<process.h>

using namespace std ;

const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=7;

int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);

int main()
{

	char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"india",
		"korea",
		"nepal",
		"malaysia",
		"philippines",
		"australia",
		"iran",
		"ethiopia",
		"oman",
		"indonesia",
		"japan",
		"iraq",
		"france",
		"singapore",
		"canada",
		"bolavia" ,
		"chile",
		"finland",
		"hungary" ,
		"ireland" ,
		"jamaica" ,
		"kenya",
		"mauritius" ,
		"romania" ,
		"sweden" ,
		"taiwan" ,
		"zimbabwe" ,
		"vietnam",
		"ukraine" ,
		"libya" ,
	};

	int e;
	int rand() ;
	int n=rand()%30;
	strcpy(word,words[n]);


	initUnknown(word, unknown);

	cout<<"\n------------------------Ý ..C++ INVESTIGATORY PROJECT.. Ý-----------------------";
	cout<<"\n\n\n\t\tInstructions for this GAME:-";
	cout<<"\n\n\t\t->You have to Guess the NAMES of COUNTRIES";
	cout<<"\n\n\t\t->Each letter is represented by a HASH(#)";
	cout<<"\n\n\t\t->You have to type only one letter in one try";
	cout<<"\n\n\t\t->You have " << MAX_TRIES << " tries to try and guess the word.";
	cout<<"\n\nMade By : APURVA GUPTA\t\t   ROLL NO.: 12  \t\tCLASS : XII `A'";
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout<<"\n\t\tPRESS `0' to EXIT or PRESS `1' to continue.. ";
	cin>>e ;
  if(e==0)
   exit(e) ;
  else
  {
	cout<<"\n\n\n\n\n\nGuess this COUNTRY : " ;

	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout<< unknown;
		cout<< "\n\nGuess a letter: ";
		cin>> letter;


		if(letterFill(letter, word, unknown)==0)
		{
			cout<< endl <<"Whoops! this letter is not there!\n" << endl;
			cout<<"------------------------\n";
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter!\n" << endl;
			cout<<"------------------------\n";
		}
		cout<<"You have "<< MAX_TRIES - num_of_wrong_guesses;
		cout<<" guesses left."<< endl;
		cout<<"------------------------\n";
		if (strcmp(word, unknown) == 0)
		{

			cout<< "Yeah! You got it!\nThe Word was : "<< word <<"\n---------------------------Ý Congrats! You WON!";
			cout<<" Ý---------------------------\n";
			break;
		}

	}
  }
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\n\t\t\tSorry, you lost... Game Over!!\n" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>> The word was :`" << word << "' <<<<<<<<<<<<<<<<<<<<<<<<<<<\n" ;
	}
	
	return 0;

}


int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{

		if (guess == guessword[i])
			return 0;
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
void initUnknown (char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='#';
	unknown[i]='\0';
}
