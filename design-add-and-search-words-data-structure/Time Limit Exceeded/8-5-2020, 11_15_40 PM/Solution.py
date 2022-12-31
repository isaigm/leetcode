// https://leetcode.com/problems/design-add-and-search-words-data-structure

import re

class WordDictionary:
    def __init__(self):
        self.dictionary = []

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        self.dictionary.append(word)
    def search(self, word: str) -> bool:
        for word_ in self.dictionary:
            if word_ == word or re.match('^'+word+'$', word_) != None:
               return True
        return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)