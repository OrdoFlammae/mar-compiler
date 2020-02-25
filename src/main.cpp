#include <iostream>
#include <fstream>

#include <tclap/CmdLine.h>
#include <config.h>

int main(int argc, char **argv) {
  std::ifstream inputFile;
  std::ofstream outputFile;

  // Parse arguments
  try {
    TCLAP::CmdLine cmd("Command description message", ' ', PROJECT_VERSION);
    TCLAP::ValueArg<std::string> outputFileName("o", "", "File to output", false, "out.asm", "filename", cmd);
    TCLAP::UnlabeledValueArg<std::string> inputFileName("inFile", "File to compile", true, "", "filename", cmd);

    cmd.parse(argc, argv);

    std::string inputFileStr = inputFileName.getValue();
    inputFile.open(inputFileStr);

    if (!inputFile.is_open()) {
      std::cerr << "Unable to open file " << inputFileStr << std::endl;

      return 2;
    }

    std::string outputFileStr = outputFileName.getValue();
    outputFile.open(outputFileStr);

    if (!outputFile.is_open()) {
      std::cerr << "Unable to open file " << outputFileStr << std::endl;
      inputFile.close();

      return 2;
    }
  } catch (TCLAP::ArgException &e) {
    std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;

    return 1;
  }

  std::cout << "Hello World!" << std::endl;
  outputFile << "This is a test output." << std::endl;

  inputFile.close();
  outputFile.close();

  return 0;
}
