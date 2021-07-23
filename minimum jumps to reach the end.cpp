class Solution{
  public:
    int minJumps(int arr[], int n){
        int low = 0;
        int high = 0;
        int jumps = 0;
        for(int i =0;i<n;i++){
            high = max(high,arr[i] + i);
            if(i == low){
                jumps++;
                low = high;
            }
            if(low >=n-1) break;
        }
        if(low <n-1) return -1;
        else return jumps;
    }
};
