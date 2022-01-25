#include <iostream>
#include <string>
#include <vector>

using namespace std;


int factorial(int param)
{
    if (param == 1)
        return 1;
    else
        return param + factorial(param - 1);
}


vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tower;
    for (int i = 0; i < n+1; i++)
    {
        if (i == n)
        {
            vector<int> temp(i + 1, -1);
            tower.push_back(temp);
        }
        else {
            vector<int> temp(i + 1, 0);
            tower.push_back(temp);
        }
    }
    int mode = 0;
    int x = 0;
    int y = 0;
    int limit = factorial(n);
    for (int i = 1; i <= limit; i++)
    {
        if (mode == 0)
        {
            if (tower[x+1][y] != 0)
            {
                tower[x][y] = i;
                y += 1;
                mode = 1;
            }
            else {
                tower[x][y] = i;
                x += 1;
            }

        }
        else if (mode == 1)
        {
            if (tower[x].size()-1 == y)
            {
                tower[x][y] = i;
                x -= 1;
                y -= 1;
                mode = 2;
            }
            else
            {
                if (tower[x][y + 1] != 0)
                {
                    tower[x][y] = i;
                    x -= 1;
                    y -= 1;
                    mode = 2;
                }
                else
                {
                    tower[x][y] = i;
                    y += 1;
                }
            }
        }
        else if(mode == 2)
        {
            if (tower[x - 1][y - 1] != 0)
            {
                tower[x][y] = i;
                mode = 0;
                x += 1;
            }
            else
            {
                tower[x][y] = i;
                x -= 1;
                y -= 1;
            }
        }
    }

    for (int i = 0; i < tower.size()-1; i++)
    {
        for (int j = 0; j < tower[i].size(); j++)
        {
            answer.push_back(tower[i][j]);
        }
    }


    return answer;
}
int main()
{
    solution(3);
}