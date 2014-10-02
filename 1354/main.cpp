#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> z_function (string &s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
        z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
        if (i + z[i] - 1 > r)
        l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s, re;
    cin >> re;
    cout << re;
    s = re;
    reverse(re.begin(), re.end());
    s = re + '#' + s;
    int i;
    vector<int> z = z_function(s);
    for (i = (int)re.size() + 2; (i < s.size() && (s.size() != i + z[i])); i++);
    cout << re.substr(s.size() - i) << endl;
}
