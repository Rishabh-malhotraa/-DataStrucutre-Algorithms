#include <bits/stdc++.h>
using namespace std;

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class TextJustify
{
public:
  int extraSpaces;
  vector<string> words;
};

class Solution
{
private:
  vector<TextJustify> getLines(vector<string> &words, int &maxWidth)
  {
    int count = 0, idx = 0;
    vector<TextJustify> lines;
    vector<string> line;
    while (idx < words.size())
    {
      string word = words[idx];
      if (count + word.size() <= maxWidth)
      {
        line.push_back(word);
        count += word.size() + 1;
        idx++;
      }
      else
      {
        lines.push_back({maxWidth - count - 1, line});
        line.clear();
        count = 0;
      }
    }
    if (line.size())
      lines.push_back({maxWidth - count + 1, line});

    return lines;
  }

  string leftJustify(TextJustify &line)
  {
    string leftJustifiedText;

    for (int i = 0; i < line.words.size(); i++)
    {
      string space = (i == line.words.size() - 1) ? "" : " ";
      leftJustifiedText += line.words[i] + space;
    }

    leftJustifiedText += string(line.extraSpaces, ' ');
    return leftJustifiedText;
  }

  string centerJustify(TextJustify &line)
  {
    string justifiedText = "";
    int divisor = max((int)(line.words.size() - 1), 1);

    int spacesAddAll = (line.extraSpaces / divisor);
    int spacesAddLeft = (line.extraSpaces % divisor);

    for (int j = 0; j < line.words.size(); j++)
    {
      string spaces = "";
      int leftAdd = (spacesAddLeft-- > 0) ? 1 : 0;

      if (j != line.words.size() - 1)
        spaces = string(1 + spacesAddAll + leftAdd, ' ');

      justifiedText += line.words[j] + spaces;
    }
    return justifiedText;
  }

public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<TextJustify> lines = getLines(words, maxWidth);
    vector<string> result;
    for (int i = 0; i < lines.size(); i++)
    {
      string text;
      if (i == lines.size() - 1 || lines[i].words.size() == 1)
        text = leftJustify(lines[i]);
      else
        text = centerJustify(lines[i]);

      result.push_back(text);
    }

    return result;
  }
};
// running the function

void solve()
{
  int n, k;

  cin >> n >> k;
  vector<string> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution *sol = new Solution();

  vector<string> res = sol->fullJustify(arr, k);

  for (int i = 0; i < res.size(); i++)
    cout << "||" << res[i] << "||" << endl;
  cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}