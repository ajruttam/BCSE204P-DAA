/*
LCS using only one table
Modify the bottom up dynamic programming algorithm for LCS to maintain only length table (c table) and print the LCS byexamining the neighboring entries of the cell and print 'No common subsequence' if no such sequence exist.
Input Format
First line contains the first string, S1
Next line contains the second string, S2
Output Format
Print the length of the longest LCS in the first line
Print the Longest LCS that we get by traversing from the last cell (m,n) of the b table where m is the length of the first stringand n is the length of the second string
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int longestCommonSubsequence(const string& s1, const string& s2, vector<vector<int>>& c) {
    int m = s1.length();
    int n = s2.length();
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }
    return c[m][n];
}
void printLCS(const string& s1, const string& s2, const vector<vector<int>>& c) {
    int m = s1.length();
    int n = s2.length();
    int i = m, j = n;
    string lcs;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } 
        else if (c[i - 1][j] >= c[i][j - 1])
            i--;
        else
            j--;
    }
    if (lcs.empty())
        cout << "No common subsequence" << endl;
    else 
        cout << lcs << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    int length = longestCommonSubsequence(s1, s2, c);
    cout << length << endl;
    printLCS(s1, s2, c);
    return 0;
}
