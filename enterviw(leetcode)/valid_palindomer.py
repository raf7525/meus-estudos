class Solution(object):
    def isPalindrome(self, s):
        limpo = re.sub(r'[^a-z0-9\s]', '', s.lower())
        espaco = limpo.replace(' ', '')
        tamanho = len(espaco)
        check=True
        for i in range(tamanho // 2):
            if espaco[i] != espaco[tamanho - 1 - i]:
                check = False
                break  
        return check        
            
        