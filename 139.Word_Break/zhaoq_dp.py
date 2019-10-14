from functools import lru_cache
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # 以前面匹配word，后面的部分做dp，十分巧妙
        @lru_cache(None)
        def isWord(front,end):
            if s[front:end] in wordDict:
                return True
            
            for i in range(front,end):
                if s[front:i+1] in wordDict and isWord(i+1,end):
                    return True
            
            return False
        
        return isWord(0,len(s))