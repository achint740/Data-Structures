#include <bits/stdc++.h>
using namespace std;

//No need of cstring and stack as bits has been used
=======
// Complete the isBalanced function below.
string isBalanced(string s) {
  int l = s.length();

    stack<char>q;

    int  c = 0 , i=0;

    while(i<l)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            q.push(s[i]);

        else if(s[i]==')')
        {
            if(!q.empty())
            {
                if(q.top()=='(')
                 {
                q.pop();
                continue;
                  }
                else
                     {
                         c--;
                         break;
                     }
            }
            else
            {
                c--;
                break;
            }
        }
        else if(s[i]==']')
        {
            if(!q.empty())
             {
            if(q.top()=='[')
                {
                    q.pop();
                    continue;
                }
             else
                     {
                         c--;
                         break;
                     }
            }

            else
            {
                c--;
                break;
            }
        }
        else if(s[i]=='}')
        {
            if(!q.empty())
                {
                    if(q.top()=='{'){
                       q.pop();
                    continue;
                    }
                     else
                     {
                         c--;
                         break;
                     }
                }
            else
            {
                c--;
                break;
            }
        }
        
      i++;
        }
     if(q.empty()&&c==0)
            return "YES";
     else
          return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        cin>>s;

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
