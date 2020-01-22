#include <iostream>
#include <fstream>

#include <tclap/CmdLine.h>

int main(int argc, char **argv) {
  std::ofstream outputFile;

  // Parse arguments
  try {
    TCLAP::CmdLine cmd("Command description message", ' ', "0.1"); // TODO: pipe the version from CMake.
    TCLAP::ValueArg<std::string> outputFileName("o", "", "File to output", false, "out.asm", "filename", cmd);

    cmd.parse(argc, argv);

    std::string outputFileStr = outputFileName.getValue();
    outputFile.open(outputFileStr);

    if (!outputFile.is_open()) {
      std::cerr << "Unable to open file " << outputFileStr << std::endl;

      return 2;
    }
  } catch (TCLAP::ArgException &e) {
    std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;

    return 1;
  }

  std::cout << "Hello World!" << std::endl;
  outputFile << "This is a test output." << std::endl;

  outputFile.close();

  return 0;
}
