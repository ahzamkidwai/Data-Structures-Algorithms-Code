//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        long long sum = 0, maxsum = INT_MIN;
        for (long long i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if (sum > maxsum)
                maxsum = sum;
            if(sum<0)
                sum = 0;
        }
        return maxsum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends