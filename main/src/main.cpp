#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <thread>

#include "processor/callbacks_functions.hpp"
#include "processor/processor.hpp"

int
main(int argc, char* argv[])
{
  using namespace std::chrono_literals;
  if (argc > 3 || argc == 1) {
    fprintf(stderr, "usage: -s size\n");
    fprintf(stderr, "test: -d\n");
    return EXIT_FAILURE;
  }

  int blockSize = atoi(argv[1]);
  char* IF_DEBUG = argv[2];

  if (!IF_DEBUG && !blockSize) {
    std::vector<std::string> test_data {
        "cmd1\ncmd2\n",
        "{\ncmd3\ncmd4\n}\n",
        "{\ncmd5\ncmd6\n{\ncmd7\ncmd8\n}\ncmd9\n}",
        "\n{\ncmd10\ncmd11"
        "\n"};
    constexpr size_t BLOCKSIZE = 3;

    for (auto& elem : test_data) {
      std::cout << "\ninput data:\n" << elem << "\n";
      std::stringstream InputStream {elem};
      Processor MyProc {BLOCKSIZE, InputStream};
      std::ostream& StreamCout = std::cout;
      Processor::s_SetOutputStream(&StreamCout);
      MyProc.addCallback(&print_to_stdout);
      MyProc.addCallback(&write_to_log);
      MyProc.parseInput();
      std::this_thread::sleep_for(2000ms);
    }
    std::cout << "end of data stream\n";
    return EXIT_SUCCESS;
  }

  if (blockSize <= 0) {
    fprintf(stderr, "block size mush be a positive and greater than zero\n");
    return EXIT_FAILURE;
  }
  Processor MyProc {static_cast<size_t>(blockSize), std::cin};
  std::ostream& StreamCout = std::cout;
  Processor::s_SetOutputStream(&StreamCout);
  MyProc.addCallback(&print_to_stdout);
  MyProc.addCallback(&write_to_log);
  MyProc.parseInput();
  return EXIT_SUCCESS;
}
