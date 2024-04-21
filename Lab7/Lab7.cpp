#include "list.h"
#include <iostream>
#include <windows.h>


void readInt(int& num) {
    std::cin >> num;
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "\t\tНеверно введено значение. Введите целое число: ";
        std::cin >> num;
    }
}

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Задание: \n\
Дана последовательность целых чисел и числа B1, B2, B3.\n\
Включить эти числа в последовательность, расположив их после второго нулевого элемента.\n\n";
    // Задание:
    // Дана последовательность целых чисел и числа B1, B2, B3.
    // Включить эти числа в последовательность, расположив их после второго нулевого элемента.

    int n;
    cout << "Введите количество элементов списка (натуральное число): ";
    readInt(n);
    List* list = new List(n);
    list->Print();

    // Найти индекс второго нуля.
    ListNode* current = list->getHead();
    int zero_count = 0; 
    int insert_index = -1; // Индекс элемента, после которого нужно вставить числа
    
    // Перебираем все элементы и находим индекс второго нуля
    for (int i = 0; i < n; i++)
    {
        if (current->value == 0)
            zero_count++;
        if (zero_count == 2)
        {
            insert_index = i;
            break;
        }  
        current = current->next;
    }
    // Вставка чисел B1, B2, B3
    int b1, b2, b3;
    cout << "Введите число B1: ";
    readInt(b1);
    cout << "Введите число B2: ";
    readInt(b2);
    cout << "Введите число B3: ";
    readInt(b3);
    
    list->Insert(insert_index, b1);
    list->Insert(insert_index + 1, b2);
    list->Insert(insert_index + 2, b3);
    cout << "Результат: ";
    list->Print();
}
