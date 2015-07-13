/*********************************************************
   COMP2710: /comp2710/samples/commandline.cpp
   Project 2 auDiskTool Phase 3: Implementation
   This file demonstrate how to parse a commandline
   To extract "type", "flag", and "value" from a commandline,
   you will have to use substr of a string object.
 
   Prototype of substr:
       basic_string substr( size_type pos = 0,
                          size_type count = npos ) const;
   Parameters
   pos	-	position of the first character to include
   count	-	length of the substring
 
   How to test the input_command() function?
   Case 1: help
   Case 2: print conf
   Case 3: set count 50
 
   Xiao Qin <xqin@auburn.edu>
   Samuel Ginn College of Engineering
  Auburn University, AL 36849-5347
  http://www.eng.auburn.edu/~xqin/

  Modified by Connor Jones - caj0006@auburn.edu

*********************************************************/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//If COMMAND_STRING is not defined, the data type of value should be int
#define COMMAND_STRING //comment this line out to make value an int

#ifdef COMMAND_STRING
//This is an earlier version, the data type of value is string
struct command {
  string type;
  string flag;
  string value;
};
#else 
//This is an updated version, the data type of value is int
struct command {
  string type;
  string flag;
  int value;
};
#endif

//Parameters
//cmd: a command entered from a user's keyboard
//return: the number of items in a commandline
short input_command(command& cmd);

//int main () {
//  command test_cmd;
//  int num_of_parameters;
//
//  num_of_parameters = input_command(test_cmd);
//
//  cout << "Number of parameters:" << num_of_parameters << endl;
//  cout << "Type is: " << test_cmd.type << endl;
//  cout << "Flag is: " << test_cmd.flag << endl;
//  cout << "Value is: " << test_cmd.value << endl;
//
//  return 0;
//}

short input_command(command& cmd) {
  string cmdline;
  int position;
  
//  cout << "Enter a commandline below" << endl;
  cout << "> ";
  getline (cin, cmdline);

  //Find command type
  position = cmdline.find(" "); 
  cmd.type = cmdline.substr(0, position);

  //Find command flag; remove type from cmdline
  cmdline = cmdline.substr(position+1);
  
  //If cmdline has a flag
  if (cmdline != cmd.type) {
    position = cmdline.find(" ");
    cmd.flag = cmdline.substr(0, position);

    //remove flag from cmdline; ready to extract value
    cmdline = cmdline.substr(position+1);
    
    //If cmdline has a value
    if (cmdline != cmd.flag) {
#ifdef COMMAND_STRING
      cmd.value = cmdline;
#else
      //Convert string into int for value, whose data type is int
      istringstream value_buffer(cmdline); 
      value_buffer >> cmd.value;
#endif
      return 3; //e.g., set count 15
    }
    //cmdline has no value 
    else {
#ifdef COMMAND_STRING
       cmd.value.clear();
#else 
       cmd.value = 0; //0 indicates that there is no value
#endif
       return 2;
    }
  }
  //cmdline has no flag and no value
  else {
    cmd.flag.clear(); //flag = "";
#ifdef COMMAND_STRING
    cmd.value.clear(); //value = "";
#else
       cmd.value = 0; //0 indicates that there is no value
#endif
    return 1; //e.g., help
  }
} //end of input_command()
