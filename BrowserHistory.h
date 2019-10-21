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
list<BrowserHistory>::iterator it; //this iterator is the main iterator that goes forward and backwards
list<BrowserHistory>::iterator it2; //this iterator is always pointing towards the end of the list
};

BrowserHistory::BrowserHistory() { //default constructor
  url_ = "";
  filesize_= 0;
  it = mylist.begin();
  it2 = prev(mylist.end());
}
BrowserHistory::BrowserHistory(string url, size_t filesize) : url_(url), filesize_(filesize){} //constructor with parameter
void BrowserHistory::visitSite(string url, size_t filesize){
  while (it!=it2){ //if the iterators are not equal, then history removes the webpages ahead of main iterator
    mylist.pop_back();
    it2 = prev(mylist.end());
  }
  BrowserHistory a = {url, filesize};
  mylist.push_back(a); //back of the node is the most recent visit
  it++; //iterator points to recent node
  it2++;//always follows the last node
}

void BrowserHistory::backButton() {
if (it == mylist.begin()){} // if the iterator is at the beginning of the list, no change
  else {
  it--;
}
}
void BrowserHistory::forwardButton() {
  if (it == prev(mylist.end())) {} // if the iterator is at the end of the list, no change
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
  while (fin >> function) { // reads the first words per line in the file
    if (function == "visit") { //if first word is visit, it runs the visitSitefunction
      fin >> Url >> fileSize;
      visitSite(Url,fileSize);
    } else if (function == "back") { // if first word is back, it runs the backButton function
      backButton();
    } else if (function == "forward") { // if first word is back, it runs the backButton function
      forwardButton();
    }

  }
 
}

size_t BrowserHistory::currentPageSize() {
  size_t pageSize = (*it).filesize_;
  return pageSize;
}

size_t BrowserHistory::getHistoryLength() {
  size_t length = mylist.size();
  return length;
}
