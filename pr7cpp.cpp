#include <iostream>
#include <fstream>
#include <string>

class FileManager {
public:
    void writeToFile(const std::string& filename, const std::string& data) {
        std::ofstream outfile(filename); 
        if (!outfile) {
            std::cerr << "Error opening file for writing: " << filename << std::endl;
            return;
        }
        outfile << data;
        outfile.close(); 
        std::cout << "Data written to file successfully.\n";
    }

    void readFromFile(const std::string& filename) {
        std::ifstream infile(filename); 
        if (!infile) {
            std::cerr << "Error opening file for reading: " << filename << std::endl;
            return;
        }

        std::string line;
        std::cout << "Contents of the file:\n";
        while (std::getline(infile, line)) {
            std::cout << line << std::endl;
        }

        infile.close(); 
    }
};

int main() {
    FileManager fileManager;

    std::string filename = "example.txt";
    std::string data = "Hello, this is a test.\nFileManager is working!";

    
    fileManager.writeToFile(filename, data);

   
    fileManager.readFromFile(filename);

}
/*
output:
Data written to file successfully.
Contents of the file:
Hello, this is a test.
FileManager is working!
*/
