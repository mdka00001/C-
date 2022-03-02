#include "simple_node.hpp"
#include <bits/stdc++.h>

using namespace std;

int main(int, char *[])
{
  // The following should compile
  SimpleNode head(13.3);

  SimpleNode new_head(head);

  SimpleNode newer_head(new_head);


  const auto newest_head = head;

  SimpleNode middle(2.3);

  SimpleNode tail(2.2);

  tail.is_tail();

  middle.insert(tail);

  newer_head.insert(middle);
  newer_head.length();

  newer_head.is_tail();

  newer_head.next().next().is_tail();

  newer_head();


  return 0;
}
