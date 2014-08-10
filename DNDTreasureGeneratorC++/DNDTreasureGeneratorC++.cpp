// DNDTreasureGeneratorC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//Fills the gem collection
vector<int> fillGemCollection(int gemNum){
	vector<int> tempVec(gemNum);
	
	for(int i = 0; i< gemNum;i++){
		int n = rand() % 100 +1;
		tempVec[i] = n;
	}

	return tempVec;
}

// Sort the gems into the 6 groups 
vector<int> sortGems(vector<int> gemArr){
	vector<int> tempVec(6);
	
	//sort the gems into the 6 categories
	for(int i = 0; i < gemArr.size(); i++){
		int temp = gemArr[i];
		if(temp < 71){
			if(temp <51){
				if(temp < 26){
					tempVec[0]++;
				} else {
					tempVec[1]++;
				}
			} else {
				tempVec[2]++;
			}
		} else {
			if(temp < 91){
				tempVec[3]++;
			} else {
				if(temp <100){
					tempVec[4]++;
				} else {
					tempVec[5]++;
				}
			}
		}
	}
	return tempVec;
}

// Generates the final gems and thier values
vector<string> finalGemValue(int gemNum, vector<int> gemSort){
	vector<string> tempVec(gemNum);

	string gemFirst[] = {"Banded agate", "agate eye", "moss agate", "azurite", 
		"blue quartz", "hematite", "lapis lazuli", "malachite", "obsidian",
		"rhodochrosite", "tiger eye turquoise", "freshwater (irregular) pearl"};

	string gemSecond[] = {"Bloodstone", "carnelian", "chalcedony",
		"chrysoprase", "citrine", "iolite", "jasper", "moonstone",
		"onyx", "peridot", "rock crystal (clear quartz)", "sard", 
		"sardonyx", "rose quartz", "smoky quartz", "star rose quartz", "zircon"};

	string gemThird[] = {"Amber", "amethyst", "chrysoberyl", "coral", "red garnet", "brown-green garnet",
		"jade", "jet", "white pearl", "golden pearl", "pink pearl", "silver pearl", 
		"red spinel", "red-brown spinel", "deep green spinel", "tourmaline"};

	string gemFourth[] = {"Alexandrite", "aquamarine", "violet garnet",
		"black pearl", "deep blue spinel", "golden yellow topaz"};

	string gemFifth[] = {"Emerald", "white opal", "black opal", "fire opal", "blue sapphire",
		"fiery yellow corundum", "rich purple corundum", "blue star sapphire", "black star sapphire", "star ruby"};

	string gemSixth[] = {"Clearest bright green emerald", "blue-white diamond", "canary diamond", "pink diamond", 
		"brown diamond", "blue diamond", "jacinth"};

	for(int i= 0; i<gemSort[0]; i++){
		int size = 12;
		int select = rand() % (size);
		int value = 0;
		for(int i = 0; i<4; i++){
			value += rand() % 4 +1;
		}
		string gem = to_string( value) +" " + gemFirst[select];
		tempVec.push_back(gem);
	}

	for(int i= 0; i<gemSort[1]; i++){
		int size = 17;
		int select = rand() % (size);
		int value = 0;
		for(int i = 0; i<2; i++){
			value += rand() % 4+1;
		}
		string gem = to_string( value*10) +" " + gemSecond[select];
		tempVec.push_back(gem);
	}

	for(int i= 0; i<gemSort[2]; i++){
		int size = 16;
		int select = rand() % (size);
		int value = 0;
		for(int i = 0; i<4; i++){
			value += rand() % 4+1;
		}
		string gem = to_string( value*10) +" " + gemThird[select];
		tempVec.push_back(gem);
	}

	for(int i= 0; i<gemSort[3]; i++){
		int size = 6;
		int select = rand() % (size);
		int value = 0;
		for(int i = 0; i<2; i++){
			value += rand() % 4+1;
		}
		string gem = to_string( value*100) +" " + gemFourth[select];
		tempVec.push_back(gem);
	}

	for(int i= 0; i<gemSort[4]; i++){
		int size = 10;
		int select = rand() % (size);
		int value = 0;
		for(int i = 0; i<4; i++){
			value += rand() % 4+1;
		}
		string gem = to_string( value*100) +" " + gemFifth[select];
		tempVec.push_back(gem);
	}

	for(int i= 0; i<gemSort[5]; i++){
		int size = 7;
		int select = rand() % (size);
		int value = 0;
		for(int i = 0; i<2; i++){
			value += rand() % 4+1;
		}
		string gem = to_string( value*1000) +" " + gemSixth[select];
		tempVec.push_back(gem);
	}

	return tempVec;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int gemNum;
	cout << "This program calculates the value and type of gems\n";
	cout << "Please enter the number of gems: ";
	cin >> gemNum;
	vector<int> gemVector(gemNum);
	vector<int> gemCollection = fillGemCollection(gemNum);
	vector<int> gemSort = sortGems(gemCollection);
	
	vector<string> gemResult = finalGemValue(gemNum, gemSort);

	for(int i = 0; i<gemResult.size();i++){
		string gemString = gemResult[i];
		cout << gemString << endl; 
	}

	// Ending the program in debugging mode
	char end;
	cout << "Press \"e\" and enter to end program\n";
	cin >> end;
	return 0;
}


