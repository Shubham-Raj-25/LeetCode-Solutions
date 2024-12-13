class RangeModule {
public:
    set<pair<int,int>>st;
    const int INF = 1e9;
    RangeModule() {
        
    }

    void addRange(int b, int e) {
        auto it = st.upper_bound({b, INF});
        while (it != st.end() and it->first <= e) {
            e = max(e, it->second);
            st.erase(it++);
        }
        if (st.size() and it != st.begin() and  b <= (--it)->second) {
            b = min(b, it->first);
            e = max(e, it->second);
            st.erase(it);
        }
        st.insert({b, e});
    }
    
    bool queryRange(int b, int e) {
        auto it = st.upper_bound({b, INF});
        if (it == st.begin()) return false;
        --it;
        return (it->first <= b and e <= it->second);
    }
    
    void removeRange(int b, int e) {
        auto it = st.upper_bound({b, INF});
        int lastE = (it == st.begin() ? -1 : prev(it)->second);
        while (it != st.end() and it->first < e) {
            lastE = it->second;
            st.erase(it++);
        }


        if (st.size() and it != st.begin() and b < (--it)->second) {
            int firstB = it->first;
            st.erase(it);
            if (firstB < b) {
                st.insert({firstB, b });
            }
        }
        if (e < lastE) {
            st.insert({e, lastE});
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */