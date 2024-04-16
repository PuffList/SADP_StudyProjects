#include <iostream>

using namespace std;

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

struct List {
    string value;
    List* pNext;
    List* pPrev;
} *head;

void initList() {
    head = new List();
    head->pNext = head;
    head->pPrev = head;
    head->value = "HEAD";
    counter = 0;
}

bool isEmpty() {
    return head->pNext == head;
}

void searchElementFromBegin(string element) {
    if (!isEmpty()) {
        List* current = head->pNext;
        int i = 1;
        while (current != head && current->value != element) {
            current = current->pNext;
            i++;
        }
        if (current != head) {
            cout << "Element was found on position " << i << endl;
        }
        else {
            cout << "Element wasn't found\n";
        }

    }
    else {
        cout << "List is empty" << endl;
    }
}

void searchElementFromEnd(string element) {
    if (!isEmpty()) {
        List* current = head->pPrev;
        int i = counter;
        while (current != head && current->value != element) {
            current = current->pPrev;
            i--;
        }
        if (current != head) {
            cout << "Element was found on position " << i << endl;
        }
        else {
            cout << "Element wasn't found\n";
        }

    }
    else {
        cout << "List is empty" << endl;
    }
}

void printListFromBegin() {
    if (!isEmpty()) {
        List* current = head->pNext;
        while (current != head) {
            cout << current->value << " ";
            current = current->pNext;
        }
        cout << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void printListFromEnd() {
    if (!isEmpty()) {
        List* current = head->pPrev;
        while (current != head) {
            cout << current->value << " ";
            current = current->pPrev;
        }
        cout << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void clearList() {
    List* current;
    head->pPrev->pNext = NULL;
    while (head != NULL) {
        current = head;
        head = head->pNext;
        delete current;
    }
   
    cout << "List was cleaned " << endl;
}

void addAfter(string element) {
    string _value;
    List* newElement = new List();
    List* current;
    if (!isEmpty()) {
        int i = 0;
        while (i == 0) {
            current = head->pNext;
            cout << "Enter the value of the item AFTER which you want to add the new item: ";
            cin >> _value;
            while (current != head && current->value != _value) {
                current = current->pNext;
            }
            if (current != head) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        newElement->pNext = current->pNext;
        newElement->pPrev = current;
        current->pNext->pPrev = newElement;
        current->pNext = newElement;       
        newElement->value = element;
        counter++;
    }
    else {
        newElement->pNext = head;
        newElement->pPrev = head;
        head->pPrev = newElement;
        head->pNext = newElement;
        newElement->value = element;
        counter++;
    }
}

void addBefore(string element) {
    if (!isEmpty()) {
        string _value;
        List* newElement = new List();
        List* current;
        int i = 0;

        while (i == 0) {
            current = head->pNext;
            cout << "Enter the value of the item BEFORE which you want to add the new item: ";
            cin >> _value;
            while (current != head && current->value != _value) {
                current = current->pNext;
            }
            if (current != head) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        newElement->pNext = current;
        newElement->pPrev = current->pPrev;
        current->pPrev->pNext = newElement;
        current->pPrev = newElement;
        newElement->value = element;
        counter++;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void deleteElement() {
    if (!isEmpty()) {
        string element;
        List* current;
        int i = 0;
        while (i == 0) {
            current = head->pNext;
            cin >> element;
            while (current != head && current->value != element) {
                current = current->pNext;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        current->pPrev->pNext = current->pNext;
        current->pNext->pPrev = current->pPrev;
        delete current;
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
        cout << "4. Search an element in the list from BEGIN\n";
        cout << "5. Search an element in the list from END\n";
        cout << "6. Print list from BEGIN\n";
        cout << "7. Print list from END\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";
        choice = console_work();

        if (choice == 1) {
            if (!isEmpty()) {
                cout << "Enter characters: ";
                cin >> element;
                addBefore(element);
                printListFromBegin();
            }
            else {
                cout << "List is empty, so unreal add element BEFORE something";
            }

        }
        else if (choice == 2) {
            cout << "Enter characters: ";
            cin >> element;
            addAfter(element);
            printListFromBegin();
        }
        else if (choice == 3) {
            if (!isEmpty()) {
                cout << "Enter the element for remove: ";
                deleteElement();
                printListFromBegin();
            }
            else {
                cout << "List is empty" << endl;
            }

        }
        else if (choice == 4) {
            if (!isEmpty()) {
                cout << "Enter the element which you want to find: ";
                cin >> element;
                searchElementFromBegin(element);
            }
            else {
                cout << "List is empty" << endl;
            }
        }
        else if (choice == 5) {
            if (!isEmpty()) {
                cout << "Enter the element which you want to find: ";
                cin >> element;
                searchElementFromEnd(element);
            }
            else {
                cout << "List is empty" << endl;
            }
        }
        else if (choice == 6) {
            printListFromBegin();
        }
        else if (choice == 7) {
            printListFromEnd();
        }
        else if (choice == 0) {
            clearList();
            break;
        }
        else {
            cout << "\nInput error. Repeat the command\n";
        }
    }
}


int main() {
    initList();
    menu();
    return 0;

}