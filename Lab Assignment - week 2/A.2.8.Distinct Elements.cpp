#include <iostream>
#include <algorithm>
using namespace std;

int countDistinct(int arr[], int n) {
    sort(arr, arr+n);
    int count=1;
    for(int i=1;i<n;i++) {
        if(arr[i]!=arr[i-1]) count++;
    }
    return count;
}

int main() {
    int arr[]={10,20,20,10,30,40,30};
    int n=7;
    cout<<"Distinct elements: "<<countDistinct(arr,n)<<endl;
}
