//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        queue<int> q;
        q.push(0);
        int l = 1;
        while(true){
            int n = q.size();
            unordered_set<int> pushed;
            for(int i = 0; i < n; i++){
                auto f = q.front();
                q.pop();
                int a = f + l, b = f + (-1)*l;
                if(a == d or b == d){
                    return l;
                }
                if(!pushed.count(a)){
                    q.push(a);
                    pushed.insert(a);
                }
                if(!pushed.count(b)){
                    q.push(b);   
                    pushed.insert(b);
                }
            }
            l++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends