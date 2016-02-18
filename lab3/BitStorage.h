#include <vector>
using namespace std;

class BitStorage
{
public:

//Constructors + Destructors
  BitStorage();
  ~BitStorage();

//Public Functions
  bool AddBits(unsigned short numBits, int bitEncoding);



//Operator Overloads


private:
  vector<int> storedInts;
  char bitsStoredInCurrentInt = 0;
};


BitStorage::BitStorage()
{
}

BitStorage::~BitStorage()
{
}
