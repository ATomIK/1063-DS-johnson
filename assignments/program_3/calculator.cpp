/**
* @ProgramName: Calculator
* @Author: Thomas Johnson
* @Description:
*     This program uses a stack and a queue to
*	  simulate a calculator
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2017
*/
#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include<math.h>

using namespace std;

/**
* @ClassName: Calculator
* @Description:
*     Organizes operations for the calculator program
* @Params:
*    string in - infix string to convert
*/
class Calculator {
private:

	// infix
	string infix;
	int size;

	// queue
	char *Q;
	int front, rear, num;

	// stack
	char *S;
	int top;

	// result
	double *R;
	int rop;

public:
	Calculator(string in) {
		// infix
		infix = in+")";
		size = infix.length();

		// queue
		Q = new char[size];
		front, rear, num = 0;

		// stack
		S = new char[size];
		top = -1;

		// result
		R = new double[size];
		rop = -1;
	}

	/**
	* @FunctionName: is_operator
	* @Description:
	*    Checks if character is an arithmetic operator
	* @Params:
	*    char c - character to check
	* @Returns:
	*    bool
	*/
	bool is_operator(char c) {
		return c == '+' || c == '-' || c == '*'
			|| c == '/' || c == '^' || c == '%';
	}

	/**
	* @FunctionName: higher
	* @Description:
	*    Checks if first operator character has higher
	*	 precedence than the second operator character
	* @Params:
	*    char f - first operator
	*    char s - second operator
	* @Returns:
	*    bool
	*/
	bool higher(char f, char s) {
		if (is_operator(f) && is_operator(s)) {
			for (int i = 0; i < 2; i++) {
				char ch = (!i ? f : s);
				int val;
				switch (ch) {
				case '+':
				case '-':
					val = 1;
					break;
				case '*':
				case '/':
				case '%':
					val = 2;
					break;
				case '^':
					val = 3;
					break;
				case '(':
					val = 4;
					break;
				default:
					val = -1;
				}
				(!i ? f : s) = val;
			}
			return f >= s;
		} else
			return false;
	}
	
	/**
	* @FunctionName: to_postfix
	* @Description:
	*    Converts the infix string to the postfix expression
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void to_postfix() {
		S[++top] = '(';
		int pcount = 0;
		while (!empty()) {
			for (int i = 0; i < size; i++) {
				// if digit
				if (isdigit(infix[i])) {
					Q[rear] = infix[i];
					rear = (rear + 1) % size;
					num++;
				}
				// if left parenthesis
				if (infix[i] == '(') {
					S[++top] = infix[i];
					pcount++;
				}
				// if operator
				if (is_operator(infix[i])) {
					while(higher(S[top], infix[i]) && S[top]!='(') {
						Q[rear] = S[top--];
						rear = (rear + 1) % size;
						num++;
					}
					S[++top] = infix[i];
				}
				// if right parenthesis
				if (infix[i] == ')') {
					pcount++;
					while (S[top] != '(') {
						Q[rear] = S[top--];
						rear = (rear + 1) % size;
						num++;
					}
					S[top--];
				}
			}
		}
	}

	/**
	* @FunctionName: calculate
	* @Description:
	*    Calculates a postfix segment
	* @Params:
	*    double x - double integer
	*    char op - operator
	*	 double y - double integer
	* @Returns:
	*    double
	*/
	double calculate(double x, char op, double y) {
		double result;
		switch (op) {
		case '+':
			result = y + x;
			break;
		case '-':
			result = y - x;
			break;
		case '*':
			result = y * x;
			break;
		case '/':
			result = y / x;
			break;
		case '^':
			result = pow(y, x);
			break;
		case '%':
			result = fmod(y, x);
			break;
		default:
			return false;
		}
		return result;
	}

	/**
	* @FunctionName: answer
	* @Description:
	*    Prints out answer for a postfix expression
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void answer() {
		double res;
		while (num != 0) {
			char pop = Q[front];
			front = (front + 1) % size;
			num--;
			if (isdigit(pop)) {
				double newpop = pop - '0';
				R[++rop] = newpop;
			}
			if (is_operator(pop)) {
				double x = R[rop--], y = R[rop--];
				res = calculate(x, pop, y);
				R[++rop] = res;
			}
		}
		cout << " = " << res << endl;
	}

	/**
	* @FunctionName: calc
	* @Description:
	*    Redundant function for organization. Displays
	*	 conversion to postfix expression first, then
	*	 the calculated answer
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void calc() {
		to_postfix();

		answer();
	}

	/**
	* @FunctionName: empty
	* @Description:
	*    Checks if main stack is empty
	* @Params:
	*    none
	* @Returns:
	*    bool
	*/
	bool empty() {
		return top == -1;
	}

	/**
	* @FunctionName: full
	* @Description:
	*    Checks if main stack is full
	* @Params:
	*    none
	* @Returns:
	*    bool
	*/
	bool full() {
		return top == size - 1;
	}

};

int main() {

	// open exp.txt
	ifstream exp;
	exp.open("exp.txt");

	// set local num to number of infix expressions
	// to compute
	int num;
	exp >> num;

	// loop through infix expressions
	for (int i = 0; i < num; i++) {
		// temp string for a single expression
		string temp;
		exp >> temp;

		// print original
		cout << temp;

		// initiate class
		Calculator calc(temp);
		// calculate answer and print to the string
		calc.calc();
	}

	// close file
	exp.close();

	return 0;
}