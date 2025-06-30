#include "FileSystemRAII.hpp"
#include <stdexcept>

File::File(const std::string &path, std::ios_base::openmode openMode)
    : filePath(path), mode(openMode) {
  file.open(filePath, mode);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath);
  }
}

File::~File() {
    if (file.is_open()) {
        file.close();
    }
}

void File::writeLine(const std::string& line) {
    if (!(mode & std::ios::out)) {
        throw std::runtime_error("File openned not for writing");
    }

    file << line << "\n";
    if (file.fail()) {
        throw std::runtime_error("Got error while writting to file: " + filePath);
    }
}

std::string File::readLine() {
    if (!(mode & std::ios::in)) {
        throw std::runtime_error("File openned not for reading");
    }

    std::string line;
    if (std::getline(file, line).fail()) {
        if (file.eof()) {
            return "";
        }
        throw std::runtime_error("Got error while reading from file: " + filePath);
    }

    return line;
}

bool File::eof() const {
    return file.eof();
}
