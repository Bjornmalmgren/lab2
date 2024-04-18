#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool IsPalindromStacksOnly(string input) {
	stack<char> stack;
	bool isPalindrome = true;

	//removed redundante
	//char space[2] = " ";

	//function below removes spaces in the "input"
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	for (size_t i = 0; i < input.length(); i++)
	{
		stack.push(input[i]);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		// removed this below, redundante
		//if (stack.top() == space[0]) {
		//	stack.pop();
		//}
		//if (input[i] == space[0])
		//{
		//	i++;
		//}
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

//
//bool IsAPalindromQueueAndStack(string input)
//{
//	queue<string> queue;
//	stack<string> stack;
//
//	bool isPalindrome = true;
//
//
//}

int main() {
	string input = " afaf";
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
