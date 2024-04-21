#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h> 

using namespace std;

// Структура, описывающая стадион
struct Stadium {
    string name;
    string activity;
    string adress;
    short year_built;
    int capacity;
    int n_fields;

    void Print() {
        cout << "\t\t" << "Название: " << name << endl;
        cout << "\t\t" << "Вид спорта: " << activity << endl;
        cout << "\t\t" << "Адрес: " << adress << endl;
        cout << "\t\t" << "Год постройки: " << year_built << endl;
        cout << "\t\t" << "Вместимость: " << capacity << endl;
        cout << "\t\t" << "Количество площадок: " << n_fields << endl;
    }
};

// Заменяет пробелы на нижние подчеркивания, т.е. ' ' на '_'. 
// Нужно для корректной записи в файл строк, содержащих пробелы.
string spaceToUnderscore(string text)
{
    replace(text.begin(), text.end(), ' ', '_');
    return text;
}

// Заменяет нижние пдочеркивания на пробелы, т.е. '_' на ' '.
// Нужно для того, чтобы пользователю выводились строки с пробелами, а не с нижними подчеркиваниями.
string underscoreToSpace(string text)
{
    replace(text.begin(), text.end(), '_', ' ');
    return text;
}

void readInt(int &num) {
    cin >> num;
    while (!cin.good() || num < 0)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t\tНеверно введено значение. Введите натуральное число: ";
        cin >> num;
    }
}
void readInt(short &num) {
    cin >> num;
    while (!cin.good() || num < 0)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t\tНеверно введено значение. Введите натуральное число: ";
        cin >> num;
    }
}

// Выводит список со стадионами на экран
void printStadiumList(vector<Stadium> stadium_list) {

    if (stadium_list.size() == 0)
    {
        cout << '\t' << "Нет добавленных стадионов!" << endl;
        cout << '\t' << "Вы можете создать новый стадион (create) или загрузить стадионы из файла (load)" << endl;
        return;
    }
    else
    {
        cout << '\t' << "Информация о добавленных стадионах: " << endl;
        cout << '\t' << "================================" << endl;
        for (size_t i = 0; i < stadium_list.size(); i++)
        {
            stadium_list[i].Print();
            cout << '\t' << "================================" << endl;
        }
    }
}
// Создание нового стадиона
// Список со стадионами передается по ссылке, т.к. необходимо добаить стадион в уже существующий список
void createStadium(vector<Stadium>& stadium_list) {

    Stadium s;
    cout << '\t' << "Вы открыли меню создания стадиона." << endl;
    cout << '\t' << "Введите название стадиона: ";
    cin.ignore(256, '\n'); // Игнорируем \n, чтобы getline не принял его. Иначе getline считает \n и остановится
    getline(cin, s.name);
    cout << '\t' << "Введите вид спорта на стадионе: ";
    getline(cin, s.activity);
    cout << '\t' << "Введите адрес стадиона: ";
    getline(cin, s.adress);
    cout << '\t' << "Введите год постройки стадиона: ";
    readInt(s.year_built);
    //cin >> s.year_built;
    cout << '\t' << "Введите вместимость стадиона: ";
    readInt(s.capacity);
    //cin >> s.capacity;
    cout << '\t' << "Введите количество площадок стадиона: ";
    readInt(s.n_fields);
    //cin >> s.n_fields;

    stadium_list.push_back(s);
    cout << '\t' << "Стадион успешно добавлен!" << endl;
}

void removeStadium(vector<Stadium>& stadium_list) {
    unsigned short id;
    cout << "Введите номер стадиона, который нужно удалить: ";
    cin >> id; 
    while (!cin.good() || id > stadium_list.size())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t\tНеверно введено значение. Повторите ввод: ";
        cin >> id;
    }
    stadium_list.erase(stadium_list.cbegin() + id - 1);
    cout << "Стадион успешно удален!" << endl;
}

void findStadium(vector<Stadium> stadium_list) {
    if (stadium_list.size() == 0)
    {
        cout << '\t' << "Нет добавленных стадионов!" << endl;
        cout << '\t' << "Вы можете создать новый стадион (create) или загрузить стадионы из файла (load)" << endl;
        return;
    }
    string value;
    unsigned short stadiums_found = 0;
    cout << "Введите значение одного из полей для поиска: ";
    cin.ignore(256, '\n');
    getline(cin, value);
    cout << endl;
    for (size_t i = 0; i < stadium_list.size(); i++)
    {
        // Если хотя-бы одно поле структуры содержит в себе искомое значение
        if (stadium_list[i].name.find(value) != string::npos || 
            stadium_list[i].activity.find(value) != string::npos ||
            stadium_list[i].adress.find(value) != string::npos ||
            to_string(stadium_list[i].year_built).find(value) != string::npos ||
            to_string(stadium_list[i].capacity).find(value) != string::npos ||
            to_string(stadium_list[i].n_fields).find(value) != string::npos)
        {
            stadiums_found++;
            cout << '\t' << "Найден стадион:" << endl;
            stadium_list[i].Print();
        }
    }
    if (stadiums_found == 0)
    {
        cout << "Не найдено ни одного стадиона." << endl;
    }
}

// Запись вектора со стадионами в файл
void writeStadiums(vector<Stadium> stadium_list) {

    ofstream fout("stadiums.txt", ios::out);
    if (!fout.is_open())
    {
        cout << '\t' << "Ошибка при открытии файла!";
    }
    else
    {
        // Записываем поля структуры через пробел, например: Great_Staduim 2023 40000 4
        // В строковых полях пробелы заменяются на нижние подчеркивания.
        for (size_t i = 0; i < stadium_list.size(); i++)
        {
            fout << spaceToUnderscore(stadium_list[i].name) << " "
                << spaceToUnderscore(stadium_list[i].activity) << " "
                << spaceToUnderscore(stadium_list[i].adress) << " "
                << stadium_list[i].year_built << " "
                << stadium_list[i].capacity << " " 
                << stadium_list[i].n_fields << endl;
        }

        fout.close();       
        cout << '\t' << "Сохранение прошло успешно!" << endl;
    }
}

// Загрузить стадионы из файла в вектор
vector<Stadium> loadStadiums() {

    ifstream fin("stadiums.txt");
    if (!fin.is_open())
    {
        cout << '\t' << "Ошибка при открытии файла!" << endl;
    }
    else
    {
        Stadium s;
        vector<Stadium> stadium_list;

        // При считывании преобразуем нижние подчеркивания в пробелы.
        while (fin >> s.name >> s.activity >> s.adress >> s.year_built >> s.capacity >> s.n_fields)
        {
            s.name = underscoreToSpace(s.name);
            s.activity = underscoreToSpace(s.activity);
            s.adress = underscoreToSpace(s.adress);
            stadium_list.push_back(s);
        }
        fin.close();
        cout << '\t' << "Чтение файла прошло успешно." << endl;
        cout << '\t' << "Загружено стадионов: " << stadium_list.size() << endl;
        cout << '\t' << "Чтобы вывести список стадионов, введите \"print\"" << endl;
        return stadium_list;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string instruction;
    vector<Stadium> stadium_list;
    while (true)
    {

        cout << endl << "Введите команду (help, чтобы узнать, какие команды есть): ";
        cin >> instruction;
        
        cout << endl;
        if (instruction == "create") {
            createStadium(stadium_list);
        }
        else if (instruction == "print")
        {
            printStadiumList(stadium_list);
        }
        else if (instruction == "write")
        {
            writeStadiums(stadium_list);
        }
        else if (instruction == "load")
        {
            stadium_list = loadStadiums();
        }
        else if (instruction == "remove")
        {
            removeStadium(stadium_list);
        }
        else if (instruction == "find")
        {
            findStadium(stadium_list);
        }
        else if (instruction == "help")
        {
            cout << '\t' << "Справка по командам: " << endl;
            cout << '\t' << "create - создать новый объект" << endl;
            cout << '\t' << "print - вывести все добавленные объекты" << endl;
            cout << '\t' << "write - сохранить объекты в файл" << endl;
            cout << '\t' << "load - загрузить объекты из файла" << endl;
            cout << '\t' << "remove - удалить элемент по номеру" << endl;
            cout << '\t' << "find - найти элемент" << endl;
            cout << '\t' << "clear - очистить консоль" << endl;
            cout << '\t' << "exit - завершить работу программы" << endl;
        }
        else if (instruction == "clear")
        {
            system("cls");
        }
        else if (instruction == "exit")
        {
            break;
        }
        else
        {
            cout << "Команда не распознана! Чтобы получить список комманд, введите help." << endl;
        }
    }
}