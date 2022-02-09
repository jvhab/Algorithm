#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int>& numbers, int number) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left <= right)
    {
        int m = left + ((right - left) / 2);
        if (numbers[m] == number)
            return m + 1;
        else if (numbers[m] > number)
        {
            right = m - 1;
        }
        else if (numbers[m] < number)
        {
            left = m + 1;
        }
    }
    return -1;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto& number : numbers) {
        std::cin >> number;
    }
    assert(std::is_sorted(numbers.begin(), numbers.end()));

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number) << " ";
    }
    std::cout << std::endl;
}