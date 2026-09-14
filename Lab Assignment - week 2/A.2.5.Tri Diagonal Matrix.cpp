#include <iostream>
using namespace std;

class TriDiagonalMatrix {
    int *arr;
    int n;
public:
    TriDiagonalMatrix(int size) {
        n=size;
        arr=new int[3*n-2];
        for(int i=0;i<3*n-2;i++) arr[i]=0;
    }
    void set(int i,int j,int val) {
        if(i-j==0) arr[i-1]=val;    
        else if(i-j==1) arr[n+i-2]=val;    
        else if(j-i==1) arr[2*n+i-2]=val;     
    }
    int get(int i,int j) {
        if(i-j==0) return arr[i-1];
        else if(i-j==1) return arr[n+i-2];
        else if(j-i==1) return arr[2*n+i-2];
        else return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    TriDiagonalMatrix t(4);
    t.set(1,1,5);
    t.set(2,1,2);
    t.set(2,2,8);
    t.set(2,3,3);
    t.set(3,2,6);
    t.set(3,3,9);
    t.set(3,4,4);
    t.set(4,3,7);
    t.set(4,4,12);
    t.display();
}
