#include <iostream>
#include <vector>

using namespace std;


std::string getInputString();

//find average and sum of numbers
void challengeOne();

//reverse a string
void challengeTwo();


//find if number is odd or even
void challengeThree();


int test() {
    cout << "Hello, World!" << std::endl;

    //challengeOne();

    //challengeTwo();

    challengeThree();

    return 0;
}



void challengeOne ()   {

    int numInputs;

    cout << "Please enter the number of inputs you would like to use!" << endl;
    cin >> numInputs;

    vector<int> inputs;

    for(int i = 0; i < numInputs; i++)   {
        cout << "Input.txt " << (i+1) << endl;

        int currentInput;


        cin >> currentInput;

        inputs.assign(i, currentInput);

    }

    int sum = 0;

    for(int i = 0; i < inputs.size(); i++)   {
        sum += inputs.at(i);
    }

    cout << sum << endl;

    int mean;

    mean = sum / numInputs;

    cout << mean;

}


void challengeTwo()   {

    string input;


    cout << "Please enter string to be flipped" << endl;

    getline(cin, input);

    string reverse;

    reverse.resize(input.size());

    for(int i = 0; i < input.size(); i++)   {
        reverse.at(i) = input.at(input.size() - i - 1);
    }

    cout << reverse << endl;



}

void challengeThree()   {

    string stringInput;
    int input;

    cout << "Please enter a number: " << endl;
    getline(cin, stringInput);

    input = stoi(stringInput);

    switch(input % 2)   {
        case 0:
            cout <<"The number is even" << endl;
            break;
        case 1:
            cout << "The number is odd" << endl;
            break;
        default:
            cout << "Error" << endl;
            break;
    }




}
