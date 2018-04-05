#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <random>


class Words
{
public:
  Words( const std::string& fileName ) 
  {
    std::string line;
    std::ifstream wordsFile( fileName );
    while ( getline( wordsFile, line ) ) {
      m_words.push_back( line );
    }
    wordsFile.close();

    m_dist = std::uniform_int_distribution<int>(1, m_words.size());
  }


  size_t size() const
  {
    return m_words.size();
  }

  std::string getWord()
  {
    if(m_words.size() != 0 )
      return m_words[m_dist(m_rd)];
    return std::string();
  }

private:
  std::vector<std::string> m_words;
  std::random_device m_rd;
  std::uniform_int_distribution<int> m_dist;
};

class SentenceGenerator
{
public:
  SentenceGenerator();
  ~SentenceGenerator() {}

  std::string getSentence();

private:

  Words m_pronoun;
  Words m_verb;
  Words m_adjective;
  Words m_noun;
 
};

