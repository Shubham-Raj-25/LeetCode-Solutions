/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    map<int,Employee*> mp;
    int helper(Employee* employee){
        int total_imp = employee->importance;
        for(int id : employee->subordinates){
            total_imp += helper(mp[id]);
        }
        return total_imp;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto employee: employees)
            mp[employee->id] = employee;
        return helper(mp[id]);
    }
};