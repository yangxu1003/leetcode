class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int pushi = 0,popi = 0;
        stack<int> st; 
        
        while(!pushV.empty() && pushi < pushV.size())
        {
            st.push(pushV[pushi]);
            
            while(!st.empty() &&  st.top() == popV[popi])
            {
                st.pop();
                popi++;
            }
            
            pushi++;
        }
        
        if(pushi == popi)
        {
            return true;
        }
        return false;
    }
};