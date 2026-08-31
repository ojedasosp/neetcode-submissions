class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nsize = nums.size();

        for(int l = 0; l < nsize; l++){
            for(int r = l+1; r < nsize; r++){
                if((nums[l] + nums[r]) == target){
                    return vector<int>{l, r};
                }
            }
        }
    }
};
