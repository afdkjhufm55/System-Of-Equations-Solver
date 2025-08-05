#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class Matrix{
    private: 
    int n;
    vector<vector<double>> A;
    vector<int> X;
    vector<double> b;
    public:
    Matrix(int a){
        n = a;
        A.resize(n, vector<double>(n));
        X.resize(n);
        b.resize(n);
        readinput();
    }

    void readinput(){
    cout<<"enter the Matrix A:"<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>A[i][j];
    cout<<"enter the matrix b:"<<endl;
    for(int i=0;i<n;i++)
    cin>>b[i];
    to_ref();
    }

    void to_ref(){
        for(int i = 0;i<n;i++){
            if(A[i][i]==0){
                int j;
                for( j = i+1;j<n;j++){
                    if(A[j][i]!=0)    break;
                }
                for(int k = 0;k<n;k++)    swap(A[i][k],A[j][k]);
                swap(b[i],b[j]);
            }
            double x = A[i][i];
            b[i] = b[i]/x;
            for(int j = 0;j<n;j++)    A[i][j] = A[i][j]/x;
            for(int j = i+1;j<n;j++){
                double y=A[j][i];
                b[j] = b[j] - y*b[i];
                for(int k = 0;k<n;k++)    A[j][k] =  A[j][k] - y*A[i][k] ;
            }
        }
        solver();
    }
    
    void solver(){
        for(int i =n-1;i>=1;i--){
            for(int j = i-1;j>=0;j--){
                double y = A[j][i];
                b[j] = b[j] - y*b[i];
                A[j][i] = 0;
            }
        }
        const double EPS = 1e-9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fabs(A[i][j]) < EPS) A[i][j] = 0;
            }
            if (fabs(b[i]) < EPS) b[i] = 0;
        }
        display_ans();
    }

    void display_ans(){
        cout<<"A"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<A[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl<<"b"<<endl;
        for(int i=0;i<n;i++){
            cout<<"x"<<i+1<<"\t"<<b[i]<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    Matrix M(n);
    return 0;
}