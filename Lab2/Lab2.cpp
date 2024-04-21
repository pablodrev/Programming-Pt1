#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int size = 10;
    int X[size] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    vector<int> new_X;
    int first_zero_index = -1; // Индекс первого нуля
    int second_zero_index = -1; // Индекс второго нуля

    // Находим первый ноль, перебирая с начала
    for (int i = 0; i < size; i++)
    {
        if (X[i] == 0)
        {
            first_zero_index = i;
            break;
        }
    }

    // Находим второй ноль, перебирая с конца
    for (int i = size; i > 0; i--)
    {
        if (X[i] == 0)
        {
            second_zero_index = i;
            break;
        }
    }

    // Добавляем в новый вектор все элементы кроме тех, которые находятся между нулями
    for (int j = 0; j < size; j++)
    {
        // Пропускаем, если индекс находится между нулями
        if (first_zero_index < j  && j < second_zero_index)
        {
            continue;
        }
        // Добавляем элемент в вектор
        new_X.push_back(X[j]);
    }

    // Вывод на экран
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
        cout << X[i] << " ";
    cout << endl << "Индекс первого нуля: " << first_zero_index << endl;
    cout << "Индекс второго нуля: " << second_zero_index << endl;
    cout << "Получившийся массив: ";
    for (int i = 0; i < new_X.size(); i++)
        cout << new_X[i] << " ";
}