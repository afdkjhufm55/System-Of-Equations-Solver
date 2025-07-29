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
    solver();
    }
    
    void solver(){
        //make the vector A into reduced row echelon form 
        //the answer will be in vector b
        for(int i=0;i<n;i++){
            if(A[i][i]!=0){
                b[i]=b[i]/A[i][i];
                for(int k = i;k<n;k++){
                    A[i][k] = A[i][k]/A[i][i];
                }
            }
            /*for(int j=i+1;j<n;j++){
                if(A[j][i]!=0){
                    for(int k = i;k<n;k++){
                        
                    }
                }
            }*/
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