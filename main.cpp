#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
#include<sstream>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename,  map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);
map<string, Color> colors;
map<string, Color>::iterator colorsIter;

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
    //map<string, Color>::iterator colorsIter;

	if (choice >= 1 && choice <= 6){
		string file = "../colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}

	else if (choice == 7){
		for (int i = 1; i <= 6; i++){
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{

    // TODO: Load the file and store the resulting colors in outVector.
    fstream file(filename, ios_base::in);
    string line;
    int colorInt;
    int i = 0;
    vector<Color> colorVector;
    map<string, Color>::iterator colorsIter;
    Color testColor;

    while (getline(file, line))
    {
        Color color;
        string strName = line.substr(0, line.find(' '));
        const char* colorName = strName.data();
        color.SetName(colorName);
        strName = line.substr(line.find(' ') + 1, line.size());
        colorInt = stoi(strName);
        color.SetValue(colorInt);
        colorVector.push_back(color);
        i++;
    }

    //cout << colorVector.size() << endl;


    for(int i = 0; i < colorVector.size(); i++){

        //cout << colorVector.at(i).GetName() << " ";
        //cout << colorVector.at(i).GetValue() << endl;
        colors.emplace(colorVector.at(i).GetName(), colorVector.at(i));
    }


    //cout << colors.size() << endl;
    //cout << colorVector.at(0).GetHexValue() << endl;
    //cout << (int) colorVector.at(0).GetR() << endl;

    file.close();
}
void PrintColors(const map<string, Color>& colors)
{
   // TODO: iterate through all entries in the map and print each color, one at a time

    for(auto const& p: colors){

        cout << left << setw(20) << p.first << right << setw(10) << p.second.GetHexValue() << "\t\t" << (int) p.second.GetR() << "," << (int) p.second.GetG() << "," << (int) p.second.GetB() << endl;
    }
    cout << "Number of colors: " << colors.size() << endl;

}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors){

    string userColor;

    cin >> userColor;
    bool colorFound = false;

    //map<string, Color>::iterator colorsIter;

    colorsIter = colors.find(userColor);

    for(auto const& p: colors){
        if (colorsIter->first == p.first){

            colorFound = true;
        }
    }

    if(colorFound){
        cout << left << setw(20) << colorsIter->first << right << setw(10) << colorsIter->second.GetHexValue() << "\t\t" << (int) colorsIter->second.GetR() << "," << (int) colorsIter->second.GetG() << "," << (int) colorsIter->second.GetB() << endl;
    }
    else{
        cout << userColor << " not found!" << endl;
    }

}
