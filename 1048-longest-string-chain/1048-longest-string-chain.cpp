bool Pred(const string& lhs, const string& rhs)
{
    return lhs.size() < rhs.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), Pred);
        
        unordered_map<string, int> mp;
        int maxLength = 1;

        for (auto& word : words)
        {
            bool flag = false;
            for (int i = 0; i < word.size(); i++)
            {
                string s = word.substr(0, i) + word.substr(i + 1);
                if (mp.find(s) != mp.end())
                {
                    int currentSize = mp[s];
                    if (mp.find(word) != mp.end())
                    {
                        if (currentSize + 1 > mp[word])
                        {
                            mp[word] = currentSize + 1;
                            maxLength = max(maxLength, currentSize + 1);
                        }
                    }
                    else
                    {
                        mp.insert({ word, currentSize + 1 });
                        maxLength = max(maxLength, currentSize + 1);
                    }

                    flag = true;
                }
            }
            if (!flag)
            {
                mp.insert({ word, 1 });
            }
        }

        return maxLength;
    }
};