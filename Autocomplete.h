#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
 private:
  friend class Autocomplete;
  bool isEndOfWord;
  std::unordered_map<char, TrieNode*> children;

 public:
  TrieNode();
};

class Autocomplete {
 private:
  TrieNode* root;
  void searchPrefix(TrieNode* node, std::string prefix,
                    std::vector<std::string>* results);

 public:
  Autocomplete();
  // return the known words that start with partialWord
  std::vector<std::string> getSuggestions(std::string partialWord);
  // add a word to the known words
  void insert(std::string word);
};

#endif