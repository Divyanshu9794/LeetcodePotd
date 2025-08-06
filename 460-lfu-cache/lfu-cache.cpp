
class Node
{
    public:
    int key;
    int value;
    int freq;
     list<int>::const_iterator it;
    Node(int key,int value,int freq,list<int>::const_iterator it)
    {
        this -> key = key;
        this -> value = value;
        this -> freq = freq;
        this -> it = it;
    }

};

class LFUCache {
    private:
    int capacity;
    int totalSize;
    int minimumFrequency;
    unordered_map <int,list<int>> storeList;
    unordered_map <int,Node*> keyToNode;
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        this -> minimumFrequency = 0;
        this -> totalSize = 0;
    }
    
    int get(int key) {
        if(keyToNode.find(key) == keyToNode.end())
        {
            return -1;
        }

        Node* nodeForKey = keyToNode[key];
        int valueForKey = nodeForKey -> value; 
        updateFrequency(nodeForKey);
        return valueForKey;
    }
    
    void put(int key, int value) {
         if (capacity == 0) return;
         
        if(keyToNode.find(key) != keyToNode.end())
        {
              Node* nodeForKey = keyToNode[key];
              nodeForKey -> value = value; 
              updateFrequency(nodeForKey);
              return;
        }

        totalSize++;
        if(totalSize > capacity)
        {
            int keyToRemove = storeList[minimumFrequency].back(); // last value of this list

            storeList[minimumFrequency].pop_back(); 
            keyToNode.erase(keyToRemove);
            totalSize--;

        }

        minimumFrequency = 1;
        storeList[minimumFrequency].push_front(key);

        // keyToNode[key] = {key,value,1,cbegin(storeList[minimumFrequency])};
        keyToNode[key] = new Node(key,value,1,storeList[minimumFrequency].cbegin());

    }

    void updateFrequency(Node* node)
    {
        int initialFrequency = node -> freq;
        node -> freq++;
        int currFrequency = node -> freq;
        storeList[initialFrequency].erase(node -> it);
        storeList[currFrequency].push_front(node -> key);
        node -> it = storeList[currFrequency].cbegin();
        if(storeList[initialFrequency].empty())
        {
            storeList.erase(initialFrequency);
            if(initialFrequency == minimumFrequency)
            {
                 minimumFrequency++;
            }
        }


    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */