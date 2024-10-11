#include<iostream>
using namespace std;

void sorting(int arr[], int x)
{
    for(int i = 1;i<x;i++)
    {
        int j = i - 1;
        int value = arr[i];
        
        while(j >= 0 && arr[j] > value )
        {
            // shift 
            arr[j+1] = arr[j];
            j--;

        }
        arr[j+1] = value;

    }
}

void print(int arr[], int x)
{
    // for printing the sorted array 
    cout<<"sorted array is : ";
    for(int i = 0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int x;
    int arr[] = {1,0,1,0,0,0,1};
    x=sizeof(arr)/sizeof(arr[0]);
    
    sorting(arr,x);
    print(arr,x);

}