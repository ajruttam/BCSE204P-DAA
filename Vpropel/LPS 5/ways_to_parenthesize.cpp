/*
Number of ways to parenthesize
In matrix chain multi plicati on problem, given the number of matrices to be multi plied, write a C++ program to fi nd the number of waysit may be parenthesized. For example, when there are three matrices A1, A2 and A3 there are two ways to parenthesize them.(A1(A2A3)) and ((A1A2)A3). If there are four matrices A1, A2, A3 and A4 then there are fi ve ways to parenthesize as shown(A1(A2(A3A4))), (A1((A2A3)A4)), ((A1,A2)(A3A4)), ((A1(A2A3))A4), (((A1A2)A3)A4).
Input Format
First line contains the number of matrices in the chain, n
Output Format
Print the possible number of parenthesization
*/

#include <iostream>
using namespace std;

long long no_ways(int n){
    if (n <= 1) return 1;
    long long ways = 0;
    for(int i = 0; i < n; i++)
        ways += no_ways(i) * no_ways(n-i-1);
    return ways;
}

int main(){
    int n; cin >> n;
    cout << no_ways(n-1);
}

