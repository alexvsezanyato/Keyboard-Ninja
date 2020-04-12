#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

//Список переменных
const int SIZE_MASSIVE = 100; //Константа, размер массивов для выборки слов из текстовых файлов
long int levelTime; //Время для уровней
int Points;
bool selectionLevel[5]; //Выбор уровня
int Token;
int Flag = 1;
using namespace std;

string currentArray[SIZE_MASSIVE];
string levelOne[SIZE_MASSIVE], levelTwo[SIZE_MASSIVE], levelThree[SIZE_MASSIVE], levelFour[SIZE_MASSIVE], levelFive[SIZE_MASSIVE]; //Массив уровней

//Методы
void arrayWrite(string *lev);
void getLevel();
void readLevelFile(const string &path, string *lev);
void timeChoose();
int writeCheck(const string &right);
int timerCheck(long int start);
int setTask();
void setGameMenu();
void startGame();

void menu1() {
    int key;
    cout << "+-------------------------------------------------------------------"
            "---------------+\n"
            "|   Keyboard        "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "|           Ninja   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "+-------------------------------------------------------------------"
            "---------------+\n"
            "| /                  |                                              "
            "            \\  |\n"
            "|                    |  Тут есть 5 уровней сложности .              "
            "               |\n"
            "|                    |  Они регулируют длину слов.                  "
            "               |\n"
            "| \\                  |  Время выбирает сам ниндзя в секундах.      "
            "             /  |\n"
            "+-------------------+-----------------------------------------------"
            "---------------+\n";
    cout << "Введите 1 если все понятно\n";
    cin >> key;
    if (key != 1) {
        cout << "Повторим!\n";
        menu1();
    } else
        ;
}
void menu2() {
    int key;
    cout << "\n"
            "\n"
            "\n"
            "\n"
            "+-------------------------------------------------------------------"
            "----------------+\n"
            "|   Keyboard        "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
            "|           Ninja   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
            "+-------------------------------------------------------------------"
            "----------------+\n"
            "|                   | Ваша задача : написать слово до того как "
            "выйдет время.        |\n"
            "|                   | Каждая оставшаяся секунда записывается в доп "
            "баллы,           |\n"
            "|                   | из этого следует ,что минимальный балл это 0. "
            "                |\n"
            "|                   | Уровень будет считаться проиденным если балл "
            "за прохождение   |\n"
            "|                   | больше 400.         "
            "                |\n"
            "|                   | Читкоды-(Devlog,RandOff).                     "
            "                |\n"
            "|                   |                                               "
            "                |\n"
            "|                   |                                               "
            "                |\n"
            "+-------------------+-----------------------------------------------"
            "----------------+\n";
    cout << "Введите 1 если все понятно(вернуть 1 окно : 2,читы :3)\n";
    cin >> key;
    switch (key) {
        case 1:

            getLevel();
            break;
        case 2:
            menu1();
            // case3:cin>>cheat;
        default:
            cout << "Видимо пропустил,еще раз посмотри ,что жать надо";
            menu2();
    }
}
// void array_test() {
// for (const auto &i : currentArray) {

//  cout << i << endl;
// }
//}

int main() {

    readLevelFile("1s.txt", levelOne);
    readLevelFile("2s.txt", levelTwo);
    readLevelFile("3s.txt", levelThree);
    readLevelFile("4s.txt", levelFour);
    readLevelFile("5s.txt", levelFive);
    menu1();
    setGameMenu();

    menu2();
    startGame();
    // array_test();
}

void arrayWrite(string *lev) {
    for (int i = 0; i < SIZE_MASSIVE; i++) {
        currentArray[i] = lev[i];
    }
}

void getLevel() {

    int key;
    cin >> key;
    Token = key;

    switch (key) {
        case 1:
            arrayWrite(levelOne);
            break;
        case 2:
            arrayWrite(levelTwo);
            break;
        case 3:
            arrayWrite(levelThree);
            break;
        case 4:
            arrayWrite(levelFour);
            break;
        case 5:
            arrayWrite(levelFive);
            break;
        default:
            cout << "Уровни от 1 до 5 написано же было,еще раз введи";
            getLevel();
            break;
    }
}

void readLevelFile(const string &path, string *lev) {

    ifstream file(path);

    string str;

    int i = 0;
    while (getline(file, str, '\n')) {

        lev[i] = str;
        i++;
    }
}

void timeChoose() {
    int key;
    cout << "Выбери свое время в секундах";
    cin >> key;
    levelTime = key;
    cout << "Начали \n Пиши слово : ";
}

int writeCheck(const string &right) {
    string in;

    while ((in != right)) {

        cin >> in;
        if (in == right) {
            cout << "\nВерно" << endl;
            return 1;
        }
        if (in != right) {
            cout << "Не верно,заново пиши";
        }
    }
    return 0;
}

int timerCheck(long int start) {
    time_t timer1 = time(NULL);

    if (timer1 - start < levelTime) {

        return (levelTime - (timer1 - start));
    } else {

        return 0;
    }
}

int setTask() {

    time_t start = time(NULL);
    // cout << start << endl;
    string word = currentArray[start % 100];

    cout << "Пиши слово : " << word << endl;

    if (writeCheck(word) != 3) {
        timerCheck(start);
        if (timerCheck(start) > 0) {
            cout << "Молодец" << endl;
            Points += timerCheck(start);
            cout << Points;
            return 1;
        }
        Flag = 0;

    } else
        ;

    return 0;
}

void setGameMenu() {
    cout << "\n+---------------------------------------------------------+\n"
            "|                         |Читкоды заблокированы          |\n"
            "| 1Уровень- "
         << selectionLevel[0]
         << "             |                               |\n"
            "|                         |                               |\n"
            "| 2Уровень- "
         << selectionLevel[1]
         << "             +-------------------------------+\n"
            "|                                                         |\n"
            "| 3Уровень- "
         << selectionLevel[2]
         << "                                             |\n"
            "|                                                         |\n"
            "| 4Уровень- "
         << selectionLevel[3]
         << "                                             |\n"
            "|                                                         |\n"
            "| 5Уровень- "
         << selectionLevel[4]
         << "                                             |\n"
            "|                                                         |\n"
            "+---------------------------------------------------------+\n";
}

void startGame() {
    selectionLevel[0] = false;
    selectionLevel[1] = false;
    selectionLevel[2] = false;
    selectionLevel[3] = false;
    selectionLevel[4] = false;
    char key = 'i';
    while (key != 'n') {
        while (Points <= 400) {
            cout << "Выбор уровня 1 - 5";
            getLevel();

            timeChoose();
            Flag = 1;
            while ((Flag != 0) && (Points <= 100)) {

                setTask();
            }
        }
        selectionLevel[Token] = true;

        setGameMenu();
        cout << "Продолжишь или нет?Если да то введи любую кнопку ,если нет введи n";
        cin >> key;
        Points = 0;
    }
    exit(1);
}
