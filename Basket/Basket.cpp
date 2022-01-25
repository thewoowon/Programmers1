#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool inspector(stack<char> st)
{
    int size = st.size();
    int left1 = 0;
    int left2 = 0;
    int left3 = 0;
    int right1 = 0;
    int right2 = 0;
    int right3 = 0;
    stack<int> index1;
    stack<int> index2;
    stack<int> index3;

    for (int i = 0; i < size; i++)
    {

        char t = st.top();
        st.pop();

        if (t == '(')
        {
            left1 += 1;
            index1.push(i);
        }
        else if (t == ')')
        {
            right1 += 1;
            if (index1.size() != 0)
            {
                int temp = index1.top();
                index1.pop();
                    
                if ((i - temp - 1) % 2 == 1)
                    return false; 
            }      
        }
        else if (t == '[')
        {
            left2 += 1;
            index2.push(i);
        }
        else if (t == ']')
        {
            right2 += 1;
            if (index2.size() != 0)
            {
                int temp = index2.top();
                index2.pop();

                if ((i - temp - 1) % 2 == 1)
                    return false;
            }
        }
        else if (t == '{')
        {
            left3 += 1;
            index3.push(i);
        }
        else if (t == '}')
        {
            right3 += 1;
            if (index3.size() != 0)
            {
                int temp = index3.top();
                index3.pop();

                if ((i - temp - 1) % 2 == 1)
                    return false;
            }
        }
        if (left1 < right1)
            return false;
        if (left2 < right2)
            return false;
        if (left3 < right3)
            return false;
    }
    if (left1 != right1)
        return false;
    if (left2 != right2)
        return false;
    if (left3 != right3)
        return false;

    return true;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) // 0칸
    {
        stack<char> st;
        string temp = s;
        temp = temp.substr(i, temp.size()-i) + temp.substr(0, i);
        for (int j = temp.size()-1; j >= 0; j--)
        {
            st.push(temp[j]); // 스택으로 만들어서 밀어 올려줌
        }
        if (inspector(st))
            answer += 1;
    }

    return answer;
}

int main()
{
    solution("{{{{{}}}}}");
}
