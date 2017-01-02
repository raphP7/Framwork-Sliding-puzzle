#!/bin/bash

g++ -std=c++0x  -O0 -g3 -c -o "object/DoublePointer.o" "src/DoublePointer.hpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/FramPlateauLand.o" "src/FramPlateauLand.hpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/CaseGeneric.o"  "src/CaseGeneric.cpp"

g++ -std=c++0x -I src/SFML-2.4.1/include -O0 -g3 -c -o"object/display.o"  "src/Display/display.hpp"



#g++ -std=c++0x  -O0 -g3 -c -o"object/CaseTakin.o"   "src/Takin/CaseTakin.hpp"

#g++ -std=c++0x  -O0 -g3 -c -o"object/PlateauTakin.o"  "src/Takin/PlateauTakin.hpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/mainTakinINT.o"  "src/Takin/mainTakinINT.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/mainTakinCHAR.o"  "src/Takin/mainTakinCHAR.cpp"




g++ -std=c++0x  -O0 -g3 -c -o"object/CaseSokoban.o"   "src/Sokoban/CaseSokoban.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/PlateauSokoban.o"  "src/Sokoban/PlateauSokoban.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/mainSokobanFile.o"   "src/Sokoban/mainSokobanFile.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/mainSokobanManual.o"   "src/Sokoban/mainSokobanManual.cpp"




g++ -std=c++0x  -O0 -g3 -c -o"object/Case2048Negative.o"   "src/2048/case2048Negative/Case2048Negative.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/Case2048Destroy.o"  "src/2048/Case2048Destroy/Case2048Destroy.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/Plateau2048Plugin.o"  "src/2048/Plateau2048Plugin.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/main2048Plugin.o"   "src/2048/main2048Plugin.cpp"



g++ -std=c++0x  -O0 -g3 -c -o"object/Case2048.o"  "src/2048/Case2048.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/Plateau2048.o"   "src/2048/Plateau2048.cpp"

g++ -std=c++0x  -O0 -g3 -c -o"object/main2048.o"   "src/2048/main2048.cpp"




g++  -o "main2048Plugin" object/Case2048.o object/Case2048Negative.o  object/Case2048Destroy.o object/Plateau2048.o object/Plateau2048Plugin.o object/CaseGeneric.o object/main2048Plugin.o   -lsfml-graphics -lsfml-system -lsfml-window

g++  -o "main2048" object/Case2048.o object/Plateau2048.o object/CaseGeneric.o object/main2048.o   -lsfml-graphics -lsfml-system -lsfml-window

g++  -o "mainSokobanManual" object/PlateauSokoban.o object/CaseGeneric.o object/mainSokobanManual.o   -lsfml-graphics -lsfml-system -lsfml-window

g++  -o "mainSokobanFile"  object/PlateauSokoban.o object/CaseGeneric.o object/mainSokobanFile.o   -lsfml-graphics -lsfml-system -lsfml-window

g++  -o "mainTakinINT" object/CaseGeneric.o object/mainTakinINT.o   -lsfml-graphics -lsfml-system -lsfml-window

g++  -o "mainTakinCHAR" object/CaseGeneric.o object/mainTakinCHAR.o