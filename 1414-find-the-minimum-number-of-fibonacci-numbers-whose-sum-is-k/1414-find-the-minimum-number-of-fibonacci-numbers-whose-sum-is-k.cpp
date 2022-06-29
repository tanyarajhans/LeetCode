class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        //variables a,b,c help us in finding the Fibonacci series
        long long a=1,b=1,c=a+b;
        //vector c stores the fibonacci series for us
        vector<long long> v;
        v.push_back(1);
        while(c<=k){
            v.push_back(c);
            a = b;
            b = c;
            c= a+b;
        }
        v.push_back(c);
        //ans is what we will return ie the min no of Fibonacci nos which will sum to k
        int ans = 0;
        int size = v.size()-1;
        //while loop iterates over v until we get the sum k with the nos
        while(true){
          //if the  
          if(v[size]==k){
              return ans+1;
          }
          //deducting the max no less than k which we get and update k and then increase the ans variable 
            else if(v[size]<k){
               k = k - v[size];
               ans++;
           }
           //decrementing the size variable to point to the next smaller no in the vector v  
           size--;
        }
        return ans;
    }
};