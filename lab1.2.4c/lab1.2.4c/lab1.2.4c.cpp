#include <iostream>

using namespace std;

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

struct Stack {
    int value;
    Stack* pNext;
} *top, *second_top;

inline void initStack() {
    top = NULL;
    second_top = NULL;
}

bool isEmpty() {
    return top == NULL;
    
}

bool is_secondEmpty() {
    return second_top == NULL;
}

Stack* addElement(Stack* _top, int _value) {
    Stack* el = new Stack;
    el->value = _value;
    el->pNext = _top;
    _top = el;
    return _top;
}

void addRand() {
    int elements;
    cout << "How many numbers do you want to add?" << endl;
    elements = console_work();
    for (int i = 0; i < elements; i++) {
        top = addElement(top, rand());
    }
}

void deleteElement() {
    if (!isEmpty()) {
        Stack* el = top;
        top = top->pNext;
        delete el;
    }
    else {
        cout << "Stack is emptyyyyy" << endl;
    }
}

void move_toSecond() {
    Stack* el = top;
    top = top->pNext;
    el->pNext = second_top;
    second_top = el;
}

void add_fromSecond() {
    Stack* el = second_top;
    second_top = second_top->pNext;
    el->pNext = top;
    top = el;
}

void printStack(Stack* _top) {
    if (_top != NULL) {
        Stack* el = _top;
        do {
            cout << el->value << endl;
            el = el->pNext;
        } while (el != NULL);
        
    }
    else {
        cout << "Stack is empty" << endl;
    }
}

void printSecondStack(Stack* _second_top) {
    if (_second_top != NULL) {
        Stack* el = _second_top;
        do {
            cout << el->value << endl;
            el = el->pNext;
        } while (el != NULL);

    }
    else {
        cout << "secondStack is empty" << endl;
    }
}



void menu() {
    int number, value, comd;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "\nChoose the number of comand:\n";
        cout << "1. Stack emptiness check\n";
        cout << "2. Adding an item to the top of the stack\n";
        cout << "3. Removing an item from the top of the stack\n";
        cout << "4. Add n number of items to the stack\n";
        cout << "5. Display the current stack state on the screen\n";
        cout << "6. Display the current deleteStack state on the screen\n";
        cout << "0. End the program\n";
        cout << "Your Choice: ";
        number = console_work(); 

        if (number == 1) { //Проверка на пустоту
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "Stack is NOT empty" << endl;
            }
        }
        else if (number == 2) { //Добавить элемент в стек
            cout << "Specify the origin of the element: \n 1. Creating a new element \n 2. Selecting it from the top of the auxiliary stack\nYour Choice: ";
            comd = console_work();
            if (comd == 1) {
                cout << "Write a number: ";
                value = console_work();
                top = addElement(top, value);
            }
            else if (comd == 2) {
                if (!is_secondEmpty()) {
                    add_fromSecond();
                }
                else {
                    cout << "secondStack is empty.\n";
                }
            }
            else
                cout << "Input error. Repeat the command\n";
        }
        else if (number == 3) { //Удалить элемент из стека
            if (!isEmpty()) {
                cout << "Specify the command: \n 1. Really delete the element with full memory release \n 2. Include it in the top of the auxiliary stack of deleted items\nYour choice: ";
                comd = console_work();
                if (comd == 1) {
                    deleteElement();
                }
                else if (comd == 2) {
                    if (top != NULL) {
                        move_toSecond();
                    }
                    else {
                        cout << "Stack is empty.\n";
                    }
                }
                else {
                    cout << "Input error. Repeat the command\n";
                }
            }
            else {
                cout << "Stack is empty so can't remove\n";
            }
        }
        else if (number == 4) {  //Добавить несколько рандомных чисел
            addRand();
        }
        else if (number == 5) { //Вывести состояние стека
            printStack(top);
        }
        else if (number == 6) { //Вывести состояние вспомогательного стека
            printSecondStack(second_top);
        }
        else if (number == 0) //Завершить работу
            break;
        else
            cout << "Input error. Repeat the command\n";
    }
}





int main()
{
    initStack();
    srand(static_cast<unsigned int>(time(0))); //инициализация генератора случайных чисел rand
    menu();
    return 0;
}
