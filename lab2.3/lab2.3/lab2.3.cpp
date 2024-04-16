#include <iostream>

using namespace std;

int* arr = NULL;
int num;
int max_key;

struct List {
    int key = -1;
    List* pNext = NULL;
    List* tail = NULL;
} *list = NULL, *head = NULL;


int console_work() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\n ОШИБКА ВВОДА. ПОВТОРИТЕ ВВОД: ";
    }
    return a;
}

int* copyArr() {
    int* cpArr = new int[num];
    for (int i = 0; i < num; i++) {
        cpArr[i] = arr[i];
    }
    return cpArr;
}

void printArr(int* cpArr) {
    for (int i = 0; i < num; i++) {
        cout << cpArr[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void createArray(int n) {
    int temp, r;
    cout << "Enter the number of elements wich you want to add into array(less 10000): ";
    while (num < 1 || num > 10000) {
        num = console_work();
        
        if (num < 1 || num > 10000) {
            cout << "Error input, repeat please" << endl;
        }
    }
    if (arr != NULL) {
        delete[] arr;
    }
    arr = new int[num];
    if (n == 1) {
        for (int i = 0; i < num; i++) {
            arr[i] = i;
        }
        max_key = num;
    }
    else if (n == 2) {
        max_key = num - num / 3;
        for (int i = 0; i < max_key; i++) {
            arr[i] = i;
        }
        for (int i = max_key; i < num; i++) {
            arr[i] = rand() % max_key;
        }
    }
    
    for (int i = 0; i < num; i++) {
        r = rand() % num;
        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }
    printArr(arr);
}



void pocketSort() {
    createArray(1);
    int* cpArr = copyArr();
    int temp, n = -1;
    cout << "Would like to use second array? \n Yes - 1\n No - 2\n Enter: ";
    n = console_work();
    while (n < 1 || n > 2) {
        cout << "Error input, repeat please" << endl;
        n = console_work();    
    }
    if (n == 1) {
        for (int i = 0; i < num; i++) {
            while (cpArr[i] != i) {
                temp = cpArr[cpArr[i]];
                cpArr[cpArr[i]] = cpArr[i];
                cpArr[i] = temp;
            }
        }
    }
    else {
        int* secondArr = new int[num];
        for (int i = 0; i < num; i++) {
            secondArr[cpArr[i]] = cpArr[i];
        }
        delete[] cpArr;
        cpArr = secondArr;
    }

    printArr(cpArr);
    delete[] cpArr;
}

void cleanList(List* current) {
    if (current->pNext != NULL) {
        cleanList(current->pNext);
    }
    delete current;
}

int* list_toArray(List* _head) {
    List* current = _head;
    int* cpArr = new int[num];
    for (int i = 0; i < num; i++) {
        cpArr[i] = current->key;
        current = current->pNext;
    }
    return cpArr;
}

List* combine(List* _list) {
    List* _head = new List;
    _head->key = _list[0].key;
    _head->pNext = _list[0].pNext;
    _head->tail = _list[0].tail;
    List* current = _head;
    for (int i = 0; i < max_key - 1; i++) {
        if (_list[i].tail != NULL) {
            current = _list[i].tail;
        }
        current->pNext = new List;
        current = current->pNext;
        current->key = _list[i + 1].key;
        current->pNext = _list[i + 1].pNext;
        current->tail = _list[i + 1].tail;
    }
    return _head;
}

void general_pocketSort() {
    createArray(2);
    int* cpArr = copyArr();
    list = new List[max_key];
    for (int i = 0; i < num; i++) {
        if (list[cpArr[i]].key == -1) {
            list[cpArr[i]].key = cpArr[i];
        }
        else if (list[cpArr[i]].pNext == NULL) {
            list[cpArr[i]].pNext = new List;
            list[cpArr[i]].tail = list[cpArr[i]].pNext;
            list[cpArr[i]].pNext->key = cpArr[i];
        }
        else if(list[cpArr[i]].tail->pNext == NULL) {
            list[cpArr[i]].tail->pNext = new List;
            list[cpArr[i]].tail->pNext->key = cpArr[i];
            list[cpArr[i]].tail = list[cpArr[i]].tail->pNext;
        }
    }
    head = combine(list);
    cpArr = list_toArray(head);
    head = NULL;
    printArr(cpArr);
    delete[] cpArr;
    delete[] list;
}

void bit_pocketSorting() {
    createArray(2);
    int* cpArr = copyArr();
    int temp = max_key;
    int k = 0;
    int x, _max;
    while(temp != 0){
        temp = temp / 10;
        k++;
    }
    cout << "Count of bits: " << k << endl;
    for (int i = 1; i <= k; i++) {
        list = new List[10];
        for (int j = 0; j < num; j++) {
            x = cpArr[j];
            for (int z = 1; z < i; z++) {
                x = x / 10;
            }
            x = x % 10;
            if (list[x].key == -1) {
                list[x].key = cpArr[j];
            }
            else if (list[x].pNext == NULL) {
                list[x].pNext = new List;
                list[x].tail = list[x].pNext;
                list[x].pNext->key = cpArr[j];
            }
            else if (list[x].tail->pNext == NULL) {
                list[x].tail->pNext = new List;
                list[x].tail->pNext->key = cpArr[j];
                list[x].tail = list[x].tail->pNext;
            }
        }
        _max = max_key;
        max_key = 10;
        head = combine(list);
        max_key = _max;
        cpArr = list_toArray(head);
        cleanList(head);
        head = NULL;
        cout << "Sorting by k = " << i << endl;
        printArr(cpArr);
        delete[] list;
    }
    delete[] cpArr;
}

void menu() {
    int choice;
    while (true) {
        cout << "\nEnter the command number:\n";
        cout << "1.Pocket Sort\n";
        cout << "2.General Pocket Sort\n";
        cout << "3.Bit Pocket Sort\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";

        choice = console_work();

        if (choice == 1) {
            
            pocketSort();
        }
        else if (choice == 2) {
            
            general_pocketSort();
        }
        else if (choice == 3) {
           
            bit_pocketSorting();
        }
        else if (choice == 0) {
            delete[] arr;
            break;
        }
        else {
            cout << "\nInput error. Repeat the command\n";
        }
    }
}



int main()
{
    srand(static_cast<unsigned int>(time(0)));
    menu();
    return 0;
}

