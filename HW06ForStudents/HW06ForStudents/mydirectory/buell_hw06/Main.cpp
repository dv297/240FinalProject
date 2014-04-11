/****************************************************************
 * Main program for doing union-find algorithm.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 12 January 2014
 *
**/

#include "Main.h"

static const string TAG = "Main: ";

int main(int argc, char *argv[])
{
  string timeCallOutput = "";
  string inFileName = "";
  string outFileName = "";
  string logFileName = "";
  ofstream outStream;
  Scanner inStream;

  UnionFind unionFind;


  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  inFileName = (string) argv[1];
  outFileName = (string) argv[2];
  logFileName = (string) argv[3];

  Utils::FileOpen(outStream, outFileName);
  Utils::LogFileOpen(logFileName);

  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Beginning execution" << endl;
  Utils::logStream.flush();

  Utils::logStream << TAG << "infile '" << inFileName << "'" << endl;
  Utils::logStream << TAG << "outfile '" << outFileName << "'" << endl;
  Utils::logStream << TAG << "logfile '" << logFileName << "'" << endl;

/*
  srand(1);
  int count = 20;
  for(int i = 0; i < 100; ++i)
  {
    int a = rand() % count;
    int b = rand() % count;
    while(a == b)
    {
      b = rand() % count;
    }

    Utils::logStream << Utils::Format(a, 3) << " " << Utils::Format(b, 3) << endl;
    Utils::logStream.flush();

  }
  exit(1);
*/

  inStream.openFile(inFileName);
  int numberOfArcs = inStream.nextInt();
  for(int arc = 0; arc < numberOfArcs; ++arc)
  {
    int a = inStream.nextInt();
    int b = inStream.nextInt();
//    cout << "ZORK " << a << " " << b << endl;
    if(a < b)
      unionFind.addLink(a, b);
    else
      unionFind.addLink(b, a);
  }

//  Utils::logStream << unionFind.toString() << endl;
//  Utils::logStream.flush();

//  unionFind.buildTrees();
//  Utils::logStream << unionFind.toString() << endl;
//  Utils::logStream.flush();

  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Ending execution" << endl;
  Utils::logStream.flush();

  Utils::FileClose(outStream);
  Utils::FileClose(Utils::logStream);

  return 0;
}
