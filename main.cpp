#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;
bool my_sort(std::pair<int, int>& a, std::pair<int, int>& b)
{
    return a.second < b.second;
}

std::vector <int> get_covering_set(std::vector <Segment> segments) {
    std::vector <int> result;
    std::sort(segments.begin(), segments.end(), my_sort);
    int f_t = segments[0].second;
    result.push_back(f_t);
    for (auto k : segments)
    {
        if (f_t < k.first)
        {
            f_t = k.second;
            result.push_back(f_t);
        }
    }
    return result;
}

int main(void) {
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (auto& s : segments) {
        std::cin >> s.first >> s.second;
    }

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point : points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;
}