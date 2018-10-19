
#include "AVL.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "json.hpp"

using namespace std;
using namespace nlohmann;

int main(int argc, char** argv){
  AVL newT;
  string fn = string(argv[1]);


  ifstream file (fn);
  json J;


  if(file.is_open()){
    //opening file
    file >> J;
  }


  for(auto i = J.begin(); i != J.end(); i++){ //iterate thru
    if(i.key() != "metadata"){
      //std::cout << "not metadata" << std::endl;


      string s1 = J[i.key()]["operation"];

      if(s1 == "Insert"){
        //std::cout << "Insert" << std::endl;
        newT.insertFunct(J[i.key()]["key"]);
      }

    }
  }


  newT.printingFunct();

  //AVLTree tree1;

//  for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
  //for (auto arrayItr = itr.value().begin(); arrayItr != itr.value().end(); ++arrayItr) {
  //std::cout << "TEST" <<  itr.key() << std::endl;
//
  // if (jsonObject[itr.key()]["operation"] == "Insert") {
  //  tree1.Insert(jsonObject[itr.key()]["key"]);
//}
//      /*if (jsonObject[itr.key()]["operation"] == "Delete") {
//        node = delete (node); // FINISH DELETE NODE
//      }
//
//      if (jsonObject[itr.key()]["operation"] == "DeleteMin") {
//        node = deletemin(node);
//      }*/

//tree1.print();

}


