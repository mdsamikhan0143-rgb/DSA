class Solution {
public:
    int parent[26];

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    string smallestEquivalentString(string s1, string s2,
                                    string baseStr) {
        // Initially, each character belongs to its own group.
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < s1.size(); i++) {
            int root1 = findParent(s1[i] - 'a');
            int root2 = findParent(s2[i] - 'a');

            // Make the smaller character the group leader.
            if (root1 < root2) {
                parent[root2] = root1;
            } else {
                parent[root1] = root2;
            }
        }

        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = 'a' + findParent(baseStr[i] - 'a');
        }

        return baseStr;
    }
};