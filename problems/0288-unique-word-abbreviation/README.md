# 0288. Unique Word Abbreviation

**Difficulty**: Medium

**Link**: LeetCode 288

---

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

    a) it                        --> it    (no abbreviation)

         1
         ↓
    b) d|o|g                     --> d1g

                  1    1  1
         1---5----0----5--8
         ↓   ↓    ↓    ↓  ↓    
    c) i|nternationalizatio|n  --> i18n

                  1
         1---5----0
         ↓   ↓    ↓
    d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Implement the `ValidWordAbbr` class:

* `ValidWordAbbr(String[] dictionary)` Initializes the object with a `dictionary` of words.
* `boolean isUnique(String word)` Returns `true` if **either** of the following conditions are met (otherwise returns `false`):
    * There is no word in `dictionary` whose abbreviation is equal to `word`'s abbreviation.
    * For any word in `dictionary` whose abbreviation is equal to `word`'s abbreviation, that word and `word` are **the same**.

**Example:**

    **Input**
    ["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique"]
    [[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"]]
    **Output**
    [null, false, true, false, true]

    **Explanation**
    ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);
    validWordAbbr.isUnique("dear"); // return false, dictionary word "deer" and word "dear" have the same abbreviation "d2r" but are not the same.
    validWordAbbr.isUnique("cart"); // return true, no words in the dictionary have the abbreviation "c2t".
    validWordAbbr.isUnique("cane"); // return false, dictionary word "cake" and word "cane" have the same abbreviation "c2e" but are not the same.
    validWordAbbr.isUnique("make"); // return true, no words in the dictionary have the abbreviation "m2e".

**Constraints:**

* `1 <= dictionary.length <= 3 * 10^4`
* `1 <= dictionary[i].length <= 20`
* `dictionary[i]` consists of lowercase English letters.
* `1 <= word.length <= 20`
* `word` consists of lowercase English letters.
* At most `5000` calls will be made to `isUnique`.
