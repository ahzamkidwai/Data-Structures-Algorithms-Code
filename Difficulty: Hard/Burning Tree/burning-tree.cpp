//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, bool> vis;
        unordered_map<Node*, Node*> makeParent;
        queue<Node*> q;
        makeParent[root] = NULL;
        q.push(root);
        Node* targetNode = NULL;
    
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
    
            if (temp->data == target)
                targetNode = temp;
    
            if (temp->left) {
                makeParent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                makeParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        q.push(targetNode);
        vis[targetNode] = true;
        int ans = 0;
    
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp->left && !vis[temp->left]) {
                    flag = true;
                    vis[temp->left] = true;
                    q.push(temp->left);
                }
                if (temp->right && !vis[temp->right]) {
                    flag = true;
                    vis[temp->right] = true;
                    q.push(temp->right);
                }
                if (makeParent[temp] && !vis[makeParent[temp]]) {
                    flag = true;
                    vis[makeParent[temp]] = true;
                    q.push(makeParent[temp]);
                }
            }
            if (flag)
                ans++;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends