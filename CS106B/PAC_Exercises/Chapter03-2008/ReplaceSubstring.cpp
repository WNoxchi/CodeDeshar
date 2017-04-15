// Wayne H. Noxchi - 30-May-2016 16:24
// helper function

/** Delete substring in str1 from str1[pos] to str1[pos+len], then insert
    str2 at str1[pos]. Modifies str1.       **/

#include <string>

void ReplaceSubstring(string & str1, string str2, int pos, int len){
    str1.erase(pos, len);
    str1.insert(pos, str2);
}

/** Reference:
    http://www.cplusplus.com/reference/string/string/erase/
    http://www.cplusplus.com/reference/string/string/insert/
 **/
