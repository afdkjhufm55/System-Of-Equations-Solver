#include<iostream>
#include<vector>
using namespace std;
class Matrix{
    private: 
    int n;
    vector<vector<float>> A;
    vector<int> X;
    vector<float> b;
    public:
    Matrix(int a){
        n = a;
        A.resize(n, vector<float>(n));
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
                for(int k = 0;k<n;k++){
                    swap(A[i][k],A[j][k]);
                    swap(b[i],b[j]);
                }
            }
            float x = A[i][i];
            b[i] = b[i]/x;
            for(int j = 0;j<n;j++)    A[i][j] = A[i][j]/x;
            for(int j = i+1;j<n;j++){
                float y=A[j][i];
                b[j] = b[j] - y*b[i];
                for(int k = 0;k<n;k++)    A[j][k] =  A[j][k] - y*A[i][k] ;
            }
        }
        solver();
    }
    void solver(){
        
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