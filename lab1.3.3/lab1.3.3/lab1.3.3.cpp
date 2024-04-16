#include <iostream>

using namespace std;


const int MAX_SIZE = 11;

int counter;

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

struct LinckList {
    string value;
    int next;
} list[MAX_SIZE];


void initLinckList() {
    list[0].value = "HEAD";
    list[0].next = 0;
    for (int i = 1; i < MAX_SIZE; i++) {
        list[i].next = -1;  
    }
    counter = 0;
}

bool isEmpty() {
    return list[0].next == 0;
}

bool isFull() {
    return counter == MAX_SIZE - 1;
}

void searchElement(string element) {
    if (!isEmpty()) {
        int current = list[0].next;
        while (current != 0 && list[current].value != element) {
            current = list[current].next;
        }
        if (current != 0) {
            cout << "Element was found on position " << current++ << endl;
        }
        else {
            cout << "Element wasn't found\n";
        }

    }
    else {
        cout << "List is empty" << endl;
    }
}

int find(string _value, int mod) {
    int current = list[0].next;
    if (mod == 1) { // ищем сам элемент
        while ((current != 0) && (list[current].value != _value)) {
            current = list[current].next;
        }
    }
    else if (mod == 0) { //ищем предшественника
        int pr = 0;
        while (current != 0) {
            if (list[current].value == _value) {
                break;
            }
            current = list[current].next;
            pr = list[pr].next;
        }
        return pr;
    }
    if (current != 0) {
        return current;
    }
    else {
        return -1;
    }
}


void printList() {
    if (!isEmpty()) {
        int current = list[0].next;
        while (current != 0) {
            cout << list[current].value << " in a memory location " << current << endl;
            current = list[current].next;
        }
    }
    else {
        cout << "List is empty" << endl;
    }
}

void addAfter(string element) {
    if (!isFull()) {
        string _value;
        if (!isEmpty()) {
            int i = -1, j = 0;
            cout << "Enter the value of the item AFTER which you want to add the new item: ";
            
            while (i == -1) {
                cin >> _value;
                i = find(_value, 1);
                if (i == -1) {
                    cout << "String " << _value << "didn't find, try again" << endl;
                }
            }
            for (j = 1; j < MAX_SIZE; j++) { 
                if (list[j].next == -1){
                    break;
                }
            }
            list[j].next = list[i].next;
            list[i].next = j;
            list[j].value = element;
        }
        else {
            list[1].value = element;
            list[1].next = 0;
            list[0].next = 1;
        }

        counter++;
    }
    else {
        cout << "List is full" << endl;
    }

}

void addBefore(string element) {
    if (!isFull()) {
        string _value;
        if (!isEmpty()) {
            int i = -1, j = 0, s = -1;
            cout << "Enter the value of the item BEFORE which you want to add the new item: ";
            
            while (i == -1 || s == -1) {
                cin >> _value;
                i = find(_value, 1);
                s = find(_value, 0);
                if (i == -1 || s == -1) {
                    cout << "String " << _value << "didn't find, try again" << endl;
                }
            }
            
            for (j = 1; j < MAX_SIZE; j++) {
                if (list[j].next == -1) {
                    break;
                }
            }
            list[j].next = i;
            list[s].next = j;
            list[j].value = element;
        }
        else {
            list[1].value = element;
            list[1].next = 0;
            list[0].next = 1;
        }

        counter++;
    }
    else {
        cout << "List is full" << endl;
    }

}

void deleteElement(string element) {
    if (!isEmpty()) {
        int i = -1, s = -1;
        while (i == -1 || s == -1) {
            i = find(element, 1);
            s = find(element, 0);
            if (i == -1 && s == -1) {
                cout << "String " << element << "didn't find, try again" << endl;
            }
        }
        list[s].next = list[i].next;
        list[i].next = -1;
        counter--;
        cout << "Element " << element << " was deleted" << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void menu() {
    int choice;
    string element;

    while (true) {
        cout << "\nEnter the command number:\n";
        cout << "1. Add an item BEFORE the specified item\n";
        cout << "2. Add an item AFTER the specified item\n";
        cout << "3. Remove an element from the list\n";
        cout << "4. Search an element in the list\n";
        cout << "5. Print list\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";
        choice = console_work();

        if (choice == 1) {
            if(!isFull()) {
                cout << "Enter characters: ";
                cin >> element;
                addBefore(element);
                printList();
            }
            else {
                cout << "List is full" << endl;
            }

        }
        else if (choice == 2) {
           if (!isFull()) {
               cout << "Enter characters: ";
               cin >> element;
               addAfter(element);
               printList();
           }
           else {
               cout << "List is full" << endl;
           }

        }
        else if (choice == 3) {
            if (!isEmpty()) {
                cout << "Enter the element for remove: ";
                cin >> element;
                deleteElement(element);
                printList();
            }
            else {
                cout << "List is empty" << endl;
            }

        }
        else if (choice == 4) {
            if (!isEmpty()) {
                cout << "Enter the element which you want to find: ";
                cin >> element;
                searchElement(element);
            }
            else {
                cout << "List is empty" << endl;
            }
        }
        else if (choice == 5) {
            printList();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "\nInput error. Repeat the command\n";
        }
    }
}


int main() {
    initLinckList();
    menu();
    return 0;
}

