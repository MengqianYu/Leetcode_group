class Solution:
    def calculate(self, s: str) -> int:
        st = []
        sign = "+"
        num = 0
        s += "+"
        for l in s:
            if l in "+-*/":
                if sign in "+-":
                    sign = [-1,1][sign=="+"]
                    st.append(sign*num)
                    
                    sign = l
                else:
                    if sign=="*":
                        st.append(st.pop()*num)
                    else:
                        st.append(int(st.pop()/num))
                    sign = l
                num = 0
            elif l.isdigit():
                num = 10*num + int(l)
        # print(st)
        return sum(st)
