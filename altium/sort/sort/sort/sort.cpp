// sort.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int g_blockSize = 10 * 1024;

class Record
{
public:
  Record( const std::string& val )
  {
    auto pos = val.find_first_of( '.' );
    m_idx = stol( val.substr( 0, pos ) );
    m_str = val.substr( pos + 2 );
  }

  friend bool operator< ( const Record& lhs, const Record& rhs )
  {
    if ( lhs.m_str == rhs.m_str )
      return lhs.m_idx < rhs.m_idx;
    else
      return  lhs.m_str < rhs.m_str;
  }

  std::string toStr() const
  {
    return std::to_string(m_idx) + ". " + m_str;
  }
private:
  long m_idx;
  std::string m_str;
};

void sortAndWrite( std::vector<Record>& records, std::ofstream& outputFile )
{
  std::sort( records.begin(), records.end() );
  for ( auto record : records )
  {
    outputFile << record.toStr() << std::endl;
  }
}

int main()
{
  std::ifstream inputFile( "gen.txt");

  std::string line;
  size_t idx = 0;
  std::ofstream outputFile( "p1_" + std::to_string(idx) + ".sort" );
  long prevBlockEnd = 0;
  long currentFilePos;
  std::vector<Record> records;
  while ( std::getline( inputFile, line ) )
  {
    
    records.push_back( line );
    currentFilePos = inputFile.tellg();
    if ( currentFilePos - prevBlockEnd > g_blockSize )
    {
      sortAndWrite( records, outputFile );
      outputFile.close();
      records.clear();
      prevBlockEnd = currentFilePos;
      ++idx;
      outputFile.open( "p1_" + std::to_string( idx ) + ".sort" );
    }
  }

  sortAndWrite( records, outputFile );
  outputFile.close();
  records.clear();



  return 0;
}

