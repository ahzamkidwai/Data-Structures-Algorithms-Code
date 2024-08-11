//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
class Solution 
{
    public:
    static bool cmp(pair<int,int> a , pair<int, int> b){
        return a.first > b.first;
    }
    vector<int> JobScheduling(Job arrstruct[], int n) 
    { 
        vector<pair<int,int>> arr;
        for(int i = 0 ; i < n ;i++){
            pair<int,int> p = make_pair(arrstruct[i].profit , arrstruct[i].dead);
            arr.push_back(p);
        }
        sort(arr.begin() , arr.end() , cmp);
        vector<bool> occp(n+1 , true);
        occp[0] = false;
        int sum = 0 , count = 0 ; 
        int limit = 0;
        for(int i = 0 ; i < n ; i++){
            bool block = true;
            for(int j = arr[i].second ; j > 0  && block; j--){
                if(j < limit){
                    block = false;
                }
                else if(occp[j]){
                    occp[j] = false;
                    count++;
                    sum += arr[i].first;
                   block = false;
                }
                if(j == 1 && block == true){
                    limit = max(arr[i].second ,limit);
                }
            }
            
        }
        return {count , sum };
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends