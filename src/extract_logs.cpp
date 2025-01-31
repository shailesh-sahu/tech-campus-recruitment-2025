#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void extract_logs(const string& date) {
   
    string input_file = "test_logs.log";  
    string output_dir = "../output";  
    string output_file = output_dir + "/output_" + date + ".txt";  

    
    fs::create_directories(output_dir);

    ifstream infile(input_file);
    ofstream outfile(output_file);

    if (!infile.is_open()) {
        cerr << "Error: Could not open input file at " << input_file << endl;
        return;
    }
    if (!outfile.is_open()) {
        cerr << "Error: Could not create output file at " << output_file << endl;
        return;
    }

    string line;
    bool found = false;  

    while (getline(infile, line)) {
        if (line.rfind(date, 0) == 0) {  
            outfile << line << '\n';
            found = true;
        }
    }

   
    infile.close();
    outfile.close();

    
    if (!found) {
        fs::remove(output_file);
        cout << "No logs found for " << date << "." << endl;
    } else {
        cout << "Logs for " << date << " saved to " << output_file << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./extract_logs YYYY-MM-DD" << endl;
        return 1;
    }

    extract_logs(argv[1]);
    return 0;
}
