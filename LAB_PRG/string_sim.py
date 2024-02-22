from difflib import SequenceMatcher 
str1 = input("Enter String 1 : ") 
str2 = input("Enter String 2 : ") 
sim = SequenceMatcher(None, str1, str2).ratio() 
print("Similarity between strings \"" + str1 + "\" and \"" + str2 + "\" is : ",sim)