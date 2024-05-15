//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
private:
public:
    vector <int> parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionSize(int u,int v){
        int up = findUPar(u);
        int vp = findUPar(v);
        if(up == vp) return;
        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map <string,int> m;
        for(int i = 0;i < n;i++){
            for(int j = 1;j < details[i].size();j++){
                if(m.count(details[i][j])){
                    ds.unionSize(m[details[i][j]],i);
                }
                else m[details[i][j]] = i;
            }
        }
        vector <vector<string>> v(n);
        for(auto it:m)
            v[ds.findUPar(it.second)].push_back(it.first);
        vector <vector<string>> ans;
        for(int i = 0;i < n;i++){
            if(v[i].size() == 0) continue;
            vector <string> curr;
            curr.push_back(details[i][0]);
            sort(v[i].begin(),v[i].end());
            for(auto it:v[i]) curr.push_back(it);
            ans.push_back(curr);
        }
        reverse(ans.begin(),ans.end());
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
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends