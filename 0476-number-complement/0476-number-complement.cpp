class Solution {
public:
    int findComplement(int num) {
           int number=num;
        int converter=0;
        int solution;

        if(number==0){
            return 1;

        }

        else{

            while(number!=0){
                converter=(converter<<1) | 1;
                number=number>>1;
                 solution=(~num) & converter;  

                

            }
        }




    return solution;
    }
        
    
};