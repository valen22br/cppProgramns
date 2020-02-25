#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string inputString;

string run_length_encode(const string &inputString)
{
    string outputString = "";
    int count;
    for (int i = 0; i < inputString.length(); i++)
    {
        count = 1;
        while (inputString[i] == inputString[i + 1])
        {
            count++;
            i++;
        }
        if (count > 1)
        {
            outputString += inputString[i] + to_string(count);
        }
        else
        {
            outputString += inputString[i];
        }
    }

    return outputString;
};

string run_length_decode(const string &inputString)
{
    string outputString = "";
    int count, repetitions;
    char tempChar[10];
    for (int i = 0; i < inputString.length(); i++)
    {
        if (isdigit(inputString[i]))
        {
            inputString.copy(tempChar, 1, i);
            repetitions = atoi(tempChar);
            for (int j = 1; j < repetitions; j++)
            {
                outputString += inputString[i - 1];
            }
        }
        else
        {
            outputString += inputString[i];
        }
    }
    return outputString;
}

int main()
{
    cout << "Enter with a string to be coded. (ie. WWWBBWWWWW)";
    cin >> inputString;
    if (inputString.length() == 0)
    {
        inputString = "WWWBBWWWWW";
    }

    cout << "run_length_encode " << run_length_encode(inputString) << endl;
    cout << "run_length_decode " << run_length_decode(run_length_encode(inputString)) << endl;
    return 0;
}