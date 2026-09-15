class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        cnt5 = 0
        cnt10 = 0
        for i in bills:
            if i == 5:
                cnt5+=1
            elif i == 10:
                cnt10+=1
                cnt5-=1
                if cnt5<0:
                    return False
            else:
                if cnt10 > 0:
                    cnt10 -= 1
                    if cnt5 > 0:
                        cnt5 -= 1
                    else:
                        return False
                else:
                    if cnt5 >= 3:
                        cnt5-=3
                    else:
                        return False
                
        return True