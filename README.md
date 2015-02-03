"# This is my README"  
  
Created by Jamie Slowgrove.  
You can do what you want with the code and images in this project, however you must credit me and add a link back to the git repository.  
  
Font used is Karmatic Arcade Font:  
http://www.dafont.com/vic-fieger.d852 

Music:
[The Way Out] Kevin MacLeod (incompetech.com) 
Licensed under Creative Commons: By Attribution 3.0
http://creativecommons.org/licenses/by/3.0/

[Shiny Tech] Kevin MacLeod (incompetech.com) 
Licensed under Creative Commons: By Attribution 3.0
http://creativecommons.org/licenses/by/3.0/

Sound Effects are from the Kenney Asset Pack:  
http://kenney.itch.io/kenney-donation  
  
Created using SDL 2.0, SLD_Image 2.0, SDL_Mixer and SDL_ttf 2.0:  
https://www.libsdl.org/  
https://www.libsdl.org/projects/SDL_image/  
http://www.libsdl.org/projects/SDL_mixer/  
https://www.libsdl.org/projects/SDL_ttf/  
  
This is a port of my MGP Assignment 1 (Caseus Tower). The reason I have ported this from Android to PC is because the Assignment required me to use the
given library to make the game on Android. This library was created by the lecturer and as such I can not put it public as it is not my work. As such when
I was creating the game I made sure to keep as much of the lectures code separate from mine, so it would be easily portable. It was due to this that I have
an application and sprite handler class, to make sure that all I would need to do was recreate these so the code would work with SDL (such as changing the 
coordinate system in these classes) and why I have all of the images separate and in .tga format instead of in a sprite-sheet. This does also mean that the 
code is not as efficient as it could be as most of it has to be converted at runtime to work with the PC.