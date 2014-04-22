/****************************************************************
 * Main program for doing union-find algorithm.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Modified by: Daniel Vu, Collin Haines, Kevin Silver, Julio Diaz
 * Date: 12 January 2014
 * Submission Date: 24 April 2014
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

  // open the output file and log file
  Utils::FileOpen(outStream, outFileName);
  Utils::LogFileOpen(logFileName);

  // announce our presence and start the timer
  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Beginning execution" << endl;
  Utils::logStream.flush();

  Utils::logStream << TAG << "infile '" << inFileName << "'" << endl;
  Utils::logStream << TAG << "outfile '" << outFileName << "'" << endl;
  Utils::logStream << TAG << "logfile '" << logFileName << "'" << endl;

  // open the input file and do the real work
  inStream.openFile(inFileName);
  int numberOfArcs = inStream.nextInt();

  for(int arc = 0; arc < numberOfArcs; ++arc)
  {
    int a = inStream.nextInt();
    int b = inStream.nextInt();
    // 4-21-14 Removed if statements
    // Variable distribution handled inside method
    unionFind.addLink(a, b);
  }

  outStream << unionFind.toString() << endl;
  outStream.flush();

  // let the world know we're done, close files, stop timer, finish
  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Ending execution" << endl;
  Utils::logStream.flush();

  Utils::FileClose(outStream);
  Utils::FileClose(Utils::logStream);

  return 0;
}
