#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;

int manhattan_distance(vector<int> x, vector<int> y)
{
      // (x1, y1)
      // (x2, y2)
    if (x[0] <= y[0] && x[1] <= y[1])
    {
        //기준 위치의 1사분면
    }
    else if(x[0] <= y[0] && x[1] >= y[1])
    {
        //기준 위치의 4사분면
    }
    else if(x[0] >= y[0] && x[1] <= y[1])
    {
        //기준 위치의 2사분면
    }
    else if (x[0] >= y[0] && x[1] >= y[1])
    {
        //기준 위치의 3사분면
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pii> p;
    vector<int> plus;
    vector<int> minus;

    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({ x,y });
        plus.push_back(x + y);
        minus.push_back(x - y);
    }
    sort(all(plus));
    sort(all(minus));
    cout << max(plus.back() - plus[0], minus.back() - minus[0]);
}

