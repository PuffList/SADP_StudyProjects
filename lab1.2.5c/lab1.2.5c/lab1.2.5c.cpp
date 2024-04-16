#include <iostream>

using namespace std;

//#define maxSize 5;

const int maxSize = 4;

struct Queue {
    int data[maxSize];
    int head;
    int tail;
    int count;

    void initQueue() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxSize;
    }

    void addElement(int value) {
        if (!isFull()) {
            data[tail] = value;
            tail++;

            if (tail == maxSize) {
                tail = NULL;
            }

            count++;
        }
        else {
            cout << "Queue is Full" << endl;
        }
    }

    void deleteElement() {
        if (!isEmpty()) {
            head++;

            if (head == maxSize) {
                head = NULL;
            }

            count--;
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }

    void printQueue() {
        if (!isEmpty()) {
            int i = head;
             do{
                cout << data[i] << endl;
                i++;
                if (i == maxSize) {
                    i = NULL;
                } 
             } while (i != tail);
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }

} queue;

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

void menu() {
    int number, value;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "Enter the command number:\n";
        cout << "1. Check if the queue is empty\n";
        cout << "2. Check if the queue is full\n";
        cout << "3. Add an element to the end of the queue\n";
        cout << "4. Remove an element from the beginning of the queue\n";
        cout << "5. Display the current state of the queue on the screen\n";
        cout << "0. Terminate the program\n";
        cout << "Enter the command number: ";
        number = console_work();


        if (number == 1) { //1. Проверка пустоты очереди
            if (queue.isEmpty()) {
                cout << "\nQueue is empy\n";
            }
            else {
                cout << "\nQueue is NOT empy\n";
            }
        }
        else if (number == 2) { //2. Проверка заполненности очереди
            if (queue.isFull()) {
                cout << "\nQeueu is full\n";
            }
            else {
                cout << "\nQeueu is NOT full\n";
            }
        }
        else if (number == 3) { //3. Добавить элемент в конец очереди

            if (!queue.isFull()) {
                cout << "\nEnter a natural number:";
                value = console_work();
                queue.addElement(value);
            }
            else {
                cout << "\nQueue is full.\n";
            }

        }
        else if (number == 4) { //4. Удалить элемент из начала очереди стека

            queue.deleteElement();
        }
        else if (number == 5) { //5. Вывод текущего состояния очереди на экран
            queue.printQueue();
        }

        else if (number == 0) //0. Завершить работу
            break;
        else {
            cout << "\nInput error. Repeat the command\n";
        }

    }
}



int main()
{
    queue.initQueue();
    menu();
    return 0;
}

