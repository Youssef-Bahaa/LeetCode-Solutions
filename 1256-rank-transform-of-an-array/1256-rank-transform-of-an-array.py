class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        temp = arr[:]
        temp = sorted(set(temp))
        rank_map = {val: idx + 1 for idx, val in enumerate(temp)}
        ans = [rank_map[val] for val in arr]
        return ans
