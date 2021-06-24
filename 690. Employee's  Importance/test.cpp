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
    int dfs(unordered_map<int, Employee*> info, int id)
    {
        int ret = info[id]->importance;//存当前员工的重要性
        for(auto& sid : info[id]->subordinates)//遍历下属
        {
            ret += dfs(info, sid);
        }

        return ret;
    }

    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
        {
            return 0;
        }

        unordered_map<int, Employee*> info;
        for(auto& e : employees)
        {
            info[e->id] = e;
        }

        return dfs(info, id);
    }
};