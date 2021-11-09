#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.reserve(50);

  for (auto i = 0; i < 50; ++i) {
    v.push_back(i);
  }

    //after execution the programme enters and infinity loop and returns a 0 while crashing. The error reported//
    //was exit code 139; segmentation error//
    int i;
    for ( i = v.size() - 1; i >= 0; --i) {
    std::cout << i << ": " << v[i] << std::endl;
  }
  return 0;
}
