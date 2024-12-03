#include "STreaderLib.hpp"
#include <fstream>
#include <filesystem>
#include <termios.h>
#include <stdio.h>

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


int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


int main(int argc, char *argv[]) {
    
    std::string image = "";
    int width;
    int tempX;
    int tempY;
    if(argv[1] == nullptr){ 
	return 0;
    }
	std::filesystem::path p = argv[1];
    if(!std::filesystem::exists(p)){
        
        int y = 0;
        std::cout << "Enter X of image: ";
        std::cin >> width;
        std::cout << "\nEnter Y of image: ";
        std::cin >> y;
        for(int i = 0; i < width*y; i++) {
            image+="w";
        }

        image = "{"+std::to_string(width)+"}"+image+"endendend";
    } else {
        
    std::fstream file(argv[1]);
    file >> image;
    width = getWidth(image);
    
    }
    int3 tempC;
    std::fstream file(argv[1]);
    int x = numDigits(width);
    char getcher;
    char las;
    int i = 0;
    std::string rgb = "255255255";
    std::string col = "000000000";
 while(true) {
    if(x < numDigits(width)) {
x = numDigits(width);
    }
    if(x >= image.length()-2) {
x = numDigits(width);
    }
        image = decrypt(image, "255255255","w");
        image = decrypt(image, "000000000","k");
        image = decrypt(image, "255000000","r");
        image = decrypt(image, "000255000","g");
        image = decrypt(image, "000000255","b");
        image = decrypt(image, "000255255","c");
        image = decrypt(image, "255000255","p");
        image = decrypt(image, "255255000","y");

    getcher = getch();
    
    if(getcher == 'd') {
        x+=9;
        if(x < numDigits(width)) {
x = numDigits(width);
    }
    
    if(x >= image.length()-2) {
x = numDigits(width);
    }
        image.replace(x+2, 9, col);
        
    }else
    if(getcher == 'a') {
        x-=9;
        if(x < numDigits(width)) {
x = numDigits(width);
    }
    
    if(x >= image.length()-2) {
x = numDigits(width);
    }
        image.replace(x+2, 9, col);
        
    }else if(getcher == 'w') {
        x-=9*width;
        if(x < numDigits(width)) {
x = numDigits(width);
    }
    
    if(x >= image.length()-2) {
x = numDigits(width);
    }
        image.replace(x+2, 9, col);
        
    }else if(getcher == 's') {
        x+=9*width;
        if(x < numDigits(width)) {
x = numDigits(width);
    }
    
    if(x >= image.length()-2) {
x = numDigits(width);
    }
        image.replace(x+2, 9, col);
        
    }else
    if((int)getcher == 27) {
        break;
    }else
    if(getcher == 'c') {
        std::cin >> col;
    } else if(getcher == 'p'){
        
        image = encrypt(image, "255255255","w");
        image = encrypt(image, "000000000","k");
        image = encrypt(image, "255000000","r");
        image = encrypt(image, "000255000","g");
        image = encrypt(image, "000000255","b");
        image = encrypt(image, "000255255","c");
        image = encrypt(image, "255000255","p");
        image = encrypt(image, "255255000","y");

        std::ofstream fi(argv[1]);
        fi << image;
        fi.close();
    } else if(getcher == 'x') {
        std::cout << "Enter X: ";
        std::cin >> tempX;
        std::cout << "\nEnter Y: ";
        std::cin >> tempY;
        if(tempX < 0) {
            tempX =0;
        }
        if(tempY < 0) {
            tempY =0;
        }
        x = numDigits(width)+(tempX+(width*tempY))*9;
        image.replace(x+2, 9, col);
    }
    las = getcher;
    
    
    /*
    if(getcher == 'd') {
        x-=9;
        image.replace(x+2, 9, tempC.i1+tempC.i2+tempC.i3);
        x+=9;
    }else
    if(getcher == 'a') {
        x+=9;
        image.replace(x+2, 9, tempC.i1+tempC.i2+tempC.i3);
        x-=9;
    }else if(getcher == 'w') {
        x+=9*width;
        image.replace(x+2, 9, tempC.i1+tempC.i2+tempC.i3);
        x-=9*width;
    }else if(getcher == 's') {
        x-=9*width;
        image.replace(x+2, 9, tempC.i1+tempC.i2+tempC.i3);
        x+=9*width;
    }
    */
    system("clear");
    std::cout << ReturnImage(image);
 }
}
