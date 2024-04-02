#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int amountSymbols;
string oper;
int nums[10]{ 1,2,3,4,5,6,7,8,9,0 };
string letters[26]{ "a","b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
string letters2[26]{ "A","B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
string specialSymbols[9]{ "!","@", "#", "$", "%", "&", "*","_", "-" };

void clearConsole()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void password()
{
    for (int i = 0; i < amountSymbols; i++)
    {
        int random1 = rand() % 4;
        int random2;

        if (random1 == 0)
        {
            random2 = rand() % 10;
            cout << nums[random2];
        }
        if (random1 == 1)
        {
            random2 = rand() % 26;
            cout << letters[random2];
        }
        if (random1 == 2)
        {
            random2 = rand() % 26;
            cout << letters2[random2];
        }
        if (random1 == 3)
        {
            random2 = rand() % 9;
            cout << specialSymbols[random2];
        }
    }
}

void error1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

    cout << "\nВыберите число сиволов в указанных пределах!";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void error2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

    cout << "\nВыбрано неверное действие!\n\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    do
    {
        cout << "1. Генератор пароля.\n";
        cout << "2. Выход из программы.\n\n";
        cout << "Выберите действие: ";
        cin >> oper;

        if (oper == "1")
        {
            clearConsole();

            cout << "\nВведите количество символов в пароле(от 5 до 30): ";
            cin >> amountSymbols;
            clearConsole();

            if (amountSymbols >= 5 && amountSymbols <= 30)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

                cout << "\n\tПароль: ";

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                password();
            }
            else
            {
                clearConsole();
                error1();
            }
            cout << endl << endl;

        }

        else if (oper == "2")
        {
            clearConsole();
            cout << "\nВыход...\n";
            exit(0);
        }

        else
        {
            clearConsole();
            error2();
        }

    } while (oper != "2");
}