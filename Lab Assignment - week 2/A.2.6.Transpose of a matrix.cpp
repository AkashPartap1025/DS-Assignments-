#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
    int rows, cols, num;
    Element *ele;
public:
    SparseMatrix(int r,int c,int n) {
        rows=r; cols=c; num=n;
        ele=new Element[num];
    }
    void read() {
        cout<<"Enter row col value:\n";
        for(int i=0;i<num;i++) {
            cin>>ele[i].row>>ele[i].col>>ele[i].val;
        }
    }
    void display() {
        int k=0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(k<num && ele[k].row==i && ele[k].col==j)
                    cout<<ele[k++].val<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
    SparseMatrix transpose() {
        SparseMatrix t(cols,rows,num);
        for(int i=0;i<num;i++) {
            t.ele[i].row=ele[i].col;
            t.ele[i].col=ele[i].row;
            t.ele[i].val=ele[i].val;
        }
        return t;
    }
};

int main() {
    SparseMatrix s(3,3,3);
    s.read();
    cout<<"Original Matrix:\n";
    s.display();
    SparseMatrix t=s.transpose();
    cout<<"Transpose Matrix:\n";
    t.display();
}
