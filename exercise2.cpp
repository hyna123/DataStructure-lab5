#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Function to reverse a doubly linked list
Node* reverseDoublyLinkedList(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    // Traverse the list and swap next and prev for each node
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // If the list was not empty, the new head is the previous tail
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}

// Function to display alternate nodes of a doubly linked list
void displayAlternateNodes(Node* head) {
    Node* current = head;
    bool display = true;

    while (current != nullptr) {
        if (display) {
            cout << current->data << " ";
        }
        display = !display;  // Toggle display for alternate nodes
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original List (Alternate Nodes): ";
    displayAlternateNodes(head); // Should print 1 3 5

    head = reverseDoublyLinkedList(head);

    cout << "Reversed List (Alternate Nodes): ";
    displayAlternateNodes(head); // Should print 5 3 1

    return 0;
}
