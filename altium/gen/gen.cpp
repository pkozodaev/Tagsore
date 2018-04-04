#include <fstream>
#include <iostream>

const size_t FILESIZE = 10 * 1024 * 1024; // 10 MB

int main()
{
  std::fstream f("big_text_file.txt", f.out | f.trunc);
  if (!f.is_open()) {
    std::cout << "failed to open file\n";
  }

  size_t filesize = 0;

  while(filesize < FILESIZE)
  {
    f << "1. test " << std::endl;
    filesize = f.tellg();
  }

  std::cout << "size = " << f.tellg() << std::endl;
  f.close();

  return 0;
}
