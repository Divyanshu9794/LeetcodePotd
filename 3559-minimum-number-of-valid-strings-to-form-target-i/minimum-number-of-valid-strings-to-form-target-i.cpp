
class Solution {
public:
    struct Trie {
        vector<vector<int>> adjMatrix;
        Trie() : adjMatrix(1, vector<int>(26, -1)) {}

        void addToTrie(const string& word) {
            int currentNodeIndex = 0;
            for (char charInWord : word) {
                int charIndex = charInWord - 'a';
                if (adjMatrix[currentNodeIndex][charIndex] == -1) {
                    adjMatrix[currentNodeIndex][charIndex] = adjMatrix.size();
                    adjMatrix.push_back(vector<int>(26, -1));
                }
                currentNodeIndex = adjMatrix[currentNodeIndex][charIndex];
            }
        }

        int findMinimumSegments(const string& targetString, int startIdx, vector<int>& minSegments) {
            int currentNodeIndex = 0;
            for (int currentIdx = startIdx; currentIdx < targetString.size(); ++currentIdx) {
                int charIndex = targetString[currentIdx] - 'a';
                if (adjMatrix[currentNodeIndex][charIndex] == -1) {
                    return -1;
                }
                currentNodeIndex = adjMatrix[currentNodeIndex][charIndex];
                minSegments[currentIdx + 1] = min(minSegments[currentIdx + 1], minSegments[startIdx] + 1);
            }
            return minSegments[targetString.size()];
        }
    };

    int minValidStrings(vector<string>& wordList, string targetString) {
        Trie trie;

        for (const string& word : wordList) {
            trie.addToTrie(word);
        }

        int targetLength = targetString.size();
        vector<int> minSegments(targetLength + 1, numeric_limits<int>::max());
        minSegments[0] = 0;

        for (int i = 0; i < targetLength; ++i) {
            if (minSegments[i] != numeric_limits<int>::max()) {
                trie.findMinimumSegments(targetString, i, minSegments);
            }
        }

        return minSegments[targetLength] == numeric_limits<int>::max() ? -1 : minSegments[targetLength];
    }
};
