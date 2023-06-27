/*
Print Rod Lengths
Modify the bottom up dynamic programming code written to solve rod cutting problem to print the size of the pieces that we should cut the rod to get maximum revenue and the maximum revenue as well
Input Format
First line contains the length of the rod, n
Next line contains the length of each price from 1 to n separated by a space
Output Format
Print length of rods and maximum revenue separated by a space
*/

#include <iostream>
using namespace std;
#include<vector>
#include<limits.h>
vector<int>s;
int bottom_up_cut_rod(vector<int> &p, int length)
{    
    vector<int> r(100,0);
    int i,q,j;
    r[0] = 0;
    for (j=1;j<=length;j++)
    {
        q = INT_MIN;
        int idx = 0;
        for(i=1;i<=j;i++)
        {
            if (q < p[i-1]+r[j-i]){
                q = p[i-1]+r[j-i];
                idx = i;
            }
        }
        r[j] = q;
        s.push_back(idx);
    }
    return r[length];
}

int main(){
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    int len = n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    max_profit = bottom_up_cut_rod(p,n);
    while(len > 0){
        cout << s[len-1] << " ";
        len = len - s[len-1];
    }
    cout<<max_profit;
}
