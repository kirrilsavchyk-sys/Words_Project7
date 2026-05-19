// Задача: 7 (Слова)
// Група: Статистика-2
// Студент: Савчук К. О. та Крикливий Є. С.
// Опис: Заголовний файл, де міститься опис базового класу СЛОВО та його спадкоємців.
#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Word {
protected:
    int type;      // 1-іменник, 2-дієслово, 3-прикметник
    int gender;    // 1-чол, 2-жін, 3-сер
    int number;    // 1-однина, 2-множина
    int person;    // 1, 2, 3 особа
    int wordCase;  // 1-7 (відмінки)

    vector<string> prefixes;
    vector<string> roots;
    vector<string> suffixes;
    string ending;

public:
    Word();
    virtual ~Word();

    virtual void inputConsole();
    virtual void outputConsole();
    virtual void inputFromFile(const string& filename);
    virtual void outputToFile(const string& filename);

    void setParts(vector<string> p, vector<string> r, vector<string> s, string e);
    void printParts();

    vector<string> splitSyllables();
    string mergeSyllables(vector<string> syls);

    void setProps(int t, int g, int n, int p, int c);
    void changeProp(int newNum, int newCase);
};

class Noun : public Word {
public:
    Noun();
};

class Verb : public Word {
public:
    Verb();
};

class Adjective : public Word {
public:
    Adjective();
};

#endif
