#include "SentenceGenerator.h"

#include <iostream>
#include <random>


SentenceGenerator::SentenceGenerator() :
  m_pronoun("pronoun.txt"),
  m_verb("verb.txt"),
  m_adjective("adjective.txt"),
  m_noun("noun.txt")
{
  std::cout << "Pronoun loaded (" << m_pronoun.size() << ")" << std::endl;
  std::cout << "Verb loaded (" << m_verb.size() << ")" << std::endl;
  std::cout << "Adjective loaded (" << m_adjective.size() << ")" << std::endl;
  std::cout << "Noun loaded (" << m_noun.size() << ")" << std::endl;
}

std::string SentenceGenerator::getSentence()
{

  return m_pronoun.getWord() + " " + m_verb.getWord() + " " + m_adjective.getWord() + " " + m_noun.getWord();
}

