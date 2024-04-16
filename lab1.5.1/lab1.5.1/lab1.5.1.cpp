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

struct Tree {
    int value;
    Tree* pLeft;
    Tree* pRight;
} *pRoot;

Tree* addNodes(Tree* current, int N) {
    int left_N, right_N;
    Tree* newNode;
    if (N == 0) {
        return NULL;
    }
    else {
        left_N = N / 2;
        right_N = N - left_N - 1;
        newNode = new Tree();
        newNode->value = rand() % 100;
        newNode->pLeft = addNodes(newNode->pLeft, left_N);
        newNode->pRight = addNodes(newNode->pRight, right_N);
        current = newNode;
        return newNode;

    }

}

void printForward(Tree* current, int level) {
    if (current != NULL) {
        string str;
        for (int i = 0; i < level; i++) {
            str += "    ";
        }
        cout << " " << str << current->value << endl;
        printForward(current->pLeft, level + 1);
        printForward(current->pRight, level + 1);
    }
}

void printSymmetric(Tree* current, int level) {
    if (current != NULL) {
        string str;
        printSymmetric(current->pLeft, level + 1);
        for (int i = 0; i < level; i++) {
            str += "    ";
        }
        cout << " " << str << current->value << endl;
        printSymmetric(current->pRight, level + 1);
    }
}

void printBackSymetric(Tree* current, int level) {
    if (current != NULL) {
        string str;
        printBackSymetric(current->pRight, level + 1);
        for (int i = 0; i < level; i++) {
            str += "    ";
        }
        cout << " " << str << current->value << endl;
        printBackSymetric(current->pLeft, level + 1);       
    }
}

void deleteTree(Tree* current) {
    if (current != NULL) {
        deleteTree(current->pLeft);
        deleteTree(current->pRight);
        delete current;
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "\nEnter the command number:\n";
        cout << "1. Start\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";

        choice = console_work();

        if (choice == 1) {
            counter = 0;
            while (counter <= 0) {
                cout << "Enter the quantity of nodes: " << endl;
                counter = console_work();
                if (counter >= 0) {
                    pRoot = addNodes(pRoot, counter);
                    cout << "Tree with " << counter << " nodes was created" << endl;
                }
                else {
                    cout << "\nInput error. Repeat the command\n ";
                }
            }
            cout << "Print forward: \n\n";
            printForward(pRoot, 0);

            cout << "\nPrint symmetric:\n\n";
            printSymmetric(pRoot, 0);

            cout << "\nPrint back symetric:\n\n";
            printBackSymetric(pRoot, 0);

            cout << "\nCleaning Tree...\n";
            deleteTree(pRoot);
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

    menu();
    return 0;
}

