//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        bool ans = 0;
        int totalSum = 0;
        for(auto itr : arr){
            totalSum = totalSum + itr;
        }
        if(totalSum % 2)
            return false;
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<arr.size(); i++){
            sum1 = sum1 + arr[i];
            sum2 = totalSum - sum1;
            if(sum1 == sum2)
                return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends