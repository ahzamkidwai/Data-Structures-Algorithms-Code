//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    // int missingNumber(int arr[], int n) 
    // { 
    //     vector<int> pos;
    //     for(int i=0; i<n; i++){
    //         if(arr[i] > 0)
    //             pos.push_back(arr[i]);
    //     }
    //     if(pos.size() == 0)
    //         return 1;
    //     int minEle = INT_MAX;
    //     for(auto itr : pos){
    //         if(itr < minEle)
    //             minEle = itr;
    //     }
    //     if(minEle != 1)
    //         return 1;
    //     for(auto itr : pos){
    //         auto it = find(pos.begin(), pos.end(), minEle + 1);
    //         if(it == pos.end()){
    //             return minEle + 1;
    //         }
    //         else
    //             minEle = minEle + 1;
    //     }
        
    //     return 1;
    // } 
    int missingNumber(int arr[], int n) 
    { 
        // Step 1: Place each positive number x in its corresponding index x-1
        for(int i = 0; i < n; i++) {
            // Use a while loop to keep placing the element in the correct position
            while(arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                // Swap elements to place arr[i] at its correct position
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // Step 2: Find the first missing positive number
        for(int i = 0; i < n; i++) {
            // If arr[i] is not equal to i+1, then i+1 is the missing number
            if(arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions are correct, return n+1
        return n + 1;
    }
 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends