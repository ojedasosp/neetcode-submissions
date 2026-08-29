class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = {}
        for i, n in enumerate(nums):
            if(n in seen):
                return True
            seen[n] = i
        return False
        