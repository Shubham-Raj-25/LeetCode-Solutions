class Solution {
public:
    vector<int> func(string input, unordered_map<string,vector<int>>& dpMap){
        int size = input.length();
        vector<int> result;
        for(int i=0;i<size;i++){
            char curr = input[i];
            if(curr == '+' || curr == '-' || curr == '*'){
                // here split the result into two parts and solve them by recusrion and memonization
                vector<int> result1,result2;

                string substr = input.substr(0,i);

                if(dpMap.find(substr)!=dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = func(substr,dpMap);
                
                substr = input.substr(i+1);

                if(dpMap.find(substr)!=dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = func(substr,dpMap);
                
                for(auto n1: result1)
                    for(auto n2: result2){
                        if(curr== '+')
                            result.push_back(n1+n2);
                        else if(curr == '-')
                            result.push_back(n1-n2);
                        else
                            result.push_back(n1*n2);
                    }
                
            }
        }
        // if the input string contains only number
		if (result.empty())
			result.push_back(atoi(input.c_str()));
		// save to dpMap
		dpMap[input] = result;
		return result;

    }
    
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>> dpMap;
        return func(expression,dpMap);
    }
};