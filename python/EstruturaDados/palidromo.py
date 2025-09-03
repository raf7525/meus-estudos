class Solution(object):
    def isPalindrome(self, x):
        x_str = str(x)
        invertida = x_str[::-1]
        if x_str == invertida:
            print("true")
        else:
            print("false")