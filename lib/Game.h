//
// Created by weders on 14.04.2020.
//

#ifndef KEYBOARD_NINJA_GAME_H
#define KEYBOARD_NINJA_GAME_H

#include <ctime>
#include <iostream>
#include <string>
#include "ArrProc.h"
#include "InputCheck.h"

using namespace std;

extern int Flag;
extern int Points;
extern string currentArray[100];
extern int Token;
extern bool selectionLevel[5];
extern long int levelTime;
extern string levelOne[100], levelTwo[100], levelThree[100], levelFour[100],
        levelFive[100]; //Массив уровней



void SelectLevel()
{
    cout << endl;

    string key;

    cin >> key;

    Token = InputCheck(key);


    switch (InputCheck(key)) {
    case 1:
        ArrayWrite(levelOne);
        break;
    case 2:
        ArrayWrite(levelTwo);
        break;
    case 3:
        ArrayWrite(levelThree);
        break;
    case 4:
        ArrayWrite(levelFour);
        break;
    case 5:
        ArrayWrite(levelFive);
        break;
    default:
        cout << "Уровни от 1 до 5 написано же было,еще раз введи\n";
        SelectLevel();
        break;
    }
}

void PrintGameMenu()
{
    cout << "╔═════════════════════════════════════════════════════════════════"
            "═══════════════════════════════════════╗\n"
            "║•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
            "•••••••••••••••••••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••╔═════════════════════════════════════════"
            "═══════════════╗•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••║              Прогресс Прохождения "
            "Уровней              ║•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••╟─────────────────────────────────────────"
            "───────────────╢•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••║              0 - не пройдено 1 - "
            "пройдено              ║•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••╚═════════════════════════════════════════"
            "═══════════════╝•••••••••••••••••••••••║\n"
            "║••••••••••••╔═══════════════╤═══════════════╤═══════════════╤════"
            "═══════════╤═══════════════╗•••••••••••║\n"
            "║••••••••••••║               │               │               │    "
            "           │               ║•••••••••••║\n"
            "║••••••••••••║ Уровень 1 - "
         << selectionLevel[0] << " │ Уровень 2 - " << selectionLevel[1]
         << " │ Уровень 3 - " << selectionLevel[2] << " │ Уровень 4 - "
         << selectionLevel[3] << " │ Уровень 5 - " << selectionLevel[4]
         << " ║•••••••••••║\n"
            "║••••••••••••║               │               │               │    "
            "           │               ║•••••••••••║\n"
            "║••••••••••••╚═══════════════╧═══════════════╧═══════════════╧════"
            "═══════════╧═══════════════╝•••••••••••║\n"
            "║•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
            "•••••••••••••••••••••••••••••••••••••••║\n"
            "╚═════════════════════════════════════════════════════════════════"
            "═══════════════════════════════════════╝\n";
}

void TimeChoose()
{
    cout << "Выбери свое время в секундах\n";
    string key = "0";
    while (InputCheck(key)==0) {
        cin >> key;


}
levelTime = InputCheck(key);
    cout << "Начали \n Пиши слово : ";
}

int WriteCheck(const string& right, const string& input)
{
    if (input == right) {
        cout << "\nВерно" << endl;
        return 0;
    } else
        return 1;
}

int TimerCheck(long int start)
{
    time_t timer1 = time(NULL);

    if (timer1 - start < levelTime) {
        return (levelTime - (timer1 - start));
    } else {
        return 0;
    }
}

int SetTask()
{

    time_t start = time(NULL);
    // cout << start << endl;
    string word = currentArray[start % 100];
    string input;
    cout << "Пиши слово : " << word << endl;
    cin >> input;
    if (WriteCheck(word, input) == 0) {
        TimerCheck(start);
        if (TimerCheck(start) > 0) {
            cout << "Молодец" << endl;
            Points += TimerCheck(start);
            cout << "Очков=" << Points << endl;
            return 0;
        } else {
            cout << "Не влез во время";
        }
    }
    if (WriteCheck(word, input) == 1) {
        cout << "Не верно,ты опечатался\n";
        cout << "Ты проиграл" << endl;
        Flag = 0;
        return 0;
    } else
        ;

    return 0;
}
void StartGame()
{
    selectionLevel[0] = false;
    selectionLevel[1] = false;
    selectionLevel[2] = false;
    selectionLevel[3] = false;
    selectionLevel[4] = false;
    string key;



    while (1) {
        while (Points <= 400) {
            cout << "Выбор уровня 1 - 5";
            SelectLevel();

            TimeChoose();
            Flag = 1;
            while ((Flag != 0) && (Points <= 400)) {
                SetTask();
            }
        }
        selectionLevel[Token - 1] = true;

        PrintGameMenu();
        cout << "Продолжишь или нет?Если да то введи любую кнопку ,если нет "
                "введи "
                "99\n";
        cin >> key;
        InputCheck(key);
        if(InputCheck(key)==99) {
            cout << "GAME OVER\n";
        }
        Points = 0;
    }

}

#endif // KEYBOARD_NINJA_GAME_H
