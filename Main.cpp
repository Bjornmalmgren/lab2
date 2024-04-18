#include <iostream>
#include <stack>
#include <queue>
#include <windows.h>

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


string IsAPalindromQueueAndStack(string input)
{

	//string input = "11115151111"; // ÅÄÖ is not working with char

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
	}
	return "is a palindrome";
	//tesiting - for debugging reasons
	//while (!stack.empty())
	//{
	//	std::cout << stack.top();
	//	stack.pop();
	//}
	//std::cout << std::endl;



	//while (!queue.empty())
	//{
	//	std::cout << queue.front();
	//	queue.pop();
	//}
	//std::cout << std::endl;

}

int main() {
	string input = "An  jiolitf nA";
	bool palindrome = false;
	
	Sleep(1000);

	for(int i = 0; i < 1000000; i++)
	palindrome = IsPalindromStacksOnly(input);

	Sleep(1000);

	if (palindrome) {
		cout << "is a palindrome";
	}
	else
	{
		cout << "is not a palindrome";
	}
	cout << endl;

	Sleep(1000);

	for (int i = 0; i < 1000000; i++)
	IsAPalindromQueueAndStack(input);

	Sleep(1000);

	return 0;
}
