
class Solution {
public:
    struct Node {
        unordered_map<string, Node*> children;
        string serial;
        bool deleted = false;
    };

    Node* root = new Node();
    unordered_map<string, int> freq;

    string dfs(Node* node) {
        if (node->children.empty()) {
            return "";
        }

        vector<string> parts;

        for (auto& [name, child] : node->children) {
            parts.push_back(name + "(" + dfs(child) + ")");
        }

        sort(parts.begin(), parts.end());

        string s = "";
        for (string& part : parts) {
            s += part;
        }

        node->serial = s;
        freq[s]++;

        return s;
    }

    void mark(Node* node) {
        if (!node->serial.empty() && freq[node->serial] > 1) {
            node->deleted = true;
        }

        for (auto& [name, child] : node->children) {
            mark(child);
        }
    }

    void collect(Node* node, vector<string>& path,
                 vector<vector<string>>& ans) {
        for (auto& [name, child] : node->children) {
            if (child->deleted) {
                continue;
            }

            path.push_back(name);
            ans.push_back(path);

            collect(child, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(
        vector<vector<string>>& paths) {

        for (auto& path : paths) {
            Node* node = root;

            for (string& name : path) {
                if (!node->children.count(name)) {
                    node->children[name] = new Node();
                }

                node = node->children[name];
            }
        }

        dfs(root);
        mark(root);

        vector<vector<string>> ans;
        vector<string> path;

        collect(root, path, ans);

        return ans;
    }
};
