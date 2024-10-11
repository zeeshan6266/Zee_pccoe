#include <iostream>

using namespace std;

class student {
    int roll_no;
    string name;
    float marks;

public:
    void getdata();
    void shell_sort(student s[], int n); 
    void display(student s[], int n); 
};

void student::getdata() {
    cout << "\nEnter your Roll No : " << endl;
    cin >> roll_no;
    cout << "\nEnter your name: " << endl;
    cin >> name;
    cout << "\nEnter your marks: " << endl;
    cin >> marks;

}

void student::shell_sort(student s[], int n) {
    int gap = n/2;
    student temp;
    while(gap>=1)
    {
        for(int j=gap;j<n;j++)
        {
            for(int i=j-gap;i>=0;i=i-gap)
            {
                if(s[i+gap].name>s[i].name)
                {
                    break;
                }
                else 
                {
                    
                    temp=s[i+gap];
                    s[i+gap]=s[i];
                    s[i]=temp;
                }

            }
            
        }
        gap=gap/2;
    }
}

void student::display(student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name : " << s[i].name << endl;
        cout << "Roll No : " << s[i].roll_no << endl; 
        cout << "\n";
    }
}

int main() {
    
    int n,choice;
    cout<<"\nEnter the number of entries : "<<endl;
    cin>>n;

    student s[n],x;
        do{
        cout<<"\nPlease enter a choice : \n1.Add data \n2.Sort data \n3.Display data \n4.Exit"<<endl;
        cin>>choice;        
        switch(choice){
            case 1: 
                for(int i=0;i<n;i++){
                 s[i].getdata();
            }
            break;
            case 2:
                x.shell_sort(s,n);
                cout<<"\nData sorted successfully"<<endl;
                break;

            case 3:
                cout<<"\nDisplaying Data : "<<endl;
                x.display(s,n);
                break;
            case 4:
                cout<<"\nSuccessfully Exited"<<endl;
            break;
            default:
                cout<<"\nPlease enter a valid choice"<<endl;
         }
        }
        while(choice!=4);
        
    return 0;
}