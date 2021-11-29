/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Isabelle Kenny
 */

#include "std_lib_facilities.h"
vector<string> numbers;
void initialize_numbers()
{
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
	numbers.push_back("ten");
}

int get_number(){
	const int nonsymbol = numbers.size();

	int val = nonsymbol;
	if (cin>>val) return val;

	cin.clear();
	string s;
	cin>>s;
	for (int i=0; i<numbers.size(); ++i)
		if (numbers[i]==s) val = i;
	if (val==nonsymbol) error("unexpected: ",s);
	return val;
}

int main()
	try{
		initialize_numbers();
		cout <<"Enter two integers seperated by an operator (+ - * / %): ";
		
		while (true) {
			int val1 = get_number();
			char op = 0;
			cin>>op;
			int val2 = get_number();
			string oper;
			double result;
			
			switch (op) {
			case '+':
				oper = "The sum of ";
				result = val1+val2; 
				break;
			case '-':
				oper = "The difference between ";
				result = val1-val2; 
				break;
			case '*':
				oper = "The product of ";
				result = val1*val2; 
				break;
			case '/':
				oper = "The ratio of ";
				if (val2==0) error("trying to divide by zero");
				result = val1/val2; 
				break;
			case '%':
				oper = "The remainder of ";
				if (val2==0) error("trying to divide by zero (%)");
				result = val1%val2; 
				break;
			default:
					error("bad operator");
			}
			cout << oper << val1 << " and " << val2 << " is " << result << '\n';
			cout << "Try again: ";
		}
	}
catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");
}

