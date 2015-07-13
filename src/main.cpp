#include <iostream>
#include "config_info.h"
#include "report.h"
#include "commandline_version2.cpp"

using namespace std;

//declaring functions
void launch();
void printHelp();

// global variables
command inputCommand;


const string version = "1.0.0";

int main() {

    launch();

//    cout << "auDiskTool, version " << version << ". Type ‘help’ to find more about commands.";

//    input_command(inputCommand);

//    cout << "Type is: " << inputCommand.type << endl;
//    cout << "Flag is: " << inputCommand.flag << endl;
//    cout << "Value is: " << inputCommand.value << endl;

    return 0;
}

void launch(){
    cout << "auDiskTool, version " << version << ". Type 'help' to find more about commands.\n\n";

    while(1) {

        input_command(inputCommand);
        string type = inputCommand.type;
        string flag = inputCommand.flag;
        string value = inputCommand.value;

        if(type == "run" && flag == ""){
            cout << "run the program.\n";
        }

        else if(type == "set") {

            if(flag == "report") {
                cout << "update report file name.\n";
            }

            else if (flag == "interval" || flag == "count") {
                //convert value to int
                //todo: need catch in case value is not a number. Error is currently thrown and program exits
                int value = stoi(inputCommand.value);

                if (value < 1) {
                    cout << "Please enter a valid command.\n";
                }
                else if (flag == "interval") {
                    cout << "Execute setInterval(" << value << ") method.\n";
                }
                else if (flag == "count") {
                    cout << "Execute setCount(" << value << ") method.\n";
                }
            }
            else if(flag == "blk_read"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_read(" << value << ") method.\n";
                }
            }
            else if(flag == "blk_read/s"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_reads(" << value << ") method.\n";
                }
            }
            else if(flag == "kb_read/s"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setKb_reads(" << value << ") method.\n";
                }
            }
            else if(flag == "blk_write"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_write(" << value << ") method.\n";
                }
            }
            else if(flag == "blk_write/s"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_writes(" << value << ") method.\n";
                }
            }
            else if(flag == "kb_write"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setKb_write(" << value << ") method.\n";
                }
            }
            else {
                cout << "Please enter a valid command. Type 'help' to see commands.\n";
            }
        }
        else if(type == "print"){

            if(flag == "conf"){
                cout << "Execute printConfig() method\n";
            }

            else if(flag == "report"){
                cout << "Execute printReport() method\n";
            }

            else {
                cout << "Please enter a valid command. Type 'help' to see commands.\n";
            }
        }
        else if(type == "exit"){
            cout << "Exiting..\n";
            exit(0);
        }

        else if(type == "help"){
            printHelp();
        }

        else if(type == "save") {
            cout << "save config settings.\n";
        }
        else {
            cout << "Please enter a valid command. Type 'help' to see commands.\n";
        }

    }

}

void printHelp(){
    cout << "run - run the monitoring tool.\n"
            "set interval [value] – set sampling period to [value]\n"
            "set count [value] – set the number of records to [value]\n"
            "set report [name] – set report file name to [name]\n"
            "set blk_read [0|1] – set print_blk_read to 0 or 1\n"
            "set blk_read/s [0|1] – set print_blk_read/s to 0 or 1\n"
            "set kb_read/s [0|1] – set print_kb_read/s to 0 or 1\n"
            "set blk_write [0|1] – set print_blk_write to 0 or 1\n"
            "set blk_write/s [0|1] – set print_blk_write/s to 0 or 1\n"
            "set kb_write [0|1] – set print_kb_write to 0 or 1\n"
            "print conf – display all the parameters\n"
            "print report – open and display the report file\n"
            "save – the configuration file audisktool.conf is updated\n"
            "exit – exit the tool.\n\n";
}