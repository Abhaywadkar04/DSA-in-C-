class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {


//runnign sum;
    for(int i=1;i<arr.size();i++){

        arr[i]=arr[i]+arr[i-1];

    }
    int count=0;
    for(int i=0;i<arr.size();i++){

        if(i*(i+1)/2==arr[i])count++;
    }

    return count;

    }
};