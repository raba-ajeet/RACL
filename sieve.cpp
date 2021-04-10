int a[N];
vi primes;
void sieve() {
    fi(i,N) a[i]=1;
    fir(i,2,N) {
        if(a[i]){   
            int x=2*i;
            while(x<N){
                a[x]=0;
                x+=i;
 
            }
        }
        if(a[i]==1) primes.pb(i);
    }
}
