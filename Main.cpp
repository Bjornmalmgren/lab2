#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> stack;
	string input = "du har bra hud";
	bool isPalindrome = true;
	char space[2] = " ";
	for (size_t i = 0; i < input.length(); i++)
	{
		stack.push(input[i]);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		
		if (stack.top() == space[0]) {
			stack.pop();
		}
		if (input[i] == space[0])
		{
			i++;
		}
		if (input[i] != stack.top()) {
			isPalindrome = false;
			break;
		}
		else
		{
			stack.pop();
		}
		
	}
	if (isPalindrome) {
		cout << "is palindrome";
	}
	else
	{
		cout << "is not palindrome";
	}

	return 0;
}