class Solution:
    def calculate(self, t: str) -> int:
        m = {}
        left = []
        for ind,l in enumerate(t):
            if l=="(":
                left.append(ind)
            elif l==")":
                m[left.pop()] = ind
        
        def cal(s,start):
            k = 0
            s += "+"
            num = 0
            sign = 1
            res = 0
            while k<len(s):
                l = s[k]
                if l in "+-":
                    res += sign*num
                    num = 0
                    sign = [1,-1][l=="-"]
                elif l.isdigit():
                    num = 10*num + int(l)
                elif l=="(":
                    right = m[k+start]
                    res += sign*cal(t[k+start+1:right],k+start+1)
                    k = right - start
                    num = 0
                k += 1
            return res
        return cal(t,0)