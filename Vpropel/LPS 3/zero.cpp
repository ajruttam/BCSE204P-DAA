/*
Zero sum subarray

Given an array of positive and negative integers, develop a linear algorithm 
and write a C++ code to check if there exist asubarray whose sum is zero is 
present in it. If such a subarray exist then print start and end index of first
occurrence. Otherwise print -1 for both start and end index. For example, if 
the array contains seven elements 10, -3, 2,4, -3, 5, 7 then print start index 
as 2 and end index as 5

Hint: Use maps for keeping track of sums

Note: If more than one zero sum subarray exist then print the one which has got maximum length

Input Format
First line contains the number of elements in the array, n
Next line contains the elements separated by a space

Output Format
Either print start index and end index of subarray whose sum becomes 0 or print -1 if no such subarray exist
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main(){
    int n, ele;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++){
        cin >> ele;
        a.push_back(ele);
    }
    unordered_map <int, vector<int>> sa; 
    int s = 0, d = 0, ll = 0, hl = 0;
    for (int i = 0; i < n; i++){
        s += a[i];
        if (s == 0){
            if (i+1 > d){
                d = i+1;
                ll = 0;
                hl = i;
            }
        }
        if (sa.find(s) != sa.end()){
            if (i - *sa[s].begin() > d){
                d = i - *sa[s].begin() + 1;
                ll = *sa[s].begin() + 1;
                hl = i;
            }
        }
        sa[s].push_back(i);
    }
    if (hl != 0) cout << ll+1 << " " << hl+1 << endl;
    else cout << -1 << endl;
}
