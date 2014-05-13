//  ClosestPair
//
//  Created by kittiphong xayasane on 2013-10-19.
//  Copyright (c) 2013 Kittiphong Xayasane. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>

class point
{
public:
  float x;
  float y;
};

class distandpair
{
public:
  float dist;
  point pair[2];
};


std::vector<point> R;
std::vector<point> Q;
std::vector<point> A;
point nullpoint;
//R.resize(100);

bool sortx (point i, point j){
  return (i.x<j.x);
}

std::vector<point> SelectCandidates(float l, float r, distandpair distandpairMin, float xmid){
  //R.clear();
  //int j = 0;
  for(int i = l; i < r; i++){
    if(abs(Q[i].x - xmid) <= distandpairMin.dist){
      //j = j+1;
      //R[j] = Q[i];
      R.push_back(Q[i]);
      
    }
  }
  return R;
}

distandpair CheckStrip(std::vector<point> R, distandpair distandpairMin){
  //float deltaprime = delta;
  //std::cout << "delta is: " << distandpairMin.dist << std::endl;
  int t = R.size();
 // std::cout << "t is: " << t << std::endl;
  distandpair distandpairprime = distandpairMin;
  for(int j = 1; j < t - 1; j++){
    for(int k = j+1; k < std::min(t,j+7); k++){
      float x = R[j].x;
      float xprime = R[k].x;
      float y = R[j].y;
      float yprime = R[k].y;
      if(distandpairprime.dist > sqrtf((xprime-x)*(xprime-x)+(yprime-y)*(yprime-y))){
        distandpairprime.pair[0].x = x;
        distandpairprime.pair[0].y = y;
        distandpairprime.pair[1].x = xprime;
        distandpairprime.pair[1].y = yprime; }
       distandpairprime.dist = std::min(distandpairprime.dist,sqrtf((xprime-x)*(xprime-x)+(yprime-y)*(yprime-y)));
     
     /* 
     else{
        distandpairprime.pair[0].x = x;
        distandpairprime.pair[0].y = y;
        distandpairprime.pair[1].x = xprime;
        distandpairprime.pair[1].y = yprime;
      }
*/
      //std::cout << "t is: " << t << std::endl;
     // std::cout << "distance is: " << distandpairprime.dist << std::endl;
    } 
  //std::cout << "hi";
  }

  return distandpairprime;
}

distandpair ClosestPairBrute(){
  distandpair distandpairMin;
  distandpairMin.dist = sqrtf((Q[1].x - Q[0].x)*(Q[1].y - Q[0].y));
  distandpairMin.pair[0] = Q[0];
  distandpairMin.pair[1] = Q[1]; 

  for (int i = 0; i < A.size()-1; i++){
    for (int j = i+1; j < A.size(); j++){
      if(sqrtf((Q[j].x - Q[i].x)*(Q[j].y - Q[i].y)) < distandpairMin.dist){
      distandpairMin.dist = sqrtf((Q[j].x - Q[i].x)*(Q[j].y - Q[i].y));
      distandpairMin.pair[0] = Q[i];
      distandpairMin.pair[1] = Q[j];
      }
    }
  }
return distandpairMin;
}

distandpair ClosestPair2(int l, int r){
  float delta;
  float m;
  float deltaLeft;
  float deltaRight;
  distandpair distandpairLeft;
  distandpair distandpairRight;
  distandpair distandpairMin;
  R.clear();
  if(Q.size() <= 3){
  //std::cout << "WE NEED TO BRUTE FORCE! 3 POINTS OR LESS!" << std::endl;
  //return 0;
  return ClosestPairBrute();
  }
  //std::cout << delta << std::endl;
  if (l == r){
    distandpairMin.dist = 99999;
  }   
  else{
  m = floor((l+r)/2);
  distandpairLeft = ClosestPair2(l,m); //change deltaLeft into struct with (deltaLeft,pair)
  distandpairRight = ClosestPair2(m+1,r);
  //delta = std::min(deltaLeft, deltaRight);
  if(distandpairLeft.dist < distandpairRight.dist){
    distandpairMin = distandpairLeft;
  }
  else{
  //else if(distandpairLeft.dist > distandpairRight.dist){
    distandpairMin = distandpairRight;
  }	
  R = SelectCandidates(l,r,distandpairMin,Q[m].x);
  //R.clear();
  distandpairMin = CheckStrip(R,distandpairMin);
  //R.clear();
  } 
   R.clear();
  return distandpairMin;
}

int main(int argc, const char * argv[])
{
    point my_point;
    //std::vector<point> Q;
    float number;
    int j = 0;
    while(std::cin >> number){
	if(j == 0){
	  my_point.x = number;
	  j++;
	}
	else{
	  my_point.y = number;
	  Q.push_back (my_point);
	  j = 0;
	}
    }
    A = Q;
    std::sort (Q.begin(), Q.end(),sortx);
    // insert code here...
/*    
    for (unsigned i=0; i<Q.size(); i++)
      std::cout << A[i].x << " " <<A[i].y << "\n";
    std::cout << '\n';
  */  
     //What does Q contain?
    distandpair output = ClosestPair2(0,Q.size());
    /*
    std::cout << output.dist << std::endl;
    std::cout << "x1: " << output.pair[0].x << std::endl;
    std::cout << "y1: " << output.pair[0].y << std::endl;
    std::cout << "x2: " << output.pair[1].x << std::endl;
    std::cout << "y2: " << output.pair[1].y << std::endl;
    */
    int indice1;
    int indice2;
    for(int i = 0; i < A.size(); i++){
      if(output.pair[0].x == A[i].x && output.pair[0].y == A[i].y){
        //std::cout << i << std::endl; 
        indice1 = i;
      }
    }
    for(int j = 0; j < A.size(); j++){
      if(output.pair[1].x == A[j].x && output.pair[1].y == A[j].y){
        //std::cout << j << std::endl;
        indice2 = j;
      }
    }
    if(indice1 < indice2){
      std::cout << indice1 << std::endl << indice2;
    }
    else{
      std::cout << indice2 << std::endl << indice1;
    }
    return 0;
}
