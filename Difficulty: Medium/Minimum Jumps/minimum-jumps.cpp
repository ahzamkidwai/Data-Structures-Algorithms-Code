//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (arr[0] == 0)
            return -1;
        int jumps = 1;
        int currentMaxReach = arr[0];
        int nextMaxReach = arr[0];
        for (int i = 1; i < n; i++) {
            if (i > currentMaxReach) {
                jumps++;
                if (currentMaxReach == nextMaxReach)
                    return -1;
                currentMaxReach = nextMaxReach;
            }
            nextMaxReach = std::max(nextMaxReach, i + arr[i]);
        }
        return jumps;
    }    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends