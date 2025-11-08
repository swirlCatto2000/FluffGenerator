// FluffGenerator
// Created By: Trentyne Morgan/Twitch

#include <iostream>			// Standard Input/Output for C++
#include <string>			// Library for C++ Strings
#include <stdlib.h>			// Standard C Library
#include <ctime>			// C++ Time Library
#include <fstream>			// C++ File Input/Output Library

bool weaponsOn = false;		// Turn character weapons on.

// Command Prefix Message
std::string cmdMessage[] = {"OWO :> ", "UWU :> ", ">w< :> "};

// Character Generator Main Attributes
std::string furryAnimalType[] = {"Fox", "Cat", "Bunny", "Wolf", "Kangaroo", "Panda", "Skunk", "Mouse"};
std::string furryGenderType[] = {"Male", "Female"};
std::string eyeColor[] 		  = {"Blue", "Green", "Brown", "Red", "Teal", "Purple", "Orange", "Yellow", "Pink", "Grey", "Black"};
std::string bodyColor[]       = {"Blue", "Green", "Brown", "Red", "Teal", "Purple", "Orange", "Yellow", "Pink", "Grey", "Black"};
std::string bodyHeight[]      = {"Short", "Tall", "Average Height"};
std::string bodySize[]        = {"Chubby", "Thin", "Well-Rounded"};

// Arrays for External Data
std::string tipOfTheDay[24];	// Tip Of The Day Messages. (External)
std::string accessories1[14];	// Character Accessory List 1 (External)
std::string accessories2[9];	// Character Accessory List 2 (External)
std::string weaponsList[9];		// Character Weapons List (External)

// Last character generateda
std::string lastCharacterCreated[9];

// =======================================
// Function to save last created character
// =======================================
void saveCharacterData(){

	// Ask the user to name their character
	std::string characterName;
	std::cout << "\nEnter a name for this character and press enter: ";
	std::cin >> characterName;

	// Put the character's name in the array
	lastCharacterCreated[0] = characterName;

	std::string filePath = "savedCharacters/";				// File Path for Saved Characters
	std::string charFileName = characterName + ".txt";		// Character File Name from User
	std::string charFilePath = filePath + charFileName;     // Full File Path
	
	std::ofstream characterFile(charFilePath);

	// Save the file with a loop
	if (characterFile.is_open()){

		for(int i = 0; i < sizeof(lastCharacterCreated)/sizeof(lastCharacterCreated[0]); i++){

			characterFile << lastCharacterCreated[i] << "\n";
		
		}
			// Print file saved message
			std::cout << ("\nFile Saved! Booping you back to command menu... OwO\n\n");
			std::cin.ignore();

	} else {

		std::cout << "\nThere was an error saving... =3=\n\n";
	}

}

// ====================================================
// Function to load all character attributes externally
// ====================================================
void loadExternalData(){

	std::fstream tipFile("externalData/tipOfTheDayList.txt");
	std::fstream accFile("externalData/accessories1.txt");
	std::fstream acc2file("externalData/accessories2.txt");
	std::fstream weapFile("externalData/weapons.txt");

	if (tipFile.is_open()){

		/* Using for loops on the size of the arrays to load data from external
		text files */
		for(int i = 0; i < sizeof(tipOfTheDay)/sizeof(tipOfTheDay[0]); i++){

			getline(tipFile, tipOfTheDay[i]);

		}

		for(int i = 0; i < sizeof(accessories1)/sizeof(accessories1[0]); i++){

			getline(accFile, accessories1[i]);

		}

		for(int i = 0; i < sizeof(accessories2)/sizeof(accessories2[0]); i++){

			getline(acc2file, accessories2[i]);

		}

		
		for(int i = 0; i < sizeof(weaponsList)/sizeof(weaponsList[0]); i++){

			getline(weapFile, weaponsList[i]);

		}

	}


}

// ===============================
// Function to Generate Characters
// ===============================
void generateNewCharacter(){
	
	system("CLS");
	
	std::cout << "Let's see what we have OWO...\n\n";
	
	// Seed the random number generator with the system time.
	srand(time(NULL));

	int randomValueList[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};		// Holds RNG Values
	int maxValueGenerate[9] = {8, 11, 11, 3, 14, 9, 2, 3, 9};	// Holds the maximum number to generate

	for (int i = 0; i < 9; i++){

		/* Store the value randomly generated from 0 to maxValueGenerate[counter i]
		into randomValueList[counter i] on every loop iteration */
		randomValueList[i] = rand() % maxValueGenerate[i];
	}

	// Saving the current attributes to an array
	lastCharacterCreated[1] = furryAnimalType[randomValueList[0]];
	lastCharacterCreated[2] = furryGenderType[randomValueList[6]];
	lastCharacterCreated[3] = eyeColor[randomValueList[1]];
	lastCharacterCreated[4] = bodyColor[randomValueList[2]];
	lastCharacterCreated[5] = bodyHeight[randomValueList[3]];
	lastCharacterCreated[6] = bodySize[randomValueList[7]];
	lastCharacterCreated[7] = accessories1[randomValueList[5]];
	lastCharacterCreated[8] = accessories2[randomValueList[8]];
	
	// Printing out the Character Attributes
	std::cout << "Animal Type:      " << furryAnimalType[randomValueList[0]] << "\n";
	std::cout << "Gender:           " << furryGenderType[randomValueList[6]] << "\n";
	std::cout << "Eyes (Iris) Type: " << eyeColor[randomValueList[1]] << "\n";
	std::cout << "Fur Color:        " << bodyColor[randomValueList[2]] << "\n";	
	std::cout << "Body Height:      " << bodyHeight[randomValueList[3]] << "\n";
	std::cout << "Body Size:        " << bodySize[randomValueList[7]] << "\n";
	std::cout << "Accessory #1:     " << accessories1[randomValueList[5]] << "\n";
	std::cout << "Accessory #2:     " << accessories2[randomValueList[8]] << "\n";

	// If the weapons are on, display the weapon generated.
	if (weaponsOn == true){
		
		std::cout << "Armed with:       " << weaponsList[randomValueList[8]] << "\n";
		
	} else {
		
		std::cout << "\n";
	}
	
	if (lastCharacterCreated[2] == "Male"){

		std::cout << "Bestest of bois! Now booping you back to the command menu.. ^w^\n\n";

	} else {

		std::cout << "Bestest of gorls! Now booping you back to the command menu.. ^w^\n\n";
	}
	 

}

// =============
// Main Function
// =============
int main(){

	// Clear the screen
	system("CLS");

	// Load all external data
	loadExternalData();

	// Seeding the Random Number Generator
	srand(time(NULL));
	
	bool userInputState = false;			// Boolean to control user input
	std::string userInput = "";				// String to hold user input
	int randCMDMessage = rand() % 3;		// Controls the Command Prompt Shown.
	int tipRNG = rand() % 24;				// Tip of the Day RNG
	
	// Title Message
	std::cout << "==== FluffGenerator - Can't Think of a Character? Generate One! ====\n";
	std::cout << "============= Type 'help' for options and commands. ================\n\n";
	
	std::cout << "=============== Version 1.2 =================================\n";
	std::cout << "* Attributes have been moved to external files!\n";
	std::cout << "* Save the last character that was generated with 'saveLast'!\n";
	std::cout << "* Purple cat code cleaning escapades.\n\n";
	
	std::cout << "Tip of the Day: " << tipOfTheDay[tipRNG] << "\n\n";
	
	// Allow user input
	userInputState = true;
	
	while (userInputState == true){
		
		std::cout << cmdMessage[randCMDMessage];
		std::cin >> userInput;

		// Toggle Weapon Generation
		if (userInput == "armed"){

			// Toggle the weapons on variable to the the opposite. If true, it will 
		    weaponsOn != (!weaponsOn) ? true : false;

			// Print a message based on the state of Weapons being enabled.
			std::string statusMsg = (!weaponsOn) ? "\nWeapons On! OWO\n\n" : "\nWeapons Off! -W-\n\n";
			std::cout << statusMsg;

			// Toggle the variable again.
			weaponsOn = !weaponsOn;
		
		// Generate a new character
		} else if (userInput == "generate"){
	
			generateNewCharacter();
			
		// Turn the terminal color green
		} else if (userInput == "neoMatrix"){
			
			system("color 0a");
			std::cout << "\nTaking the red pill and going further down the rabbit hole, neo... \n\n";
	
		// Display the Help Menu
		} else if (userInput == "help"){
			
			std::cout << "\n====== Help and Options =========================================\n\n";
			std::cout << "generate      - Generate a new furry friend!                  >w<\n";
			std::cout << "exit          - Exit the program.                             >~<\n";
			std::cout << "clear         - Clear the screen.                             :3\n";
			std::cout << "armed         - Want to arm your character with weapons?      >:3\n";
			std::cout << "neoMatrix     - Enter the Matrix.                             TwT\n";
			std::cout << "saveLast      - Save last created character!                  ^W^\n\n";	
			
		// Exit the Program
		} else if (userInput == "exit"){
			
			exit(0);
			
		// Clear the screen
		} else if (userInput == "clear"){
			
			system("CLS");

		// Save last generated character
		} else if (userInput == "saveLast"){

			saveCharacterData();
			
		// Error prompt
		} else {
			
			std::cout << "\nUWU, I think you made a typo mister; please try again~\n\n";
			
		}
		
	}
	
}