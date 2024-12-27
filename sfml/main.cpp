#include "STreaderLib.hpp"
#include <fstream>
#include <termios.h>
#include <stdio.h>
#include <filesystem>
#include <unistd.h>
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}


int main(int argc, char* argv[]){
std::filesystem::path pa = argv[1];

    if(pa.extension() == ".stai") {
        
    std::string f;
    std::string len;
    std::string del;
    int pos;
    std::string token = "";
    std::fstream y(argv[1]);
	std::string loops;
y >> f;
pos = f.find('(');
bool loop = f.find(".l") != f.npos;
if (loop){
loops = f;
}
for(pos++; f.at(pos) != ')'; pos++) {
token += f.at(pos);
}
len = token;
token = "";

pos = f.find('<');
for(pos++; f.at(pos) != '>'; pos++) {
token += f.at(pos);
}
del = token;
token = "";
while (loop) {
for (int i = 0; i < atoi(len.c_str());i++) {

system("clear");
ReturnImage(f);
usleep(atoi(del.c_str())*1000);
f.erase(0, f.find("endendend")+9);
}
f=loops;
}
for (int i = 0; i < atoi(len.c_str());i++) {

ReturnImage(f);
usleep(atoi(del.c_str())*1000);
system("clear");
f.erase(0, f.find("endendend")+9);
}

}
else {









    std::string f;
    std::fstream y(argv[1]);
y >> f;
ReturnImage(f);
if(argv[2] != nullptr) {
	getch();
}
}
}
