/*
Maximum sub array with maximum length
Given an array of positive and negative numbers, develop a linear algorithm 
and write a C++ code to print the start index,end index and sum of subarray 
which is having maximum sum and maximum length. Consider an array with 13 
elements 4,-12, 3, 10, 4, 5, -100, 6, 7, 1, 3, 1, 4. There are two subarrays 
having sum as 22, that is starting at 2 and ending at 5 withelements 3, 10, 4, 
5 and another subarray that starts at 8 and end at 13 with elements 6, 7, 1, 3, 1, 4

Input Format
First line contains the number of elements in array, n
Next line contains the elements in the array separated by a space

Output Format
Print the start index, end index and sum of array having maximum sum and having maximum number of elements
*/

#include <iostream>
#include <vector>
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
    int s = 0, msum = INT_MIN, g_low = 0, low = 0, high = 0;
    for (int i = 0; i < n; i++){
        s += a[i];
        if (s > msum){
            msum = s;
            g_low = low;
            high = i;
        }
        if (s == msum){
            if (i - low > high - g_low){
                g_low = low;
                high = i;
            }
        }
        if (s < 0){
            s = 0;
            low = i+1;
        }
    }
    cout << g_low+1 << " " << high+1 << " " << msum << endl;
}
