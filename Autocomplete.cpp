#include "Autocomplete.h"

TrieNode::TrieNode() { isEndOfWord = false; }

Autocomplete::Autocomplete() { root = new TrieNode(); }

void Autocomplete::insert(std::string word) {
  TrieNode* current = root;
  for (auto c : word) {
    if (current->children.find(c) == current->children.end()) {
      TrieNode* newNode = new TrieNode();
      current->children.insert({c, newNode});
    }
    current = current->children.find(c)->second;
  }
  current->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
  std::vector<std::string> results;
  TrieNode* current = root;
  std::string traverseUntil = "";
  for (auto c : partialWord) {
    if (current->children.find(c) == current->children.end()) {
      break;
    } else {
      traverseUntil += c;
      current = current->children.find(c)->second;
    }
  }
  if (traverseUntil == partialWord) {
    if (current->isEndOfWord) {
      results.push_back(traverseUntil);
    }
    for (auto pair : current->children) {
      std::string new_prefix = partialWord + pair.first;
      TrieNode* new_node = pair.second;
      searchPrefix(new_node, new_prefix, &results);
    }
  }
  return results;
}

void Autocomplete::searchPrefix(TrieNode* node, std::string prefix,
                                std::vector<std::string>* results) {
  if (node->isEndOfWord) {
    results->push_back(prefix);
  }
  for (auto pair : node->children) {
    std::string new_prefix = prefix + pair.first;
    TrieNode* new_node = pair.second;
    searchPrefix(new_node, new_prefix, results);
  }
}