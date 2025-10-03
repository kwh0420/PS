#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    s+=' ';
    stack<string> num;
    stack<char> op;
    for (int i = 0; i < s.length(); i++) {
        if ('A'<=s[i] && s[i]<='Z') {
            num.push(string(1,s[i]));
        }
        else {
            bool a1 = (!op.empty())&&(s[i]=='-' || s[i]=='+') &&(op.top()=='*' ||op.top()=='/' || op.top() =='+' || op.top()=='-');
            bool a2 = (!op.empty())&&(s[i]=='*'|| s[i]=='/') &&(op.top()=='/' || op.top()=='*');
            if (s[i]=='(') {
                op.push(s[i]);
            }
            else if (a1||a2) {
                while (!op.empty() && op.top() != '(' &&
                       ((s[i]=='+' || s[i]=='-') || 
                        ((s[i]=='*' || s[i]=='/') && (op.top()=='*' || op.top()=='/')))) {
                    string a=num.top(); num.pop();
                    string b=num.top(); num.pop();
                    string c=b+a+op.top();
                    op.pop();
                    num.push(c);
                        }
                op.push(s[i]);
            }
            else if (s[i]==')') {
                while (op.top()!='(') {
                    string a=num.top();
                    num.pop();
                    string b = num.top();
                    num.pop();
                    string c= b+a+op.top();
                    op.pop();
                    num.push(c);
                }
                op.pop();
            }
            else if (i==s.length()-1) {
                while (!op.empty()) {
                    string a=num.top();
                    num.pop();
                    string b=num.top();
                    num.pop();
                    string c=b+a+op.top();
                    num.push(c);
                    op.pop();
                }
            }
            else {
                op.push(s[i]);
            }
        }
    }
    cout << num.top();
}