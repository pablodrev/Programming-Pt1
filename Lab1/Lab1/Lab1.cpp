#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    const int m = 5, n = 6; // Количество строк и столбцов
    int Z[m][n]; // Матрица размера M на N
    int V[m]; // Вектор размера M
    int neg_sum = 0; // Сумма отрицательных элементов по строкам
    
    // Заполним матрицу и выведем её
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Z[i][j] = -5 + rand() % 10;
            cout.width(3);
            cout << Z[i][j];
        }
        V[i] = Z[i][0];
        cout << endl;
    }

    // Перебор по нечетным строкам
    for (int i = 0; i < m; i+=2) {
        neg_sum = 0; // Обнуляем сумму
        for (int j = 0; j < n; j++) {
            // Если число отрицательное, то прибавляем в сумму
            if (Z[i][j] < 0) {
                neg_sum += Z[i][j];
            }
        }
        // Меняем первый элемент столбца на полученную сумму, обновляем значение в векторе
        V[i] = Z[i][0] = neg_sum;
    }
    //  Повторно выводим матрицу
    cout << endl << "Измененная матрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(3);
            cout << Z[i][j];
        }
        cout << endl;
    }
    // Выводим вектор
    cout << endl << "Вектор из элементов первого столбца: " << endl;
    for (int i = 0; i < m; i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}
