// Complete the abbreviation function below.
string abbreviation(string a, string b) {
       
       int lena = a.length();
       int lenb = b.length();

       int** dp = new int*[lenb+1];
       for(int i=0;i<=lenb;i++){
           dp[i] = new int[lena+1];
       }

       //No. of Rows = lenb + 1
       //No. of Columns = lena + 1

       //Initialize 0th column with 0
       for(int i=0;i<=lenb;i++){
           dp[i][0]=0;
       }

       //Initialize 0th row with 1
       for(int j=0;j<=lena;j++){
           dp[0][j]=1;
       }

       for(int i=1;i<=lenb;i++){
           for(int j=1;j<=lena;j++){
               char ch1 = a[j-1];
               char ch2 = b[i-1];
               int d = ch1 - ch2;
               if(ch1>=97 && ch2<=122){
                    //Option 1
                    bool op1 = dp[i][j-1];
                    //Option 2
                    bool op2 = (d==32)&(dp[i-1][j-1]);

                    dp[i][j] = op1 || op2;
               }
               else{
                    if(d==0 && dp[i-1][j-1])
                      dp[i][j]=1;
                    else    
                      dp[i][j]=0;
               }
           }
       }

    //    for(int i=0;i<=lenb;i++){
    //        for(int j=0;j<=lena;j++){
    //            cout<<dp[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    //    cout<<"--------------------\n";
       string ans = "";
       if(dp[lenb][lena]==1){
           ans+="YES";
       }
       else{
           ans+="NO";
       }

    return ans;

}
