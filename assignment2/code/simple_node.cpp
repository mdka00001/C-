#include "iostream"
#include "simple_node.hpp"

using namespace std;
SimpleNode *head= nullptr;

std::unique_ptr<SimpleNode> ahead=nullptr;
//constructor
SimpleNode::SimpleNode(double content) {


    this->content_ = content;
    this->successor_ = nullptr;



}
//copy constructor
SimpleNode::SimpleNode(const SimpleNode &other_node) {
    content_ = other_node.content_;
    if(other_node.successor_) successor_= make_unique<SimpleNode>(*other_node.successor_);

}

//copy assignment
SimpleNode& SimpleNode::operator=(const SimpleNode &other_node){
    content_ = other_node.content_;
    if(other_node.successor_) successor_= make_unique<SimpleNode>(*other_node.successor_);

}

//move constructor
SimpleNode::SimpleNode(SimpleNode &&other_node)  {
    content_ = move(other_node.content_);
    successor_ = move(other_node.successor_);
}

//move assignment
SimpleNode& SimpleNode::operator=(SimpleNode &&other_node){

    content_ = move(other_node.content_);
    successor_ = move(other_node.successor_);
}

void SimpleNode::insert(SimpleNode &successor_node) {
    SimpleNode *tmp = this;
    while (tmp->successor_.get() != nullptr) {
        tmp = tmp->successor_.get();
    }
    tmp->successor_=make_unique<SimpleNode>(successor_node);

 }

SimpleNode &SimpleNode::next() const {
    return *successor_.get();
}

bool SimpleNode::is_tail() const {

    return this->successor_ == nullptr;
}

std::size_t SimpleNode::length() const {
    SimpleNode *temp1 = const_cast<SimpleNode *>(this);
    unsigned long long listlen=0;
    if(this== nullptr){
        return listlen;
    }

    while(temp1!= nullptr){

        temp1=temp1->successor_.get();
        listlen++;
    }

    return listlen;
}

double &SimpleNode::operator()() {

    return this->content_;

}

double SimpleNode::operator()() const {
    return content_;
}





