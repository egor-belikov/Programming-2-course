#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> prefix_function (string &s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string jack, wall, s;
    cin >> jack >> wall;
    s = jack + '#' + wall;
    vector<int> pi = prefix_function(s);
    for (int i = (int)s.size() - 1; s[i] != '#'; i--)
        if (pi[i] == 0)
        {
            cout << "Yes";
            return 0;
        }
    cout << "No\n";
    vector<string> res;
    for (int i = (int) s.size() - 1; s[i] != '#';)
    {
        res.push_back(s.substr(i - pi[i] + 1, pi[i]));
        i -= pi[i];
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
