/*
A C++ program to decode CAN frame message, by considering CAN ID and CAN Frame from command line arguments.

Q What will change in your code if you have to process large amounts of CAN data in
  real time?
  Instead of command line arguments, file reading and writing using getinline and string stream concept can give advantage for larger data sets of CAN data.
  Imagining CAN .dbc files.
*/

// Necessary Preprocessors

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//Standard namespace
using namespace std;
//std::vector<char>::iterator it;
std::vector<char> Id;                                         // A global scoped char vector to store Target ID

/*
DecocdeMsg Function to decode only the Data bytes
and store it in a string type, later to convert Hex to ASCII
*/

void DecodeMsg(char frame[]){
//  printf("Decoding Msg \n");
  std::string msg{""};                                        //Empty String, can be used to concate byte level strings 
  for(short i = 9; frame[i] != '\0'; ++i){
    msg += frame[i];
  }
//  cout << msg << endl;
  string ascii = "";
  for (size_t i = 0; i < msg.length(); i += 2)
  {
    string part = msg.substr(i, 2);                           //Substring function for seperating only 2 char levels each
    char ch = stoul(part, nullptr, 16);                       //Converting from Hex to ASCII 
    ascii += ch;
  }
  cout << "Decoded Data Bytes:  " << ascii << endl;
}



/*
  splitFrame function, performs Data Bytes split as per character '#' 
  and compares the CAN ID and ID in Data Bytes
*/

void splitFrame(char ID[], char frame[]){
  for(char *frameId = frame; *frameId != '#'; ++frameId){
    Id.push_back(*frameId);                                    // Pushing in the form of FIFO
  }

/*  if(*frameId == '#') break;
    for(it = Id.begin(); it != Id.end(); ++it){
    cout << *it << endl;
    }
*/

  if(ID[0] == Id[4] && ID[1] == Id[5]){                        // If the Target ID is matched to ID in Data bytes, calling DecodeMSg function further or gives standard C error
    DecodeMsg(frame);
  }
  else std::cerr << "CAN ID and ID in Message Data Bytes were Different" << endl;
  
}

//The main function, gathers argumets and passes to splitFrame function

int main(int argc, char* argv[]){
  if(argc != 3){                                              //  Warning Info to consider only 2 command line arguments
    printf("Please enter only CANID and CAN Frame\n");
    return 0;
  }
  else{
//    printf("Entered %d Arguments\n", argc);
    splitFrame(argv[1], argv[2]);                             // Passing command line arguments CAN ID and Whole CAN Frame respectively
  }
  return 0;
}
