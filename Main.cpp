#include <iostream>
#include <stack>
using namespace std;

bool IsPalindromStacksOnly(string input) {
	stack<char> stack;
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
	return isPalindrome;
}

int main() {
	string input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	bool palindrome = false;
	palindrome = IsPalindromStacksOnly(input);

	if (palindrome) {
		cout << "is palindrome";
	}
	else
	{
		cout << "is not palindrome";
	}




	return 0;
}
