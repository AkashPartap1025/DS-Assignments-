#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
public:
    int rows, cols, num;
    Element *ele;
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
};

SparseMatrix add(SparseMatrix &s1, SparseMatrix &s2) {
    if(s1.rows!=s2.rows || s1.cols!=s2.cols) {
        cout<<"Addition not possible\n";
        return SparseMatrix(0,0,0);
    }
    SparseMatrix sum(s1.rows,s1.cols,s1.num+s2.num);
    int i=0,j=0,k=0;
    while(i<s1.num && j<s2.num) {
        if(s1.ele[i].row<s2.ele[j].row || 
           (s1.ele[i].row==s2.ele[j].row && s1.ele[i].col<s2.ele[j].col))
            sum.ele[k++]=s1.ele[i++];
        else if(s2.ele[j].row<s1.ele[i].row || 
                (s2.ele[j].row==s1.ele[i].row && s2.ele[j].col<s1.ele[i].col))
            sum.ele[k++]=s2.ele[j++];
        else {
            sum.ele[k]=s1.ele[i];
            sum.ele[k++].val=s1.ele[i++].val+s2.ele[j++].val;
        }
    }
    while(i<s1.num) sum.ele[k++]=s1.ele[i++];
    while(j<s2.num) sum.ele[k++]=s2.ele[j++];
    sum.num=k;
    return sum;
}

int main() {
    SparseMatrix s1(3,3,2), s2(3,3,2);
    cout<<"Matrix 1:\n"; s1.read();
    cout<<"Matrix 2:\n"; s2.read();
    SparseMatrix sum=add(s1,s2);
    cout<<"Resultant Matrix:\n";
    sum.display();
}
