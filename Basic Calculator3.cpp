#include <iostream>
#include <string>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
class Solution {
    public:
    int calculate(string s) {
      lli l1 = 0;
      lli l2 = 1;
      lli o1 = 1;
      lli o2 = 1;
      stack<lli> st;
      lli n = s.size();
      for (lli i = 0; i < n; i++) {
         char x = s[i];
         if (x >= '0' && x <= '9') {
            lli num = x - '0';
            while (i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '9') {
               i++;
               num = (num * 10) + (s[i] - '0');
            }
            l2 = (o2 == 1) ? l2 * num : l2 / num;
         }
         else if (x == '(') {
            st.push(l1);
            st.push(o1);
            st.push(l2);
            st.push(o2);
            l1 = 0;
            o2 = 1;
            o1 = 1;
            l2 = 1;
         }
         else if (x == ')') {
            lli temp = l1 + o1 * l2;
            o2 = st.top();
            st.pop();
            l2 = st.top();
            st.pop();
            o1 = st.top();
            st.pop();
            l1 = st.top();
            st.pop();
            l2 = (o2 == 1) ? l2 * temp : l2 / temp;
         }
         else if (x == '*' || x == '/') {
            o2 = (x == '*') ? 1 : -1;
         }
         else if (x == '+' || x == '-') {
            if (x == '-' && (i == 0 || (i - 1 >= 0 && s[i - 1] == '('))) {
               o1 = -1;
               continue;
            }
            l1 += o1 * l2;
            o1 = (x == '+') ? 1 : -1;
            l2 = 1;
            o2 = 1;
         }
      }
      return l1 + o1 * l2;
    }
};

int main(){
    string s;
    cin >> s;
    Solution ob;
    cout << (ob.calculate(s));
}