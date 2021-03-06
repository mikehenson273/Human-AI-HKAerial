/*Michael Henson
  CSC215
  Basic User guessing variant
*/

//sets up the libraries
#include "pch.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Sets up variables here
int randomNumber = rand();
int searchHigh = 64;
int searchLow = 1;
int binaryTargetFinder = ((searchHigh - searchLow) / 2) + searchLow; // sets equation for binary search
int linearTargetFinder = 0; // sets intial value for linear target finder
int randomTargetFinder = rand() % 64 + 1;

int main()
{
	bool isTargetLocated = false;
	srand(static_cast<unsigned int>(time(0))); // prevents same number usage between restarts
	int rebelLocal = rand() % 64 + 1; //sets up rebel location on in a number from 1 to 64
	//int rebelLocal = 10; // for debugging purposes
	int humanTries = 0; //human search tries
	int binarySearchTries = 0; //binary search tries
	int linearSearchTries = 0; //linear search tries
	int randomSearchTries = 0; //random search tries
	int humanGuess = 0; // Human guess number
	char again = 'Y';
	while (again == 'Y' || again == 'y')

	do
	{
		
		cout << "\tWelcome to HKAerial Interface\n\n";
		
		// starts user guessing here
		do
		{
			cout << "Enter a guess:\n";
			cin >> humanGuess;
			//adds 1 try to each guess
			++humanTries;
			if (humanGuess > rebelLocal) //checks to see if it's high
			{
				cout << "\nToo high!\n\n";
			}
			else if (humanGuess < rebelLocal) //checks to see if it's low
			{
				cout << "Too low!\n\n";
			}
			else //outputs when values are equal even though it doesn't say so
			{
				cout << "\nThe User has found the rebels after searching " << humanTries << " times!\n\n";
			}
		} while (humanGuess != rebelLocal); //keeps current loop repeating until user guesses correctly
		
		do
		{
			//underneath the searchHigh and searchLow vars are used when you want more depth to it working
			//cout underneath this is mainly for debugging as well
			//cout << "The rebels are hiding at location " << rebelLocal << " on the grid.\n";

			// Recalc guess based off learning.
			binaryTargetFinder = ((searchHigh - searchLow) / 2) + searchLow;
			++binarySearchTries;
			//cout << "The HKAerial's new search is at location: " << targetFinder << ".\n";
			//cout << "This is the HKAerial's attempt number " << binarySearchTries << ".";

			// Is Guess too high
			if (binaryTargetFinder > rebelLocal)
			{
				// set high search number at a new lower level to 1 less than you guessed.
				searchHigh = (binaryTargetFinder - 1);
				//cout << "\nThe search was high of rebel base at " << rebelLocal << ". Continuing search.\n\n";
				//system("pause");
				//cout << endl;
			}
			// Is Guess too Low
			else if (binaryTargetFinder < rebelLocal)
			{
				// set low search number at a new higher level to 1 more than you guessed.
				searchLow = (binaryTargetFinder + 1);
				//cout << "\nThe search was low of rebel base at " << rebelLocal << ". Continuing search.\n\n";
				//system("pause");
				//cout << endl;
			}
			// Is Target Found?
			else if (binaryTargetFinder == rebelLocal)
			{
				isTargetLocated = true;
				cout << "\n\nOn the Binary Search HK's attempt number " << binarySearchTries << "\n";
				cout << "it has found them at grid location " << rebelLocal << ".\n\n";
				system("pause");
			}
			else
			{
				// You should never get to this unless you have a logic error.
				cout << "\nError Something went wrong when trying to classify targetFinder";
			}
			// Keep going until target is found
			
		} while (!isTargetLocated); //keeps current loop repeating until AI gets the correct answer
		
		//linear searches
		for ( ; linearTargetFinder < rebelLocal; ) //keeps current loop repeating until linear search is the same as rebel location
		{
			//starts counters for searching and adds one per run
			++linearSearchTries;
			++linearTargetFinder;
			if (linearTargetFinder < rebelLocal) //keeps it going and counting until value is hit
			{
				
				//debugging purposes
				//cout << "\nSearch was low keep going\n";
				//system("pause");
				
			}
			else //when value is hit here stops the loop
			{
			cout << "\nOn the Linear Search HK's attempt number " << linearSearchTries << "\n";
			cout << "it has found them at grid location " << linearTargetFinder << ".\n\n";
			system("pause");
			}
		}
		
		//Random searches
		do
		{
			//underneath too high and too low guesses is for more in-depth look (I advise against as it can take A WHILE)
			randomTargetFinder = rand() % 64 + 1;
			++randomSearchTries;
			//debugging
			//cout << "The Random HKAerial's new search is at location: " << randomTargetFinder << ".\n";
			//cout << "This is the Random HKAerial's attempt number " << randomSearchTries << ".\n";

			// Is Guess too high
			if (randomTargetFinder > rebelLocal)
			{
				//cout << "\nThe search was high of rebel base at " << rebelLocal << ". Continuing search.\n\n";
				//system("pause");
			}
			// Is Guess too Low
			else if (randomTargetFinder < rebelLocal)
			{
				//cout << "\nThe search was low of rebel base at " << rebelLocal << ". Continuing search.\n\n";
				//system("pause");
			}
			// Is Target Found?
			else if (randomTargetFinder == rebelLocal)
			{
				cout << "\n\nOn the Random Search HK's attempt number " << randomSearchTries << "\n";
				cout << "it has found them at grid location " << rebelLocal << ".\n\n";
				system("pause");
			}
			else
			{
				// You should never get to this unless you have a logic error.
				cout << "\nError Something went wrong when trying to classify randomTargetFinder";
			}
			// Keep going until target is found

		} while (randomTargetFinder != rebelLocal); //keeps current loop repeating until AI randomly gets the correct answer
	
	
		// We have located the target
		// Let's congrad the winner and display stats!
		cout << "\nAll drones have now found the rebels.\n";
		cout << "The rebels were hiding at location " << rebelLocal << ".\n\n";
		cout << "The Human user took " << humanTries << " tries to find the target location.\n";
		cout << "Using a binary search pattern the AI attempted " << binarySearchTries << " times to find the target location.\n";
		cout << "Using a linear search pattern the AI attempted " << linearSearchTries << " times to find the target location.\n";
		cout << "Using a random search pattern the AI attempted " << randomSearchTries << " times to find the target location.\n";
		system("pause\n");
		cout << "Would you care to track another group? (Y/N): \n";
		cin >> again;
 
		// Let's reset our vars
		randomNumber = rand();
		searchHigh = 64;
		searchLow = 1;
		binaryTargetFinder = ((searchHigh - searchLow) / 2) + searchLow; // sets equation for binary search
		linearTargetFinder = 0; // sets intial value for linear target finder
		randomTargetFinder = rand() % 64 + 1;
		isTargetLocated = false; //resets boolean vaule to false
		srand(static_cast<unsigned int>(time(0))); // prevents same number usage between restarts
		rebelLocal = rand() % 64 + 1; //sets up rebel location on in a number from 1 to 64
		//rebelLocal = 10; // for debugging purposes
		humanTries = 0; //human search tries
		binarySearchTries = 0; //binary search tries
		linearSearchTries = 0; //linear search tries
		randomSearchTries = 0; //random search tries
		humanGuess = 0; // Human guess number
	}
	while (again == 'Y' || again == 'y'); //conditional to replay
	return 0;
}
