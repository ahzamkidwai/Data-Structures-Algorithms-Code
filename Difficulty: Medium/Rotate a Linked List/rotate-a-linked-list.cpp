//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    private:
    int length(struct Node* head)
    {
        int cnt = 0;
        while(head != NULL)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        int n = length(head);
        
        if(k > n)
            k = n;
        
        if(k%n ==0)
            return head;
            
        struct Node *temp1, *temp2, *prev;
        temp1 = head;
        int i = 0;
        
        while(i < k)
        {
            prev = head;
            head = head->next;
            i++;
        }
        
        prev->next = NULL;
        temp2 = head;
        
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        
        temp2->next = temp1;
        return head;
        return nullptr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends