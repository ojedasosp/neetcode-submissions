class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++){
            seen[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto& p : seen){
            v.push_back({p.first, p.second});
        }
        sort(v.begin(), v.end(), [](auto& a, auto&b){
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
