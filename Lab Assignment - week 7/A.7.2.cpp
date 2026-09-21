#include <iostream>
using namespace std;

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90};
    int n = 6;

    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int minIndex = left;
        int maxIndex = left;

        for(int i = left; i <= right; i++)
        {
            if(arr[i] < arr[minIndex])
                minIndex = i;

            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if(maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}