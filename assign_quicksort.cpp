#include<iostream>
using namespace std;

class Employee {
    public:
        int employeeId;
        string employeeName;
        float employeeSalary;

        void readData() {
            cout << "Enter employee ID: ";
            cin >> employeeId;
            cout << "Enter employee name: ";
            cin >> employeeName;
            cout << "Enter employee salary: ";
            cin >> employeeSalary;
        }

        void display() {
            cout << "Employee ID: " << employeeId << endl;
            cout << "Employee Name: " << employeeName << endl;
            cout << "Employee Salary: " << employeeSalary << endl;
        }

        void quickSort(Employee e[], int low, int high) {
            if (low < high) {
                int pivot = partition(e, low, high);
                quickSort(e, low, pivot - 1);
                quickSort(e, pivot + 1, high);
            }
        }

        int partition(Employee e[], int low, int high) {
            int pivot = e[low].employeeId;
            int i = low + 1;
            int j = high;

            while (i <= j) {
                while (e[i].employeeId <= pivot) {
                    i++;
                }
                while (e[j].employeeId > pivot) {
                    j--;
                }
                if (i <= j) {
                    Employee temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;
                    i++;
                    j--;
                    
                }
            }
            Employee temp = e[low];
            e[low] = e[j];
            e[j] = temp;
            return j;
        }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* e = new Employee[n];

    cout << "Enter employee data:" << endl; 
    for (int i = 0; i < n; i++) {
        e[i].readData();
    }
    e[0].quickSort(e, 0, n - 1);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        e[i].display();
    }

    delete[] e;

    return 0;
}