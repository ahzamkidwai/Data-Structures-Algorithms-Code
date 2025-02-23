//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> v;
        reverse(arr.begin(), arr.end());
        v.push_back(-1);
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]<arr[i-1])
            {
                s.push(arr[i-1]);
                v.push_back(arr[i-1]);
            }
            else
            {
                while(!s.empty() && arr[i]>=s.top())
                {
                    s.pop();
                }
                if(s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends