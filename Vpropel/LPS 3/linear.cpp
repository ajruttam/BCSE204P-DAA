/*
Linear Solution for Maximum Sub array Problem
Develop an algorithm and implement it to solve maximum sum subarray problem 
in linear time to print the starting index,end index and sum of the subarray 
whose sum is maximum. Compare the performance of this algorithm with naive
algorithm and divide and conquer algorithm for size of inputs 100, 1000, 10000, 
50000, 100000, 500000, 1000000. For example, consider an array with 16 elements, 
13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7. 
Maximum subarray starts at index 8 and ends at index 11 (human indices) and sum is 43

Input Format
First line contains the number of elements, n
Next line contains 'n' elements separated by a space

Output Format
Print the start index, end index and sum of subarray that has got maximum sum
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
        if (s >= msum){
            msum = s;
            g_low = low;
            high = i;
        }
        if (s < 0){
            s = 0;
            low = i+1;
        }
    }
    cout << g_low+1 << " " << high+1 << " " << msum << endl;
}
