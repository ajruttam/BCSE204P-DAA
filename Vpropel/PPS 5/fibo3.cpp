/*
My Fibanocci Term
MyFibonacci series is one which is defi ned as follows:
fiba(1) = 0
fiba(2) = 1
fiba(3) = 2
fiba(n) = fiba(n-1) + fiba(n-2) + fiba(n-3)
Given value of ‘n’, use top-down dynamic programming to find fiba(n).
Input Format
First line contains the value of 'n'
Output Format
Print the nth term in My Fibanocci series
*/

#include <iostream>
#include <vector>
using namespace std;

vector <long long> a(100,-1);
long long fiba(int n){
    if (n == 1){
        return 0;
    }
    else if (n == 2){
        return 1;
    }
    else if (n == 3){
        return 2;
    }
    else if (a[n-1]!= -1){
        return a[n-1];
    }
    else{
        a[n-1] = fiba(n-1) + fiba(n-2) + fiba(n-3);
        return a[n-1];
    }
}

int main(){
    int n;
    cin >> n;
    long long ans = fiba(n);
    cout << ans;
}

