// https://leetcode.com/problems/design-a-text-editor/

class TextEditor
{
    deque<char> prefix, suffix;

public:
    TextEditor()
    {
        prefix.clear(), suffix.clear();
    }

    void addText(string text)
    {
        for (auto c : text)
            prefix.push_back(c);
    }

    int deleteText(int k)
    {
        int len = 0;
        while (!prefix.empty() && k--)
            prefix.pop_back(), len++;
        return len;
    }

    string lastChars()
    {
        string ans;
        int n = min(10, (int)prefix.size());
        for (int i = 0; i < n; i++)
            ans += prefix.back(), prefix.pop_back();
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; i++)
            prefix.push_back(ans[i]);
        return ans;
    }

    string cursorLeft(int k)
    {
        string temp;
        while (!prefix.empty() && k--)
        {
            suffix.push_front(prefix.back());
            prefix.pop_back();
        }
        return lastChars();
    }

    string cursorRight(int k)
    {
        string temp;
        while (!suffix.empty() && k--)
        {
            prefix.push_back(suffix.front());
            suffix.pop_front();
        }
        return lastChars();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */