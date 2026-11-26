class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        stack<char> st;
        for(char c : directions)
        {
            while(!st.empty() && st.top() == 'R' && (c == 'L' || c == 'S'))
            {
                st.pop();
                if(c == 'L')
                {
                    collisions += 2;
                    c = 'S';
                }
                else
                    collisions++;
            }
            if(!st.empty() && st.top() == 'S' && c == 'L')
                collisions++;
            else
                st.push(c);
        }
        return collisions;
    }
};