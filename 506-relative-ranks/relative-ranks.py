class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        ans = [""] * n
        score_idx = [(val, idx) for idx, val in enumerate(score)]
        score_idx.sort(reverse=True)

        for i, (_, idx) in enumerate(score_idx):
            if i == 0:
                ans[idx] = "Gold Medal"
            elif i == 1:
                ans[idx] = "Silver Medal"
            elif i == 2:
                ans[idx] = "Bronze Medal"
            else:
                ans[idx] = str(i + 1)

        return ans
