//  basic code for binary lifting 

// first calculate the 0th state and then we will go for upper state 
//  basic dp logic is dp[i][x]=dp[i-1][dp[i-1][x]]  // i reperents the 2^i
//  the above expression we can understand by basic example like suppose at x axis i have to go from 0 to 4 at a time i can take one step 
//  dp[0][0]=1; dp[0][1]=2; dp[0][2]=3;dp[0][3]=4; here i am taking one step at a time 2^0 
// but if i take 2^1 step a time where my position will be 
//   dp[1][0]=dp[0][dp[0][0]] ; basically i can divide it in the two steps  first i will go to dp[0][0](1) then i will go for dp[0][1] 
// dp[2][0] = dp[1][dp[1][0]]  // first calc the dp[1][0] (2)  then use this will to make the next step dp[1][2]


// first fill the ground state 

int dp[20][N];
for(int i=0;i<n;i++){
  dp[0][i]=a[i]; // fill it with basic requirement  
}


 
for(int i=1;i<20;i++){
    for(int j=0;j<=n;j++){
        dp[i][j]=dp[i-1][dp[i-1][j]];
   }
}


//  now for answering the query 
//  for l to r 
int ans=0;
for(int i=19;i>=0;i--){
  if(dp[i][l]<=r){
    ans+=(1<<i);
    l=dp[i][l];
  }
}
