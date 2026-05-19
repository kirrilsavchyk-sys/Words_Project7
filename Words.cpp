// Задача: 7 (Слова)
// Група: Статистика-2
// Студент: Савчук К. О. та Крикливий Є. С.
// Опис: Файл модуля з реалізацією методів класу СЛОВО та його спадкоємців.
#include "Words.h"

Word::Word() {
    type = 0;
    gender = 0;
    number = 0;
    person = 0;
    wordCase = 0;
    ending = "";
}

Word::~Word() {
}

void Word::inputConsole() {
    string temp;

    cout << "Введіть префікс (якщо немає, пишіть -): ";
    cin >> temp;
    if (temp != "-") prefixes.push_back(temp);

    cout << "Введіть корінь: ";
    cin >> temp;
    roots.push_back(temp);

    cout << "Введіть суфікс (якщо немає, пишіть -): ";
    cin >> temp;
    if (temp != "-") suffixes.push_back(temp);

    cout << "Введіть закінчення (якщо немає, пишіть -): ";
    cin >> temp;
    if (temp != "-") ending = temp;
}
void Word::outputConsole() {
    cout << "Будова слова: ";
    printParts();
}

void Word::inputFromFile(const string& filename) {
    ifstream fin(filename);
    if (fin.is_open()) {
        fin >> ending;
        fin.close();
    }
    else {
        cout << "Помилка відкриття файлу!" << endl;
    }
}

void Word::outputToFile(const string& filename) {
    ofstream fout(filename);
    if (fout.is_open()) {
        fout << "Закінчення: " << ending << endl;
        fout.close();
    }
}

void Word::setParts(vector<string> p, vector<string> r, vector<string> s, string e) {
    prefixes = p;
    roots = r;
    suffixes = s;
    ending = e;
}

void Word::printParts() {
    for (int i = 0; i < prefixes.size(); i++) {
        cout << prefixes[i] << "-";
    }
    for (int i = 0; i < roots.size(); i++) {
        cout << roots[i] << "-";
    }
    for (int i = 0; i < suffixes.size(); i++) {
        cout << suffixes[i] << "-";
    }
    cout << ending << endl;
}

vector<string> Word::splitSyllables() {
    vector<string> res;
    string word = "";

    // Склеюємо все слово до купи
    for (int i = 0; i < prefixes.size(); i++) word += prefixes[i];
    for (int i = 0; i < roots.size(); i++) word += roots[i];
    for (int i = 0; i < suffixes.size(); i++) word += suffixes[i];
    word += ending;

    // СТУДЕНТСЬКА МИЛИЦЯ: Видаляємо невидимий BOM від файлу txt на САМОМУ ПОЧАТКУ
    if (word.length() >= 3 && (unsigned char)word[0] == 0xEF && (unsigned char)word[1] == 0xBB && (unsigned char)word[2] == 0xBF) {
        word = word.substr(3);
    }

    string syl = "";
    string vowels_utf8[10] = { "а", "е", "є", "и", "і", "ї", "о", "у", "ю", "я" };

    for (int i = 0; i < word.length(); ) {
        bool isVowel = false;
        string letter = "";

        if (i + 1 < word.length() && (unsigned char)word[i] >= 0xD0 && (unsigned char)word[i] <= 0xD1) {
            letter = word.substr(i, 2);
            i += 2;
            for (int j = 0; j < 10; j++) {
                if (letter == vowels_utf8[j]) isVowel = true;
            }
        }
        else {
            letter = word.substr(i, 1);
            i += 1;
            unsigned char c = (unsigned char)letter[0];

            if (c == 0xE0 || c == 0xE5 || c == 0xAA || c == 0xE8 || c == 0xB3 ||
                c == 0xBF || c == 0xEE || c == 0xF3 || c == 0xFE || c == 0xFF ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                isVowel = true;
            }
        }

        syl += letter;

        if (isVowel) {
            res.push_back(syl);
            syl = "";
        }
    }

    if (syl != "") {
        if (res.size() > 0) res[res.size() - 1] += syl;
        else res.push_back(syl);
    }

    return res;
}
    string Word::mergeSyllables(vector<string> syls) {
    string res = "";
    for (int i = 0; i < syls.size(); i++) {
        res += syls[i];
    }
    return res;
}

void Word::setProps(int t, int g, int n, int p, int c) {
    type = t;
    gender = g;
    number = n;
    person = p;
    wordCase = c;
}

void Word::changeProp(int newNum, int newCase) {
    number = newNum;
    wordCase = newCase;
}

Noun::Noun() {
    type = 1;
}

Verb::Verb() {
    type = 2;
}

Adjective::Adjective() {
    type = 3;
}
