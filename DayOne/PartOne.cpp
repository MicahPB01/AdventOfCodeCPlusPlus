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


