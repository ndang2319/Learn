#include <iostream>
#include <vector>

class SearchValue
{
public:
  SearchValue(int pos, int val) : position(pos), value(val) {}

  int getPosition() const { return position; }
  int getValue() const { return value; }

private:
  int position;
  int value;
};

class SearchDebugger
{
public:
  SearchDebugger()
  {
    values.push_back(SearchValue(0, 0));   // Start
    values.push_back(SearchValue(11, 11)); // End
    values.push_back(SearchValue(5, 5));   // Middle
    values.push_back(SearchValue(-1, 12)); // Out of List
  }

  int debugSearch(const std::vector<int> &v)
  {
    for (const SearchValue &sv : values)
    {
      int result = search(v, sv.getValue());
      if (result != sv.getPosition())
      {
        return sv.getPosition();
      }
    }
    return 0;
  }

private:
  std::vector<SearchValue> values;

  int search(const std::vector<int> &v, const int searchValue)
  {
    bool isFound = false;
    int start = 0;
    int len = v.size();
    int endValue = v[len - 1];
    if (endValue != searchValue)
    {
      v[len - 1] = searchValue;
      while (v[start] != searchValue)
      {
        start++;
      }
      v[len - 1] = endValue;
      return ((start + 1) % len) - 1;
    }
    else
      return len - 1;
  }
};

int main(int argc, char const *argv[])
{
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  SearchDebugger debugger;

  int result = debugger.debugSearch(v);

  if (result == 0)
  {
    std::cout << "Search Function run successfully";
  }
  else
  {
    std::cout << "Search Function error at position " << result;
  }

  return 0;
}
