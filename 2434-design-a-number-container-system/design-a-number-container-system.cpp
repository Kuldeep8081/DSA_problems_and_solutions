class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp; // Min-heap for each number
    unordered_map<int, int> ind; // Stores (index -> number) mapping

    NumberContainers() {}

    void change(int index, int number) {
        if (ind.count(index) && ind[index] == number)
            return; // No change needed

        if (ind.count(index)) {
            int prevNum = ind[index];
            ind[index] = number; // Update mapping

            // Lazy deletion: Just mark that index was changed
            while (!mp[prevNum].empty() && ind[mp[prevNum].top()] != prevNum) {
                mp[prevNum].pop(); // Remove outdated top elements
            }
        } else {
            ind[index] = number; // New index mapping
        }

        mp[number].push(index); // Insert into priority queue
    }

    int find(int number) {
        if (!mp.count(number) || mp[number].empty())
            return -1; // No indices found

        // Lazy cleanup: Ensure top is valid
        while (!mp[number].empty() && ind[mp[number].top()] != number) {
            mp[number].pop();
        }

        return mp[number].empty() ? -1 : mp[number].top();
    }
};
