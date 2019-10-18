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

    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
  // TO BE COMPLETED

  string url_;
  size_t filesize_;

};

BrowserHistory::BrowserHistory() {
  url_ = "";
  filesize_= 0;
  list<BrowserHistory> mylist = {url_,filesize_};
  list<BrowserHistory>::iterator it = mylist.begin(); //main iterator
}
void BrowserHistory::visitSite(string url, size_t filesize){
  url_ = url;
  filesize_= filesize;
  BrowserHistory visited = {url_,filesize_};
  mylist.emplace_back(visit); //back of the node is the most recent visit
  if (it->url_== "") { //if browserHistory was empty, pop the "empty" node
    mylist.pop_front();
    it = mylist.begin();
  } else {
  it++; //iterator points to recent node
}
list<BrowserHistory>::iterator it2 = mylist.back(); //secondary iterator to delete history
 while (it2!=it) { //if the main iterator is not in the back of the list, pop every node after
   pop_back();
   it2 = mylist.back();
 }
}
void BrowserHistory::backButton() {
if (it == mylist.begin()){} // if the iterator is at the beginning of the list, no change
  else {
  it--;
}
}
void BrowserHistory::forwardButton() {
  if (it == mylist.begin()) {} // if the iterator is at the beginning of the list, no change
  else {
    it++;
  }
}
string BrowserHistory::currentUrl() {
  string currentUrl = it -> url_;
  return currentUrl;
}
void BrowserHistory::readFile(string fileName) {
  ifstream fin(fileName);
  string Url, function;
  size_t fileSize;
  
}
