class Solution
{
public:
  vector<string> reorderLogFiles(vector<string> &logs)
  {
    // std::stable_sort() rather than std::sort() so equal items retain their original order
    std::stable_sort(logs.begin(), logs.end(), myCmp);
    return logs;
  }

  // Return bool value indicates whether the first argument is considered to go before the second
  static bool myCmp(const string &str1, const string &str2)
  {
    const char *ident1 = str1.c_str();
    const char *ident2 = str2.c_str();
    const char *data1 = strstr(ident1, " ") + 1;
    const char *data2 = strstr(ident2, " ") + 1;

    if (isdigit(*data1) && isdigit(*data2))
      return false;
    else if (isdigit(*data1))
      return false;
    else if (isdigit(*data2))
      return true;

    // compare data
    int diff = strcmp(data1, data2);
    if (diff)
      return diff < 0;

    // compare leading identifiers on tie
    return strcmp(ident1, ident2) < 0;
  }
};
