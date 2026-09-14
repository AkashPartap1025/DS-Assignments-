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
                bool found=false;
                for(int x=0;x<num;x++) {
                    if(ele[x].row==i && ele[x].col==j) {
                        cout<<ele[x].val<<" ";
                        found=true;
                        break;
                    }
                }
                if(!found) cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

SparseMatrix multiply(SparseMatrix &s1, SparseMatrix &s2) {
    if(s1.cols!=s2.rows) {
        cout<<"Multiplication not possible\n";
        return SparseMatrix(0,0,0);
    }
    SparseMatrix result(s1.rows,s2.cols,s1.num*s2.num);
    int k=0;
    for(int i=0;i<s1.num;i++) {
        for(int j=0;j<s2.num;j++) {
            if(s1.ele[i].col==s2.ele[j].row) {
                result.ele[k].row=s1.ele[i].row;
                result.ele[k].col=s2.ele[j].col;
                result.ele[k].val=s1.ele[i].val*s2.ele[j].val;
                k++;
            }
        }
    }
    result.num=k;
    return result;
}

int main() {
    SparseMatrix s1(2,2,2), s2(2,2,2);
    cout<<"Matrix 1:\n"; s1.read();
    cout<<"Matrix 2:\n"; s2.read();
    SparseMatrix prod=multiply(s1,s2);
    cout<<"Resultant Matrix:\n";
    prod.display();
}
