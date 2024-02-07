nt countPrimes(int n){
//     if(n == 0)  return 0;
//     vector<bool> prime(n, true);
//     prime[0] = prime[1] = false;
//     int ans = 0;
    
//     for(int i=2; i<n; i++){
//         if(prime[i] == true){
//             ans++;
//         }
//         int j = 2 * i;
//         while(j < n){
//             prime[i] = false;
//             j = j+i;
//         }
//     }
//     return ans;
// }