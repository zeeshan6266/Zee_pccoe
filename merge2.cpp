#include <iostream>
using namespace std;
class employee {
public:
int salary, id;
string name;
void input(employee e[], int n);
void quick_sort(employee e[], int f, int l);
void merge_sort(employee e[],int l,int r);
void merge(employee e[],int l,int m,int r);
void display(employee e[], int n);
};
void employee::input(employee e[], int n) {
cout << "Enter employee details :\n";
for (int i = 0; i < n; i++) {
cin >> e[i].name >> e[i].id >> e[i].salary;
}
}
void employee::quick_sort(employee e[], int f, int l) {
if (f < l) {
int pivot = e[f].id;
int i = f + 1;
int j = l;
while (i <= j) {
while (i <= l && e[i].id < pivot)
i++;
while (j >= f && e[j].id > pivot)
j--;
if (i < j) {
employee temp = e[i];
e[i] = e[j];

e[j] = temp;
}
}
employee temp = e[f];
e[f] = e[j];
e[j] = temp;
quick_sort(e, f, j - 1);
quick_sort(e, j + 1, l);
}
}
void employee::merge(employee e[], int l, int m, int r) {
int i = l, j = m + 1, k = 0;
employee b[100];
while (i <= m && j <= r) {
if (e[i].name <= e[j].name) {
b[k++] = e[i++];
} else {
b[k++] = e[j++];
}
}
while (i <= m) {
b[k++] = e[i++];
}
while (j <= r) {
b[k++] = e[j++];
}
for (int i = 0; i < k; i++) {
e[l + i] = b[i];
}
}
void employee::merge_sort(employee e[], int l, int r) {
if (l < r) {
int m = l + (r - l) / 2;
merge_sort(e, l, m);
merge_sort(e, m + 1, r);
merge(e, l, m, r);
}

}
void employee::display(employee e[], int n) {
for (int i = 0; i < n; i++) {
cout << e[i].name << " " << e[i].id << " " << e[i].salary;
cout << "\n";
}
}
int main() {
int n;
cout<<"Enter the number of employee:";
cin>>n;
employee e[n],aa;
int choice = 0;
while (true) {
cout << "1. Input employee details\n";
cout << "2. Sort employee by id number\n";
cout << "3. Sort employee by name\n";
cout << "4. Display sorted employee details\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
aa.input(e, n);
break;
case 2:
aa.quick_sort(e, 0, n - 1);
break;
case 3:
aa.merge_sort(e,0,n-1);
break;
case 4:
aa.display(e, n);
break;
case 5:
cout << "Exit\n";
return 0;
default:
cout << "Invalid option.\n";
}

}
}