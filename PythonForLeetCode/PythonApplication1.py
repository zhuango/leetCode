import sys
import os
import shutil
from distutils.command.clean import clean as Clean

descr = "sfasdfa"
print(descr)

with open('test.txt') as test:
    content = test.read()
print (content)

#################  String #######################
arrayTest = "liuzhuang"

print('"Isn\'t, " she said.')

print("""
asdfas
asdfasd
asdfa
    saf
    asdfas
    as
    """)

print (3 * "zhuanglui" + 'sdfa')
print ('asdf''asdf')

text = ('sveral strings withiin parenthess' 'to have them joined together.')
word = 'Python' 
print (word[0])# character in position 0
print (word[5])# character in position 5
print (word[-1])  # last character
print (word[-2])  # second-last character

print (word[0:2])#string in range [0, 2), characters from position 0 (included) to 2 (excluded)
print (word[:2])  # character from the beginning to position 2 (excluded)
print (word[4:])  # characters from position 4 (included) to the end
print (word[-2:]) # characters from the second-last (included) to the end

print (len(word)) # get length of word.

########################################################
################## Lists ###############################
squares = [1, 4, 9, 16, 25]
print (squares) # get string "[1, 4, 9, 16, 25]"

squares = squares + [23, 4, 123, 4, 5]
print (squares)

squares[3] = 10000
print (squares)

squares.append(123456)
squares.append(7 ** 3)
print(squares);

squares[2:4] = [1, 3]
print(squares)

print (len(squares));

a = ['a', 'b', 'c']
n = [1, 2, 3]
x = [a, n]
print (x)# [['a', 'b', 'c'], [1, 2, 3]]
############################################

########### while ###########################

a, b = 0, 1 # multiple assignment
while b < 10:
    print (b, end= ',')#The keyword argument end can be used to avoid the newline after the output, or end the output with a different string:
    a, b = b, a + b
    #the expressions on the right-hand side are all evaluated first before any of the assignments take place
    # temp = a
    # a = b
    # b = temp + b
################################################

################## if for##########################
x = int(input("Please enter an interger: "))
if x < 0:
    x = 0
    print ("Negative changed to zero")
elif x == 0:
    print('Zero')
elif x == 1:
    print('Single')
else:
    print ('More')

words = ['cat', 'window', 'defenestrate']
for w in words:
    print (w, len(w))

for w in words[:]:  # Loop over a slice copy of the entire list.
    if len(w) > 6:
        words.insert(0, w)
print (words)#['defenestrate', 'cat', 'window', 'defenestrate']

for i in range(5):#print 0 ~ 4
    print (i)

#   range(5, 10)
#   5 through 9

#   range(0, 10, 3)
#   0, 3, 6, 9

#   range(-10, -100, -30)
#  -10, -40, -70

list(range(5))#[0, 1, 2, 3, 4]


############# Ditionary ############
mapingtest = {"liuzhuang" : "good",
              "zhuanglui" : "bad",
              "kailizhang" : "beautiful"}
if mapingtest.get("kaizhang"):
    print ("get it")
else:
    mapingtest["kaizhang"] = "sdfsdfsdf"

str = "as asd fd wer q g"
mapingtest = {}
strSet = str.split(" ")

############# lambda expression #################

def make_incrementor(n):
    return lambda x: x + n
f = make_incrementor(42)
print(f(0))
print(f(1))

pairs = [(1, 'one'), (2,'two'), (3, 'three'), (4, 'four')]
pairs.sort(key = lambda pair: pair[1])#lambda arguments: expression
print(pairs)

pairs.sort(key = lambda pair: pair[0])
print(pairs)

print(pairs)