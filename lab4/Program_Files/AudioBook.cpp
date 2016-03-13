#include "AudioBook.h"

ostream& operator<<(ostream &outStream, const AudioBook &audioBookToPrint)
{
  audioBookToPrint.print(outStream);
  return outStream;
}

void AudioBook::print(ostream& outStream) const
{
  outStream << type << ": " << title << " by " << author << " and narrated by " << narrator << " (" << mapQuality(quality) << ") $" << cost << endl;
}

AudioBook::AudioBook()
{
  this->type = "AudioBook";
}
AudioBook::AudioBook(string author): Book(author)
{
  this->type = "AudioBook";
}
AudioBook::AudioBook(string author, string title): Book(author, title)
{
  this->type = "AudioBook";
}
AudioBook::AudioBook(string author, string title, float cost): Book(author, title, cost)
{
  this->type = "AudioBook";
}
AudioBook::AudioBook(string author, string title, float cost, string narrator): Book(author, title, cost)
{
  this->narrator = narrator;
  this->type = "AudioBook";
}
AudioBook::AudioBook(string author, string title, float cost, string narrator, string quality): Book(author, title, cost, quality)
{
  this->narrator = narrator;
  this->type = "AudioBook";
}
AudioBook::~AudioBook()
{
}

string AudioBook::getNarrator() const
{
  return narrator;
}

bool AudioBook::setNarrator(string narrator)
{
  this->narrator = narrator;
}