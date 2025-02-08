class NumberContainers {
public:
    map<int, set<int>> mp;
    map<int, int> indexs;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexs.find(index) != indexs.end()){
            int num = indexs[index];
            mp[num].erase(index);
        }
        indexs[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp[number].empty())
            return -1;
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */