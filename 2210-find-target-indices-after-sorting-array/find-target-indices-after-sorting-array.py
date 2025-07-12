class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        idx = []
        
        for indx , val in enumerate(nums):
            if val == target :
                idx.append(indx)

        return idx
        