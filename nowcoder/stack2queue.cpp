#include <stack>
#include <iostream>

using namespace std;

template<class Ta>
class QueueViaStack
{
public:
	int top()
	{
		if (sb.empty()) swapab();
		return sb.top();
	}
	void pop()
	{
		if (sb.empty()) swapab();
		sb.pop();
	}
	void push(int a)
	{
		sa.push(a);
	}

private:
	void swapab()
	{
		while (!sa.empty())
		{
			sb.push(sa.top());
			sa.pop();
		}
	}
	stack<Ta> sa;
	stack<Ta> sb;
};
int main(void)
{
	QueueViaStack<int> qs;
	qs.push(1);
	qs.push(2);
	cout << qs.top() << endl;
	qs.pop();
	qs.push(3);
	cout << qs.top() << endl;
	qs.pop();
	qs.push(4);

	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
}