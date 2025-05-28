#include "DocumentManager.h"

#include <iostream>

Document::Document() {}

Document::Document(std::string name, int license_limit)
    : name(name), license_limit(license_limit), num_used_license(0) {};

DocumentManager::DocumentManager() {}

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
  if (documents.find(id) != documents.end()) {
    return;
  }
  documents[id] = Document(name, license_limit);
}

void DocumentManager::addPatron(int patronID) { patronIDs.insert(patronID); }

int DocumentManager::search(std::string name) {
  for (auto i = documents.begin(); i != documents.end(); i++) {
    if (i->second.name == name) {
      return i->first;
    }
  }
  return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (patronIDs.find(patronID) == patronIDs.end()) {
    return false;
  } else {
    if (documents.find(docid) == documents.end()) {
      return false;
    } else {
      if (documents.find(docid)->second.license_limit >
          documents.find(docid)->second.num_used_license) {
        documents.find(docid)->second.num_used_license++;
        return true;
      } else {
        return false;
      }
    }
  }
}

void DocumentManager::returnDocument(int docid, int patronID) {
  if (patronIDs.find(patronID) == patronIDs.end()) {
    return;
  } else {
    if (documents.find(docid) == documents.end()) {
      return;
    }
    if (documents.find(docid)->second.num_used_license > 0) {
      documents.find(docid)->second.num_used_license--;
    }
  }
}

void DocumentManager::print() {
  for (auto i = documents.begin(); i != documents.end(); i++) {
    std::cout << i->first << " ";
    std::cout << i->second.name << " ";
    std::cout << i->second.license_limit << " ";
    std::cout << i->second.num_used_license << std::endl;
  }
  for (auto i = patronIDs.begin(); i != patronIDs.end(); i++) {
    std::cout << *i << std::endl;
  }
}
