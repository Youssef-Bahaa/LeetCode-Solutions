class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        ans = []
        for idx , val in enumerate(words):
            if x in val:
                ans.append(idx)
        return ans
        