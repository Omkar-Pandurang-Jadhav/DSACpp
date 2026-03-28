class Solution {
  public:
    bool isOperator(char ch){
        if(ch=='*' || ch=='^' || ch=='-' || ch=='+' || ch=='/') return true;
        return false;
    }
    int orderOfOperator(char ch){
        if(ch=='^') return 2;
        else if(ch=='/' || ch=='*') return 1;
        else if(ch=='+' || ch=='-') return 0;
        else return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        string ans="";
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!isOperator(s[i]) && s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
            else if(isOperator(s[i])){
                while((orderOfOperator(s[i]) < orderOfOperator(st.top())) || 
       (orderOfOperator(s[i]) == orderOfOperator(st.top()) && s[i] != '^') &&
      st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if(s[i]=='(') st.push('(');
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    string reverseString(string a){
        int n=a.size();
        reverse(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]=='(') a[i]=')';
            else if(a[i]==')') a[i]='(';
        }
        return a;
    }
    string infixToPrefix(string &s) {
        // code here
        s=reverseString(s);
        string ans=infixToPostfix(s);
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
