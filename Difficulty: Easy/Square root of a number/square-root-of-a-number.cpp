//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        if (n < 2) return n;

        long long int f = 1;
        long long int l = n / 2;
        while (f <= l) {
            long long int mid = f + (l - f) / 2;
            long long int midSquare = mid * mid;
            
            if (midSquare == n) {
                return mid;
            } else if (midSquare > n) {
                l = mid - 1;
            } else {
                f = mid + 1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends