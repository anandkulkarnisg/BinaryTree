#include<iostream>
#include<string>

using namespace std;

#ifndef Converters_H
#define Converters_H

// A converter function that helps the serialization functions do proper data conversion while loading data stored on disk from string.
template<typename T> T converter(const string& ref)
{
  return(static_cast<T>(ref));
}

template<> inline int converter(const string& ref)
{
  return(stoi(ref));
}
template<> inline long converter(const string& ref)
{
  return(stol(ref));
}
template<> inline float converter(const string& ref)
{
  return(stof(ref));
}
template<> inline char converter(const string& ref)
{
  return(char(ref[0]));
}
template<> inline size_t converter(const string& ref)
{
  return(stoul(ref));
}
template<> inline const char* converter(const string& ref)
{
 return(ref.c_str());
}
template<> inline string converter(const string& ref)
{
  return(ref);
}

template<typename T> constexpr T defaultVal = T(FLT_MIN);
template<> inline constexpr int defaultVal<int> = INT_MIN;
template<> inline constexpr float defaultVal<float> = FLT_MIN;
template<> inline constexpr long defaultVal<long> = LONG_MIN;
template<> inline constexpr char defaultVal<char> = '!';
template<> inline constexpr size_t defaultVal<size_t> = ULONG_MAX;
template<> inline constexpr const char* defaultVal<const char*> = "$%#$%#$";
template<> inline string defaultVal<string> = "$%#$%#$";

#endif
