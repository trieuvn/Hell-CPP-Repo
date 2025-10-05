#include <iostream>
#include <cstdlib>

int main() {
    int N;
    std::cin >> N;

    unsigned int* A = (unsigned int*) malloc(N * sizeof(int));

    unsigned long sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> *(A + i);
        sum += *(A + i);
    }

    free(A);

    std::cout << sum << std::endl;

    return 0;
}
