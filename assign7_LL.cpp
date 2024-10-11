#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string pagename;  // Page name
    Node* next;

    Node(string page) {
        this->pagename = page;  // Using this pointer
        this->next = NULL;
    }
};

class BrowserHistory {
private:
    Node* top;

public:
    BrowserHistory() {
        this->top = NULL;  // Using this pointer
    }

    void addPage(string page) {
        Node* newPage = new Node(page);
        newPage->next = top;
        top = newPage;
        cout << "Visited: " << page << "\n";
    }

    void goBack() {
        if (top == NULL) {
            cout << "No previous page in history.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        if (top == NULL) {
            cout << "No pages left in history.\n";
        } else {
            cout << "Navigated back to: " << top->pagename << "\n";
        }
    }

    void viewCurrentPage() {
        if (top != NULL) {
            cout << "Current page: " << top->pagename << "\n";
        } else {
            cout << "No pages in history.\n";
        }
    }

    void HistoryEmpty() {
        if (top == NULL) {
            cout << "History is empty.\n";
        } else {
            cout << "History is not empty.\n";
        }
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string page;

    do {
        cout << "\nHistory Menu: \n";
        cout << "1. Add visited page\n";
        cout << "2. Navigate back\n";
        cout << "3. View current page\n";
        cout << "4. Check if history is empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter page name: ";
            cin >> page;
            browser.addPage(page);
            break;

        case 2:
            browser.goBack();
            break;

        case 3:
            browser.viewCurrentPage();
            break;

        case 4:
            browser.HistoryEmpty();
            break;

        case 5:
            cout << "Exited Successfully\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
