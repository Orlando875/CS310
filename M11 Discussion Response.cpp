#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class Type>
class MyList {
private:
    struct ListNode {
        Type value;
        ListNode* pNext;
    };

    ListNode* pFirstNode;
    ListNode* pLastNode;
    ListNode* pCurrentNode;
    int size;

public:
    MyList() : pFirstNode(nullptr), pLastNode(nullptr), pCurrentNode(nullptr), size(0) {}

    int getSize() const {
        return size;
    }

    void add(Type obj) {
        ListNode* pNode = new ListNode;
        pNode->value = obj;
        pNode->pNext = nullptr;

        if (size == 0) {
            pFirstNode = pNode;
            pLastNode = pNode;
        } else {
            pLastNode->pNext = pNode;
            pLastNode = pNode;
        }

        size++;
    }

    void insert(int index, Type obj) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of bounds.");
        }

        ListNode* pNode = new ListNode;
        pNode->value = obj;

        if (index == 0) {
            pNode->pNext = pFirstNode;
            pFirstNode = pNode;
        } else {
            ListNode* p = pFirstNode;

            for (int i = 0; i < index - 1; i++) {
                p = p->pNext;
            }

            pNode->pNext = p->pNext;
            p->pNext = pNode;
        }

        size++;
    }

    Type get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }

        ListNode* pNode = pFirstNode;

        for (int i = 0; i < index; i++) {
            pNode = pNode->pNext;
        }

        return pNode->value;
    }

    bool hasNext() const {
        return (size > 0 && (pCurrentNode == nullptr || pCurrentNode->pNext != nullptr));
    }

    Type getNext() {
        if (pCurrentNode == nullptr && size > 0) {
            pCurrentNode = pFirstNode;
        } else if (pCurrentNode != nullptr) {
            pCurrentNode = pCurrentNode->pNext;
        }

        return pCurrentNode->value;
    }

    void reset() {
        pCurrentNode = nullptr;
    }
};

template <class Type>
void printDelimitedList(const MyList<Type>& list) {
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i);
        if (i < list.getSize() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

template <class Type>
void printVerticalList(MyList<Type>& list) {
    list.reset();
    while (list.hasNext()) {
        cout << list.getNext() << endl;
    }
    cout << endl;
}

int main() {
    MyList<string> names;
    names.add("Michael");
    names.add("Anthony");
    names.add("Isabella");

    cout << "Original list" << endl;
    printDelimitedList(names);

    names.insert(1, "Megan");
    cout << "Inserted name" << endl;
    printDelimitedList(names);

    cout << "Vertical list" << endl;
    printVerticalList(names);

    return 0;
}