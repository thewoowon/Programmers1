#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int MaxFinder(vector<int> vec, int iter)
{
    int maxV = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (i != iter)
        {
            maxV = max(maxV, vec[i]);
        }
    }
    return maxV;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            land[i][j] += MaxFinder(land[i - 1], j);
        }
        if (i == land.size() - 1)
        {
            answer = *max_element(land[i].begin(), land[i].end());
        }
    }

    return answer;
}
int main()
{
    solution({ {1, 2, 3, 5},{5, 6, 7, 8}, { 4, 3, 2, 1 } });
}