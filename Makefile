obj = main.cpp sourceFiles/Init.cpp sourceFiles/Buttons.cpp sourceFiles/stateManager.cpp  sourceFiles/Background.cpp sourceFiles/Test.cpp sourceFiles/globals.cpp

cc = g++

include_path = -Isrc\include

library_path = -Lsrc\lib

linker_flags = -lmingw32 -lSDL3 -lSDL3_image.dll -lSDL3_ttf.dll #-lSDL3main -lSDL3 #-lSDL2_image

obj_name = main

all: $(obj)
		$(cc) $(obj) $(include_path) $(library_path) $(linker_flags) -o $(obj_name)
# all:
#g++ main.cpp headers/init.cpp -IC:\Users\Rinny\Desktop\portfolio\c++\game\src\include 
#-LC:\Users\Rinny\Desktop\portfolio\c++\game\src\lib -lmingw32 -lSDL3 -o main  