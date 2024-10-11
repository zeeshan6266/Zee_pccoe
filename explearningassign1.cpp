
#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100; // Define a maximum number of inventory items

class InventoryItem {
public:
    int id;
    int stockLevel;
    int reorderDate; // (e.g., YYYYMMDD)
    string category;

        // Default constructor (using default member initializers)
    InventoryItem() = default;

    // Parameterized constructor (using default member initializers)
    InventoryItem(int i, int s, int r, const string& c) 
        : id(i), stockLevel(s), reorderDate(r), category(c) {}
};

// Function to swap two InventoryItem objects
void swap(InventoryItem& a, InventoryItem& b) {
    InventoryItem temp = a;
    a = b;
    b = temp;
}

// Partition function for Quick Sort by stockLevel
int partitionByStock(InventoryItem arr[], int low, int high) {
    int pivot = arr[high].stockLevel;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].stockLevel <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort function for sorting by stockLevel
void quickSortByStock(InventoryItem arr[], int low, int high) {
    if (low < high) {
        int pi = partitionByStock(arr, low, high);
        quickSortByStock(arr, low, pi - 1);
        quickSortByStock(arr, pi + 1, high);
    }
}

// Function to print inventory items
void printInventory(const InventoryItem arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "ID: " << arr[i].id
             << ", Stock Level: " << arr[i].stockLevel
             << ", Reorder Date: " << arr[i].reorderDate
             << ", Category: " << arr[i].category
             << endl;
    }
}

int main() {
    int n;
    InventoryItem inventory[MAX_ITEMS]; // Fixed-size array for inventory items

    cout << "Enter number of inventory items (max " << MAX_ITEMS << "): ";
    cin >> n;
    

    if (n > MAX_ITEMS) {
        cerr << "Number of items exceeds the maximum allowed." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int id, stockLevel, reorderDate;
        string category;

        cout << "Enter ID, Stock Level, Reorder Date, and Category for item " << i + 1 << ": ";
        cin >> id >> stockLevel >> reorderDate >> category;
        

        inventory[i] = InventoryItem(id, stockLevel, reorderDate, category);
    }

// Sorting by stock levels
    quickSortByStock(inventory, 0, n - 1);
    cout << "\nSorted Inventory by Stock Level:\n";
    printInventory(inventory, n);
    return 0;
}
