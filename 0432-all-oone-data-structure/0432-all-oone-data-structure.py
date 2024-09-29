class AllOne:
# Programming with Larry
    def __init__(self):
        self.data = defaultdict(set)
        self.freq = {}
        self.maxi = 0
        self.mini = 0

    def inc(self, key: str) -> None:
        if key not in self.freq:
            self.freq[key] = 1
            self.data[1].add(key)
            self.mini = 1
            if self.maxi < 1:
                self.maxi = 1
        else:
            self.data[self.freq[key]].remove(key)
            curr_freq = self.freq[key]
            
            if self.mini == curr_freq and len(self.data[curr_freq]) == 0:
                self.mini += 1 # taken care in getters
            
            self.freq[key] += 1
            self.data[self.freq[key]].add(key)

            if self.freq[key] > self.maxi:
                self.maxi = self.freq[key]

    def dec(self, key: str) -> None:
        curr_freq = self.freq[key]
        self.data[curr_freq].remove(key)
        
        if self.mini == curr_freq and len(self.data[curr_freq]) == 0:
            self.mini -= 1 # taken care in getters
        if self.maxi == curr_freq and len(self.data[curr_freq]) == 0:
            self.maxi -= 1 # taken care in getters
        
        self.freq[key] -= 1
        new_freq = self.freq[key]

        if new_freq > 0:
            self.data[new_freq].add(key)
        else:
            del self.freq[key]


    def getMaxKey(self) -> str:
        if (len(self.data[self.maxi])) > 0:
            return next(iter(self.data[self.maxi])) # random element from set
        return ""

    def getMinKey(self) -> str:
        if len(self.data[self.mini]) > 0:
            return next(iter(self.data[self.mini])) # random element from set
        if self.mini == 0 and len(self.freq) > 0:
            while len(self.data[self.mini]) == 0:
                self.mini += 1
            return next(iter(self.data[self.mini])) # random element from set
        return ""


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()