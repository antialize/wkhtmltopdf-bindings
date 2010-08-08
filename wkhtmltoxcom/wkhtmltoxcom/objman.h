#ifndef __objman_h__
#define __objman_h__
#include <vector>
#include <map>


template <typename T>
class ObjMan {
public:
  std::vector<int> free;
  std::vector<T*> objects;

  inline T * get(size_t number) {
    if (number < 0 || number >= objects.size()) return 0;
    return objects[number];
  }

  inline int set(T * e) {
    int number;
    if (free.size() == 0) {
      objects.push_back(e);
      number  = objects.size()-1;
    } else {
      number = free.back();
      free.pop_back();
      objects[number] = e;
    }
    return number;
  }

  inline void unset(int number) {
    if (objects[number] == 0) return;
    objects[number] = 0;
    free.push_back(number);
  }
};




template <typename T, typename T2>
class ObjMan2 {
public:
  std::vector<int> free;
  std::vector<std::pair<T*,T2*> > objects;
  std::map<T*, int> rev;

  inline T * get(size_t number) {
    if (number < 0 || number >= objects.size()) return 0;
    return objects[number].first;
  }

  inline T2* get2(size_t number) {
    if (number < 0 || number >= objects.size()) return 0;
    return objects[number].second;
  }

  inline int set(T * e, T2 * o) {
    int number;
    if (free.size() == 0) {
      objects.push_back( std::make_pair(e,o));
      number  = objects.size()-1;
    } else {
      number = free.back();
      free.pop_back();
      objects[number] = std::make_pair(e,o);;
    }
    rev[e] = number;
    return number;
  }

  inline void unset(int number) {
    if (objects[number].first == 0) return;
    objects[number].first = 0;
    free.push_back(number);
  }
};

#endif