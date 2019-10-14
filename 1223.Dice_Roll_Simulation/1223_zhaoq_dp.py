from functools import lru_cache
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10 ** 9 + 7 
        @lru_cache(None)
        # 这道题关键是这个dp如何构造太难想了, 此处 dp 代表数字为index的点数 在前面已经出现了k个相同的index的基础上还需要n次的过程
        def dp(k,index,n):
            if n == 0:
                return 1
            ans = 0
            for i in range(6):
                if i != index:
                    ans += dp(1,i,n-1) 
                elif k < rollMax[i]:
                    ans += dp(k+1, i, n-1)
                # 此处如果k == rollMax[i]的话，值不能使用，就放弃了
            return ans % MOD
        
        return dp(0,0,n) % MOD