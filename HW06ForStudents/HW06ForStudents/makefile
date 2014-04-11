GPP = g++ -O3 -Wall

UTILS = ../../Utilities
UTILS = ../../Utilities

M = Main.o
F = PathFinder.o
MAT = Matrix.o
O = Operators.o
S = Scanner.o
U = Utils.o

Aprog: $(M) $(F) $(MAT) $(O) $(S) $(U)
	$(GPP) -o Aprog $(M) $(F) $(MAT) $(O) $(S) $(U)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c -DEBUG Main.cpp

PathFinder.o: PathFinder.h PathFinder.cpp
	$(GPP) -o PathFinder.o -c -DEBUGPATH PathFinder.cpp

Matrix.o: Matrix.h Matrix.cpp
#	$(GPP) -o Matrix.o -c -DEBUGMATRIX Matrix.cpp
	$(GPP) -o Matrix.o -c Matrix.cpp

Operators.o: Operators.cpp
#	$(GPP) -o Matrix.o -c -DEBUGOPERATORS Operators.cpp
	$(GPP) -o Operators.o -c Operators.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(UTILS)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	clean

