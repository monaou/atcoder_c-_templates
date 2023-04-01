#include <bits/stdc++.h>
using namespace std;
const long double PI = (acos(-1));

int main() {
  double N,x0,y0,x2,y2,x1,y1;
  cin>>N>>x0>>y0>>x2>>y2;
  double ansx,ansy,angel0,angel2;
  x1=-(x2-x0)/double(2);y1=-(y2-y0)/double(2);
  angel0=2*PI/N;
  ansx=x1*cos(angel0)-y1*sin(angel0);
  ansy=x1*sin(angel0)+y1*cos(angel0);
  ansx+=x0-x1;
  ansy+=y0-y1;
  cout<<setprecision(12)<<ansx<<" "<<ansy<<endl;
}