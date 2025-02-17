//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Step 1: Initialize a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Step 2: Traverse the array
        for(int x : arr){
            if(pq.size() < k) {
                // If heap size is less than k, push the current element
                pq.push(x);
            }
            else {
                // If heap size is k, compare the current element with the top of the heap
                if(pq.top() < x){
                    // If the current element is larger, replace the smallest element in the heap
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        
        // Step 3: Extract elements from the heap and store them in the result list
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        // Step 4: Reverse the result list to get elements in decreasing order
        reverse(ans.begin(), ans.end());
        
        // Step 5: Return the result
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends