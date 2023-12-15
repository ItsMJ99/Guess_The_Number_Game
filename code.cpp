#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int Number_Generator(int min, int max)
{
    int ans = min + rand() % (max - min + 1);
    return ans;
}

void Guessing(int ans, int diff, int min, int max)
{
    int chances, guess;
    if (diff == 1)
        chances = 12;
    if (diff == 2)
        chances = 6;
    if (diff == 3)
        chances = 3;

    cout << "You have " << chances << " chances to guess the number between " << min << " and " << max << endl;
    cout << "Good Luck :)" << endl;
    cout << "Press any key to continue..." << endl;
    getch();
    system("cls");
    for (int i = 1; i <= chances; i++)
    {
        system("cls");
        cout << "Enter Chance " << i << " Guess = ";
        cin >> guess;
        if (guess == ans)
        {
            cout << "Congratulations! You guessed the number correctly.\nPress any key to exit" << endl;
            getch();
            break;
        }
        else if (guess < min || guess > max)
        {
            cout << "Entered Number is out of the Specified Range.\nPress any key to continue" << endl;
        }
        else if (guess > ans)
        {
            cout << "Entered Number is Greater than the EXPECTED number.\nPress any key to continue" << endl;
        }
        else if (guess < ans)
        {
            cout << "Entered Number is Smaller than the EXPECTED number.\nPress any key to continue" << endl;
        }

        if (i == chances)
        {
            cout << "OOPS You ran out of Chances\nThe Number was " << ans << "\nBetter Luck Next Time\nGame Over\nGG.\nPress any key to exit" << endl;
            getch();
        }
        else
        {
            getch();
        }
    }
}

void Game(int diff)
{
    int ANS;
MAINGAME:
    system("cls");
    int range[2];
    cout << "Enter range (START END) = ";
    cin >> range[0] >> range[1];

    if (range[0] > range[1])
    {
        int swp = range[0];
        range[0] = range[1];
        range[1] = swp;
    }
    if (range[0] == range[1])
    {
        cout << "Invalid Range !!!\nPress any Key to go back to setting Range" << endl;
        getch();
        system("cls");
        goto MAINGAME;
    }
    system("cls");
    cout << "Range Set Successfully" << endl;
    ANS = Number_Generator(range[0], range[1]);
    Guessing(ANS, diff, range[0], range[1]);
}

int main()
{
    system("cls");
    int opt, diff;
MENU:
    cout << "<=============> Menu <=============>" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit Game" << endl;
    cout << "\nEnter Choice = ";
    cin >> opt;

    switch (opt)
    {
    case 1:
        system("cls");
        cout << "<=============> Difficulty Level <=============> " << endl;
    LEVEL:
        cout << "1. Easy   (12 Guesses)" << endl;
        cout << "2. Normal (6 Guesses)" << endl;
        cout << "3. Hard   (3 Guesses)" << endl;
        cout << "\nEnter Choice = ";
        cin >> diff;
        if (diff < 1 || diff > 3)
        {
            cout << "Invalid Difficulty Level !!!\nPress any key to continue" << endl;
            goto LEVEL;
        }
        Game(diff);
        goto MENU;

    case 2:
        system("cls");
        cout << "Thank You for Playing the Game" << endl;
        break;

    default:
        cout << "Invalid Option !!!" << endl;
        getch();
        system("cls");
        goto MENU;
    }
    return 0;
}
