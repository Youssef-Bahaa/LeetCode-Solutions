class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        ans = [idx for idx,val in enumerate(nums) if val == target]
        return ans
        