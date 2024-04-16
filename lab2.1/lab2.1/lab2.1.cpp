#include <iostream>

using namespace std;

int* arr = NULL;
int num;
int compares, changes;


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


void createArray() {
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
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 100;
    }
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
}

void bubbleSort() {
    compares = 0, changes = 0;
    int* cpArr = copyArr();
    int temp;
    cout << "Process of sorting..." << endl;
    for (int i = 0; i < num; i++) {
        for (int j = num - 1; j > i; j--) {
            compares++;
            if (cpArr[j - 1] > cpArr[j]) {
                temp = cpArr[j - 1];
                cpArr[j - 1] = cpArr[j];
                cpArr[j] = temp;
                changes++;
            }
        }
    }
    printArr(cpArr);
    cout << "Compares: " << compares << endl;
    cout << "Changes: " << changes << endl;
    delete[] cpArr;
}

void insertSort() {
    compares = 0, changes = 0;
    int* cpArr = copyArr();
    int temp, j;
    cout << "Process of sorting..." << endl;
    for (int i = 1; i < num; i++) {
        temp = cpArr[i];
        j = i - 1;
        compares++;
        changes++;
        while (j >= 0 && temp < cpArr[j]) {
            compares++;
            cpArr[j + 1] = cpArr[j];
            j--;
            changes++;
        }
        cpArr[j + 1] = temp;
        changes++;
    }
    changes = int(changes / 3);
    printArr(cpArr);
    cout << "Compares: " << compares << endl;
    cout << "Changes: " << changes << endl;
    delete[] cpArr;
}

void choiceSort() {
    compares = 0, changes = 0;
    int* cpArr = copyArr();
    int temp, min;
    cout << "Process of sorting..." << endl;
    for (int i = 0; i < num - 1; i++) {
        min = i;
        for (int j = i + 1; j < num; j++) {
            compares++;
            if (cpArr[j] < cpArr[min]) {
                min = j;
            }
        }
        if (min != i) {
            changes++;
            temp = cpArr[min];
            cpArr[min] = cpArr[i];
            cpArr[i] = temp;
        }
    }

    printArr(cpArr);
    cout << "Compares: " << compares << endl;
    cout << "Changes: " << changes << endl;
    delete[] cpArr;
}

void menu() {
    int choice;
    createArray();
    printArr(arr);
    while (true) {
        cout << "\nEnter the command number:\n";
        cout << "1.Bubble Sort\n";
        cout << "2. Insert Sort\n";
        cout << "3. Choice Sort\n";
        cout << "4. Sort with help of 3 methods \n";
        cout << "5. Recreate array\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";

        choice = console_work();

        if (choice == 1) {
            printArr(arr);
            bubbleSort();
        }
        else if (choice == 2) {
            printArr(arr);
            insertSort();
        }
        else if (choice == 3) {
            printArr(arr);
            choiceSort();
        }
        else if (choice == 4) {
            printArr(arr);
            cout << "----------------------------------" << endl;
            bubbleSort();
            cout << "----------------------------------" << endl;
            insertSort();
            cout << "----------------------------------" << endl;
            choiceSort();
        }
        else if (choice == 5) {
            createArray();
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

int main() {
    menu();
    return 0;
}

