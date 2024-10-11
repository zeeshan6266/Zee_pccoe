#include <iostream>
using namespace std;

class Node {
    string song_name;
    Node *next;
public:
    Node() {
        song_name = "";
        next = NULL;
    }
    Node(string s) {
        song_name = s;
        next = NULL;
    }
    friend class playlist; 
};

class playlist {
    Node *head;
public:
    playlist() {
        head = NULL;
    }

    void insert_song_beginning(string s) {
        Node *nn = new Node(s); 
        if (head == NULL) {
            head = nn; 
        } 
        else {
            nn->next = head; 
            head = nn; 
        }
    }

    void insert_song_end(string s) {
        Node *nn = new Node(s);
        if (head == NULL) {
            head = nn;
        }
        else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void insert_song_between(string s, string key) {
        Node *nn = new Node(s);
        if (head == NULL) {
            head = nn;
        }
        else {
            Node *temp = head;
            while (temp != NULL) {
                if (temp->song_name == key) {
                    nn->next = temp->next;
                    temp->next = nn;
                    return;
                }
                temp = temp->next;
            }
            cout << "Key song not found. Inserting at the end." << endl;
            insert_song_end(s);
        }
    }

    void delete_song_beginning() {
        if (head == NULL) {
            cout << "Playlist is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_song_end() {
        if (head == NULL) {
            cout << "Playlist is empty. Nothing to delete." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void delete_song_at_position(string key) {
        if (head == NULL) {
            cout << "Playlist is empty. Nothing to delete." << endl;
            return;
        }

        if (head->song_name == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL) {
            if (temp->next->song_name == key) {
                Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found in the playlist." << endl;
    }

    void display_song() {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }
        cout << "Displaying song playlist:" << endl;
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->song_name << endl;
            temp = temp->next;
        }
    }

    void song_search(string s) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->song_name == s) {
                cout << "Song \"" << s << "\" found in the playlist." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song \"" << s << "\" not found in the playlist." << endl;
    }
};

int main() {
    playlist song1;
    int choice, sub_choice;
    string song_name, key_song;

    do {
        cout << "Select your choice: \n 1. Add song \n 2. Display songs \n 3. Delete song \n 4. Search song \n 5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add song options: \n 1. Add song at the beginning \n 2. Add song at the end \n 3. Add song in between" << endl;
                cin >> sub_choice;
                cin.ignore();
                switch (sub_choice) {
                    case 1:
                        cout << "Enter the song name to insert at the beginning: ";
                        getline(cin, song_name);
                        song1.insert_song_beginning(song_name);
                        cout << "Successfully inserted song at the beginning." << endl;
                        break;

                    case 2:
                        cout << "Enter the song name to insert at the end: ";
                        getline(cin, song_name);
                        song1.insert_song_end(song_name);
                        cout << "Successfully inserted song at the end." << endl;
                        break;

                    case 3:
                        cout << "Enter the song name to insert: ";
                        getline(cin, song_name);
                        cout << "Enter the song name after which to insert: ";
                        getline(cin, key_song);
                        song1.insert_song_between(song_name, key_song);
                        cout << "Successfully inserted song in between." << endl;
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 2:
                song1.display_song();
                break;

            case 3:
                cout << "Delete song options: \n 1. Delete from the beginning \n 2. Delete from the end \n 3. Delete specific song" << endl;
                cin >> sub_choice;
                cin.ignore(); 
                switch (sub_choice) {
                    case 1:
                        song1.delete_song_beginning();
                        cout << "Successfully deleted the first song." << endl;
                        break;

                    case 2:
                        song1.delete_song_end();
                        cout << "Successfully deleted the last song." << endl;
                        break;

                    case 3:
                        cout << "Enter the song name to delete: ";
                        getline(cin, key_song);
                        song1.delete_song_at_position(key_song);
                        cout << "Successfully deleted the specified song." << endl;
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 4:
                cout << "Enter the song name to search: ";
                cin.ignore();
                getline(cin, song_name);
                song1.song_search(song_name);
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
