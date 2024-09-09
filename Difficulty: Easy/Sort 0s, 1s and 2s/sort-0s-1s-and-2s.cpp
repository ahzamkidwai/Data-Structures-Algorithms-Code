//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& a) 
    {
        int n = a.size();
        int one = 0, two = 0, zero = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i]==1)
                one++;
            else if(a[i]==2)
                two++;
            else if(a[i]==0)
                zero++;
        }
        for(int i=0; i<zero; i++)
            a[i] = 0;
        int i = zero;
        for(int j=0; j<one; j++)
        {
            a[i] = 1;
            i++;
        }
        for(int j=0; j<two; j++)
        {
            a[i] = 2;
            i++;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends