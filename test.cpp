#include <regex>
#include <string>
#include <iostream>

using namespace std;

time_t timeConverter(std::string text)
{
    struct tm _tm;
    sscanf(text.c_str(), "%d-%d-%d %d:%d", &_tm.tm_year, &_tm.tm_mon,
           &_tm.tm_mday, &_tm.tm_hour, &_tm.tm_min);
    _tm.tm_sec = 0;
    _tm.tm_isdst = false;
    _tm.tm_year += 100;

    return text.empty() ? (time_t) 0 : mktime(&_tm);
}

int main(){
    // string time_text1 = "22-01-14 07:19";
    // string time_text2 = "2022-01-14 07:19";

    // regex time_regex("\\d{4}-\\d{2}-\\d{2}\\ ([0-1][0-9]|2[0-3]):[0-5][0-9]");

    // auto result = regex_search(time_text2, time_regex);
    // cout << result << endl;
    cout << timeConverter("22-02-08 09:53:01") << endl;
    cout << timeConverter("22-02-08 09:53") - timeConverter("22-02-08 08:05")<< endl;
    return 0;
}