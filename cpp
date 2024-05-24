class Solution {
public:
    int cnt[26]={0};
    int maxScore(int index,vector<string> &W,vector<int> &S){
        if(index==W.size()){
            return 0;
        }
        int ans=0;
        bool valid=true;
        int wordCnt=0;
        int i=0;
        for(;i<W[index].size();i++){
            cnt[W[index][i]-'a']--;
            wordCnt+=S[W[index][i]-'a'];
            if(cnt[W[index][i]-'a']<0){
                valid=false;
                break;
            }
        }
        if(valid){
            ans=wordCnt+maxScore(index+1,W,S);  
        }      
        for(int j=0;j<=i && j<W[index].size();j++){
            cnt[W[index][j]-'a']++;
        }
        ans=max(ans,maxScore(index+1,W,S));
        return ans;
    }
    int maxScoreWords(vector<string>& W, vector<char>& L, vector<int>& S) {
        for(int i=0;i<L.size();i++){
            cnt[L[i]-'a']++;
        }
        return maxScore(0,W,S);
    }
};
