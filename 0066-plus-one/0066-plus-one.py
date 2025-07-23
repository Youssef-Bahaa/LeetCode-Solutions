class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n) :
            if(digits[n - i - 1] < 9):
                digits[n - i - 1] += 1
                return digits
            digits[n - i - 1] = 0
        
        digits.insert(0,1)
        return digits

            
        