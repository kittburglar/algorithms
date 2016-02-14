class Solution {
public:
    int addDigits(int num) {
        if(num <= 9){
            return num;
        }
        int total = 0;
        while(num){
            total = total + num % 10;
            num = num / 10;
        }
        return addDigits(total);
    }
};
