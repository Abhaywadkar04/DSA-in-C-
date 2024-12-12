class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>maxHeap(gifts.begin(),gifts.end());


        long long score=0;

        while(k>0 && !maxHeap.empty()){
            int num=maxHeap.top();
            maxHeap.pop();
            int reducedGift = sqrt(num); 
            maxHeap.push(reducedGift);
            k--;

        }


        while(!maxHeap.empty()){

            score+=maxHeap.top();
            maxHeap.pop();
        }

            return score;

    }
};