
class WordDictionary {
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root;

    bool dfs(Node* current, string &word, int pos) {
        if (pos == word.size()) {
            return current->isEnd;
        }

        char ch = word[pos];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    if (dfs(current->children[i], word, pos + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        int index = ch - 'a';

        if (current->children[index] == nullptr) {
            return false;
        }

        return dfs(current->children[index], word, pos + 1);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* current = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new Node();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
