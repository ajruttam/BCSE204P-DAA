/*
Maximum cost for matrix chain multiplication
Modify the algorithm developed in problem 4 (matrix chain multiplication problem) to find the way to parenthesize thatwill have maximum number of multiplications. Print the matrices with parenthesis that will have maximum number ofmultiplications as well. For example given three matrices and dimension as follows:
4
10 100 5 50
The code must print the m table as
5000 75000
25000
S table as
1 1
2
Maximum cost is
75000
Paraenthesization of matrices is
(A1(A2A3))
Input Format
First line contains the number of matrices +1, n
Next line contains the dimensions of the matrices in the chain
Output Format
Print the mtable
Print the s table
Print the maximum cost
Print the parenthesization that will lead to maximum cost
*/

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
void matrix_chain_order(vector<int> p, vector<vector<int> >& m, vector<vector<int> >& s){
    int n,l,i,j,k,q;
    n = p.size()-1;
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            m[i-1][j-1] = INT_MIN;
            for(k=i;k<=j-1;k++){
                q = m[i-1][k-1] + m[k][j-1] + p[i-1]*p[k]*p[j];
                if(q>m[i-1][j-1]){
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
}
void print_Optimal_Parens(vector<vector<int> >& s, int i, int j){
    if(i==j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        print_Optimal_Parens(s,i,s[i-1][j-1]);
        print_Optimal_Parens(s,s[i-1][j-1]+1,j);
        cout<<")";
    }
}
int main(){    
    int n,i,j;
    cin>>n;
    vector<int> p(n);
    for(i=0;i<n;i++)
        cin>>p[i];
    vector<vector<int> > m(n-1,vector<int>(n-1,0));
    vector<vector<int> > s(n-1,vector<int>(n-1,0));
    matrix_chain_order(p,m,s);
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<m[0][n-2]<<endl;
    print_Optimal_Parens(s,1,n-1);
}
