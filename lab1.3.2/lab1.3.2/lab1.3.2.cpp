#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

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

struct ArrayList {
    string value;
    string list[MAX_SIZE];
    int count;

    void initArrayList() {
        for (int i = 0; i < MAX_SIZE; i++) {
            list[i] = "";
        }
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void addElement(string element) {
        if (!isFull()) {
            int i = count - 1;
            while (i >= 0 && list[i] > element) {
                list[i + 1] = list[i];
                i--;
            }

            list[i + 1] = element;
            count++;
        }
        else {
            cout << "ArrayList is full" << endl;
        }
    }

    void deleteElement(string element) {
        if (!isEmpty()) {
            int i = 0;
            while (i < count && list[i] != element) {
                i++;
            }

            if (i == count) {
                cout << "Element" << element << "wasn't found" << endl;;
                return;
            }

            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }

            count--;
        }
        else {
            cout << "ArrayList is empty" << endl;
        }
    }

    void printArrayList() {
        if (!isEmpty()) {
            for (int i = 0; i < count; i++) {
                cout << list[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "ArrayList is empty" << endl;
        }
    }

    void searchElement(string element) {
        if (isEmpty()) {
            cout << "ArrayList is empty" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            if (list[i] == element) {
                cout << "Element was found on position " << i << endl;
                return;
            }
        }

        cout << "Element wasn't found\n";
    }


} arrayList;

void menu() {
    int choice;
    string element;

    while (true) {
        cout << "\nEnter the command number:\n";
        cout << "1. Add an element in the list\n";
        cout << "2. Remove an element from the list\n";
        cout << "3. Search an element in the list\n";
        cout << "4. Print list\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";
        choice = console_work();

        if (choice == 1) {
            if (!arrayList.isFull()) {
                cout << "Enter characters: ";
                cin >> element;
                arrayList.addElement(element);
                arrayList.printArrayList();
            }
            else {
                cout << "List is full" << endl;
            }
            
        }
        else if (choice == 2) {
            if (!arrayList.isEmpty()) {
                cout << "Enter the element for remove: ";
                cin >> element;
                arrayList.deleteElement(element);
                arrayList.printArrayList();
            }
            else {
                cout << "List is empty" << endl;
            }
            
        }
        else if (choice == 3) {
            if (!arrayList.isEmpty()) {
                cout << "Enter the element which you want to find: ";
                cin >> element;
                arrayList.searchElement(element);
            }
            else {
                cout << "List is empty" << endl;
            }
        }
        else if (choice == 4) {
            arrayList.printArrayList();
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
    arrayList.initArrayList();
    menu();
    return 0;
}
