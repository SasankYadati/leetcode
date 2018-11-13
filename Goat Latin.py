class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        S_list = S.split(" ")
        n = len(S_list)
        
        vowels = {'a','e','i','o','u','A','E','I','O','U'}
        
        for i in range(n):
            if S_list[i][0] in vowels:
                S_list[i] = S_list[i] + 'ma'
            else:
                S_list[i] = S_list[i][1:] + S_list[i][0]+'ma'
            S_list[i] += ('a'*(i+1))
        
        S_res = " ".join(S_list)
        return S_res
