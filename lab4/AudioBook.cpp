#include "AudioBook.h"

ostream& operator<<(ostream &outStream, const AudioBook &audioBookToPrint)
{
  audioBookToPrint.print(outStream);
  return outStream;
}

void AudioBook::print(ostream& outStream) const
{
  outStream << "(" << quality << ") $" << cost << ": " << title << " by " << author << " and narrated by " << narrator << endl;
}

AudioBook::AudioBook()
{
}
AudioBook::AudioBook(string author): Book(author)
{
}
AudioBook::AudioBook(string author, string title): Book(author, title)
{
}
AudioBook::AudioBook(string author, string title, float cost): Book(author, title, cost)
{
}
AudioBook::AudioBook(string author, string title, float cost, string narrator): Book(author, title, cost)
{
  this->narrator = narrator;
}
AudioBook::AudioBook(string author, string title, float cost, string narrator, string quality): Book(author, title, cost, quality)
{
  this->narrator = narrator;
}

string AudioBook::getNarrator() const
{
  return narrator;
}

bool AudioBook::setNarrator(string narrator)
{
  this->narrator = narrator;
}