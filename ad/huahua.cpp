class Solution {
public: 
    bool canIWin(int M, int T) {
        
        const int sum = (M+1)*M/2;
        
        if(sum<T)
            return false;
        if(T<=0)
            return true;
        
        m_ = vector<char>(1<<M,0);
        
        return help(M, T, 0);
        
         
    }
private:
    vector<char> m_;
    
    bool help(int M, int T, int state){
        
        if(T<=0)
            return false;
        
        if(m_[state])
            return m_[state]==1;
        
        for(int i=0;i<M;i++){
            if(state & (1<<i))
                continue;
            if(!help(M,T-i-1,state | (1<<i)))
               return m_[state] = 1;
        }
               
        m_[state] = -1;
        return false;
    }
};