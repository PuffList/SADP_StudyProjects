#include <iostream>


using namespace std;

int counter;
bool found = false;

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
} *pRoot, *pParent;

/*void printForward(Tree* current, int level) {
    if (current != NULL) {
        string str;
        for (int i = 0; i < level; i++) {
            str += "    ";
        }
        cout << " " << str << current->value << endl;
        printForward(current->pLeft, level + 1);
        printForward(current->pRight, level + 1);
    }
}*/

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

/*void printBackSymetric(Tree* current, int level) {
    if (current != NULL) {
        string str;
        printBackSymetric(current->pRight, level + 1);
        for (int i = 0; i < level; i++) {
            str += "    ";
        }
        cout << " " << str << current->value << endl;
        printBackSymetric(current->pLeft, level + 1);
    }
}*/

void find(Tree* current, int _value) {
    if (found == false) {
        if (current != NULL) {
            if (current->value == _value) {
                found = true;
                pParent = current;
            }
            else {
                find(current->pLeft, _value);
                find(current->pRight, _value);
            }
        }
    }
}

Tree* addNd(Tree* current, int _value) {
     current = new Tree();
     current->pLeft = current->pRight = NULL;
     current->value = _value;
     return current;
}

void addNodes() {
    int _value, n;
    cout << "Enter value Parent for newNode: " << endl;
    _value = console_work();
    if (pRoot != NULL) {
        found = false;
        find(pRoot, _value);
        if (found == true) {
            found = false;
            if (pParent->pLeft != NULL && pParent->pRight != NULL) {
                cout << "This Parent has already had children" << endl;
            }
            else {
                cout << "Enter value of newNode: " << endl;
                _value = console_work();
                if (pParent->pLeft == NULL && pParent->pRight == NULL) {
                    cout << "Parent haven't got any children, so where do you wand to add child?\n 1- left side\n 2- right side\n Enter: ";
                    n = console_work();
                    while (n != 1 && n != 2) {
                        cout << "Wrong command" << endl;
                        n = console_work();
                    }
                    if (n == 1) {
                        pParent->pLeft = addNd(pParent, _value);
                    }
                    if (n == 2) {
                        pParent->pRight = addNd(pParent, _value);
                    }
                }
                else if (pParent->pLeft == NULL) {
                    pParent->pLeft = addNd(pParent, _value);
                    cout << "newNode was added in left side" << endl;
                }
                else if (pParent->pRight == NULL) {
                    pParent->pRight = addNd(pParent, _value);
                    cout << "newNode was added in right side" << endl;
                }
                printSymmetric(pRoot, 0);
            }
        }           
        else {
            cout << "Parent with value " << _value << "hasn't found" << endl;
        }
        

    }
    else {
        pRoot = new Tree;
        pRoot->pLeft = pRoot->pRight = NULL;
        pRoot->value = _value;
        cout << "Tree was clear, so newNode is a Root now" << endl;
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
        cout << "1. Add an element to the Tree\n";
        cout << "2. Find an element in the Tree\n";
        cout << "3. Print Tree\n";
        cout << "4. Clean Tree\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";

        choice = console_work();

        if (choice == 1) {
            addNodes();
        }
        else if (choice == 2) {
            if (pRoot != NULL) {
                int _value;
                cout << "Enter value which you want to find: " << endl;
                _value = console_work();
                found = false;
                find(pRoot, _value);
                if (found == true) {
                    cout << "Element " << _value << " was found" << endl;
                }
                else {
                    cout << "Element " << _value << " wasn't found" << endl;
                }
            }
            else {
                cout << "Tree is clear" << endl;
            }
            
        }
        else if (choice == 3) {
            if (pRoot != NULL) {
                printSymmetric(pRoot, 0);
            }
            else {
                cout << "Tree is clear" << endl;
            }
        }
        else if (choice == 4) {
            deleteTree(pRoot);
            cout << "Tree was cleaned" << endl;
            pRoot = NULL;
        }
        else if (choice == 0) {
            deleteTree(pRoot);
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