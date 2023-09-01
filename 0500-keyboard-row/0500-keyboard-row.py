class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        result = []
        set1 = set("qwertyuiop")
        set2 = set("asdfghjkl")
        set3 = set("zxcvbnm")
        for word in words:
            w = set(word.lower())
            if w <= set1 or w <= set2 or w <= set3:
                result.append(word)
        return result