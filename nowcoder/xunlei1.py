import sys

num = [int(elem) for elem in sys.stdin.readline().strip().split(",")]
sumforward = [0 for i in range(len(num) + 1)]
sumbackwad = [0 for i in range(len(num) + 1)]

ss = 0


for i in range(len(num)):
    sumforward[i + 1] = sumforward[i] + num[i]
i = len(num)
while(i > 0):
    sumbackwad[i-1] = sumbackwad[i] + num[i - 1]
    i -=1

hasresult = False
for i in range(len(num)):
    if(sumforward[i] == sumbackwad[i + 1]):
        print(num[i])
        hasresult = True
        break

if not hasresult:
    print("False")