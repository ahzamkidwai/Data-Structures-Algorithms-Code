//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        int n = str.size();
        if(str[0] == '.' || str[n-1] == '.'){
            // cout << "Two same dots\n";
            return false;
        }
        for(int i=0; i<n-1; i++){
            if(str[i] == '.' && str[i+1] == '.'){
                // cout << "Two same dots\n";
                return false;
            }
        }
        int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
        vector<int> dots;
        for(int i=0; i<n; i++){
            if(str[i] == '.')
                dots.push_back(i);
        }
        if(dots.size() != 3)
            return false;
        int ind1 = dots[0];
        string str1 = str.substr(0, dots[0]);
        string str2 = str.substr(dots[0]+1, dots[1]-dots[0]-1);
        string str3 = str.substr(dots[1]+1, dots[2]-dots[1]-1);
        string str4 = str.substr(dots[2]+1);
        if(str1.size() == 0 || str2.size() == 0 || str3.size() == 0 || str4.size() == 0)
            return false;
        num1 = stoi(str1);
        num2 = stoi(str2);
        num3 = stoi(str3);
        num4 = stoi(str4);
        // cout << "Num1 : "<< num1 << endl;
        // cout << "Num2 : "<< num2 << endl;
        // cout << "Num3 : "<< num3 << endl;
        // cout << "Num4 : "<< num4 << endl;
        if (num1 < 0 || num1 > 255 || num2 < 0 || num2 > 255 || num3 < 0 || num3 > 255 || num4 < 0 || num4 > 255) {
            // cout << "Invalid input: number out of range.\n";
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends