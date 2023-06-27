/*
Print all LCSs
Rewrite the print LCS routine to print all the LCSs of two sequences
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
#include <algorithm>
#include <set>
using namespace std;
int LCS(const string& s1, const string& s2, int m, int n, vector<vector<int>>& dp){
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + LCS(s1, s2, m - 1, n - 1, dp);
    return dp[m][n] = max(LCS(s1, s2, m - 1, n, dp), LCS(s1, s2, m, n - 1, dp));
}

vector<string> constructLCS(const string& s1, const string& s2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) 
        return {""};

    if (s1[m - 1] == s2[n - 1]) {
        vector<string> lcs = constructLCS(s1, s2, m - 1, n - 1, dp);
        for (string& s : lcs)
            s += s1[m - 1];
        return lcs;
    }

    if (dp[m - 1][n] > dp[m][n - 1])
        return constructLCS(s1, s2, m - 1, n, dp);
    else if (dp[m][n - 1] > dp[m - 1][n])
        return constructLCS(s1, s2, m, n - 1, dp);
    else {
        vector<string> lcs1 = constructLCS(s1, s2, m - 1, n, dp);
        vector<string> lcs2 = constructLCS(s1, s2, m, n - 1, dp);
        lcs1.insert(lcs1.end(), lcs2.begin(), lcs2.end());
        return lcs1;
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int length = LCS(s1, s2, m, n, dp);
    vector<string> lcs = constructLCS(s1, s2, m, n, dp);
    set <string> lcsSet(lcs.begin(), lcs.end());
    for (string str : lcsSet)
        cout << str << endl;
    return 0;
}
