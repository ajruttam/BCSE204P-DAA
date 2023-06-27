/*
Top Down LCS
Develop a top down dynamic programming algorithm for Longest Common Subsequence problem and implement usingC++. Print the length of the LCS and the LCS as well.
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

int LCS(string s1,string s2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + LCS(s1, s2, m - 1, n - 1, dp);
    return dp[m][n] = max(LCS(s1, s2, m - 1, n, dp), LCS(s1, s2, m, n - 1, dp));
}

string constructLCS(string s1,string s2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return "";
    if (s1[m - 1] == s2[n - 1])
        return constructLCS(s1, s2, m - 1, n - 1, dp) + s1[m - 1];
    if (dp[m - 1][n] >= dp[m][n - 1])
        return constructLCS(s1, s2, m - 1, n, dp);
    else
        return constructLCS(s1, s2, m, n - 1, dp);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int length = LCS(s1, s2, m, n, dp);
    string lcs = constructLCS(s1, s2, m, n, dp);
    cout << length << endl;
    cout << lcs << endl;
    return 0;
}
