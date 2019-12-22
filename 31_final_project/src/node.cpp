#include "node.h"


bool EmptyNode::Evaluate(const Date& date, const string& str) const {;
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date){
}

bool DateComparisonNode::Evaluate(const Date& date, const string& str) const {
	if(cmp_ == Comparison::Less){ return date < date_;}
	if(cmp_ == Comparison::LessOrEqual){ return date <= date_;}
	if(cmp_ == Comparison::Greater){ return date > date_;}
	if(cmp_ == Comparison::GreaterOrEqual){ return date >= date_;}
	if(cmp_ == Comparison::Equal){ return date == date_;}
	if(cmp_ == Comparison::NotEqual){ return date != date_;}
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, string str) : cmp_(cmp), str_(str){
}

bool EventComparisonNode::Evaluate(const Date& date, const string& str) const {
	if(cmp_ == Comparison::Less){ return str < str_;}
	if(cmp_ == Comparison::LessOrEqual){ return str <= str_;}
	if(cmp_ == Comparison::Greater){ return str > str_;}
	if(cmp_ == Comparison::GreaterOrEqual){ return str >= str_;}
	if(cmp_ == Comparison::Equal){ return str==str_;}
	if(cmp_ == Comparison::NotEqual){ return str!=str_;}
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& operation, shared_ptr<Node> left, shared_ptr<Node> right)
: operation_(operation), left_(left), right_(right){
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& str) const {
	if(operation_ == LogicalOperation::And){
		return left_->Evaluate(date, str) && right_->Evaluate(date, str);
	}

	if(operation_ == LogicalOperation::Or){
		return left_->Evaluate(date, str) || right_->Evaluate(date, str);
	}
}

