#include <iostream>
#include <time.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    const int m = 5, n = 3; // Параметры матрицы
    int size = m; // Размер массива с максимальными элементами
    int max_elements[m]; // Массив с максимальными элементами в строках

    // Создание матрицы
    int** M = new int* [m];
    for (int i = 0; i < m; i++)
        M[i] = new int[n];

    // Вывод матрицы
    cout << "Исходная матрица: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = -4 + rand() % 10;
            cout.width(3);
            cout << M[i][j];
        }
        cout << endl;
    }

    // Получаем максимальные элементы по строкам
    for (int i = 0; i < m; i++)
    {
        max_elements[i] = M[i][0];
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] > max_elements[i])
            {
                max_elements[i] = M[i][j];
            }
        }
    }

    // Сортировка максимальных элементов и соответсвующих строк
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (max_elements[j] > max_elements[j + 1])
            {
                swap(max_elements[j], max_elements[j + 1]);
                swap(M[j], M[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    // Вывод преобразованной матрицы
    cout << endl << "Преобразованная матрица: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout.width(3);
            cout << M[i][j];
        }
        cout << endl;
    }

    // Удаление массива из памяти
    for (int i = 0; i < m; i++)
        delete[] M[i];

    delete[] M;
}
