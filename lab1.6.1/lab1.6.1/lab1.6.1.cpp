#include <iostream>


using namespace std;

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
    int counter;
    Tree* pLeft;
    Tree* pRight;
} *pRoot, * pParent;


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

void printInLine(Tree* current) {
    if (current != NULL) {
        printInLine(current->pLeft);
        cout << current->value << "(" << current->counter << ") ";
        printInLine(current->pRight);
    }
}

Tree* find(int _value) {
    Tree* current = pRoot;
    found = false;
    while (current != NULL && found == false) {
        if (_value < current->value) {
            pParent = current;
            current = current->pLeft;
        }
        else if (_value > current->value) {
            pParent = current;
            current = current->pRight;
        }
        else {
            found = true;
        }
    }

    return current;
}

Tree* addNodeRecurs(Tree* current, int _value) {
    if (current == NULL) {
        current = new Tree;
        current->value = _value;
        current->pLeft = current->pRight = NULL;
        current->counter = 1;
    }
    else {
        if (_value < current->value) {
            current->pLeft = addNodeRecurs(current->pLeft, _value);
        }
        else if (_value > current->value) {
            current->pRight = addNodeRecurs(current->pRight, _value);
        }
        else {
            current->counter++;
        }        
    }
    return current;
}

void addNodeNotRecurs(int _value) {
    if (pRoot == NULL) {
        pRoot = new Tree;
        pRoot->pLeft = pRoot->pRight = NULL;
        pRoot->value = _value;
        pRoot->counter = 1;
    }
    else {
        Tree *current = pRoot;
        while (current != NULL) {
            pParent = current;
            if (_value < current->value) {
                current = current->pLeft;
            }
            else if(_value > current->value) {
                current = current->pRight;
            }
            else {
                current->counter++;
                current = NULL;
                
            }
        }
        if (_value < pParent->value) {
            current = new Tree;
            current->pLeft = current->pRight = NULL;
            current->counter = 1;
            current->value = _value;
            pParent->pLeft = current;
        }
        else if (_value > pParent->value) {
            current = new Tree;
            current->pLeft = current->pRight = NULL;
            current->counter = 1;
            current->value = _value;
            pParent->pRight = current;
        }
    }
}

void addNodes() {
    int _value, n;
    cout << "Enter value of newNode: " << endl;
    _value = console_work();
    cout << "How you want to add a newNode? With help of:\n 1. Recursive method\n 2.Not Recursive method\n Choice: ";
    n = console_work();
    while (n != 1 && n != 2) {
        cout << "Error input, try again: ";
        n = console_work();
    }
    if (n == 1) {
        pRoot = addNodeRecurs(pRoot, _value);
    }
    if (n == 2) {
        addNodeNotRecurs(_value);
    }
    
    printBackSymetric(pRoot, 0);
}

void randAddNodes() {
    int n = 0;

    while (n == 0) {
        cout << " How many Nodes do you want to add?\n Enrer: ";
        n = console_work();
        for (int i = 0; i < n; i++) {
            pRoot = addNodeRecurs(pRoot, rand() % 100);
        }
    }
}

Tree* changer(Tree* p) {
    if (p->pLeft != NULL) {
        p = changer(p->pLeft);
    }
    return p;
}


Tree* deleteNode(Tree* current, int _value) {
    if (current == NULL) {
        cout << "Tree hasn't got this Node" << endl;
    }
    else if (_value < current-> value) {
        current->pLeft = deleteNode(current->pLeft, _value);
    }
    else if (_value > current->value) {
        current->pRight = deleteNode(current->pRight, _value);
    }
    else {
        if (current->counter > 1) {
            current->counter--;
        }
        else {
            Tree* pNode = current;
            if (pNode->pRight == NULL) {
                current = pNode->pLeft;
            }                 
            else if (pNode->pLeft == NULL) {
                current = pNode->pRight;
            }                
            else if ((pNode->pRight == NULL) && (pNode->pLeft == NULL)) {
                current = NULL;
            }
            else {
                Tree* p = changer(current->pRight);
                p = find(p->value);
                cout << "value of changeNode " << p->value << " value of pParent " << pParent->value << endl;
                if (current == pParent) {
                    pParent->pRight = p->pRight;
                }
                else {
                    pParent->pLeft = p->pRight;
                }
                current->value = p->value;
                pNode = p;
                delete pNode;
                return current;
            }

            delete pNode;                
        }
    }

    return current;
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
        cout << "1.Create Tree with N elements\n";
        cout << "2. Find an element in the Tree\n";
        cout << "3. Add an element to the Tree\n";
        cout << "4. Delete element from the Tree\n";
        cout << "5. Print Tree in line\n";
        cout << "6. BackSimmetricPrint Tree\n";
        cout << "0. Exit\n";
        cout << "Enter the command number: ";

        choice = console_work();

        if (choice == 1) {
            randAddNodes();
            printBackSymetric(pRoot, 0);
        }
        else if (choice == 2) {
            if (pRoot != NULL) {
                int _value;
                cout << "Enter value which you want to find: " << endl;
                _value = console_work();
                found = false;
                find(_value);
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
            addNodes();
        }
        else if (choice == 4) {
            if (pRoot != NULL) {
                printBackSymetric(pRoot, 0);
                cout << "Which element do you want to delete?\nEnter: ";
                choice = console_work();
                pRoot = deleteNode(pRoot, choice);
                cout << "The element with value " << choice << " was deleted" << endl;
                printBackSymetric(pRoot, 0);
            }
            else {
                cout << "Tree is clean" << endl;
            }
        }
        else if (choice == 5) {
            if (pRoot != NULL) {
                printInLine(pRoot);
            }
            else {
                cout << "Tree is clean" << endl;
            }
        }
        else if (choice == 6) {
            if (pRoot != NULL) {
                printBackSymetric(pRoot, 0);
            }
            else {
                cout << "Tree is clean" << endl;
            }
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
    srand(static_cast<unsigned int>(time(0)));
    menu();
    return 0;
  }

