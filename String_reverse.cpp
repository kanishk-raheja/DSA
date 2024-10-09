#include <iostream>
#include <string>
using namespace std;

string reverseString(string& s) {
    string res;
  
      // Traverse on s in backward direction
      // and add each charecter to a new string
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}

int main() {
    string s = "abdcfe";
    string res = reverseString(s);
    cout << res;
    return 0;
}
