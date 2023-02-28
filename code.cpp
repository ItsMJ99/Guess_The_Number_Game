#include <iostream>
#include <random>
using namespace std;

void game()
{
    int range[2];
    cout << "Enter range (START END) = ";
    cin >> range[0] >> range[1];

    if (range[0] >= range[1])
    {
        int s = range[0];
        range[0] = range[1];
        range[1] = s;
        cout << "Range Set Successfully......" << endl;
    }
}

int main()
{
    system("cls");
    int opt;
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
        game();
        break;

    case 2:
        system("cls");
        exit(0);
        break;

    default:
        system("cls");
        goto MENU;
    }
    // 1
}