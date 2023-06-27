/*
Print length of LCS using only two rows
Modify the bottom up dynamic programming algorithm for LCS to print the length of the LCS by maintaining only recenttwo rows of ‘b’ table
Input Format
First line contains the first string, S1
Next line contains the second string, S2
Output Format
Print the length of the longest LCS in the first line
*/

#include <iostream>
using namespace std;
int lcs(string x, string y) {
    int n = x.length();
    int m = y.length();
    int b1[2][m + 1];
    int bi = 0;
    for (int i = 0; i <= n; i++) {
        bi = i & 1;
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                b1[bi][j] = 0;
            else if (x[i - 1] == y[j - 1])
                b1[bi][j] = b1[1 - bi][j - 1] + 1;
            else
                b1[bi][j] = max(b1[1 - bi][j], b1[bi][j - 1]);
        }
    }

    return b1[bi][m];
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << lcs(x, y) << endl;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the length of the LCS and construct the recent two rows of 'b' table
int longestCommonSubsequence(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    vector<int> prevRow(n + 1, 0);
    vector<int> currRow(n + 1, 0);

    // Bottom-up computation of the recent two rows of 'b' table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                currRow[j] = prevRow[j - 1] + 1;
            } else {
                currRow[j] = max(currRow[j - 1], prevRow[j]);
            }
        }
        prevRow = currRow;
    }

    return currRow[n];
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    int length = longestCommonSubsequence(s1, s2);

    cout << "Length of LCS: " << length << endl;

    return 0;
}

*/
