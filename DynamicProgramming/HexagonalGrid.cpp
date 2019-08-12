#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the hexagonalGrid function below.
 */
string hexagonalGrid(string a, string b) {
    int i,count = 0;
    int lena = a.length();
    int lenb = b.length();
    for(i=0;i<lena;i++)
     {
         if(a[i]=='1')
           count++;
         if(b[i]=='1')
           count++;
     }
    if(count%2)
      return "NO";
    else
     {
         int n = lena + lenb;
         //Forming the Alternating Array
         int arr[n];
         int j = 0;
         for(i=0;i<lena;i++)
          {
              arr[j++] = a[i] - 48;
              arr[j++] = b[i] - 48;
          }
          //Tiling Up
        for(i=1;i<n;i++)
         {
             if(arr[i]==0 && arr[i-1]==0)
               {
                   arr[i]=arr[i-1]=1;
               }
             else if(i!=1 && arr[i]==0 && arr[i-2]==0)
              {
                  arr[i]=arr[i-2]=1;
              }
         }
         //Check
         for(i=0;i<n;i++)
           {
               if(arr[i]==0)
                 return "NO";
           }
     }
 return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = hexagonalGrid(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
