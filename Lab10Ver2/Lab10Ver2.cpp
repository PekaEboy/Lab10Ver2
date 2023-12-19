// Lab10Ver2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Student {
    char Name[100];
    char Group[100];
    int Ochenka[3];
};

float srball(Student a) {
    return (float)(a.Ochenka[0] + a.Ochenka[1] + a.Ochenka[2]) / 3;
}

struct Node {
    Student val;
    Node* next;

    Node(Student _val) : val(_val), next(nullptr) {};
};

struct List {
    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(Student _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val.Name << " ";
            p = p->next;
        }
        cout << endl;
    }
    
    Node* find(Student _val) {
        Node* p = first;
        while (p && (p->val.Name != _val.Name)) p = p->next;
        return (p && (p->val.Name != _val.Name)) ? p : nullptr;
    }

    void remove(Student _val) {
        Node* p = first;
        Node* delp = find(_val);
        if (delp != nullptr) {
            while (p && (p->next == delp)) p = p->next;
            if (p) {
                p->next = delp->next->next;
            }
        }
    }
}; 
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List l;
    char vvod[2];
    Student dude;
    const int N = 1000;
    char t[N];
    bool Flag = true;
    cout << "Номера команды: \n1. Добавлять элементов в конце списка\n2. Удалить студента по ФИО\n3. Вставить студента на указанную списку\n4. Отредактировать данные студента на указанные позиции\n5. Отсортировать студентов в списке по возрастанию среднего балла\n6. Вывести всех студентов указанной группы\n7. Очистить список\n8. Сохранить список в файл\n9. Загрузить список из файла\n0. Выход из программ\n";
    while (Flag) {
        cout << "Введите номер команды: ";
        cin.getline(vvod, 2);
        switch (atoi(vvod)) {
        case 1:
            cout << "Введите ФИО студента: ";
            cin.getline(dude.Name, 100);
            cout << "Введите группу студента: ";
            cin.getline(dude.Group, 100);
            cout << "Введите оценка по 3 предметам студента: ";
            for (int j = 0; j < 3; j++) {
                cin >> dude.Ochenka[j];
            }
            cin.getline(t, N);
            l.push_back(dude);
            break;
        case 2:
            cout << "Введите ФИО студента: ";
            cin.getline(dude.Name, 100);
            l.remove(dude);
            break;
        case 0:
            Flag = false;
            break;
        }
        l.print();

    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
