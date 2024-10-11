#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(char c) {
        data = c;
        next = NULL;
        prev = NULL;
    }

    friend class object;
};

class object {
    Node* head;
    Node* tail;

public:
    object() {
        head = NULL;
        tail = NULL;
    }

    // Insert text at the end
    void insertTextEnd(string text) {
        cout<<"\n";
        for (char c : text) {
            Node* newNode = new Node(c);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    // Insert text at the beginning
    void insertTextBeginning(string text) {
        for (int i = text.length() - 1; i >= 0; i--) {
            Node* newNode = new Node(text[i]);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
    }

    // Insert text at a specific position (after a given character)
    void insertTextBetween(string text, char key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                for (char c : text) {
                    Node* newNode = new Node(c);
                    newNode->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = newNode;
                    }
                    newNode->prev = temp;
                    temp->next = newNode;
                    temp = newNode;
                    if (newNode->next == NULL) {
                        tail = newNode;
                    }
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Key character not found. Inserting at the end." << endl;
        insertTextEnd(text);
    }

    // Delete the entire text
    void deleteText() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        cout << "Successfully deleted all text." << endl;
    }

    // Display the text buffer
    void displayText() {
        if (head == NULL) {
            cout << "Text is empty. \n" << endl;
            return;
        }

        Node* temp = head;
        cout << "Current text : ";
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Search for a character in the text buffer
    void searchText(char key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Character '" << key << "' found in the text buffer." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Character '" << key << "' not found in the text buffer." << endl;
    }
};

int main() {
    object textObject;
    int choice, sub_choice;
    string text;
    char key;

    do {
        cout << "Select your choice: \n 1. Insert text \n 2. Display text \n 3. Delete all text \n 4. Search text \n 5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add text options: \n 1. Add text at the beginning \n 2. Add text at the end \n 3. Add text in between" << endl;
                cin >> sub_choice;
                cin.ignore();
                switch (sub_choice) {
                    case 1:
                        cout << "Enter the text to insert at the beginning: ";
                        getline(cin, text);
                        textObject.insertTextBeginning(text);
                        cout << "Successfully inserted text at the beginning." << endl;
                        break;

                    case 2:
                        cout << "Enter the text to insert at the end: ";
                        getline(cin, text);
                        textObject.insertTextEnd(text);
                        cout << "Successfully inserted text at the end." << endl;
                        break;

                    case 3:
                        cout << "Enter the text to insert: ";
                        getline(cin, text);
                        cout << "Enter the character after which to insert: ";
                        cin >> key;
                        textObject.insertTextBetween(text, key);
                        cout << "Successfully inserted text in between." << endl;
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 2:
                cout<<"\n";
                textObject.displayText();
                break;

            case 3:
                textObject.deleteText();
                break;

            case 4:
                cout << "Enter the character to search: ";
                cin >> key;
                textObject.searchText(key);
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Enter the correct choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
