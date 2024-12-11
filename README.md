# ST: The TTY image format
## mainw.cpp is the editor, main.cpp is the reader
## The ST image format is something I made when I was bored.
> I didn't know any graphics frameworks at the time, so I decided to use ANSI color codes to display. In doing so, I allowed to work in a TTY which is fun and funky.

## You may be wondering, What does ST stand for?
> ST is a shortening of .SHIT, and one of the reasons I made the format is because I thought .SHIT would be a funny file extension. SHIT stands for **S**imple **H**eavy **I**mage **T**ype, and you can tell I was grasping for straws when I made that acronym.



## More stuff
> There is a animated version which works similar to a gif, but that's only for windows and I'm too lazy to put it on github.
> To use the editor, WASD to move, C to change color to a 9 digit rgb value (like 002168255) or use the shorthand colors which are r(ed) g(reen) b(lue) p(ink but it's actually magenta) c(yan) y(ellow). X to move to a specific x and y (starting at index 0) and P to save.
> You may want to just construct a ST yourself (If you're using it, which you shouldn't) because my editor is dogshit. First, you start with the width in curly brackets (eg. {5}). and then, put either the shorthand colors (r, g, b, etc) or 9 digit rgb values. if you're a psychopath, you can misalign the shorthand to be really annoying (eg. 255g000055 would be the same as 255000255000000055). At the end, add "endendend".
