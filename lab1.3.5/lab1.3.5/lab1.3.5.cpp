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

struct List {
    string value;
    List* pNext;
} *head, *topStack;

void initList() {
    head = new List();
    head->pNext = NULL;
    topStack = new List();
    topStack->pNext = NULL;
}

bool isEmpty() {
    return head->pNext == NULL;
}

bool isStackEmpty() {
    return topStack->pNext == NULL;
}

void searchElement(string element) {
    if (!isEmpty()) {
        List* current = head->pNext;
        int i = 1;
        while (current != NULL && current->value != element) {
            current = current->pNext;
            i++;
        }
        if (current != NULL) {
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

void printList() {
    if (!isEmpty()) {
        List *current = head->pNext;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->pNext;
        }
        cout << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void printStack() {
    if (!isStackEmpty()) {
        List* current = topStack->pNext;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->pNext;
        }
        cout << endl;
    }
    else {
        cout << "Stack is empty" << endl;
    }
}

void clearList() {
    List* current;
    List* stack;
    while(head != NULL) {
        current = head;
        head = head->pNext;
        delete current;
    }
    while (topStack != NULL) {
        stack = topStack;
        topStack = topStack->pNext;
        delete stack;
    }
    cout << "List and Stack was cleaned " << endl;
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
            while (current != NULL && current->value != _value) {
                current = current->pNext;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        newElement->pNext = current->pNext;
        current->pNext = newElement;
        newElement->value = element;
    }
    else {
        newElement->pNext = NULL;
        head->pNext = newElement;
        newElement->value = element;
    }
}

void addBefore(string element) {
    if (!isEmpty()) {
        string _value;
        List* newElement = new List();
        List* current;
        List* prev;
        int i = 0;
        
        while (i == 0) {
            current = head->pNext;
            prev = head;
            cout << "Enter the value of the item BEFORE which you want to add the new item: ";
            cin >> _value;
            while (current != NULL && current->value != _value) {
                current = current->pNext;
                prev = prev->pNext;
            }            
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        newElement->pNext = current;
        prev->pNext = newElement;
        newElement->value = element;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void deleteElement() {
    if (!isEmpty()) {
        string element;
        List* current;
        List* prev;
        int i = 0;
        int comd;
        while (i == 0) {
            current = head->pNext;
            prev = head;
            cin >> element;
            while (current != NULL && current->value != element) {
                current = current->pNext;
                prev = prev->pNext;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        cout << "Specify the command: \n 1. Really delete the element with full memory release \n 2. Include it in the top of the auxiliary stack of deleted items\nYour choice: ";
        while (true) {            
            comd = console_work();
            if (comd == 1) {
                prev->pNext = current->pNext;
                delete current;
                cout << "Element " << element << " was deleted" << endl;
                break;
            }
            else if (comd == 2) {
                prev->pNext = current->pNext;
                List* el = current;
                el->pNext = topStack->pNext;
                topStack->pNext = el;
                cout << "Element " << element << " was moved to Stack" << endl;
                break;
            }
            else {
                cout << "Input error. Repeat the command\n";
            }
        }
        
       
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
        cout << "6. Print Stack\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";
        choice = console_work();

        if (choice == 1) {
            if (!isEmpty()) {
                cout << "Enter characters: ";
                cin >> element;
                addBefore(element);
                printList();
            }
            else {
                cout << "List is empty, so unreal add element BEFORE something";
            }
            
        }
        else if (choice == 2) {
            cout << "Enter characters: ";
            cin >> element;
            addAfter(element);
            printList();
        }
        else if (choice == 3) {
            if (!isEmpty()) {
                cout << "Enter the element for remove: ";
                deleteElement();
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
        else if (choice == 6) {
            printStack();
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

