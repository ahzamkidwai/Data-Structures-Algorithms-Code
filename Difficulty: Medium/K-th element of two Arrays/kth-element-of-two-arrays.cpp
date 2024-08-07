//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        int i = 0, j = 0;
        int n = arr1.size(), m = arr2.size();
        int ind = 0;
        while(i<n && j<m){
            if(arr1[i] > arr2[j]){
                j++;
                ind++;
                if(ind == k)
                    return arr2[j-1];
            }
            else if(arr1[i] <= arr2[j]){
                i++;
                ind++;
                if(ind == k)
                    return arr1[i-1];
            }
        }
        while(i < n){
            if(ind == k)
                return arr1[i-1];
            ind++;
            i++;
        }
        while(j < m){
            if(ind == k)
                return arr2[j-1];
            ind++;
            j++;
        }
        if(k == (n+m))
            return max(arr1[n-1], arr2[m-1]);
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends