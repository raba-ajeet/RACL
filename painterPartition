int painter(int n,int k){
    if(k>n)  return -1;
    int l=0,r=0;
    fi(i,n) r+=a[i];
    int ans=r;
    while(l<r){
        int m=l+(r-l)/2;
        int curr_sum=0,cnt=0,ok=1;
        fi(i,n){
            if(a[i]>m) {
                ok=0;
                break;
            }
            if(a[i]+curr_sum>m) curr_sum=a[i],cnt++;
            else curr_sum+=a[i];
        }
        if(curr_sum) cnt++;
        if(ok && cnt<=k) ans=min(ans,m),r=m; 
        else l=m+1;
    }
    return ans;
}

// we will have the input array as a and n(size of the aray ) and k (no of partitions)
// then basically we will do binary search on it using array sum as upper limit and 0 as lower limit 
//  we will try to divide the sections in sum as m 
// if its possible to divide them in <= k  sections ( < bcz we can break sections in smaller sections ) then just search for more optimal answer 
// else we will increase the l value to find sum which can satisify the condition 
