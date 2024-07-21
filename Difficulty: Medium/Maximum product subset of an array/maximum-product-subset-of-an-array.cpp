//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        long long int maxProd = 1;
        const long long int m = 1e9 + 7;
        int neg = 0, zero = 0, negative = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            else if (arr[i] < 0)
            {
                maxProd = (maxProd * arr[i]) % m;
                neg++;
                negative = max(negative, arr[i]);
            }
            else
            {
                maxProd = (maxProd * arr[i]) % m;
            }
        }
        if (zero == arr.size())
            return 0;
        if (neg == 1 && zero == arr.size() - 1)
            return 0;
        if (neg % 2 == 0)
            return maxProd % m;
        else if (neg % 2 == 1)
            return (maxProd / negative) % m;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends