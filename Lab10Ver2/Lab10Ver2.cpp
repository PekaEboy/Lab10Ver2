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
    int Number = 0;
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
            cout << p->val.Number << ") ФИО студента: " << p->val.Name << " - Группа студента: " << p->val.Group << " - Средний балл по 3 предметам: " << srball(p->val) << endl;
            p = p->next;
        }
        cout << endl;
    }
    
    Node* find(int _val) {
        Node* p = first;
        while (p && p->val.Number != _val) p = p->next;
        return (p && p->val.Number == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;

    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(string _val) {

        if (is_empty()) return;
        if (first->val.Name == _val) {
            remove_first();
            return;
        }
        else if (last->val.Name == _val) {
    		remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val.Name != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "Данного студента нет в списках" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }


    void update_numbers() {
        if (is_empty()) return;
        Node* p = first;
        int i = 1;
        while (p) {
            p->val.Number=i;
            i++;
            p=p->next;
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
    Student man;
    const int N = 1000;
    char t[N];
    bool Flag = true;
    Node* p;
    int i = 0;
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
            dude.Number = dude.Number+1;
            l.push_back(dude);
            break;
        case 2:
            cout << "Введите ФИО студента: ";
            cin.getline(dude.Name, 100);
            l.remove(dude.Name);
            l.update_numbers();
            break;
        case 3:
            cout << "Введите номер студента: ";
            cin.getline(t, N);
            p = l.find(atoi(t));
            if (p) {
                cout << "Введите ФИО студента: ";
                cin.getline(dude.Name, 100);
                cout << "Введите группу студента: ";
                cin.getline(dude.Group, 100);
                cout << "Введите оценка по 3 предметам студента: ";
                for (int j = 0; j < 3; j++) {
                    cin >> dude.Ochenka[j];
                }
                cin.getline(t, N);
                dude.Number = atoi(t);
                man = p->val;
                p->val = dude;
                p = p->next;
                while (p) {
                    if (i % 2 == 0) {
                        dude = p->val;
                        p->val = man;
                    }
                    else {
                        man = p->val;
                        p->val = dude;
                    }
                    p = p->next;
                    i++;
                }
                if (i % 2 == 0) {
                    l.push_back(man);
                }
                else {
                    l.push_back(dude);
                }
                l.update_numbers();
            }
            else {
                cout << "Данного студента нет в списках: " << endl;
            }
            break;
        case 4:
            cout << "Введите номер студента: ";
            cin.getline(t, N);
            p = l.find(atoi(t));
            if (p) {
                cout << "Введите ФИО студента: ";
                cin.getline(dude.Name, 100);
                cout << "Введите группу студента: ";
                cin.getline(dude.Group, 100);
                cout << "Введите оценка по 3 предметам студента: ";
                for (int j = 0; j < 3; j++) {
                    cin >> dude.Ochenka[j];
                }
                cin.getline(t, N);
                dude.Number = atoi(t);
                p->val = dude;
                l.update_numbers();
            }
            else {
                cout << "Данного студента нет в списках: " << endl;
            }
            break;
        case 5:
            if (!l.is_empty()) {
                for (Node* q = l.first; q; q = q->next) {
                    for (Node* r = q->next; r; r = r->next) {
                        if (srball(q->val) > srball(r->val)) {
                            dude = r->val;
                            r->val = q->val;
                            q->val = dude;
                        }
                    }
                }
            }
            l.update_numbers();
            break;
        case 6:
            cout << "Введите название группы: ";
            cin.getline(t, N);
            p = l.first;
            while (p) {
                if (strcmp(p->val.Group, t) == 0) {
                    cout << p->val.Number << ") ФИО студента: " << p->val.Name << " - Группа студента: " << p->val.Group << " - Средний балл по 3 предметам: " << srball(p->val) << endl;

                }
            }
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
