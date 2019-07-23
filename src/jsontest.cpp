#include "rapidjson/filereadstream.h"
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "rapidjson/writer.h"
#include "strings.h"
#include "cstring"
using namespace rapidjson;
using namespace std;
int main()
{
FILE* fp = fopen("small.json", "rb"); // non-Windows use "r"
char readBuffer[65536];
FileReadStream is(fp, readBuffer, sizeof(readBuffer));
Document d;
d.ParseStream(is);
std::cout<<d;
fclose(fp);
}