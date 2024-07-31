//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string lcp(string s1, string s2)
    {
        string ans="";
        int min_length = 0;
        min_length = min(s1.size(), s2.size());
        for(int i=0; i<min_length; i++)
        {
            if(s1[i]!=s2[i])
                break;
            ans = ans + s1[i];
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string> arr) 
    {
        // your code here
        int n = arr.size();
        bool f=true;
        sort(arr.begin(), arr.end());
        string temp = arr[0];
        for(int i=1; i<n; i++)
        {
            temp = lcp(temp, arr[i]);
            if(temp=="")
            {
                f = false;
                break;
            }
        }
        if(f!=false)
            return temp;
        temp = "-1";
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends