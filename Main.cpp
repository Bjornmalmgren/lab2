#include <iostream>
#include <stack>
#include <queue>
#include <windows.h>
#include <chrono>
#include <string>

using namespace std;

bool IsPalindromStacksOnly(string input) {
	stack<char> stack;
	bool isPalindrome = true;
	//function below removes spaces in the "input"
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	for (size_t i = 0; i < input.length(); i++)
	{
		stack.push(input[i]);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
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



string IsAPalindromQueueAndStack(string input)
{
	queue<char> queue;
	stack<char> stack;
	//function below removes spaces in the "input"
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

	for (size_t i = 0; i < input.length() / 2; i++)
	{
		stack.push(input[i]);
	}
	if (input.length() % 2 == 1) // removes the middle char
	{
		for (size_t i = (1 + input.length() / 2); i < input.length(); i++) // skips the middle char
		{
			queue.push(input[i]);
		}
	}
	else
	{
		for (size_t i = (input.length() / 2); i <= input.length() - 1; i++) // other half of input string
		{
			queue.push(input[i]);
		}
	}
	for (size_t i = 0; i < stack.size(); i++)
	{
		if (queue.front() != stack.top())
		{
			return "is not a palindrome";
		}
		queue.pop();
		stack.pop();
	}
	return "is a palindrome";
}

int main() {
	int amountOfCharMultiplier = 1;
	for (int amountOfCharMultiplier = 1; amountOfCharMultiplier < 6; amountOfCharMultiplier++)
	{
		string input = "";
		for (int j = 0; j < 1000000 * amountOfCharMultiplier; j++)
		{
			input += "af";
		}
		bool palindrome = false;
		cout << "Amout of characters that are in the palindrom: " << input.length();
		auto start1 = chrono::steady_clock::now();
		palindrome = IsPalindromStacksOnly(input);
		auto end1 = chrono::steady_clock::now();
		cout << "Stack time: \n"
			<< chrono::duration_cast<chrono::milliseconds>(end1 - start1).count()
			<< "ms" << endl;
		if (palindrome) {
			cout << "is a palindrome";
		}
		else
		{
			cout << "is not a palindrome";
		}
		cout << endl;
		auto start = chrono::steady_clock::now();
		IsAPalindromQueueAndStack(input);
		auto end = chrono::steady_clock::now();
		IsAPalindromQueueAndStack(input);
		cout << "Queue/stack time: \n"
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< "ms" << endl;
	}
	return 0;
}

// Conclusion, seems like the stack is faster with few number of digits when compareing palindromes but worse with larger numbers
