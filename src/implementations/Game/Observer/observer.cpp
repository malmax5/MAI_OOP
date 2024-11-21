#include "../../../../include/Game/Observer/observer.hpp"

FileLogger::FileLogger(const std::string& filename) : filename(filename) {}

void FileLogger::update(const std::string& event) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << event << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}

void ScreenLogger::update(const std::string& event) {
    std::cout << event << std::endl;
}
