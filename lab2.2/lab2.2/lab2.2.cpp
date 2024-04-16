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
    //int a[] = { 15, 33, 42, 7, 12, 19 };
    
    arr = new int[num];
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 100;
        //arr[i] = a[i];
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
        while (j >= 0 && temp < cpArr[j]) {
            compares++;
            cpArr[j + 1] = cpArr[j];
            j--;
            changes++;
        }
        cpArr[j + 1] = temp;
    }

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
    for (int i = 0; i < num; i++) {
        temp = i;
        min = cpArr[i];
        for (int j = i + 1; j < num; j++) {
            if (cpArr[j] < min) {
                temp = j;
                min = cpArr[j];
                changes++;
            }
            compares++;
        }
        cpArr[temp] = cpArr[i];
        cpArr[i] = min;
    }

    printArr(cpArr);
    cout << "Compares: " << compares << endl;
    cout << "Changes: " << changes << endl;
    delete[] cpArr;
}

void shellSort() {
    compares = 0, changes = 0;
    int* cpArr = copyArr();
    int temp, j, k;
    int step = (log(num) / log(2) - 1);
    int a[] = { 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191 };
    cout << "Process of sorting..." << endl;
    for (int m = step - 1; m >= 0; m--) {
        k = a[m];
        for (int i = k; i < num; i++) {
            temp = cpArr[i];
            j = i - k;
            compares++;
            while (j >= 0 && temp < cpArr[j]) {
                compares++;
                cpArr[j + k] = cpArr[j];
                j = j - k;
                changes++;
            }
            cpArr[j + k] = temp;
            
        }
    }

    printArr(cpArr);
    cout << "Compares: " << compares << endl;
    cout << "Changes: " << changes << endl;
    delete[] cpArr;
}

/*void shellSort2() {
    compares = 0, changes = 0;
    int* cpArr = copyArr();
    int temp, j, k;
    int countSteps = (log(num) / log(2) - 1);
    int steps[] = { 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191 };
    for (int gap = countSteps - 1; gap > -1; gap--) {
        int H = steps[gap];
        for (int i = H; i < num; i++) {
            int temp = cpArr[i];
            int j;
            for (j = i; j >= H; j -= H) {
                compares++;
                if (cpArr[j - H] > temp) {
                    cpArr[j] = cpArr[j - H];
                    changes++;
                }
                else {
                    break;
                }
            }
            cpArr[j] = temp;
        }
    }
    printArr(cpArr);
    cout << "Compares: " << compares << endl;
    cout << "Changes: " << changes << endl;
    delete[] cpArr;
}*/

void fastSort(int left, int right, int* cpArr) {
    int i, j, temp, mid;
    i = left, j = right;
    if (arr == cpArr) {
        cpArr = copyArr();
    }
    mid = cpArr[(left + right) / 2];
    do {      
        while (cpArr[i] < mid) {
            i++;
            compares++;
        }      
        while (cpArr[j] > mid) {
            j--;
            compares++;
        }      
        if (i <= j) {
            temp = cpArr[i];
            cpArr[i] = cpArr[j];
            cpArr[j] = temp;
            i++;
            j--;
            changes++;
        }
        
    } while (i < j);
    
    if (left < j) {
        fastSort(left, j, cpArr);
    }
    
    if (i < right) {
        fastSort(i, right, cpArr);
    }
    if (left == 0 && right == num - 1) {
        printArr(cpArr);
        cout << "Compares: " << compares << endl;
        cout << "Changes: " << changes << endl;
        delete[] cpArr;
    }
}

void sito(int a_l, int a_r, int* cpArr) {
    int min = a_l;
    int left = a_l * 2 + 1;
    int right = a_l * 2 + 2;

    if (left < a_r) {
        compares++;
        if (cpArr[left] < cpArr[min]) {
            min = left;
        }
    }
    if (right < a_r) {
        compares++;
        if (cpArr[right] < cpArr[min]) {
            min = right;
        }
    }

    if (min != a_l) {
        int temp = cpArr[a_l];
        cpArr[a_l] = cpArr[min];
        cpArr[min] = temp;
        changes++;
        sito(min, a_r, cpArr);
    }
}

void pyramidSort() {
    int* cpArr = copyArr();
    for (int i = num / 2 - 1; i >= 0; i--) {
        sito(i, num, cpArr);
    }
    
    for (int i = num - 1; i > 0; i--) {
        int temp = cpArr[0];
        cpArr[0] = cpArr[i];
        cpArr[i] = temp;
        changes++;
        sito(0, i, cpArr);
        
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
        cout << "Bust sort methods\n";
        cout << "5. Shell Sort\n";
        cout << "6. Fast Sort\n";
        cout << "7. Pyramid Sort\n";
        cout << "------------------------\n";
        cout << "8. Recreate array\n";
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
            printArr(arr);
            shellSort();
        }
        else if (choice == 6) {
            printArr(arr);
            compares = 0, changes = 0;
            fastSort(0, num - 1, arr);
        }
        else if (choice == 7) {
            printArr(arr);
            compares = 0, changes = 0;
            pyramidSort();
        }
        else if (choice == 8) {
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