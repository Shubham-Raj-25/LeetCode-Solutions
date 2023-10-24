class Solution {
    public Boolean isSelfDividing(int n){
        int num=n;

        while(num>0){
            int digit = num % 10;
            num = num/10;
            if(digit == 0 || n % digit != 0)
                return false; 
        }

        return true;

    }

    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i))
                list.add(i);
        }

        return list;
    }
}