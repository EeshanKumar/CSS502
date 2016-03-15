#include <string>
#include "Book.h"

#ifndef GRAPHICNOVEL_H
#define GRAPHICNOVEL_H

class GraphicNovel: public Book
{
friend ostream& operator<<(ostream &outStream, const GraphicNovel &graphicNovelToPrint);

public:
  GraphicNovel();
  GraphicNovel(string author);
  GraphicNovel(string author, string title);
  GraphicNovel(string author, string title, float cost);
  GraphicNovel(string author, string title, float cost, string artist);
  GraphicNovel(string author, string title, float cost, string artist, string quality);
  ~GraphicNovel();

  string getArtist() const;

  bool setArtist(string artist);

  void print(ostream& outStream) const;

private:
  string artist;
};

#endif //GRAPHICNOVEL_H