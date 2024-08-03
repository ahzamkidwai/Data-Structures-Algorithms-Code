//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> vp;
        for(int i=0; i<n; i++){
            vp.push_back({end[i], start[i]}); 
        }
        sort(vp.begin(), vp.end());
        int ans = 0, temp = -1;
        for(auto itr : vp){
            if(temp < itr.second){
                ans++;
                temp = itr.first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends