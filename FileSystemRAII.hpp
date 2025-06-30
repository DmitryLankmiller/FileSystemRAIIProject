#ifndef FILERAII_HPP
#define FILERAII_HPP

#include <fstream>
#include <string>

class File {
private:
    std::fstream file;
    std::string filePath;
    std::ios_base::openmode mode;

public:
    File(const std::string& path, std::ios_base::openmode openMode);
    ~File();

    void writeLine(const std::string& line);
    std::string readLine();
    bool eof() const;
};

#endif // FILERAII_HPP
