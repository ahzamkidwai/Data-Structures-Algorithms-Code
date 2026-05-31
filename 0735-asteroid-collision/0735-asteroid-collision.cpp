class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for (int itr : ast) {
            bool alive = true;
            while (alive && !st.empty() && st.top() > 0 && itr < 0) {
                if (st.top() < -itr) st.pop();            
                else if (st.top() == -itr) {
                    st.pop();
                    alive = false;
                }
                else alive = false;
            }
            if (alive) st.push(itr);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};