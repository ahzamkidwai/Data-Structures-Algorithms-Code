//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{   
public:
    int isPossible(string s){
        if(s.size() < 4)
            return false;
        unordered_map<char, int> m;
        int n = s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        if(m.size()==2 && s.size()<6)
            return 0;
        if(m.size()==3 && s.size()<5)
            return 0;
        return 1;
    }
};
    

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isPossible(s)<<"\n";
    }
    return 0; 
}
// } Driver Code Ends