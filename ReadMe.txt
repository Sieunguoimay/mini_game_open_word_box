What I learned through this project:

--------------------------------------------------------------
1.Stackoverflow:How to add icon to a MinGW GCC compiled executable?

Command line to compile the .rc file to .res file
for using icon:
	windres resource.rc -O coff -o resource.res
After being compiled .res file will be used to attach icon to
the .exe file. By adding *.res to the end of gcc command:
	g++ -Wall *.cpp -o main file.res
---------------------------------------------------------------

2.How to hide the console away.
--->add the flag -mwindows to the end of gcc command

-------------------------------------------------------------
3.How to enable transparent of the SDL_Window:
	SDL_SetWindowOpacity(window, 0.0 - 1.0f);
