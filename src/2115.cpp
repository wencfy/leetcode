#include "iostream"
#include "vector"
#include "map"
#include "set"
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, vector<string>> mp;
        set<string> sup;

        for (string s: supplies) {
            sup.insert(s);
        }

        for (int i = 0; i < recipes.size(); i++) {
            if (mp.find(recipes[i]) == mp.end()) {
                for (string in: ingredients[i]) {
                    mp[recipes[i]].push_back(in);
                }
            }
        }

        vector<string> ret;
        for (auto recipe: recipes) {
            map<string, bool> vis;
            if (cook(recipe, mp, sup, vis)) {
                ret.push_back(recipe);
            }
        }
        return ret;
    }

    bool cook(string re, map<string, vector<string>> &mp, set<string> &sup, map<string, bool> &vis) {
        if (vis.find(re) != vis.end()) {
            return false;
        }

        vis[re] = true;

        if (sup.find(re) != sup.end()) {
            return true;
        }

        if (mp.find(re) != mp.end()) {
            for (string s: mp[re]) {
                if (sup.find(s) != sup.end()) {
                    continue;
                } else {
                    if (!cook(s, mp, sup, vis)) {
                        return false;
                    }
                }
            }
            sup.insert(re);
            return true;
        }

        return false;
    }
};