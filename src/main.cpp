#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits>

using namespace std;

//Flag values
bool f_verbose = false; //verbose mode
bool f_sumMode = false; //summation mode
bool f_avgMode = false; //mean mode
bool f_varMode = false; //variance mode
bool f_stdMode = false; //standard deviation mode
string delimiter = " ";

vector<string> split(string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    return arr;
}

void displayVersion(){
    cout << "\033[1;37mast\033[0m ";
    cout << %VERSION; //To be replaced by compile script
    cout << ", by Martín del Río (2018)" << endl;
    cout << "Building date: ";
    cout << %COMPILEDATE << endl; //To be replaced by script
    cout << "Repository: <https://github.com/lartu/ast>." << endl;
}

void displayHelp(){
    cout << "Usage: ast OPTION [delimiter]" << endl << endl;
    cout << "  -a, -m, --avg, --mean" << endl;
    cout << "\tOutput average / mean of all numbers in data passed through stdin." << endl;
    cout << "  -s, --sum" << endl;
    cout << "\tOutput sum of all numbers in data passed through stdin." << endl;
    cout << "  -v, --var" << endl;
    cout << "\tOutput variance of all numbers in data passed through stdin." << endl;
    cout << "  -d, --dev" << endl;
    cout << "\tOutput standard deviation of all numbers in data passed through stdin." << endl;
    cout << "  -h, --help" << endl;
    cout << "\tPrints this help and exits." << endl;
    cout << "  --version" << endl;
    cout << "\tPrints version information." << endl;
    cout << endl;
    displayVersion();
}

void check_flags(const vector<string> & args){
    for(int i = 0; i < args.size(); ++i){
        if(args[i] == "-h" || args[i] == "--help"){
            displayHelp();
            exit(0);
        }
        else if(args[i] == "--version"){
            displayVersion();
            exit(0);
        }
        else if(args[i] == "-a" || args[i] == "--avg" || 
           args[i] == "-m" || args[i] == "--mean"){
            f_avgMode = true;
            f_sumMode = f_varMode = f_stdMode = false;
        }
        else if(args[i] == "-s" || args[i] == "--sum"){
            f_sumMode = true;
            f_avgMode = f_varMode = f_stdMode = false;
        }
        else if(args[i] == "-v" || args[i] == "--var"){
            f_varMode = true;
            f_sumMode = f_avgMode = f_stdMode = false;
        }
        else if(args[i] == "-d" || args[i] == "--dev"){
            f_stdMode = true;
            f_sumMode = f_avgMode = f_varMode = false;
        }
        else {
            delimiter = args[i];
        }
    }
}

int main(int argc, char** argv){    
    // - Turn argument array into a vector of strings -
    vector<string> args(argv, argv + argc);
    
    // - Check for flags and load files and exit on error -
    check_flags(args);
    
    // - If no output mode was choosen -
    if(f_avgMode == f_sumMode == f_stdMode == f_varMode){
        displayHelp();
        exit(0);
    }
    
    // - Get stdin and calculate average -
    long double sum = 0;
    long long int total_numbers = 0;
    vector<long double> numbers;
    string input_line;
    while(getline(cin, input_line)){
        vector<string> line_tokens = split(input_line, delimiter);
        for(string token : line_tokens){
            try {
                cout << stod(token) << endl;
                sum += stod(token);
                ++total_numbers;
                // - If we are on standard deviation mode store numbers -
                if(f_stdMode || f_varMode){
                    numbers.push_back(stod(token));
                }
            } catch (const std::invalid_argument&) {
                //Nothing here, just checking.
            }
        }
    }
    
    // - Set cout precision -
    cout.precision(numeric_limits<long double>::digits10);
    
    // - If we are in sum mode, output sum and exit -
    if(f_sumMode || total_numbers == 0){
        cout << sum << endl;
        exit(0);
    }
    
    // - Calculate mean -
    long double mean = (sum / total_numbers);
    
    // - If we are in average mode, output mean and exit -
    if(f_avgMode){
        cout << mean << endl;
        exit(0);
    }
    
    // - Calculate variance -
    long double variance = 0;
    for(long double num : numbers){
        variance += pow((num - mean), 2);
    }
    variance = variance / (total_numbers - 1);
    
    // - If we are in variance mode, output variance and exit -
    if(f_varMode){
        cout << variance << endl;
        exit(0);
    }
    
    // - If we are in std. dev. mode sqrt variance, output and exit -
    if(f_stdMode){
        cout << sqrt(variance) << endl;
        exit(0);
    }
    
    return 0;
}
