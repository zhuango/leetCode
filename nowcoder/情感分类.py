import sys
import math

good = {"high", "great", "good", "easy", "worth", "cheap", "convenient" ,"fun", "cost-effective", "like", "ok", "fresh", "value"}
bad = {"expensive", "inconvenient", "never", "bad", "poor"}
notWord = {"nothing", "don't", "not", "too"}

words = sys.stdin.readline().strip().lower().split(" ")
goodC = 0
badC = 0
notW = False
for word in words:
    if word in good:
        goodC += 1
    if word in bad:
        badC += 1
    if word in notWord:
        notW = True

print(int(not notW and goodC > badC))
