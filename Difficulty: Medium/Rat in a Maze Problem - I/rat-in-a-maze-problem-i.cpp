//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void danish(int i,int j,vector<vector<int>>&mat,string &tmp,vector<string>&ans){
      int n=mat.size();
      if(i<0||j<0||i>=n||j>=n||mat[i][j]==0)
      return ;
      if(i==n-1 && j==n-1){
         ans.push_back(tmp);
         return ;
      }
      mat[i][j]=0;
      
      tmp.push_back('L');
      danish(i,j-1,mat,tmp,ans); //Saare Left side ke possibilities dekho
      tmp.pop_back();
      
      tmp.push_back('R');
      danish(i,j+1,mat,tmp,ans); //Saare Right side ke possibilities dekho
      tmp.pop_back();
      
      tmp.push_back('U');
      danish(i-1,j,mat,tmp,ans); //Saare Up side ke possibilities dekho
      tmp.pop_back();
      
      tmp.push_back('D');
      danish(i+1,j,mat,tmp,ans); //Saare Down side ke possibilities dekho
      tmp.pop_back();
      
      mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>>&mat) {
        vector<string>ans;
        string tmp="";
        danish(0,0,mat,tmp,ans);
        if(ans.size()==0)
        ans.push_back("-1");
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends