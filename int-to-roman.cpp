class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int digits[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanNumeral;
        while(num > 0){
            for(int i = 0; i < 13; i++){
                if(num/digits[i] >=1){
                    romanNumeral = romanNumeral + roman[i];
                    num = num - digits[i];
                    break;
                }
            }
        }
    return romanNumeral;
    }
};
