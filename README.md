# FileSystemRAIIProject

Small libray for working with file system

## Available commands

- Open file with <code>File()</code> constructor
- Read line from file with <code>readLine()</code>
- Write line to file with <code>writeLine()</code>
- Check end of file with <code>eof()</code>
- Auto-closing file when calling <code>File</code> destructor

## Build the project
```bash
mkdir build
cd build
cmake ..
make
./file_demo
```