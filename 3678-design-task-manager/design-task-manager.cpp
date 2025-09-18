#include <bits/stdc++.h>
using namespace std;

class TaskManager {
private:
    // Map from taskId -> pair(userId, priority)
    unordered_map<int, pair<int,int>> taskInfo;
    // Set to keep tasks ordered by priority desc, then taskId desc
    // We'll store (priority, taskId) but need custom comparator
    struct Node {
        int priority;
        int taskId;
        bool operator<(const Node &o) const {
            if (priority != o.priority) return priority > o.priority;
            return taskId > o.taskId;
        }
    };
    // Because std::set does ascending, but our comparator makes top as smallest in set
    set<Node> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int u = t[0], i = t[1], p = t[2];
            taskInfo[i] = {u, p};
            taskSet.insert(Node{p, i});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        taskSet.insert(Node{priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto &info = taskInfo[taskId];
        int oldPriority = info.second;
        // remove old
        taskSet.erase(Node{oldPriority, taskId});
        // update
        info.second = newPriority;
        // insert new
        taskSet.insert(Node{newPriority, taskId});
    }

    void rmv(int taskId) {
        auto it = taskInfo.find(taskId);
        if (it == taskInfo.end()) return;
        int priority = it->second.second;
        taskSet.erase(Node{priority, taskId});
        taskInfo.erase(it);
    }

    int execTop() {
        if (taskSet.empty()) return -1;
        // first element is the top by our comparator
        Node top = *taskSet.begin();
        taskSet.erase(taskSet.begin());
        int tid = top.taskId;
        int uid = taskInfo[tid].first;
        taskInfo.erase(tid);
        return uid;
    }
};
