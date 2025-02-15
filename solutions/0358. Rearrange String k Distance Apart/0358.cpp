class Solution {
 public:
  string rearrangeString(string s, int k) {
    const int n = s.length();
    string ans;
    vector<int> count(128);
    // valid[i] := the leftmost index character i can appear
    vector<int> valid(128);

    for (const char c : s)
      ++count[c];

    for (int i = 0; i < n; ++i) {
      const char c = getBestLetter(count, valid, i);
      if (c == '*')
        return "";
      ans += c;
      --count[c];
      valid[c] = i + k;
    }

    return ans;
  }

 private:
  // Returns the valid letter that has the most count.
  char getBestLetter(const vector<int>& count, const vector<int>& valid,
                     int index) {
    int maxCount = -1;
    char bestLetter = '*';

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] > 0 && count[c] > maxCount && index >= valid[c]) {
        bestLetter = c;
        maxCount = count[c];
      }

    return bestLetter;
  }
};
