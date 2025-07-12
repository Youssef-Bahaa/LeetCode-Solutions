class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        ans = [idx for idx , val in enumerate(words) if x in val ]
        return ans
        