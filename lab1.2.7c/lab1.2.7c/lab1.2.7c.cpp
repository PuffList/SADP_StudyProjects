#include <iostream>
#include <random>
#include "windows.h"

using namespace std;

int const generate_time = 5;

int console_work() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nWrong writing, try again \n" << endl;
    }

    return a;
}

int randomizer(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

struct QueueItem {
    char value;
    QueueItem* pNext;
} *head, *tail;


void initQueueItem() {
    head = NULL;
    tail = NULL;
}

bool isEmpty() {
    return head == NULL;
}

void addElement(char _value) {
    QueueItem* ch = new QueueItem;
    ch->value = _value;
    ch->pNext = NULL;
    if (isEmpty()) {
        head = tail = ch;
    }
    else {
        tail->pNext = ch;
        tail = ch;
    }
}

void deleteElement() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        QueueItem* d_value = head;
        head = head->pNext;
        delete d_value;
    }
}

void deleteQueue() {
    if (isEmpty()) {
        cout << "Queue has already empty" << endl;
    }
    else {        
        while (!isEmpty()) {
            QueueItem* _value = head;
            head = head->pNext;
            delete _value;
            
        }
        cout << "Memory cleared";
    }
}

void printQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        QueueItem* _value = head;
        do {
            cout << _value->value << " ";
            _value = _value->pNext;
        } while (_value != NULL);
                     
        cout << endl;
    } 
}

void base_ofProgram(int time) {
    int r_num1, r_num2, time_counter = 0;
    char r_char;
    while (true) {
        r_num1 = randomizer(1, 3);
        r_num2 = randomizer(1, 100);
        if (r_num2 % 2 == 0) {
            cout << r_num1 << " items will be added to the queue" << endl;
            for (int i = 0; i < r_num1; i++) {
                r_char = static_cast<char>(randomizer(65, 90));
                addElement(r_char);
            }
        }
        else {
            cout << r_num1 <<  " items will be delete from the queue" << endl;
            for (int i = 0; i < r_num1; i++) {
                if (!isEmpty()) {
                    deleteElement();
                }
                else {
                    if (i == 0) {
                        cout << "Queue have already empty" << endl;
                    }
                    else {
                        cout << "Queue have been cleaned" << endl;
                    }
                    break;
                }
            }
        }
        printQueue();
        cout << "--------------------------------" << endl;
        time_counter++;
        if (time_counter == time) break;
        Sleep(1000);
    }
}

void menu() {
    int number;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "\nChoose the number of comand:\n";
        cout << "1. Start the program\n";
        cout << "0. End the program with memory scrubbed\n";
        cout << "Your Choice: ";
        number = console_work();

        if (number == 1) {
            base_ofProgram(generate_time);
        }
        else if (number == 0) {
            deleteQueue();
            break;
        }
        else{
            cout << "Input error. Repeat the command\n";
        }
            
    }
}


int main()
{
    initQueueItem();
    menu();
    return 0;
}

