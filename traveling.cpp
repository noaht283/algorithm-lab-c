//Noah Tola nat2eh 12/3/19
#include <iostream>
#include "middleearth.h"
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

void printRoute (string start, vector<string> dests);
float computeDistance (MiddleEarth &me, string start, vector<string> dests);

/**
 *from the 5 paramters passed in from the hobbits world. 
 *The program has a vector that has and uses all the destinations and 
 *is then sorted from the second destination to the last. The
 *program then goes through the permuatations by using the other
 *methods and finds the shortest path and the shows the shortest path.
 */
int main(int argc, char **argv) {
  if (argc !=6){
    exit(0);
  }
  int width, height;
  int num_cities, rand_seed, cities_to_visit;
  sscanf (argv[1], "%d", &width);
  sscanf (argv[2], "%d", &height);
  sscanf (argv[3], "%d", &num_cities);
  sscanf (argv[4], "%d", &rand_seed);
  sscanf (argv[5], "%d", &cities_to_visit);
  
  MiddleEarth me(width,height,num_cities,rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);
  string start = dests[0];
  vector<string> itinr;
  float dist1 = 0.0;
  float min = computeDistance(me,start,dests);

 
  sort(dests.begin() +1, dests.end());
  while (next_permutation(dests.begin() +1, dests.end())) {
    dist1 = computeDistance(me, start, dests);
    if (dist1 < min){
      itinr = dests;
      min = dist1;
      
    }}
  cout << "minimum path distance "<< min << ": ";
  printRoute(itinr[0], itinr);
  cout << endl;
  return 0;
}
/**
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.                                    
 */
void printRoute (string start, vector<string> dests) {
  vector<string>::iterator itr;
  for (itr =dests.begin(); itr != dests.end(); itr++) {
    cout << " " << *itr << " ->";
  }
  cout << start;
}
/**
 * This method will compute the full distance of the cycle that starts                                           
  */
/**
 *computes the distance from the start city to all the other cities then back
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  double dist = 0.0;
  for (int i=0; i<dests.size(); i++) {
    dist = dist + me.getDistance(start, dests[i]);

    start = dests[i];
  }
  dist = dist + me.getDistance(dests[dests.size() -1], dests[0]);
  return dist;
}

