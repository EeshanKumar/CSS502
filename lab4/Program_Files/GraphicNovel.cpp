#include "GraphicNovel.h"

ostream& operator<<(ostream &outStream, const GraphicNovel &graphicNovelToPrint)
{
  graphicNovelToPrint.print(outStream);
  return outStream;
}

void GraphicNovel::print(ostream& outStream) const
{
  outStream << type << ": " << title << " by " << author << " with art by " << artist << " (" << mapQuality(quality) << ") $" << cost << endl;
}

GraphicNovel::GraphicNovel()
{
  this->type = "GraphicNovel";
}
GraphicNovel::GraphicNovel(string author): Book(author)
{
  this->type = "GraphicNovel";
}
GraphicNovel::GraphicNovel(string author, string title): Book(author, title)
{
  this->type = "GraphicNovel";
}
GraphicNovel::GraphicNovel(string author, string title, float cost): Book(author, title, cost)
{
  this->type = "GraphicNovel";
}
GraphicNovel::GraphicNovel(string author, string title, float cost, string artist): Book(author, title, cost)
{
  this->artist = artist;
  this->type = "GraphicNovel";
}
GraphicNovel::GraphicNovel(string author, string title, float cost, string artist, string quality): Book(author, title, cost, quality)
{
  this->artist = artist;
  this->type = "GraphicNovel";
}
GraphicNovel::~GraphicNovel()
{
}

string GraphicNovel::getArtist() const
{
  return artist;
}

bool GraphicNovel::setArtist(string artist)
{
  this->artist = artist;
}