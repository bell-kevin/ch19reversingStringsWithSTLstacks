// ch19reversingStringsSTLstacks.cpp
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

//STL stack container to hold a vector of strings
stack<vector<string>> stlStack;

//function to reverse a string
string reverseString(string str)
{
	//create a stack of characters
	stack<char> charStack;

	//push each character of the string onto the stack
	for (int i = 0; i < str.length(); i++)
		charStack.push(str[i]);

	//create a string to hold the reversed string
	string reversedString;

	//pop each character off the stack and append it to the reversed string
	while (!charStack.empty())
	{
		reversedString += charStack.top();
		charStack.pop();
	}

	//return the reversed string
	return reversedString;
}

//function to reverse a vector of strings
vector<string> reverseVector(vector<string> vec)
{
	//create a stack of strings
	stack<string> stringStack;

	//push each string of the vector onto the stack
	for (int i = 0; i < vec.size(); i++)
		stringStack.push(vec[i]);

	//create a vector to hold the reversed vector
	vector<string> reversedVector;

	//pop each string off the stack and append it to the reversed vector
	while (!stringStack.empty())
	{
		reversedVector.push_back(stringStack.top());
		stringStack.pop();
	}

	//return the reversed vector
	return reversedVector;
}

//function to reverse a vector of strings using an STL stack
vector<string> reverseVectorSTL(vector<string> vec)
{
	//push the vector onto the stack
	stlStack.push(vec);

	//create a vector to hold the reversed vector
	vector<string> reversedVector;

	//pop the vector off the stack and append it to the reversed vector
	while (!stlStack.empty())
	{
		reversedVector = stlStack.top();
		stlStack.pop();
	}

	//return the reversed vector
	return reversedVector;
}

int main()
{
	cout << "Ch 19 Reversing Strings by Kevin Bell\n\n";
	cout << "Pushing the phrase:\n";
	//create a vector of strings
	vector<string> vec = { "this", "question", "to", "us", "demands", "wisdom"};

	//count the number of strings in the vector
	int numStrings = vec.size();

	//print the vector
	cout << "\t";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	cout << "Filled the stack, size is " << numStrings << endl;
	cout << "Popping the stack" << endl;

	//reverse the vector
	vec = reverseVector(vec);

	//reverse the vector using an STL stack
	vec = reverseVectorSTL(vec);

	//print the reversed vector
	cout << "\t";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	cout << endl;
	system("pause");
	return 0;
} //end of main function