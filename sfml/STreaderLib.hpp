#include "cryptman.hpp"
#include <SFML/Graphics.hpp> 
#include <cstdlib>
#include <string>
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

void ReturnImage(std::string Img) {


       
sf::RenderWindow window(sf::VideoMode(300, 300), "Image");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Image image;
    sf::Texture texture;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }










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
image.create(300, 300);
bool going = true;
int i = 1;
while(going) {
for(;counter<width;) { 
val = colr(pos, pict); 
if(val.i1 == "end"||val.i2 == "end"||val.i3 == "end") {
going = false;
break;
}
image.setPixel(counter, i, sf::Color(stoi(val.i1), stoi(val.i2), stoi(val.i3)));
imgOut += ("\033[48;2;"+val.i1+";"+val.i2+";"+val.i3+"m");
imgOut += "  ";
counter++;
}
imgOut += "\n";
counter = 0;
i++;
}
imgOut += "\033[m";
texture.loadFromImage(image);
sf::Sprite sprite(texture);
sprite.setScale(5,5);
window.clear();
window.draw(sprite);
window.display();
}
//return imgOut;

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


