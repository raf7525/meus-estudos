class Solution(object):
    def lengthOfLongestSubstring(self, s):
        letras_unicas_string = ''.join(sorted(set(s), key=s.index))
        print(len(letras_unicas_string))
                