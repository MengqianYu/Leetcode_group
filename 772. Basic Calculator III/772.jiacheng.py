class Solution:
    def calculate(self, s: str) -> int:
        m,left = {},[]
        for ind,i in enumerate(s):
            if i == "(":
                left.append(ind)
            elif i==")":
                m[left.pop()] = ind
                
        def cal(local,start):
            k,num,sign,st = 0,0,"+",[]
            local += "+"
            while k<len(local):
                l = local[k]
                if l in "+-*/":
                    if sign=="+":
                        st.append(num)
                    elif sign =="-":
                        st.append(-num)
                    elif sign == "*":
                        st.append(st.pop()*num)
                    else:
                        st.append(int(st.pop()/num))
                    num = 0
                    sign = l
                elif l.isdigit():
                    num = 10*num + int(l)
                elif l == "(":
                    right = m[k+start]
                    num = cal(s[k+start+1:right],k+start+1)
                    k = right - start
                k += 1
            return sum(st)
        return cal(s,0)