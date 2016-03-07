#include "GraphicNovel.h"

ostream& operator<<(ostream &outStream, const GraphicNovel &graphicNovelToPrint)
{
  graphicNovelToPrint.print(outStream);
  return outStream;
}

void GraphicNovel::print(ostream& outStream) const
{
  outStream << "Author: " << author << endl;
  outStream << "Title: " << title << endl;
  outStream << "Artist: " << artist << endl;
  outStream << "Cost: $" << cost << endl;
  outStream << "Quality: " << quality << endl;
}

GraphicNovel::GraphicNovel()
{
}
GraphicNovel::GraphicNovel(string author): Book(author)
{
}
GraphicNovel::GraphicNovel(string author, string title): Book(author, title)
{
}
GraphicNovel::GraphicNovel(string author, string title, float cost): Book(author, title, cost)
{
}
GraphicNovel::GraphicNovel(string author, string title, float cost, string artist): Book(author, title, cost)
{
  this->artist = artist;
}
GraphicNovel::GraphicNovel(string author, string title, float cost, string artist, string quality): Book(author, title, cost, quality)
{
  this->artist = artist;
}

string GraphicNovel::getArtist() const
{
  return artist;
}

bool GraphicNovel::setArtist(string artist)
{
  this->artist = artist;
}