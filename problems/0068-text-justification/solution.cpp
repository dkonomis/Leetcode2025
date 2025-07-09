#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
    Problem: 0068 - Text Justification

    Given a list of words and a max line width, format the text so that each
    line has exactly maxWidth characters and is fully justified.

    Approach:
    - Greedily group words into lines without exceeding maxWidth.
    - For each line, decide how to distribute spaces:
        - If it's the last line or contains one word → left-justify.
        - Else → distribute spaces as evenly as possible.
    - Use helper functions for modularity.

    Time Complexity: O(n), where n = total number of characters across all words.
    Space Complexity: O(n), for the result list.
    */
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        int n = words.size();

        while (i < n) {
            // Collect words for the current line starting from index i.
            auto[line_words, line_len] = collectLine(words, i, maxWidth);
            i += line_words.size();

            // Check whether we're on the last line.
            bool is_last_line = (i == n);

            // Justify the collected line accordingly.
            string line = justifyLine(line_words, line_len, maxWidth, is_last_line);

            // Add the justified line to the result list.
            res.push_back(line);
        }

        return res;
    }

private:
    // Helper to collect words into a line without exceeding maxWidth.
    pair<vector<string>, int> collectLine(const vector<string>& words, int start, int maxWidth) {
        vector<string> line_words;
        int total_len = 0;
        int i = start;

        while (i < words.size()) {
            int word_len = words[i].length();
            // Check if adding this word would exceed maxWidth (account for spaces).
            if (total_len + line_words.size() + word_len > maxWidth) {
                break;
            }
            line_words.push_back(words[i]);
            total_len += word_len;
            i++;
        }

        return {line_words, total_len};
    }

    // Helper to justify a single line.
    string justifyLine(const vector<string>& line_words, int line_len, int maxWidth, bool is_last_line) {
        if (is_last_line || line_words.size() == 1) {
            // For the last line or single-word line, we left-justify.
            // Join words with a single space and pad the end.
            string line;
            for (int i = 0; i < line_words.size(); ++i) {
                if (i > 0) line += ' ';
                line += line_words[i];
            }
            line += string(maxWidth - line.length(), ' ');
            return line;
        }

        // Compute number of spaces to distribute.
        int num_spaces = maxWidth - line_len;
        int slots = line_words.size() - 1;
        int even_space = num_spaces / slots;
        int extra_space = num_spaces % slots;

        string justified;
        for (int i = 0; i < slots; ++i) {
            justified += line_words[i];
            // Add one extra space to the first 'extra_space' slots.
            int spaces = even_space + (i < extra_space ? 1 : 0);
            justified += string(spaces, ' ');
        }

        // Append the last word without extra spaces after.
        justified += line_words.back();
        return justified;
    }
};

