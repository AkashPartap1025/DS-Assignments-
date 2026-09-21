#include<iostream>
using namespace std;

int main() {

    int arr[] = {5,1,4,2,8};
    int n = 5;

    for(int i=0;i<n-1;i++) {

        for(int j=0;j<n-i-1;j++) {

            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    cout<<"Sorted Array: ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}