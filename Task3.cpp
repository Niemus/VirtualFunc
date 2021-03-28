#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /*Подключаем необходимые библиотеки*/
#include <string.h>
using namespace std;    /*Пространство имен*/
//string DecHex(int);     // Переменная для функции расчета 16-чной

/*______________________________________________________________*/

class num {
    public:
    virtual string ShowNUM() {      //Класс "num" с виртуальной фун-ей ShowNum()
        return 0;
    }
};

/*______________________________________________________________*/

class outhex: public num {
    public:
    string ShowNUM(int NB){
        if (NB == 0) return("0");
        string s;                               //Класс "outhex", который наследует класс "num"
        while (NB) {
        s = "0123456789ABCDEF"[NB%16]+s;
        NB/=16; }
        return(s);
        }
    };

/*______________________________________________________________*/

class outoct: public num {
    public:
    int ShowNUM(int N){
        string s;
        while (N > 0) {
            s += N % 8 + '0';
            N /= 8; }
        reverse(s.begin(), s.end());
        return atoi(s.c_str());
        }
};

/*______________________________________________________________*/

int main() 
{
    setlocale (LC_ALL, "rus");
    int a, b;
    outhex OH1;
    outoct OC1;
    
    cout << "Your number: "; cin >> a;
    cout << "Hexadecimal number system: " << OH1.ShowNUM(a) << endl;
    cout << "___________________________________________" << endl;
    cout << "Your number: "; cin >> b;
    cout << "Octal number system: " << OC1.ShowNUM(b) << endl << endl;

    system("pause");
}