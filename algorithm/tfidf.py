#!/usr/bin/python3

from collections import defaultdict
import math
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.datasets import fetch_20newsgroups


def tf(document, spliter = "  "):
    words = document.split(spliter)
    wordCount = defaultdict(lambda:0)
    l = len(words)
    for word in words:
        wordCount[word] += 1
    for word in wordCount:
        wordCount[word] = wordCount[word]
    return wordCount

def idf(documents, smooth_idf = True, spliter = "  "):
    idfs = defaultdict(lambda:int(smooth_idf))
    for doc in documents:
        words = doc.split(spliter)
        wordsSet = set()
        # words in this document
        for word in words:
            wordsSet.add(word)
        for word in wordsSet:
            idfs[word] += 1
    # number of documents
    n = len(documents) + int(smooth_idf)

    for word in idfs:
        idfs[word] = math.log(n / idfs[word]) + 1.0
    return idfs

def Norm(d):
    length = 0.0
    for word in d:
        length += d[word]**2
    length = math.sqrt(length)
    for word in d:
        d[word] /= length

def tfidf(tfs, idfs, norm=True):
    tfidfs = {}
    for word in tfs:
        tfidfs[word] = tfs[word]*idfs[word]
    if norm:
        Norm(tfidfs)
    return tfidfs

def test():
    documents = ["what  a  beautiful  day  fuck  fuck  fuck",
                 "a  very  hard-wording  student"]
    idfs = idf(documents)
    print(abs(idfs["what"] - math.log(3/2) - 1.0) < 0.0000001)
    print(abs(idfs["a"] - math.log(1) - 1.0) < 0.0000001)
    print(abs(idfs["fuck"] - math.log(3/2) - 1.0) < 0.0000001)

    tfd = tf(documents[0])
    print(tfd["what"] == 1)
    print(tfd["fuck"] == 3)
    

test()
print("==============================================")
if __name__ == "__main__":

    documents = ["what beautiful day fuck fuck fuck",
                 "very hard wording student",
                 "tfidf is very simple",
                 "just do it fuck"]

    idfs = idf(documents, spliter=" ")
    tfs = tf(documents[2], spliter=" ")
    tf_idf = tfidf(tfs, idfs)

    
    vec = TfidfVectorizer()
    trn_term_doc = vec.fit_transform(documents)

    for word in tfs:
        try:
            print("{}\t{}\t{}".format(word, tf_idf[word], vec.vocabulary_[word]))
        except:
            pass
    print(trn_term_doc[2])
    print(len(vec.vocabulary_))
    print(len(idfs))
    