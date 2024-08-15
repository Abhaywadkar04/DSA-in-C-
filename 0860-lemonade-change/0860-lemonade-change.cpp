class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0; // count of $5 bills
        int ten = 0;  // count of $10 bills
        
        for (int bill : bills) {
            if (bill == 5) {
                five++; // receive a $5 bill
            }
            else if (bill == 10) {
                if (five > 0) {
                    five--; // give one $5 bill as change
                    ten++;  // receive a $10 bill
                } 
                else {
                    return false; // cannot give change
                }
            }
            else if (bill == 20) {
                if (ten > 0 && five > 0) {
                    ten--;  
                    five--;// give one $10 bill and one $5 bill as change
                } else if (five >= 3) {
                    five -= 3; // give three $5 bills as change
                } else {
                    return false; // cannot give change
                }
            }
        }
        
        return true; // all customers were given the correct change
    }
};
