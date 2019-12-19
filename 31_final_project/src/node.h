#pragma once

#include <string>
#include <memory>
#include "date.h"

using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation{
	And,
	Or,
};

class Node{
public:
	virtual bool Evaluate(Date date, string str) const=0;

};
class EmptyNode : public Node{
public:
	bool Evaluate(Date date, string str) const override;
};
class DateComparisonNode : public Node{
public:
	DateComparisonNode(Comparison cmp, const Date& date);
	bool Evaluate(Date date, string str) const override;
private:
	Comparison cmp_;
	Date date_;
};

class EventComparisonNode : public Node{
public:
	EventComparisonNode(Comparison cmp, string str);
	bool Evaluate(Date date, string str) const override;
private:
	Comparison cmp_;
	string str_;
};
class LogicalOperationNode : public Node{
public:
	LogicalOperationNode(LogicalOperation operation, shared_ptr<Node> left, shared_ptr<Node> right);
	bool Evaluate(Date date, string str) const override;
private:
	LogicalOperation operation_;
	shared_ptr<Node> left_;
	shared_ptr<Node> right_;
};
