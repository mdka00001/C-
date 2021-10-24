#include <iostream>

int add(int x, int y){
    return x + y;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        int sum = add(4,i);

        if (sum < 8) {
            std::cout << sum << std::endl;
        }
        if (sum == 8)
        {
            std::cout << "sum is 8" << std::endl;
        }
    }
    return 0;
}