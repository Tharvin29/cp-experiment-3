#include<iostream>
#include<cassert>
using namespace std;
class matrix {
    private:
    int data[2][2];
    public:
    matrix(int a=0,int b=0,int c=0, int d=0){
        data[0][0]=a;
        data[0][1]=b;
        data[1][0]=c;
        data[1][1]=d;

    }
    matrix operator+(const matrix &m){
        matrix result;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                result.data[i][j]=data[i][j]+m.data[i][j];
     return result;
    }
    matrix operator *(const matrix &m){
        matrix result;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                result.data[i][j]=0;
                for(int k=0;k<2;k++)
                result.data[i][j]+=data[i][k]*m.data[k][j];
               }
        }
        return result;
    }
    int*operator[](int index){
        return data[index];
    }
    friend ostream & operator<<(ostream&out,const matrix&m){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout<<m.data[i][j]<<"";
        cout<<endl;
        }
        return out;
    }

};
int main(){
    matrix A(1,2,3,4);
    matrix B(5,6,7,8);
    matrix sum = A+B;
    matrix product=A*B;

    assert(sum[0][0]==6);
    assert(sum[1][1]==12);
    assert(product[0][0]==19);
    assert(product[0][1]==22);
    assert(product[1][0]==43);
    assert(product[1][1]==50);
    cout<<"matrix A :"<<endl;
    cout<<A;
    cout<<"matrix B :"<<endl;
    cout<<B;

    cout<<"addition of matrices :"<<endl;
    cout<<sum;
    cout<<"multiplication of matrices :"<<endl;
    cout<<product;
    cout<<"All unit tests passed successfully."<<endl;
    return 0;
}