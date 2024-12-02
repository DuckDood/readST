#include "cryptman.hpp"

struct int3{
std::string i1;
std::string i2;
std::string i3;
};

int3 colr(int &pos, std::string file) {
    std::string in = "";
    int3 re;
for(int i = 1; i <=3 ;i++) {
    in += file.at(pos);
    pos++;
}
re.i1 = in;
in = "";
for(int i = 1; i <=3 ;i++) {
    in += file.at(pos);
    pos++;
}
re.i2 = in;
in = "";
for(int i = 1; i <=3 ;i++) {
    in += file.at(pos);
    pos++;
}
re.i3 = in;
in = "";

return re;
}

int3 colorG(int pos, std::string file) {
    std::string in = "";
    int3 re;
for(int i = 1; i <=3 ;i++) {
    in += file.at(pos);
    pos++;
}
re.i1 = in;
in = "";
for(int i = 1; i <=3 ;i++) {
    in += file.at(pos);
    pos++;
}
re.i2 = in;
in = "";
for(int i = 1; i <=3 ;i++) {
    in += file.at(pos);
    pos++;
}
re.i3 = in;
in = "";

return re;
}

std::string ReturnImage(std::string Img) {
 int counter = 0;
    int3 val;
    std::string token = "";
int width;
std::string pict;
pict=Img;
int pos = 0;
std::string imgOut = "";

pict = decrypt(pict, "255255255","w");
pict = decrypt(pict, "000000000","k");
pict = decrypt(pict, "255000000","r");
pict = decrypt(pict, "000255000","g");
pict = decrypt(pict, "000000255","b");
pict = decrypt(pict, "000255255","c");
pict = decrypt(pict, "255000255","p");
pict = decrypt(pict, "255255000","y");

for(pos++; pict.at(pos) != '}'; pos++) {
token += pict.at(pos);
}
    

pos++;

width = std::atoi(token.c_str());

bool going = true;
while(going) {
for(;counter<width;) { 
val = colr(pos, pict); 
if(val.i1 == "end"||val.i2 == "end"||val.i3 == "end") {
going = false;
break;
}
imgOut += ("\033[48;2;"+val.i1+";"+val.i2+";"+val.i3+"m");
imgOut += "  ";
counter++;
}
imgOut += "\n";
counter = 0;

}
imgOut += "\033[m";
return imgOut;
}

int getWidth(std::string Img) {
 int counter = 0;
    int3 val;
    std::string token = "";
int width;
std::string pict;
pict=Img;
int pos = 0;
std::string imgOut = "";

pict = decrypt(pict, "255255255","w");
pict = decrypt(pict, "000000000","k");
pict = decrypt(pict, "255000000","r");
pict = decrypt(pict, "000255000","g");
pict = decrypt(pict, "000000255","b");
pict = decrypt(pict, "000255255","c");
pict = decrypt(pict, "255000255","p");
pict = decrypt(pict, "255255000","y");

for(pos++; pict.at(pos) != '}'; pos++) {
token += pict.at(pos);
}
    

pos++;

width = std::atoi(token.c_str());

bool going = true;
while(going) {
for(;counter<width;) { 
val = colr(pos, pict); 
if(val.i1 == "end"||val.i2 == "end"||val.i3 == "end") {
going = false;
break;
}
imgOut += ("\033[48;2;"+val.i1+";"+val.i2+";"+val.i3+"m");
imgOut += "  ";
counter++;
}
imgOut += "\n";
counter = 0;

}

return width;
}


