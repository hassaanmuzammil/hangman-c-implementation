#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>

bool checkcharacter(char[], char, char[]);
void drawHangman(int);
void welcome(void);
int main()
{
	welcome();
	char word[20]; //Word which will be randomly selected from user's choosen category
	int wrongtries = 0; 
	int maxwrong = 5; // Maximum number of wrong tries
	int category, x; // Categories of word list(animals, cities, countries)
	int word_index;
	char gword[20]; //Guessed word to a certain point
	char input;
	char animals[10][20] = { "tiger", "leopard", "cheetah", "crocodile", "alligator","lion","rhino","ostrich","gorilla","hyena" };
	char cities[10][20] = { "london", "karachi", "california", "milan", "paris", "moscow","mumbai","berlin","sydney","melbourne" };
	char countries[10][20] = { "pakistan", "russia", "thailand", "morocco", "india","malaysia","america","england","germany","france" };
	while (1)
	{
		srand(time(NULL));
		printf("*********************************************************************\n");
		printf("[1] Animals \n[2] Cities \n[3] Countries\n\nChoose a category [1/2/3]: ");
		scanf("%d", &category); //User has to input a number between 1 to 3 to choose category.
		word_index = rand() % 5;
		switch (category) //Switch case to choose a word randomly from the user's specified category
		{
		case 1:
			strcpy(word, animals[word_index]); //copies the word randomly assigned from animals to word
			break;
		case 2:
			strcpy(word, cities[word_index]); //copies the word randomly assigned from cities to word
			break;
		case 3:
			strcpy(word, countries[word_index]);// copies the word randomly assigned from countries to word
			break;
		}
		//printf("Chosen word: %s\n", word); //this will tell the word which has randomly been assigned(to check program)

		for (int i = 0; i < strlen(word); i++)
		{
			gword[i] = '_'; //initializes gword and all the elements are assigned blank spaces 
			printf(" _ "); //Shows the number of characters in word.
		}
		gword[strlen(word)] = '\0'; //the length of guess word is same as of gword

		printf("\n");

		printf("%s\n", gword);

		while (wrongtries <= maxwrong) //initially wrong tries is equal to 0
		{
			printf("\t\nEnter a character: \n\n");
			getchar();
			scanf("%c", &input);
			//printf("Your selection: %c\n", input);
			bool found = checkcharacter(word, input, &gword); //checks if the entered character is found in word or not

			//bool found = false;
			if (found == false) 
				wrongtries++;//if character is not found in the list increase the number of of wrongtries

			drawHangman(wrongtries); //draws hangman on console

			printf("%s", gword);
			printf("\nWrong tries left: %d\n", 6 - wrongtries);
			if (strcmp(word, gword) == 0) //if the word is guessed correctly
			{
				printf("\n CONGRAGULATIONS! YOU WIN! \n\n");

				break;
			}
		}
		if(wrongtries == 6) //if word is not guessed and wrongtries equals to maximum wrong tries
		{
			printf("\nYOU LOSE!\nThe correct word was: %s\n", word);
		}
		wrongtries = 0;

		printf("\n\nDo you want to play again?");
		printf("\n[1]Yes\n[2]No");
		printf("\nAnswer(1 or 2):  ");
		scanf("%d", &x);

		if (x == 2)
			break;

		if (x != 1)
		{
			while (x != 1 || x != 2) {
				printf("\n\nDo you want to play again?");
				printf("\n[1]Yes\n[2]No");
				printf("\nAnswer(1 or 2):  ");
				scanf(" %d", &x);
				if (x == 1 || x == 2)
					break;
			}

		}
		if (x == 2)
			break;

	}
	printf("\n\n");
	system("pause");

}

bool checkcharacter(char oword[], char c, char gword[])
{
	bool found = false;
	for (int i = 0; i < strlen(oword); i++)
	{
		if (oword[i] == c)
			//if (strcasecmp(oword[i],c) == 0)
		{
			gword[i] = c;
			found = true;
		}
	}

	return found;
}

void drawHangman(int wrongtries)
{
	printf("\n");

	switch (wrongtries)
	{
	case 0:
		printf("\t|---------\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		break;
	case 1:
		printf("\t|---------\n");
		printf("\t|    | \n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		break;
	case 2:
		printf("\t|---------\n");
		printf("\t|    | \n");
		printf("\t|    O \n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");

		printf("\t|\n");
		break;
	case 3:
		printf("\t|---------\n");
		printf("\t|    | \n");
		printf("\t|    O \n");
		printf("\t|    | \n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		break;
	case 4:
		printf("\t|---------\n");
		printf("\t|    | \n");
		printf("\t|    O \n");
		printf("\t|    | \n");
		printf("\t|   / \\\n");
		printf("\t| \n");
		printf("\t| \n");
		printf("\t| \n");
		break;
	case 5:
		printf("\t|---------\n");
		printf("\t|    |\n");
		printf("\t|    O\n");
		printf("\t|    |\n");
		printf("\t|   / \\\n");
		printf("\t|    | \n");
		printf("\t|\n");
		printf("\t|\n");
		break;
	case 6:
		printf("\t|---------\n");
		printf("\t|    |\n");
		printf("\t|    O    \n");
		printf("\t|    |    \n");
		printf("\t|   / \\   \n");
		printf("\t|    |    \n");
		printf("\t|   / \\   \n");
		printf("\t| \n");
		break;

		printf("\n");

	}
}
void welcome(void)
{
	printf("\t\t***********************************************************************\n\t\t***********************************************************************\n\t\t\t\t*****    WELCOME TO HANGMAN GAME    *****\n\t\t***********************************************************************\n\t\t***********************************************************************");
	Sleep(3000);
	system("cls");
}
