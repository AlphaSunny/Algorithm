//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine //if the input string is valid.

class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        if(length%2)
        {
            return false;
        }
        map<char, char> mymap;
        mymap.insert(pair<char, char>('(', ')'));
        mymap.insert(pair<char, char>('{', '}'));
        mymap.insert(pair<char, char>('[', ']'));
        
        stack<char> mystack;
        
        if(s[0]==')' || s[0] == ']' || s[0] == '}')
            {
                return false;
            }
        for(int i =0;i<length ;i++)
        {
            if(s[i]=='{' || s[i] == '[' || s[i] == '(')
            {
                mystack.push(s[i]);
            }
            else
            {
                char temp = mystack.top();
                if(mymap[temp] == s[i])
                {
                    mystack.pop();
                }
                else
                {
                    return false;
                }
            }
            
        }
        
        if(mystack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};



/*
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int length = ops.size();
        if(length ==0) return 0;
        
        stack<int> s;
        for(int i=0; i<length; i++)
        {
            if(ops[i] == "C")
            {
                s.pop();
            }
            
            else if(ops[i] == "D")
            {
                s.push(2*s.top());
            }
            else if(ops[i] == "+")
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.push(x);
                s.push(x+y);
            }
            else
            {
                s.push(stoi(ops[i]));
            }
        }
        int sum = 0;
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
            
    }
};