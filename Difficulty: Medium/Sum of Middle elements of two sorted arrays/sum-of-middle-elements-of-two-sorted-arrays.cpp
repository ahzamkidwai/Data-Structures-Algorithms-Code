//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int i = 0, j = 0, cnt = 0;
        int mid1 = 0, mid2 = 0;
        while (cnt <= n) {
            int val;
            if (i < n && (j >= n || arr1[i] < arr2[j])) {
                val = arr1[i++];
            } else {
                val = arr2[j++];
            }
            if (cnt == n - 1) {
                mid1 = val;
            } else if (cnt == n) {
                mid2 = val;
            }
            cnt++;
        }
        return mid1 + mid2;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends