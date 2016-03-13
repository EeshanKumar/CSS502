#include "Book.h"

#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

class AudioBook: public Book
{
friend ostream& operator<<(ostream &outStream, const AudioBook &audioBookToPrint);

public:
  AudioBook();
  AudioBook(string author);
  AudioBook(string author, string title);
  AudioBook(string author, string title, float cost);
  AudioBook(string author, string title, float cost, string narrator);
  AudioBook(string author, string title, float cost, string narrator, string quality);
  ~AudioBook();

  string getNarrator() const;

  bool setNarrator(string narrator);

  void print(ostream& outStream) const;

private:
  string narrator;
};

#endif //AUDIOBOOK_H