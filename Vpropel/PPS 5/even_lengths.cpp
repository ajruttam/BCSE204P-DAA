/*
Cut Rods of Even Length only
If a company decides to cut only rods of even size, given the length of the rod and price of each size, modify your dynamic programming code (both top-down and bottom-up) to find the maximum revenue that shall be generated. There is no penalty for wastage.
Input Format
First line contains the length of the rod, n
Next line contains the price of rods of each length from 1 to n separated by a space
Output Format
Maximum revenue that may be generated by cutting rod into rods of even length
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximum(int a, int b){
    if (a > b) return a;
    return b;
}

int memoized_cut_rod_aux(vector<int> &p, int length,vector<int> &r)
{
    int q;
    if(r[length]>=0)
        return(r[length]);
    if(length==0 || length==1)
        return 0;
    q = INT_MIN;
    for(int i=2;i<=length;i+=2){
        q = maximum(q,p[i-1]+(memoized_cut_rod_aux(p,length-i,r)));
    }
    r[length] = q;
    return q;
}

int memoized_cut_rod(vector<int> &p, int length)
{    
    vector<int> r(100,INT_MIN);
    return memoized_cut_rod_aux(p,length,r);    
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    int max_r = memoized_cut_rod(p,n);
    cout << max_r<<endl;
}
