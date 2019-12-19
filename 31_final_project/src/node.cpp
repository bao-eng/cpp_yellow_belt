#include "node.h"


bool EmptyNode::Evaluate(Date date, string str) const {
	cout << "EmptyNode::Evaluate" << endl;
	return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date) : cmp_(cmp), date_(date){
	//cout << "DateComparisonNode::DateComparisonNode" << endl;
}

bool DateComparisonNode::Evaluate(Date date, string str) const {
	//cout << date_ << endl;
	//cout << "DateComparisonNode::Evaluate" << endl;
	if(cmp_ == Comparison::Less){ return date < date_;}
	if(cmp_ == Comparison::LessOrEqual){ return date <= date_;}
	if(cmp_ == Comparison::Greater){ return date > date_;}
	if(cmp_ == Comparison::GreaterOrEqual){ return date >= date_;}
	if(cmp_ == Comparison::Equal){ return date == date_;}
	if(cmp_ == Comparison::NotEqual){ return date != date_;}
}

EventComparisonNode::EventComparisonNode(Comparison cmp, string str) : cmp_(cmp), str_(str){
	//cout << "EventComparisonNode::EventComparisonNode" << endl;
}

bool EventComparisonNode::Evaluate(Date date, string str) const {
	//cout << "EventComparisonNode::Evaluate" << endl;

	if(cmp_ == Comparison::Equal){ return str==str_;}
	if(cmp_ == Comparison::NotEqual){ return str!=str_;}
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation operation, shared_ptr<Node> left, shared_ptr<Node> right)
: operation_(operation), left_(left), right_(right){
	//cout << "LogicalOperationNode::LogicalOperationNode" << endl;
}

bool LogicalOperationNode::Evaluate(Date date, string str) const {
	//cout << "LogicalOperationNode::Evaluate" << endl;
	if(operation_ == LogicalOperation::And){
		return left_->Evaluate(date, str) && right_->Evaluate(date, str);
	}

	if(operation_ == LogicalOperation::Or){
		return left_->Evaluate(date, str) || right_->Evaluate(date, str);
	}
}

