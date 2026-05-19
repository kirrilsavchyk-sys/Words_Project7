// Задача: 7 (Слова)
// Група: Статистика-2
// Студент: Савчук К. О.
// Опис: Тестовий файл, у якому викликаються всі функції модуля та перевіряється їхня робота.

#include <iostream>
#include <string>
#include <windows.h> // ДОДАНО: бібліотека для роботи з консоллю Windows
#include "Words.h"

using namespace std;

int main() {
    // ДОДАНО: Встановлюємо кодування UTF-8 для правильного відображення української мови
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    cout << "Оберіть режим вводу даних:" << endl;
    cout << "1 - З клавіатури (консоль)" << endl;
    cout << "2 - З тестового файлу (test.txt)" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    Word w;

    if (choice == 1) {
        w.inputConsole();
    }
    else if (choice == 2) {
        w.inputFromFile("test.txt");
    }
    else {
        cout << "Помилка: невірний вибір!" << endl;
        return 1;
    }

    cout << "\n--- Результат роботи програми ---" << endl;
    w.outputConsole();
    cout << "\n--- Аналіз слова ---" << endl;
    vector<string> syls = w.splitSyllables();
    cout << "Кількість складів: " << syls.size() << endl;
    cout << "Склади: ";
    for (int i = 0; i < syls.size(); i++) {
        cout << syls[i];
        if (i != syls.size() - 1) cout << "-";
    }
    cout << endl << endl;
    w.outputToFile("output.txt");
    cout << "Дані успішно записані у файл output.txt" << endl;

    return 0;
}