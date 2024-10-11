#include <iostream>
#include <string>

using namespace std;

class Route {
    public:
    string location;
    Route *next;
    Route *prev;

    Route (string x) // parameterized constructor 
    {
    location = x;
    next = NULL;
    prev = NULL;
    }

};

class NavigationSystem{
    private:
    Route *last;

    public:
    NavigationSystem(){
        last = NULL;
    }

    void add_route(string location)
    {
        Route *temp = new Route(location);

        if(last == NULL){
            last = temp;
            last -> next = last;
            last -> prev = last;

        }
        else {
            temp->next = last->next;
            temp->prev = last;
            last->next->prev = temp;
            last->next = temp;
            last = temp;
    }
    }

    void remove(string location)
    {
        if (last == NULL){
            cout<<"No routes to remove"<<endl;
            return;
        }

        Route *current = last->next;
        do{
            if(current->location == location){
                if(current == last && current -> next == last){
                    delete current;
                    last = NULL;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    if (current == last){
                        last = current->prev;
                    }
                    delete current;
                }
                
                return;
            }
            current = current->next;
            cout<<"route removed successfully." << endl;
        }
        while(current != last->next);
        cout << "Route not found." << endl;
    }

    void display_routes(){
        if (last == NULL) {
            cout << "No routes available." << endl;
            return;
        }

        Route* current = last->next;  
        cout << "Routes : ";

        do {
            cout << current->location << " ";
            current = current->next;
        } while (current != last->next);

        
    }
};

int main() {
    NavigationSystem navSys;
    int choice;
    string location;

    do {
        cout << "\nNavigation System Options: \n 1. Add route \n 2. Remove route \n 3. Display routes \n 4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the location to add: ";
                cin.ignore();
                getline(cin, location);
                navSys.add_route(location);
                break;

            case 2:
                cout << "Enter the location to remove: ";
                cin.ignore();
                getline(cin, location);
                navSys.remove(location);
                break;

            case 3:
                navSys.display_routes();
                break;
        
            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}