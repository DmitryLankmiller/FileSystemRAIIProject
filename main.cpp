#include "FileSystemRAII.hpp"
#include <iostream>

int main() {
  const std::string hello = "Hello, world!";
  try {
    File writer("example.txt", std::ios::out);
    writer.writeLine(hello);
    std::cout << "Write line: " << hello << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    File reader("example.txt", std::ios::in);
    std::string line = reader.readLine();
    std::cout << "Read line: " << line << "\n";
    std::cout << "Are lines similar? " << ((hello == line) ? "YES" : "NO")
              << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "We're expecting error from next code:"
            << "\n";
  try {
    File bad_writer("bad.txt", std::ios::in);
    bad_writer.writeLine("Bad!");
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}