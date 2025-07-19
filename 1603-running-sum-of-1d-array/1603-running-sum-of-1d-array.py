class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum = 0
        for idx , val in enumerate(nums):
            sum += val
            nums[idx] = sum
        return nums
        