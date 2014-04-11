GPP = g++ -O3 -Wall

UTILS = ../../Utilities

M = Main.o
UF = UnionFind.o
XX = XX.o
S = Scanner.o
U = Utils.o

Aprog: $(M) $(UF) $(XX) $(S) $(U)
	$(GPP) -o Aprog $(M) $(UF) $(XX) $(S) $(U)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c -DEBUG Main.cpp

UnionFind.o: UnionFind.h UnionFind.cpp
	$(GPP) -o UnionFind.o -c UnionFind.cpp

XX.o: XX.h XX.cpp
	$(GPP) -o XX.o -c XX.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(UTILS)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	clean

