CC=g++ -std=c++11
CFLAGS=-std=c++0x -I src/SFML-2.4.1/include
LDFLAGS=-lsfml-graphics -lsfml-system -lsfml-window
EXEC= mainTakinCHAR mainTakinINT mainSokobanManual mainSokobanFile main2048Plugin main2048

FRAMWORK=src/CaseGeneric.cpp  src/CaseGeneric.hpp    src/DoublePointer.hpp  src/FramPlateauLand.hpp    src/Display/display.hpp
SOKOBAN=   src/Sokoban/CaseSokoban.cpp    src/Sokoban/PlateauSokoban.cpp 
2048= src/2048/Case2048Destroy/Case2048Destroy.hpp  src/2048/Case2048Destroy/Case2048Destroy.cpp  src/2048/Case2048.hpp  src/2048/Plateau2048Plugin.hpp  src/2048/Plateau2048.cpp  src/2048/Case2048.cpp  src/2048/Plateau2048.hpp  src/2048/case2048Negative/Case2048Negative.hpp  src/2048/case2048Negative/Case2048Negative.cpp  src/2048/Plateau2048Plugin.cpp

SRC= $(FRAMWORK)

SRC2= $(FRAMWORK) $(SOKOBAN)

SRC3= $(FRAMWORK) $(2048)

OBJFram= $(SRC:.cpp=.o)

OBJFramSokoban= $(SRC2:.cpp=.o)

OBJFram2048= $(SRC3:.cpp=.o)

all: $(SRC) $(EXEC)

object/main2048.o: src/2048/main2048.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main2048: object/main2048.o $(OBJFram2048)
	$(CC) -o $@ $^ $(LDFLAGS)

object/main2048Plugin.o: src/2048/main2048Plugin.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main2048Plugin: object/main2048Plugin.o $(OBJFram2048)
	$(CC) -o $@ $^ $(LDFLAGS)

object/mainSokobanFile.o: src/Sokoban/mainSokobanFile.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

mainSokobanFile: object/mainSokobanFile.o $(OBJFramSokoban)
	$(CC) -o $@ $^ $(LDFLAGS)

object/mainSokobanManual.o: src/Sokoban/mainSokobanManual.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

mainSokobanManual: object/mainSokobanManual.o $(OBJFramSokoban)
	$(CC) -o $@ $^ $(LDFLAGS)

object/mainTakinINT.o: src/Takin/mainTakinINT.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

mainTakinINT: object/mainTakinINT.o $(OBJFram)
	$(CC) -o $@ $^ $(LDFLAGS)

object/mainTakinCHAR.o: src/Takin/mainTakinCHAR.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

mainTakinCHAR: object/mainTakinCHAR.o $(OBJFram)
	$(CC) -o $@ $^ $(LDFLAGS)


.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf object/*.o
	find . -name '*.o' -delete

mrproper: clean
	rm -rf $(EXEC)