#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    // Map cuisine -> ordered set of foods in that cuisine, sorted by (-rating, name)
    unordered_map<string, set<pair<int, string>>> cuisineFoods;
    // Map food -> its cuisine
    unordered_map<string, string> foodToCuisine;
    // Map food -> its current rating
    unordered_map<string, int> foodRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            const string &f = foods[i];
            const string &c = cuisines[i];
            int r = ratings[i];
            foodToCuisine[f] = c;
            foodRating[f] = r;
            // store negative rating so that higher rating → smaller key in set
            // but since set by default sorts ascending, using {-rating, name}
            cuisineFoods[c].insert({-r, f});
        }
    }
    
    void changeRating(string food, int newRating) {
        // find old rating & cuisine
        string c = foodToCuisine[food];
        int old = foodRating[food];
        // remove old record
        cuisineFoods[c].erase({-old, food});
        // update
        foodRating[food] = newRating;
        // insert new
        cuisineFoods[c].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &s = cuisineFoods[cuisine];
        // The set is sorted so that smallest pair is the one with largest rating
        // (because first element has the smallest key = (-rating) minimal => rating max),
        // and among equal ratings, name ascending
        auto it = s.begin();
        return it->second;
    }
};
