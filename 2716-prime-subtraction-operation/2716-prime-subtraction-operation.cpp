class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<=sqrt(n);i++)
            if(n % i == 0)
                return false;
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        // you go to every element and make it as small as possible but > the prev element 
        // greedily do it
        vector<int> primes(1000);
        int biggest_prime = 1;
        for(int i=1;i<=1000;i++){
            primes[i-1] = biggest_prime;
            if(isPrime(i))
                biggest_prime = i;
        }

        for(int i=0;i<nums.size();i++){
            if(i == 0){
                int biggest_prime = primes[nums[i]-1];
                if(biggest_prime != 1)
                    nums[i] -= biggest_prime;
            }
            else{
                int diff = nums[i] - nums[i-1];
                if(diff <= 0)
                    return false;
                int biggest_prime = primes[diff-1];
                if(biggest_prime != 1)
                    nums[i] -= biggest_prime;
            }
        }

        return true;
    }
};