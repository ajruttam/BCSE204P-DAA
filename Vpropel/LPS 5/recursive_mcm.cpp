/*
Recursive Matrix Chain multiplication
Matrix chain multi plicati on problem aims at fi nding the opti mal way to parenthesize the matrix chain so that the number ofmulti plicati ons (cost) will be minimum. The matrices are compati ble for matrix multi plicati on so the number of columns in the ithmatrix will be equal to number of rows in the (i+1)th matrix. Given dimension of ‘n’ matrices in the chain, write a recursive algorithmand code to fi nd the minimum cost required to multi ply the matrices in the chain. For example, if there are three matrices A1, A2, A3and the dimension are 10 x 100, 100 x 5 and 5 x 50 respecti vely then input will 10, 100, 5, 50 and minimum cost will be 7500 whenparenthesized as ((A1A2)A3).
Input Format
First line contains the number of dimensions (number of matrices in the chain + 1), n
Next line contain 'n' numbers indicati ng dimensions of matrices in order
Output Format
Print the minimum cost (number of multi plicati ons required ) to multi ply matrices in the chain
*/
#include<iostream>
using namespace std;
#include<vector>
#include<climits>    
vector<vector<int> > m(100,vector<int>(100,0));
vector<vector<int> > s(100,vector<int>(100,0));
int matrix_chain_mul(int st, int e, vector<int> p){
    int n,l,i,j,k,q;
    n = p.size()-1;
    for(l=2;l<=e;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            m[i-1][j-1] = INT_MAX;
            for(k=i;k<=j-1;k++){
                q = m[i-1][k-1] + m[k][j-1] + p[i-1]*p[k]*p[j];
                if(q<m[i-1][j-1]){
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
    return m[0][n-1];
}

int main()
{
    int n,ele,i;
    vector<int> p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p.push_back(ele);
    }
cout<<matrix_chain_mul(1,n-1,p);
}
