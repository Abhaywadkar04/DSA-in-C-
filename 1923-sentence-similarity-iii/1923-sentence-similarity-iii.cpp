class Solution {

    vector<string>splitWords(string sentence){
        vector<string>words;
        istringstream stream(sentence);
        string word;
         while (stream >> word) {
        words.push_back(word);
    }
    return words;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string>word1=splitWords(sentence1);
        vector<string>word2=splitWords(sentence2);


        if(word1.size()<word2.size()) swap(word1,word2);
        int start=0;
        int end=0;
        int n1=word1.size();
        int n2=word2.size();
        while(start < n2 && word1[start]==word2[start])start++;
        while(end < n2 && word1[n1-end-1]==word2[n2-end-1])end++;
        
        return start+end>=n2;

    }
};