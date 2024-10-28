#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DList {
private:
    Node* head;

public:
    DList() {
        head = nullptr;
    }

    bool emptyList() {
        return head == nullptr;
    }

    void insert_after(int oldV, int newV) {
        Node* current = head;
        while (current != nullptr && current->data != oldV) {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node(newV);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current != nullptr) {
            if (current == head) {
                head = current->next;
            } else {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
        }
    }

    void insert_begin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insert_end(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DList list;

    list.insert_end(10);
    list.insert_begin(5);
    list.insert_after(10, 15);
    list.insert_end(20);

    list.traverse(); // Output: 5 10 15 20

    list.deleteNode(15);

    list.traverse(); // Output: 5 10 20

    return 0;
}