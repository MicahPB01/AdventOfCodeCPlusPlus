//
// Created by micah on 1/12/2024.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int combineNumbers(int, int);
int findTotal(vector<string>);
string replaceSpelledNumbers(string);
string replaceAll(string, string, string);


int main()   {

    cout << "Starting" << endl;

    ifstream file("C:\\Users\\micah\\CLionProjects\\untitled1\\DayOne\\Input.txt");

    if(!file.is_open())   {
        cout << "Error opening the file" << endl;
        return 1;
    }


    vector<string> lines;

    string currentLine;

    while(getline(file, currentLine))   {
        lines.push_back(currentLine);
    }

    file.close();

    for(int i = 0; i < lines.size(); i++)   {
        cout << lines[i] << endl;
    }

    int total = findTotal(lines);
    cout << "The total is: " << total << endl;


}

int findTotal(vector<string> lines)   {
    vector<int> numbers;




    //sorting through each line
    for(int i = 0; i < lines.size(); i++)   {
        char firstNumber = 'p';
        char secondNumber = 'p';

        string tempString = lines[i];
        string combinedNumbers;

        tempString = replaceSpelledNumbers(tempString);




        for(int j = 0; j < tempString.length(); j++)   {



            //check for digit
            if(isdigit(tempString.at(j)))   {


                //only set first digit once
                if(firstNumber == 'p')   {
                    firstNumber = tempString.at(j);
                    continue;
                }

                secondNumber = tempString.at(j);

            }


        }

        //check if there was only one number
        if(secondNumber == 'p')   {
            secondNumber = firstNumber;
        }

        combinedNumbers = string(1, firstNumber) + string(1, secondNumber);

        int fullNumber = stoi(combinedNumbers);

        cout << " Adding: " << i << " " << fullNumber << endl;

        numbers.push_back(fullNumber);







    }

    int total = 0;
    for(int i = 0; i < numbers.size(); i++)   {
        total += numbers[i];
    }

    return total;

}


string replaceSpelledNumbers(string currentLine)   {

    string returnString = replaceAll(currentLine, "one", "o1ne");
    returnString = replaceAll(returnString, "two", "t2wo");
    returnString = replaceAll(returnString, "three", "thr3ee");
    returnString = replaceAll(returnString, "four", "fo4ur");
    returnString = replaceAll(returnString, "five", "fi5ve");
    returnString = replaceAll(returnString, "six", "si6x");
    returnString = replaceAll(returnString, "seven", "sev7en");
    returnString = replaceAll(returnString, "eight", "eig8ht");
    returnString = replaceAll(returnString, "nine", "ni9ne");





    return returnString;
}




string replaceAll(string currentString, string search, string replace)   {
    int startPos = 0;




    while ((startPos = currentString.find(search, startPos)) != string::npos)   {


        currentString.replace(startPos, search.length(), replace);
        startPos += replace.length();

    }

    return currentString;



}


