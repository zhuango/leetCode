#!/usr/bin/python3

from collections import defaultdict
import math

def tf(document):
    wordCount = defaultdict(lambda:0)
    for word in document:
        wordCount[word] += 1
    l = len(document)
    for word in wordCount:
        wordCount[word] = wordCount[word] / l
    return wordCount

def idf(documents):
    idfs = defaultdict(lambda:0)
    for doc in documents:
        wordsSet = set()
        # words in this document
        for word in doc:
            wordsSet.add(word)
        for word in wordsSet:
            idfs[word] += 1
    # number of documents
    n = len(documents)
    for word in idfs:
        idfs[word] = math.log(n / idfs[word])
    return idfs

def test():
    documents = [["what", "a", "beautiful", "day", "fuck", "fuck", "fuck"],
                 ["a", "very", "hard-wording", "student"]]
    idfs = idf(documents)
    print(abs(idfs["what"] - math.log(2)) < 0.0000001)
    print(idfs["a"] == 0)
    print(abs(idfs["fuck"] - math.log(2)) < 0.0000001)

    tfd = tf(documents[0])
    print(abs( tfd["what"] - (1/len(documents[0])) ) < 0.0000001)
    print(abs( tfd["fuck"] - (3/len(documents[0])) ) < 0.0000001)
    

test()
if __name__ == "__main__":
    inputFile = "./train.txt"

    documents = []
    with open(inputFile, 'r') as f:
        for line in f:
            documents.append(line.strip().split("  "))

    idfs = idf(documents)
    tfs = tf(documents[1])
    for word in tfs:
        print("{}  {}".format(word, tfs[word]*idfs[word]))
