impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut i: i32 = 0;
        let mut j: i32 = 0;
        while i < nums.len() as i32 - 1 {
            j = i + 1;
            while j < nums.len() as i32 {
                if nums[i as usize] + nums[j as usize] == target {
                    return vec![i, j];
                }
                j += 1;
            }
            i += 1;
        }
        return vec![];
    }
}
