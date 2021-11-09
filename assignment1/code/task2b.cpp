#include <iostream>
#include <vector>

unsigned int get_max(unsigned int a, unsigned int b) {
  unsigned int c = a > b ? a : b;
  return c;
}
//on execution the code terminates and returns a segmentation error//
//this was due to assignment of memory address to the function get_max//
int main() {
  std::vector<unsigned int> v(10000, 0);
  v[9999] = 1000u;

  auto max = 0u;
  for(auto e : v){
    max = get_max(max, e);
  }
  std::cout << "Maximum: " << max << std::endl;
  return 0;
}
