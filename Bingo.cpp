#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

// To display array
void displayArray(vector<int> &Array, char check = 'y')
{
    // For clearing console screen
    if (check == 'y')
    {
        system("cls");
    }

    for (int i = 1; i < 26; i++)
    {
        if (i == 1)
        {
            for (int j = 0; j < 26; j++)
            {
                cout << "-";
            }
            cout << endl;
        }
        cout << "| " << setfill('0') << setw(2) << Array[i - 1] << " ";
        if (i % 5 == 0)
        {
            cout << "|" << endl;
            for (int j = 0; j < 26; j++)
            {
                cout << "-";
            }
            cout << endl;
        }
    }
    Sleep(1000);
}

// To display timer
void displayTimer(int num = 3)
{
    system("cls");
    while (num > 0)
    {
        cout << "Computer's Turn" << endl;
        cout << num << endl;
        Sleep(400);
        system("cls"); // Clear the console screen
        num--;
    }
}

// To convert a string to uppercase
string toUpper(string str)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        result += toupper(str[i]);
    }
    return result;
}

// Computer's functionality
void Computer(vector<int> &computerArray)
{
    int num = 0;

    // Assigning values to computer's array
    for (int i = 0; i < 25; i++)
    {
        num = (rand() % 25) + 1;
        for (int j = 0; j < 25; j++)
        {
            if (num == computerArray[j])
            {
                num = (rand() % 25) + 1;
                j = 0;
            }
        }
        computerArray[i] = num;
    }

    // Printing computer's array
    // displayArray(computerArray);
}

// Filling user's array
void User(vector<int> &userArray, string name)
{

    // Clearing console screen
    system("cls");

    char option; // We used char instead of int because if we use int and the user enters a char, the system does not respond with sanity
    bool check = true;
    int num = 0;
    int n = 0;
    do
    {
        if (n > 0)
        {
            cout << "\nInvalid input." << endl;
        }
        cout << "\n<============== " << name << "'S BINGO ==============>" << endl
             << "\nPress '1' to auto-fill your Bingo array." << endl
             << "Press '2' to fill your Bingo array yourself." << endl
             << "Press '3' to exit." << endl;
        cin >> option;
        n++;
        if (option == 49 || option == 50 || option == 51) // Since ASCII of 1,2,3 is 49, 50, 51
        {
            check = false;
            n = 0;
        }
    } while (check);

    switch (option)
    {
    case 49:
        // For clearing console screen
        system("cls");
        for (int i = 0; i < 25; i++)
        {
            num = rand() % 25 + 1;
            while (num < 1 || num > 25) // input validation
            {
                num = rand() % 25 + 1;
            }
            for (int j = 0; j < 25; j++)
            {
                if (num == userArray[j])
                {
                    num = rand() % 25 + 1;
                    while (num < 1 || num > 25) // input validation
                    {
                        num = rand() % 25 + 1;
                    }
                    j = -1;
                }
            }
            userArray[i] = num;
        }
        break;

    case 50:
        // For clearing console screen
        system("cls");
        for (int i = 0; i < 25; i++)
        {
            cout << "Enter value: ";
            cin >> num;

            while (num < 1 || num > 25) // input validation
            {
                cout << "\nInvalid input." << endl;
                cout << "\nEnter again: ";
                cin >> num;
            }
            for (int j = 0; j < 25; j++)
            {
                if (num == userArray[j])
                {
                    cout << "Enter again: ";
                    cin >> num;

                    while (num < 1 || num > 25) // input validation
                    {
                        cout << "\nInvalid input." << endl;
                        cout << "\nEnter again: ";
                        cin >> num;
                    }
                    j = -1;
                }
            }
            userArray[i] = num;
            // For printing array
            displayArray(userArray);
        }
        break;

    case 51:
        exit(0);
        break;
    }
}

// Check if a line is complete
int isLineComplete(vector<int> &arr)
{
    int count = 0;

    // Rows
    for (int i = 0; i < 5; i++)
    {
        if ((arr[i * 5] == -1 || arr[i * 5] == 0) && (arr[i * 5 + 1] == -1 || arr[i * 5 + 1] == 0) && (arr[i * 5 + 2] == -1 || arr[i * 5 + 2] == 0) && (arr[i * 5 + 3] == -1 || arr[i * 5 + 3] == 0) && (arr[i * 5 + 4] == -1 || arr[i * 5 + 4] == 0))
        {
            if (arr[i * 5] == 0 && arr[i * 5 + 1] == 0 && arr[i * 5 + 2] == 0 && arr[i * 5 + 3] == 0 && arr[i * 5 + 4] == 0)
            {
            }
            else
            {
                arr[i * 5] = 0;
                arr[i * 5 + 1] = 0;
                arr[i * 5 + 2] = 0;
                arr[i * 5 + 3] = 0;
                arr[i * 5 + 4] = 0;
                count++;
            }
        }
    }

    // Columns
    for (int i = 0; i < 5; i++)
    {
        if ((arr[i] == -1 || arr[i] == 0) && (arr[i + 5] == -1 || arr[i + 5] == 0) && (arr[i + 10] == -1 || arr[i + 10] == 0) && (arr[i + 15] == -1 || arr[i + 15] == 0) && (arr[i + 20] == -1 || arr[i + 20] == 0))
        {
            if (arr[i] == 0 && arr[i + 5] == 0 && arr[i + 10] == 0 && arr[i + 15] == 0 && arr[i + 20] == 0)
            {
            }
            else
            {
                arr[i] = 0;
                arr[i + 5] = 0;
                arr[i + 10] = 0;
                arr[i + 15] = 0;
                arr[i + 20] = 0;
                count++;
            }
        }
    }

    // Diagonals
    if ((arr[0] == -1 || arr[0] == 0) && (arr[6] == -1 || arr[6] == 0) && (arr[12] == -1 || arr[12] == 0) && (arr[18] == -1 || arr[18] == 0) && (arr[24] == -1 || arr[24] == 0))
    {
        if (arr[0] == 0 && arr[6] == 0 && arr[12] == 0 && arr[18] == 0 && arr[24] == 0)
        {
        }
        else
        {
            arr[0] = 0;
            arr[6] = 0;
            arr[12] = 0;
            arr[18] = 0;
            arr[24] = 0;
            count++;
        }
    }
    if ((arr[4] == -1 || arr[4] == 0) && (arr[8] == -1 || arr[8] == 0) && (arr[12] == -1 || arr[12] == 0) && (arr[16] == -1 || arr[16] == 0) && (arr[20] == -1 || arr[20] == 0))
    {
        if (arr[4] == 0 && arr[8] == 0 && arr[12] == 0 && arr[16] == 0 && arr[20] == 0)
        {
        }
        else
        {
            arr[4] = 0;
            arr[8] = 0;
            arr[12] = 0;
            arr[16] = 0;
            arr[20] = 0;
            count++;
        }
    }

    return count;
}

int main()
{
    // For clearing console screen
    system("cls");

    // Seeding the random number generator with the current time
    srand(time(NULL));

    // User's Interface:-
    //  To set user's name
    string name;
    cout << "\nEnter your Name: ";
    cin.ignore(-1, '\n');
    getline(cin, name);
    name = toUpper(name);

    // Printing user's array
    vector<int> userArray(25);
    // for (int i = 1; i < 26; i++)
    // {
    //     if (i == 1)
    //     {
    //         for (int j = 0; j < 26; j++)
    //         {
    //             cout << "-";
    //         }
    //         cout << endl;
    //     }
    //     cout << "| " << setfill('0') << setw(2) << "XX"
    //          << " ";
    //     if (i % 5 == 0)
    //     {
    //         cout << "|" << endl;
    //         for (int j = 0; j < 26; j++)
    //         {
    //             cout << "-";
    //         }
    //         cout << endl;
    //     }
    // }

    // Getting values from user (Asks if user wants to input values himself or auto-place)
    User(userArray, name);

    vector<int> computerArray(25);
    Computer(computerArray);

    // Game Logic
    vector<int> calledNumbers(25, 0);
    vector<int> computerCalledNumbers(25, 0);
    bool isGameOver = false;
    int isLineCompleteCountUser = 0;
    int isLineCompleteCountComputer = 0;

    cout << "Let's Play BINGO!" << endl;

    while (!isGameOver)
    {
        system("cls");
        // Printing User's Array
        displayArray(userArray);

        // User's Turn
        int calledNumber;
        cout << "\nEnter a number (1-25): ";
        cin >> calledNumber;

        while (calledNumber < 1 || calledNumber > 25 || calledNumbers[calledNumber - 1] == 1)
        {
            cout << "Invalid input or number already called.\nEnter again: ";
            cin >> calledNumber;
        }

        calledNumbers[calledNumber - 1] = 1;
        computerCalledNumbers[calledNumber - 1] = 1;

        // Check if the number is present in the user's array
        auto it = find(userArray.begin(), userArray.end(), calledNumber);
        if (it != userArray.end())
        {
            int index = distance(userArray.begin(), it);
            userArray[index] = -1;

            // Printing Updated User's Array
            displayArray(userArray);

            // Check if a line is completed
            int count = isLineComplete(userArray);
            if (count != 0)
            {
                isLineCompleteCountUser += count;
            }
            // Check if the user has won
            if (isLineCompleteCountUser >= 5)
            {
                system("cls");
                // For printing array
                cout << "<=== Computer's Array ===>" << endl;
                displayArray(computerArray, 'n');
                cout << endl;
                // For printing array
                cout << "<===== User's Array =====>" << endl;
                displayArray(userArray, 'n');
                cout << "\nCongratulations, " << name << "! You have won Bingo!" << endl
                     << endl;
                isGameOver = true;
                break;
            }

            // Updating computer's array
            it = find(computerArray.begin(), computerArray.end(), calledNumber);
            index = distance(computerArray.begin(), it);
            computerArray[index] = -1;

            // Check if a line is completed
            count = isLineComplete(computerArray);
            if (count != 0)
            {
                isLineCompleteCountComputer += count;
            }
            // Check if the computer has won
            if (isLineCompleteCountComputer >= 5)
            {
                system("cls");
                // For printing array
                cout << "<=== Computer's Array ===>" << endl;
                displayArray(computerArray, 'n');
                cout << endl;
                // For printing array
                cout << "<===== User's Array =====>" << endl;
                displayArray(userArray, 'n');
                cout << "\nSorry, " << name << ". The computer has won Bingo!" << endl
                     << endl;
                isGameOver = true;
                break;
            }
        }

        // Computer's Turn
        displayTimer();
        int computerCalledNumber = (rand() % 25) + 1;
        while (computerCalledNumbers[computerCalledNumber - 1] == 1)
        {
            computerCalledNumber = (rand() % 25) + 1;
        }

        computerCalledNumbers[computerCalledNumber - 1] = 1;
        calledNumbers[computerCalledNumber - 1] = 1;

        // Check if the number is present in the computer's array
        it = find(computerArray.begin(), computerArray.end(), computerCalledNumber);
        if (it != computerArray.end())
        {
            int index = distance(computerArray.begin(), it);
            computerArray[index] = -1;

            // Check if a line is completed
            int count = isLineComplete(computerArray);
            if (count != 0)
            {
                isLineCompleteCountComputer += count;
            }
            // Check if the computer has won
            if (isLineCompleteCountComputer >= 5)
            {
                system("cls");
                // For printing array
                cout << "<=== Computer's Array ===>" << endl;
                displayArray(computerArray, 'n');
                cout << endl;
                // For printing array
                cout << "<===== User's Array =====>" << endl;
                displayArray(userArray, 'n');
                cout << "\nSorry, " << name << ". The computer has won Bingo!" << endl
                     << endl;
                isGameOver = true;
                break;
            }

            // Updating user's array
            it = find(userArray.begin(), userArray.end(), computerCalledNumber);
            index = distance(userArray.begin(), it);
            userArray[index] = -1;

            // Printing Updated User's Array
            // displayArray(userArray);

            // Check if a line is completed
            count = isLineComplete(userArray);
            if (count != 0)
            {
                isLineCompleteCountUser += count;
            }
            // Check if the user has won
            if (isLineCompleteCountUser >= 5)
            {
                system("cls");
                // For printing array
                cout << "<=== Computer's Array ===>" << endl;
                displayArray(computerArray, 'n');
                cout << endl;
                // For printing array
                cout << "<===== User's Array =====>" << endl;
                displayArray(userArray, 'n');
                cout << "\nCongratulations, " << name << "! You have won Bingo!" << endl
                     << endl;
                isGameOver = true;
                break;
            }
        }
    }

    return 0;
}