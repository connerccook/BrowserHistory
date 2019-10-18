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
  string fileName_;
  string url_;
  size_t filesize_;
  string currentUrl_;
};

BrowserHistory::BrowserHistory() {
  list<BrowserHistory> mylist;
  url_ = "";
  filesize_= 0;
  currentUrl_ = url_;
}
BrowserHistory::visitSite(string url, size_t filesize){
  url_ = url;
  filesize_= filesize;
  BrowserHistory
  mylist.emplace_back()

}
