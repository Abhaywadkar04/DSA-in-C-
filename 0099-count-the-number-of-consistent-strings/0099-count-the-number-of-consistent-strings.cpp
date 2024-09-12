class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        int arr[26]={0};

        int count =0;
        for(char c:allowed){
            arr[c-'a']=1;

        }
      
        for(string word : words){
              int check=1;
            for(char w:word){
                if(arr[w-'a']==0){
                    check=0;
                    break;
                }
            }

            count =count+check;

        }


        return count;


        
    }
};