/*
Cut into lengths 3 or 5
A variation of rod cutting problem is one in which length of the rod will be of length greater than or equal to 8 and you canmake cuts of rods of length 3 or 5 only. For each unit of wastage a penalty of Rs.1 should be given. Write an recursivealgorithm and implement it to find the maximum revenue that may be generated.
Input Format
First line contains the length of the rod,n
Next line contains the price of rod of length 3 and 5 separated by a space
Output Format
Prin the maximum revenue that may be generated
*/

#include <iostream>
using namespace std;
int maxc, minc, max_value, min_value;
int threeOrFive(int length){
    if (length < 3 && length < 5)
        return -length;
    if (length >= max_value)
        return maxc + threeOrFive(length - max_value);
    if (length >= min_value)
        return minc + threeOrFive(length - min_value);
}

int main(){
    int l, three, five;
    cin >> l >> three >> five;
    maxc = (three>five)? three:five;
    max_value = (maxc == three)? 3 : 5;
    minc = (three<five)? three:five;
    min_value = (minc == three)? 3 : 5;
    int ans = threeOrFive(l);
    cout << ans;
}
