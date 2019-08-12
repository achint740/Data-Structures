#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int steps(int x,int target){
    int a[] = {1,2,5};
    int j=2;
    int d = a[j];
    int ans=0;
    while(x!=target && j>=0){
       if(x-d>=target){
           x-=d;
           ans++;
       }
       else{
           j-=1;
           d=a[j];
       }
    }
return ans;
}

// Complete the equal function below.
int equal(vector<int> arr) {
    int n = arr.size();
    int target=INT_MAX,i;
    for(i=0;i<n;i++){
        if(arr[i]<target)
            target = arr[i];
    }
    int minmoves = INT_MAX;
    int moves;
    int j=0;
    while(j<=4){
      moves=0;
      for(i=0;i<n;i++){
          int element=arr[i];
          moves+=steps(element,target);
      }
      if(moves<minmoves)
         minmoves=moves;
      j++;
      target-=1;
    }
return minmoves;
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

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
