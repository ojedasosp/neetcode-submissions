class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int start = 0;
        int have = 0;
        for(int i = 0; i < target.size(); i++){
            start = start + std::max(0, target[i] - have);
            have = target[i];
        }
        return start;
    }
};