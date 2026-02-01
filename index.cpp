#include <iostream>

using namespace std;

struct Staff {
    int id;
    string name;
    string role;
    Staff* next;
};

Staff* head = nullptr;

void addStaff() {
    Staff* newnode = new Staff;
    cout << "Enter Staff ID: ";
    cin >> newnode->id;
    cout << "Enter Staff Name: ";
    cin >> newnode->name;
    cout << "Enter Role (Manager/Chef/Waiter/Security): ";
    cin >> newnode->role;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
    } else {
        Staff* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newnode;
    }
}

void displayStaff() {
    if (head == nullptr) {
        cout << "No staff registered\n";
        return;
    }
    Staff* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << " Name: " << temp->name << " Role: " << temp->role << endl;
        temp = temp->next;
    }
}

#define MAX 5

class EntryQueue {
    int arr[MAX];
    int front, rear;

public:
    EntryQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void requestEntry() {
        int id;
        if (isFull()) {
            cout << "Entry queue is full\n";
            return;
        }
        cout << "Enter Staff ID requesting entry: ";
        cin >> id;
        if (isEmpty())
            front = rear = 0;
        else
            rear++;
        arr[rear] = id;
    }

    void allowEntry() {
        if (isEmpty()) {
            cout << "No pending entry requests\n";
            return;
        }
        cout << "Entry allowed for Staff ID: " << arr[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void nextEntry() {
        if (isEmpty())
            cout << "No pending requests\n";
        else
            cout << "Next Entry Request Staff ID: " << arr[front] << endl;
    }
};

int main() {
    EntryQueue q;
    int choice;

    do {
        cout << "\n1. Register Staff\n";
        cout << "2. Display Staff\n";
        cout << "3. Request Entry\n";
        cout << "4. Allow Entry\n";
        cout << "5. View Next Entry\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStaff();
            break;
        case 2:
            displayStaff();
            break;
        case 3:
            q.requestEntry();
            break;
        case 4:
            q.allowEntry();
            break;
        case 5:
            q.nextEntry();
            break;
        case 0:
            cout << "System Closed\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 0);

    return 0;
}
