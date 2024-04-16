#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> stack;
	string input = "rosor";
	bool isPalindrome = true;
	for (size_t i = input.length(); i > 0; i--)
	{
		stack.push(input[i - 1]);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] != stack.top()) {
			isPalindrome = false;
			break;
		}
		stack.pop();
	}
	if (isPalindrome) {

	}

	return 0;
}