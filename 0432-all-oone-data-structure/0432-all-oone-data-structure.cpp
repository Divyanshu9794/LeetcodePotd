class AllOne {
public:
unordered_map<string, int> m;
    AllOne() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
    void updateMin() {        
        _min.second = INT_MAX;
        for(auto & nd : m) {
            if(_min.second > nd.second) {
                _min.second = nd.second;
                _min.first = nd.first;
            }
        }
    }
    void updateMax() {        
        _max.second = INT_MIN;
        for(auto & nd : m) {
            if(_max.second < nd.second) {
                _max.second = nd.second;
                _max.first = nd.first;
            }
        }
    }
    void inc(string key) {
        auto & v = m[key];
        ++v;
        if(v > _max.second) {
            _max.second = v;
            _max.first = key;
        }
        if(key == _min.first) {
            updateMin();
        }
        if(_min.second > v || _min.first.empty()) {
            _min.first = key;
            _min.second = v;
        }
    }
    void dec(string key) {
        m[key]--;
        if(m[key] ==0)
            m.erase(key);
        _min.first = _max.first = "";
    }
    string getMaxKey() {
        if(!_max.first.empty())
            return _max.first;
        updateMax();
        return _max.first;
    }
    string getMinKey() {
        if(!_min.first.empty())
            return _min.first;

        updateMin();
        return _min.first;
    }
    pair<string, int> _min{{}, 0};
    pair<string, int> _max{{}, 0};
};