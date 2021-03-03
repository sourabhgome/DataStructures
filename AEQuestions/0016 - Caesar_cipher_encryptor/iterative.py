'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(n)
'''

def caesarCipherEncryptor(string, key):
    newLetters = []
    key = key%26
    for letter in string:
        newLetterCode = ord(letter) + key
        newLetters.append(chr(newLetterCode) if newLetterCode <= 122 else chr(96 + newLetterCode%122));
    return "".join(newLetters)

#Driver Code
print(caesarCipherEncryptor("xyz", 2))