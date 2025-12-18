#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Массив имен файлов
    string filenames[3] = { "file1.txt", "file2.txt", "file3.txt" };

    for (int i = 0; i < 3; i++) {
        ofstream file(filenames[i]);

        if (!file.is_open()) {
            cout << "Ошибка открытия файла " << filenames[i] << endl;
            return 1;
        }

        // Генерация 10 случайных чисел
        for (int j = 0; j < 10; j++) {
            int random_number = rand() % 10 + 1; // от 1 до 10
            file << random_number;

            if (j < 9) {
                file << " "; // пробел между числами
            }
        }

        file.close();
        cout << "Создан файл: " << filenames[i] << endl;
    }

    cout << "Все файлы успешно созданы!" << endl;
    return 0;
}