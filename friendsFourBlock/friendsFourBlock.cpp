#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true)
    {
        vector<int> four;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                char now = board[i][j];
                bool square = true;
                if (now == ' ')
                    continue;
                if (board[i][j + 1] != now)
                    square = false;
                if (board[i + 1][j + 1] != now)
                    square = false;
                if (board[i + 1][j] != now)
                    square = false;

                if (square)
                {
                    four.push_back(i);
                    four.push_back(j);
                }
            }
        }

        if (four.size() == 0)
            break;

        for (int i = 0; i < four.size(); i += 2)
        {
            board[four[i]][four[i + 1]] = '@';
            board[four[i]][four[i + 1]+1] = '@';
            board[four[i]+1][four[i + 1]] = '@';
            board[four[i]+1][four[i + 1]+1] = '@';
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '@')
                {
                    for (int k = i; k >= 0; k--)
                    {
                        if (k == 0)
                        {
                            board[k][j] = ' ';
                            break;
                        }   
                        board[k][j] = board[k - 1][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == ' ')
                answer += 1;
        }
    }

    return answer;
}

int main()
{
    solution(3, 4, { "ARRG","TRRT","WRRW"});
}
