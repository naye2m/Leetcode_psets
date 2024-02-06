# 44 : 49
class Solution(object):
    def countAnagrams(self, s):
        """
        :type s: str
        :rtype: int
        """

        res = 1 #for multiplications
        sa = s.split()
        for st in sa:
            res *= painw(st)
        return res % (10**9 + 7)

        
def painw(s):
        """
        :type s: str
        :rtype: int
        """
        test = {}
        for strah in s:
            if not test.get(strah):
                test[strah] = 1
            else:
                test[strah]+= 1
        if len(test.values()) == 1:
            return 1
        res = fr(len(s))
        for v in test.values():
            if v > 1:
                res /= fr(v)
        return res

def fr(n):#factorial_recursive
    if not n <= 1:
        return n * fr(n - 1)
    return 1
