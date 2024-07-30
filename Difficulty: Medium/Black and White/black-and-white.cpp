//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
const int mod = 1e9 + 7;
long long solve(long long n, long long m, long long i, long long j) {
    long long delRow[] = {+1, +1, -1, -1, +2, +2, -2, -2};
    long long delCol[] = {-2, +2, -2, +2, +1, -1, +1, -1};
    long long wrongSpaces = 0;
    for (long long k = 0; k < 8; k++) {
        long long newRow = i + delRow[k];
        long long newCol = j + delCol[k];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
            wrongSpaces++;
        }
    }
    long long totalPositions = (n * m) - 1;
    long long validPositions = totalPositions - wrongSpaces;
    return validPositions % mod;
}

long long numOfWays(int N, int M) {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = (ans + solve(N, M, i, j)) % mod;
        }
    }
    return ans % mod;
}