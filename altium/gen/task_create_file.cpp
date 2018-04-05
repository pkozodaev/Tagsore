// task_create_file.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <random>
#include <limits>
#include <sstream>

#include "SentenceGenerator.h"

int main(int argc, char* argv[])
{
  if (argc != 2) return -1;
  auto fileSize = std::atol(argv[1]) * 1024 * 1024;
  std::ofstream of( "testfile.txt" );
  
  std::random_device rd;
  std::mt19937 mt( rd() );
  std::uniform_int_distribution<int> dist( 1, std::numeric_limits<int>::max() );

  SentenceGenerator gen;

  while( true )
  {
    auto sentence = gen.getSentence();
    of << dist( mt ) << ". " << sentence << std::endl;
    of << dist( mt ) << ". " << sentence << std::endl;
    auto currentFileSize = of.tellp();
    if ( currentFileSize > fileSize )
      break;
  }

  return 0;
}

