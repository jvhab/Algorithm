#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Item final {
    double weight;
    double value;
};

bool my_sort(std::pair<double, int>& a, std::pair<double, int>& b)
{
    return a.first > b.first;
}

double get_max_knapsack_value(double capacity, std::vector <Item> items) {
    double value = 0.0;
    std::vector<std::pair<double, int>> v1;
    for (int i = 0; i < items.size(); ++i)
    {
        v1.push_back(std::make_pair((items[i].value / items[i].weight), i));
    }
    std::sort(v1.begin(), v1.end(), my_sort);
    for (int i = 0; i < v1.size(); ++i)
    {
        if (items[v1[i].second].weight <= capacity)
        {
            capacity -= items[v1[i].second].weight;
            value += items[v1[i].second].value;
        }
        else if (items[v1[i].second].weight > capacity)
        {
            value += items[v1[i].second].value * (static_cast <double>(capacity) / items[v1[i].second].weight);
            break;
   
        }
    }
    return value;
}

int main(void) {
    int number_of_items;
    double knapsack_capacity;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
        std::cin >> items[i].value >> items[i].weight;
    }

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout << std::fixed << std::setprecision(3) << max_knapsack_value << std::endl;
    return 0;
}