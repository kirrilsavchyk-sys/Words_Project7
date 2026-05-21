// Задача: 7 (Слова)
// Група: Статистика-2
// Студент: Савчук К. О.
// Опис: Тестовий файл, у якому викликаються всі функції модуля та перевіряється їхня робота.

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Words.h"

using namespace std;

// Допоміжна функція для швидкого та гарного виведення результатів тесту
void runTest(Word& w, string wordTypeStr) {
    cout << "\n[" << wordTypeStr << "]" << endl;
    w.outputConsole();
    vector<string> syllables = w.splitSyllables();
    cout << "Кількість складів: " << syllables.size() << endl;
    cout << "Поділ на склади: ";
    for (size_t i = 0; i < syllables.size(); i++) {
        cout << syllables[i];
        if (i < syllables.size() - 1) cout << "-";
    }
    cout << endl;
}

int main() {
    // Встановлюємо кодування UTF-8 для правильного відображення української мови
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    cout << "Оберіть режим вводу даних:" << endl;
    cout << "1 - З клавіатури (консоль)" << endl;
    cout << "2 - З тестового файлу (test.txt)" << endl;
    cout << "3 - АВТОМАТИЧНИЙ ТЕСТ (Різні типи слів: Іменник, Дієслово, Прикметник)" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        Word w;
        w.inputConsole();
        runTest(w, "Ручний ввід");
        w.outputToFile("output.txt");
        cout << "\nДані успішно записані у файл output.txt" << endl;
    }
    else if (choice == 2) {
        Word w;
        w.inputFromFile("test.txt");
        runTest(w, "Слово з файлу");
        w.outputToFile("output.txt");
        cout << "\nДані успішно записані у файл output.txt" << endl;
    }
    else if (choice == 3) {
        cout << "\n=========== РОЗШИРЕНА ТЕСТОВА ЧАСТИНА ===========" << endl;

        // 1. Тест Іменника (Noun) - слово "замок"
        Noun n;
        n.setParts({"за"}, {"мок"}, {}, ""); 
        n.setProps(1, 1, 1, 3, 1); // 1-іменник, 1-чол.рід, 1-однина
        runTest(n, "Тип: ІМЕННИК (Клас Noun)");

        // 2. Тест Дієслова (Verb) - слово "переробляти" (багато частин)
        Verb v;
        v.setParts({"пере"}, {"роб"}, {"ля"}, {"ти"}); 
        v.setProps(2, 0, 2, 0, 0); // 2-дієслово
        runTest(v, "Тип: ДІЄСЛОВО (Клас Verb)");

        // 3. Тест Прикметника (Adjective) - слово "найкращий"
        Adjective a;
        a.setParts({"най"}, {"кращ"}, {}, {"ий"}); 
        a.setProps(3, 1, 1, 0, 1); // 3-прикметник
        runTest(a, "Тип: ПРИКМЕТНИК (Клас Adjective)");

        // 4. Перевірка складного збігу голосних підряд
        Word w_complex;
        w_complex.setParts({""}, {"аеропорт"}, {}, ""); 
        runTest(w_complex, "Тип: СКЛАДНЕ СЛОВО (збіг голосних)");

        cout << "\n=================================================" << endl;
    }
    else {
        cout << "Помилка: невірний вибір!" << endl;
        return 1;
    }

    return 0;
}
