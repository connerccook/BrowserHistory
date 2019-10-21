#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev
#include <list>
using std::string;
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();
    BrowserHistory(string url, size_t filesize);
    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
  // TO BE COMPLETED
list<BrowserHistory> mylist;
  string url_;
  size_t filesize_;
list<BrowserHistory>::iterator it;
list<BrowserHistory>::iterator it2;
};


//list<BrowserHistory>::iterator it2 = prev(mylist.end());
BrowserHistory::BrowserHistory() {
  url_ = "";
  filesize_= 0;
  it = mylist.begin();
  it2 = prev(mylist.end());
  //list<BrowserHistory> mylist;
  //list<BrowserHistory>::iterator it = mylist.begin(); //main iterator
}
BrowserHistory::BrowserHistory(string url, size_t filesize) : url_(url), filesize_(filesize){}
void BrowserHistory::visitSite(string url, size_t filesize){
  BrowserHistory a = {url, filesize};
  mylist.push_back(a); //back of the node is the most recent visit
  it++; //iterator points to recent node
  it2++;
while (it!=prev(mylist.end())) { //if the main iterator is not in the back of the list, pop every node after
  mylist.pop_back();
  it2 = prev(mylist.end());
}
}

void BrowserHistory::backButton() {
if (it == mylist.begin()){} // if the iterator is at the beginning of the list, no change
  else {
  it--;
}
}
void BrowserHistory::forwardButton() {
  if (it == prev(mylist.end())) {} // if the iterator is at the beginning of the list, no change
  else {
    it++;
  }
}
string BrowserHistory::currentUrl() {
  string currentUrl = (*it).url_;
  return currentUrl;
}
void BrowserHistory::readFile(string fileName) {
  ifstream fin(fileName);
  string Url, function;
  size_t fileSize;
  while (fin >> function) {
    if (function == "visit") {
      fin >> Url >> fileSize;
      visitSite(Url,fileSize);
    } else if (function == "back") {
      backButton();
    } else if (function == "forward") {
      forwardButton();
    }

  }
  /*while (fin>>function>>Url>>fileSize) {
    if (function == "visit") {
      visitSite(Url,fileSize);
    } else if (function == "back") {
      backButton();
    } else if (function == "forward") {
      forwardButton();
    }
  } */
}

size_t BrowserHistory::currentPageSize() {
  size_t pageSize = (*it).filesize_;
  return pageSize;
}

size_t BrowserHistory::getHistoryLength() {
  size_t length = mylist.size();
  return length;
}
