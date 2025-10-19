#include<iostream>
#include<cmath>
#include<vector>
class Matrix{
    private: 
    int m,n,rank;
    bool singular;
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> Augmatrix;
    std::vector<double> b;
    public:
    Matrix(int row){
        m = n = row;
        A.resize(n, std::vector<double>(n));
        b.resize(n);
        readinput();
        singular=false;
    }

    Matrix(int row,int col){
        m = row;
        n = col;
        A.resize(m, std::vector<double>(n));
        b.resize(n);
        readinput();
        singular=false;
    }

    bool is_singular(){
        to_ref();
        return singular;
    }

    void readinput(){
        std::cout<<"enter the Matrix A:"<<std::endl;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) std::cin>>A[i][j];
        std::cout<<"enter the matrix b:"<<std::endl;
        for(int i=0;i<n;i++) std::cin>>b[i];
        to_ref();
    }

    void to_ref(){
        int col=0;
        for(int i=0;i<m;i++){
            int j;
            for(j=i;j<m;j++){
                if(A[j][col]!=0) break;
            }
            if(j!=m&&j!=i){
                for(int k = 0;k<n;k++)  std::swap(A[i][k],A[j][k]);
            }
            if(j==m) singular = true;
            else {
                double x = A[i][col];
                b[i] = b[i]/x;
                for(int k = col;k<n;k++) A[i][k] = A[i][k]/x;
                for(int j = i+1;j<m;j++){
                    double y=A[j][col];
                    b[j] = b[j] - y*b[i];
                    for(int k = col;k<n;k++)    A[j][k] =  A[j][k] - y*A[i][k] ;
                }
            }
            col++;
        }
        fix_precision_values();
        /*for(int i = 0;i<n;i++){
            if(A[i][i]==0){
                int j;
                for( j = i+1;j<n;j++){
                    if(A[j][i]!=0)    break;
                }
                if(j==n) singular=true;
                else{ 
                    singular = false;
                    for(int k = 0;k<n;k++)    swap(A[i][k],A[j][k]);
                    swap(b[i],b[j]);
                }
            }
            if(singular) return; 
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
        */
    }

    void solver(){
        if(m==n) {   
            for(int i =n-1;i>=1;i--){
                for(int j = i-1;j>=0;j--){
                    double y = A[j][i];
                    b[j] = b[j] - y*b[i];
                    A[j][i] = 0;
                }
            }
        }
        else{
            find_rank();
            int col=0;
            for(int i = rank-1;i>=1;i--){
                if(A[i][col]==0){
                    for(col = i-1;col<n;col++) if(A[i][col]!=0) break;
                }
                for(int j = i-1;j>=0;j--){
                    double y = A[j][col];
                    b[j] = b[j] - y*b[i];
                    A[j][col] = 0;
                }   
                col--;
            }
        }
        fix_precision_values();
    }

    void display_matrix_A(){
        std::cout<<"A"<<std::endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                std::cout<<A[i][j]<<"\t";
            std::cout<<std::endl;
        }
    }
    
    void display_vector_b(){
        std::cout<<"b"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<"x"<<i+1<<"\t"<<b[i]<<std::endl;
        }
    }

    void fix_precision_values(){
        const double EPS = 1e-9;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fabs(A[i][j]) < EPS) A[i][j] = 0;
            }
            if (fabs(b[i]) < EPS) b[i] = 0;
        }
    }

    void find_rank(){
        rank = 0;
        int col = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(A[i][j]!=0){rank++;break;}
            }
        }
    }

    
};

int main(){
    int m,n;
    std::cout<<"enter the value of m and n:";
    std::cin>>m;
    std::cin>>n;
    Matrix M(m,n);
    return 0;
}