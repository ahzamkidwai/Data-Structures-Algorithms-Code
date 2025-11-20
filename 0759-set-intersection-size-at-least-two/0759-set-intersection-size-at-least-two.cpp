class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<pair<int,int>> p;
        int n = intervals.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int first = intervals[i][0];
            int second = intervals[i][1];
            p.push_back({second, first});
        }
        sort(p.begin(), p.end());
        for(int i = 0; i < n; i++){
            int start = p[i].second;
            int end = p[i].first;
            int count = 0;
            for(auto itr : ans){
                if(itr >= start && itr <= end)  count++;
            }
            if(count == 1) {
                if(ans.back() != end) ans.push_back(end);
                else  ans.push_back(end - 1);
            }

            else if(count == 0){
                ans.push_back(end);
                ans.push_back(end-1);
            }
        }   
        return ans.size();
    }
};