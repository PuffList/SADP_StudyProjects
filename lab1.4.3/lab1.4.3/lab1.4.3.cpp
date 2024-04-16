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

struct SubList {
    string value;
    SubList* pNext;
};

struct MainList {
    string main_value;
    MainList* pNextMain;
    SubList* firstSub;
} *headMain;

void initList() {
    headMain = new MainList();
    headMain->firstSub = NULL;
    headMain->pNextMain = NULL;
}

bool main_isEmpty() {
    return headMain->pNextMain == NULL;
}

bool sub_isEmpty(MainList* currentMainList) {
    return currentMainList->firstSub->pNext == NULL;
}

void printList() {
    if (!main_isEmpty()) {
        MainList* currentMain = headMain->pNextMain;
        while (currentMain != NULL) {
            cout << "contents of element " << currentMain->main_value << " of the main list:" << endl;
            
            if (!sub_isEmpty(currentMain)) {
                SubList* currentSub = currentMain->firstSub->pNext;
                while (currentSub != NULL) {
                    cout << currentSub->value << " ";
                    currentSub = currentSub->pNext;
                }              
            }
            else {
                cout << "Empty" << endl;
            }
            currentMain = currentMain->pNextMain;
            cout << endl;
        }       
    }
    else {
        cout << "MainList is Empty" << endl;
    }
}

void searchElement(string element) {
    if (!main_isEmpty()) {
        MainList* currentMain = headMain->pNextMain;
        while (currentMain != NULL) {
            cout << "Search among list items " << currentMain->firstSub->value << endl;
            if (!sub_isEmpty(currentMain)) {
                SubList* currentSub = currentMain->firstSub->pNext;
                while (currentSub != NULL && currentSub->value != element) {
                    currentSub = currentSub->pNext;
                }
                if (currentSub != NULL) {
                    cout << "Element " << element << " was found" << endl; 
                    return;
                }
                else {
                    cout << "String wasn't found" << endl;
                }
            }
            
            currentMain = currentMain->pNextMain;
        } 
        cout << "Element " << element << " wasn't found" << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void addInMainAfter(string element) {
    string _value;
    MainList* newElement = new MainList();
    newElement->firstSub = new SubList();
    MainList* current;
    if (!main_isEmpty()) {
        int i = 0;
        while (i == 0) {
            current = headMain->pNextMain;
            cout << "Enter the value of the item AFTER which you want to add the new item: ";
            cin >> _value;
            while (current != NULL && current->main_value != _value) {
                current = current->pNextMain;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        newElement->pNextMain = current->pNextMain;
        newElement->firstSub->pNext = NULL;
        current->pNextMain = newElement;
        newElement->main_value = element;
    }
    else {
        newElement->pNextMain = NULL;
        newElement->firstSub->pNext = NULL;
        headMain->pNextMain = newElement; 
        newElement->main_value = element;
    }
}

void addInMainBefore(string element) {
    if (!main_isEmpty()) {
        string _value;
        MainList* newElement = new MainList();
        newElement->firstSub = new SubList();
        MainList* current;
        MainList* prev;
        int i = 0;

        while (i == 0) {
            current = headMain->pNextMain;
            prev = headMain;
            cout << "Enter the value of the item BEFORE which you want to add the new item: ";
            cin >> _value;
            while (current != NULL && current->main_value != _value) {
                current = current->pNextMain;
                prev = prev->pNextMain;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        newElement->pNextMain = current;
        newElement->firstSub->pNext = NULL;
        prev->pNextMain = newElement;
        newElement->main_value = element;
    }
    else {
        cout << "List is empty" << endl;
    }
}

void addInSubAfter(string element) {
    if (!main_isEmpty()) {
        string _value;
        MainList* current;
        int i = 0;
        while (i == 0) {
            current = headMain->pNextMain;
            cout << "Enter the title name of the linked list header to which you want to add the new item: ";
            cin >> _value;
            while (current != NULL && current->main_value != _value) {
                current = current->pNextMain;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }

        SubList* head = current->firstSub;
        SubList* currentSub;
        SubList* newElement = new SubList;
        if (!sub_isEmpty(current)) {
            i = 0;
            while (i == 0) {
                currentSub = head->pNext;
                cout << "Enter the value of the item AFTER which you want to add the new item: ";
                cin >> _value;
                while (currentSub != NULL && currentSub->value != _value) {
                    currentSub = currentSub->pNext;
                }
                if (currentSub != NULL) {
                    i++;
                }
                else {
                    cout << "Element wasn't found, try again\n";
                }
            }
            newElement->pNext = currentSub->pNext;
            currentSub->pNext = newElement;
            newElement->value = element;
        }
        else {
            newElement->pNext = NULL;
            head->pNext = newElement;
            newElement->value = element;
        }

    }
    else {
        cout << "No linked lists" << endl;
    }
}

void addInSubBefore(string element) {
    if (!main_isEmpty()) {
        string _value;
        MainList* current;
        int i = 0;
        while (i == 0) {
            current = headMain->pNextMain;
            cout << "Enter the title name of the linked list header to which you want to add the new item: ";
            cin >> _value;
            while (current != NULL && current->main_value != _value) {
                current = current->pNextMain;
            }
            if (current != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }

        SubList* head = current->firstSub;
        SubList* currentSub;
        SubList* prev;
        SubList* newElement = new SubList;
        if (!sub_isEmpty(current)) {
            i = 0;
            while (i == 0) {
                currentSub = head->pNext;
                prev = head;
                cout << "Enter the value of the item BEFORE which you want to add the new item: ";
                cin >> _value;
                while (currentSub != NULL && currentSub->value != _value) {
                    currentSub = currentSub->pNext;
                    prev = prev->pNext;
                }
                if (currentSub != NULL) {
                    i++;
                }
                else {
                    cout << "Element wasn't found, try again\n";
                }
            }
            newElement->pNext = currentSub;
            prev->pNext = newElement;
            newElement->value = element;
        }
        else {
            cout << "SubList is empty, so unreal add element BEFORE something" << endl;
        }

    }
    else {
        cout << "No linked lists" << endl;
    }
}

void deleteMainElement() {
    if (!main_isEmpty()) {
        string element;
        MainList* currentMain;
        MainList* prev;
        SubList* currentSub;
        int i = 0;
        while (i == 0) {
            currentMain = headMain->pNextMain;
            prev = headMain;
            cin >> element;
            while (currentMain != NULL && currentMain->main_value != element) {
                currentMain = currentMain->pNextMain;
                prev = prev->pNextMain;
            }
            if (currentMain != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        while (!sub_isEmpty(currentMain)) {
            currentSub = currentMain->firstSub;
            currentMain->firstSub = currentMain->firstSub->pNext;
            delete currentSub;
        }
        delete currentMain->firstSub;
        prev->pNextMain = currentMain->pNextMain;
        delete currentMain;
        cout << "MainList's element was deleted and his SubList too" << endl;
    }
    else {
        cout << "MainList is Empty" << endl;
    }
}

void deleteSubElement() {
    if (!main_isEmpty()) {
        string element;
        MainList* currentMain;
        int i = 0;
        while (i == 0) {
            currentMain = headMain->pNextMain;
            cout << "Enter the header value of the linked list in which you want to delete an item: " << endl;
            cin >> element;
            while (currentMain != NULL && currentMain->main_value != element) {
                currentMain = currentMain->pNextMain;
            }
            if (currentMain != NULL) {
                i++;
            }
            else {
                cout << "Element wasn't found, try again\n";
            }
        }
        if(!sub_isEmpty(currentMain)) {
            SubList* head = currentMain->firstSub;
            SubList* currentSub;
            SubList* prev;
            i = 0;
            while (i == 0) {
                currentSub = head->pNext;
                prev = head;
                cout << "Enter the value of the SubList which you want to delete: " << endl;
                cin >> element;
                while (currentSub != NULL && currentSub->value != element) {
                    currentSub = currentSub->pNext;
                    prev = prev->pNext;
                }
                if (currentSub != NULL) {
                    i++;
                }
                else {
                    cout << "Element wasn't found, try again\n";
                }
            }
            prev->pNext = currentSub->pNext;
            cout << "Element " << currentSub->value << " was deleted from SubList" << endl;
            delete currentSub;            
        }
        else {
            cout << "SubList is empty" << endl;
        }
        
    }
    else {
        cout << "MainList is Empty" << endl;
    }
}

void clearList() {
    MainList* currentMain;
    SubList* currentSub;
    currentMain = headMain;
    while (headMain != NULL) {
        currentMain = headMain;
        while (currentMain->firstSub != NULL) {
            currentSub = currentMain->firstSub;
            currentMain->firstSub = currentMain->firstSub->pNext;
            delete currentSub;
        }
        headMain = currentMain->pNextMain;
        delete currentMain;
    }
    cout << "List was cleaned" << endl;
}

void menu() {
    int choice;
    string element;

    while (true) {
        cout << "\nEnter the command number:\n";
        cout << "1. Add an item in MainList BEFORE the specified item\n";
        cout << "2. Add an item in MainList AFTER the specified item\n";
        cout << "3. Add an item in SubList BEFORE the specified item\n";
        cout << "4. Add an item in SubList AFTER the specified item\n";
        cout << "5. Remove an element from the Mainlist\n";
        cout << "6. Remove an element from the Sublist\n";
        cout << "7. Search an element in the list\n";
        cout << "8. Print list\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";
        choice = console_work();

        if (choice == 1) {
            if (!main_isEmpty()) {
                cout << "Enter characters: ";
                cin >> element;
                addInMainBefore(element);
                printList();
            }
            else {
                cout << "List is empty, so unreal add element BEFORE something";
            }

        }
        else if (choice == 2) {
            cout << "Enter characters: ";
            cin >> element;
            addInMainAfter(element);
            printList();
        }
        else if (choice == 3) {
            if (!main_isEmpty()) {
                cout << "Enter characters: ";
                cin >> element;
                addInSubBefore(element);
                printList();
            }
            else {
                cout << "List is empty, so unreal add element BEFORE something" << endl;
            }
        }
        else if (choice == 4) {
            if (!main_isEmpty()) {
                cout << "Enter characters: ";
                cin >> element;
                addInSubAfter(element);
                printList();
            }
            else {
                cout << "No linked lists" << endl;
            }
        }
        else if (choice == 5) {
            if (!main_isEmpty()) {
                cout << "Enter the element for remove: ";
                deleteMainElement();
                printList();
            }
            else {
                cout << "MainList is empty" << endl;
            }

        }
        else if (choice == 6) {
            if (!main_isEmpty()) {
                deleteSubElement();
                printList();
            }
            else {
                cout << "MainList is empty, so SubList empty too" << endl;
            }

        }
        else if (choice == 7) {
            if (!main_isEmpty()) {
                cout << "Enter the element which you want to find: ";
                cin >> element;
                searchElement(element);
            }
            else {
                cout << "MainList is empty" << endl;
            }
        }
        else if (choice == 8) {
            printList();
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
