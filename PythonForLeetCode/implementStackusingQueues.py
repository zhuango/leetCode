class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.stack.append(x)
        

    def pop(self):
        """
        :rtype: nothing
        """
        del self.stack[len(self.stack) - 1]
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[len(self.stack) - 1]
        

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.stack) == 0
        
pro = Stack()
pro.push(1)
pro.push(2)
pro.push(3)
pro.push(4)
pro.push(5)

print(pro.top())
pro.pop()

print(pro.top())
pro.pop()

print(pro.top())

pro.pop()
pro.pop()
print(pro.empty())
pro.pop()
print(pro.empty())