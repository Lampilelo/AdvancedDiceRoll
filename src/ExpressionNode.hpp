#ifndef EXPRESSION_NODE_H
#define EXPRESSION_NODE_H

class ExpressionNode
{
public:
	enum NodeType { OPERAND, OPERATOR };

private:
	const std::string _text;
	const NodeType _type;

public:
	ExpressionNode(std::string text, NodeType type) : _text(text), _type(type) {}
	~ExpressionNode();

	std::string getText() { return _text; }
	NodeType getType() { return _type; }
};

#endif // !EXPRESSION_NODE_H
