#ifndef SIMPLE_NODE_HPP
#define SIMPLE_NODE_HPP

#include <vector>
#include <memory>

class SimpleNode
{
public:
  class Invalid
  {
  };
  explicit SimpleNode(double content);

  SimpleNode(const SimpleNode &other_node);
  SimpleNode(SimpleNode &&other_node);

  SimpleNode &operator=(const SimpleNode &other_node);
  SimpleNode &operator=(SimpleNode &&other_node);

  void insert(SimpleNode& successor_node);
  SimpleNode &next() const;

  bool is_tail() const;
  std::size_t length() const;

  double &operator()();
  double operator()() const;


private:
    double content_;
    std::unique_ptr<SimpleNode> successor_;
};

#endif // SIMPLE_NODE_HPP
