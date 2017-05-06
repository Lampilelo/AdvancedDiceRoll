// MathematicalExpressionParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ExpressionNode.h"

using namespace std;


bool isOperand(char character)
{
	if (character <= 57  && character >= 48) return true; // is a number
	if (character <= 90  && character >= 65) return true; // is a capital letter
	if (character <= 122 && character >= 97) return true; // is a small letter
	return false; // everything else
}

bool isOperator(char character)
{
	if (character == 42 /* "*" */ ||
		character == 43 /* "+" */ ||
		character == 45 /* "-" */ ||
		character == 47 /* "/" */ ||
		character == 40 /* "(" */ ||
		character == 41 /* ")" */)
			return true;
	return false;
}

vector<ExpressionNode> split(string expression)
{
	vector<ExpressionNode> result;
	string item;
	queue<char> operandQueue;
	int expressionLength = expression.length();
	for (int i = 0; i < expressionLength; i++)
	{
		item = "";
		if (isOperand(expression[i])) operandQueue.push(expression[i]);
		if (isOperator(expression[i]) || i == expressionLength - 1)
		{
			while (!operandQueue.empty())
			{
				item += operandQueue.front();
				operandQueue.pop();
			}
			result.emplace_back(item, ExpressionNode::OPERAND);
			if (i != expressionLength - 1)
			{
				item = expression[i];
				result.emplace_back(item, ExpressionNode::OPERATOR);
			}
		}
	}
	return result;
}

vector<ExpressionNode> infixToPostfix(vector<ExpressionNode> infixExpressionAsList)
{
	const map<string, int> operatorPrecedence =
	{ { "*", 3 },
	{ "/", 3 },
	{ "+", 2 },
	{ "-", 2 },
	{ "(", 1 } };

	stack<ExpressionNode> operatorStack;
	vector<ExpressionNode> postfixList;

	for (std::vector<ExpressionNode>::iterator token = infixExpressionAsList.begin();
		token != infixExpressionAsList.end();
		++token)
	{
		if ((*token).getType() == ExpressionNode::OPERAND)
			postfixList.push_back(*token);
		//if not OPERAND than it must be an OPERATOR
		else if ((*token).getText() == "(") operatorStack.push(*token);
		else if ((*token).getText() == ")")
		{
			while (operatorStack.top().getText() != "(")
			{
				postfixList.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.pop(); // pop "(" also
		}
		else // that should happen only if ExpressionNode is of OPERATOR type and is "+", "-", "*" or "/"
		{
			while (!operatorStack.empty() &&
				operatorPrecedence.at(operatorStack.top().getText()) >= operatorPrecedence.at((*token).getText()))
			{
				postfixList.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(*token);
		}
	}
	while (!operatorStack.empty())
	{
		postfixList.push_back(operatorStack.top());
		operatorStack.pop();
	}
	return postfixList;
}

int main()
{
	string infixExp = "2+2*2/(5+3)*4"; //TODO: doesn't work with variables
	vector<ExpressionNode> infixList = split(infixExp);

	for (std::vector<ExpressionNode>::iterator it = infixList.begin(); it != infixList.end(); ++it)
	{
		cout << (*it).getText();
	}

	vector<ExpressionNode> postfixList = infixToPostfix(infixList);

	cout << endl << endl;
	for (std::vector<ExpressionNode>::iterator it = postfixList.begin(); it != postfixList.end(); ++it)
	{
		cout << (*it).getText() << " ";
	}

	string temp;
	std::cin >> temp;

	return 0;
}

