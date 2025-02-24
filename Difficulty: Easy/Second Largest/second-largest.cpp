//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int maxEle = INT_MIN;
        for(auto itr : arr){
            if(itr > maxEle) maxEle = itr;
        }
        int secondLargestEle = -1;
        for(auto itr : arr){
            if(itr != maxEle && itr > secondLargestEle)
                secondLargestEle = itr;
        }
        return secondLargestEle;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends