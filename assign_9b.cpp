#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int size;
    int queue[5];

public:
    
    CircularQueue() {
        front = rear = -1;
        size = 5;
    }
    // enqueue
    void customerArrival(int customer) {
        if ((rear + 1) % size == front) {
            cout << "Checkout counter is full. Cannot add more customers.\n";
            return;
        }
        if (front == -1) {
            front = 0;  
        }
        rear = (rear + 1) % size;
        queue[rear] = customer;
        cout << "Customer " << customer << " arrived.\n";
    }
    // dequeue
    void customerCheckout() {
        if (front == -1) {
            cout << "No customers in the queue.\n";
            return;
        }
        cout << "Customer " << queue[front] << " checked out.\n";
        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % size;
        }
    }

    // display queue
    void viewCustomers() {
        if (front == -1) {
            cout << "No customers in the queue.\n";
            return;
        }
        cout << "Customers in the queue: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << queue[rear] << "\n"; 
    }

    // Close the checkout counter
    void closeCheckoutCounter() {
        if (front == -1) {
            cout << "Checkout counter is already empty.\n";
            return;
        }
        cout << "Closing checkout counter. Remaining customers: ";
        viewCustomers();
        front = rear = -1;  
    }
};


int main() {
    CircularQueue checkout;
    int choice, customerID;

    do {
        cout << "\nSupermarket Checkout System\n";
        cout << "1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. View Customers\n";
        cout << "4. Close Checkout Counter\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer ID: ";
                cin >> customerID;
                checkout.customerArrival(customerID);
                break;

            case 2:
                checkout.customerCheckout();
                break;

            case 3:
                checkout.viewCustomers();
                break;

            case 4:
                checkout.closeCheckoutCounter();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
