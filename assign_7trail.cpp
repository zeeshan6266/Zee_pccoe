#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string stack[100];  
    int top;            

public:
    BrowserHistory() // default constructor to initialize top
    {
        top = -1;  
    }

    // Add a new page 
    void addPage(string page) {
        if (top >= 99) {  // Check if the stack is full
            cout << "History is full.\n";
            return;
        }
        top++;
        stack[top] = page;  // Add the page to the stack
        cout << "Visited: " << page << "\n";
    }

    // navigate back
    void goBack() {
        if (top <= 0) {
            cout << "No previous page in history.\n";
        } else {
            top--;
            cout << "Navigated back to: " << stack[top] << "\n";
        }
    }

    // View the current page
    void viewCurrentPage() {
        if (top != -1) {  // Check if the stack is not empty
            cout << "Current page: " << stack[top] << "\n";
        } else {
            cout << "No pages in history.\n";
        }
    }

    // if the history is empty 
    void HistoryEmpty() {
        if (top == -1) {
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
            cout << "Enter page URL: ";
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
            cout << "Exited Succesfully\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
