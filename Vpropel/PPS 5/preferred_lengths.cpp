/*
Cut Rods of Preferred Lengths
A rod cutting company streling corporation will cut rods of specific lengths only. Given a list of lengths by which thiscompany will make rods, a rod of length ‘n’ and list of prices of each piece of rod that shall be cut by the company, write analgorithm and implement it using top down dynamic programming to find maximum revenue that shall be generated. Inthat case, give a penalty of Rs 1 for each meter of the residue.
Input Format
First line contains the length of the rod, n
Next line contains price of various lengths of rods from 1 to n
Next line cotains the number of preferred lengths
Next line contains the preferred lengths separated by a space
Output Format
Print the maximum revenue that may be generated
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximum(int a, int b)
{    
    if(a>b)
        return a;
    return b;
}

int memoized_cut_rod_aux(vector<int> &p, vector<int> &pref, int length,vector<int> &r)
{
    int q;
    if(r[length]>=0)
        return(r[length]);
    if(length==0)
        return 0;
    int f = 0;
    for (int i = 0; i < pref.size(); i++){
        if (length < pref[i])
            f++;
    }
    if (f == pref.size()){
        return -length;
        
    }
    q = INT_MIN;
    for (int k = 0; k < pref.size(); k++){
        if (length >= pref[k]){
            q = maximum(q,p[pref[k]-1]+memoized_cut_rod_aux(p,pref,length-pref[k],r));
        }
    }
    r[length] = q;
    return q;
}

int memoized_cut_rod(vector<int> &p, vector<int> &pref,int length)
{    
    vector<int> r(100,-1);
    return memoized_cut_rod_aux(p,pref,length,r);    
}

int main(){
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    vector<int> pref_p;
    int pref; cin >> pref;
    for(i=0;i<pref;i++)
    {
        cin>>price;
        pref_p.push_back(price);
    }
    max_profit = memoized_cut_rod(p,pref_p,n);
    cout<<max_profit;
}
