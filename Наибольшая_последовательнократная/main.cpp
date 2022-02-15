#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
int get_length_of_longest_divisible_subsequence(const std::vector<int>& numbers)
{
    vector<int> D(numbers.size());
    for (int i = 0; i < D.size(); ++i)
    {
        D[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if ((numbers[i] % numbers[j] == 0) && (D[j] + 1 > D[i]))
            {
                D[i] = D[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < D.size(); ++i)
    {
        if (D[i] > ans)
            ans = D[i];
    }
    return ans;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto& number : numbers) {
        std::cin >> number;
    }

    std::cout << get_length_of_longest_divisible_subsequence(numbers) << std::endl;
}