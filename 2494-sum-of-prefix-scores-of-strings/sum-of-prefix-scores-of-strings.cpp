

class Node 
{

	public : 
	
	Node* links[26];
	bool flag = false;
    int count = 0;
	bool containsKey(char ch)
	{
		return (links[ch-'a'] != NULL);
	}

	void put(char ch , Node*node)
	{
		links[ch-'a'] = node;
	}
	Node*get(char ch)
	{
		return links[ch-'a'];
	}
	void setEnd()
	{
		flag = true;
	}
	bool isEnd()
	{
		return flag;
	}
};

class Trie 
{
	private : Node * root;
	public : 
	Trie()
	{
		root = new Node();
	}

	// tc - O(n)
	void insert(string word)
	{
		Node*node = root;
		for(int i = 0; i < word.size(); i++)
		{
			if(!node->containsKey(word[i]))
			{
				node->put(word[i] , new Node());
			}
			node = node->get(word[i]);
            node->count++;
		}
		node->setEnd();
	}

	bool search(string word)
	{
		Node*node = root;
		for(int i =0 ; i < word.size(); i++)
		{
			if(!node->containsKey(word[i]))
			{
				return false;
			}
			node = node->get(word[i]);
		}
		return  node->isEnd();
	}

	int  startsWith(string word)
	{
		Node*node = root;
        int count = 0;
		for(int i = 0 ; i < word.size() ; i++)
		{
			if(!node->containsKey(word[i]))return false;
			node = node->get(word[i]);
            count += node->count;
		}
        return count;
		// return node->count;
	}
};



class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t = new Trie();
        for(auto i : words)
        {
            t->insert(i);
        }
        vector<int>a;
        for(auto i : words)
        {
            int count = t->startsWith(i);
            a.push_back(count);
        }
        return a;

    }
};