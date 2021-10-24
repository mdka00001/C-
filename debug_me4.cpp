#include <iostream>
#include <vector>

int main() {
    int v[10];

    for (int i = 0; i <= 10; ++i)
    {
        v[i] = i;
        std::cout << v[i] << std::endl;
    }
}