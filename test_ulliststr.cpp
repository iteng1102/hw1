#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_front("hi");
  dat.push_front("hii");
  dat.push_front("hiii");
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
  dat.push_front("6");
  dat.push_back("10");
  dat.pop_back();

  ULListStr dat1;
  //std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};
  for (int i = 50; i>=0; i--){
    dat1.pop_front();
  }
  //std::cout << dat1.get(0) << std::endl;


}
