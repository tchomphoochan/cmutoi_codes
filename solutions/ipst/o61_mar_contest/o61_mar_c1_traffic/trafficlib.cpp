#include "traffic.h"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

using namespace std;

#define MAX_NN 10020
#define TEMP_ID1 10001
#define TEMP_ID2 10002

#define MAX_QUERY 222

static int n,k;
static int sx1, sy1, sx2, sy2;
static int tx1, ty1, tx2, ty2;
static bool initialized = false;
static int query_counter = 0;

static vector<int> adj[MAX_NN];

static void report_incorrect()
{
  cout << "incorrect" << endl;
  exit(0);
}

static void report_correct()
{
  cout << "correct" << endl;
  exit(0);
}

static int node_num(int x, int y)
{
  return y*100 + x;
}

static void read_input()
{
  cin >> n >> k;
  cin >> sx1 >> sy1 >> sx2 >> sy2;
  sx1--; sy1--; sx2--; sy2--;
  if(k==2) {
    cin >> tx1 >> ty1 >> tx2 >> ty2;
    tx1--; ty1--; tx2--; ty2--;
  }
}

static void set_edge(int u, int v, int w)
{
  for(int i=0; i<adj[u].size(); i++) {
    if(adj[u][i] == v) {
      adj[u][i] = w;
      return;
    }
  }
}

static void increase_length(int x1, int y1, int x2, int y2,
                            int temp_id)
{
  int u = node_num(x1,y1);
  int v = node_num(x2,y2);

  set_edge(u,v,temp_id);
  set_edge(v,u,temp_id);
  adj[temp_id].push_back(u);
  adj[temp_id].push_back(v);
}

static void add_edge(int x1, int y1, int x2, int y2)
{
  int u = node_num(x1,y1);
  int v = node_num(x2,y2);

  adj[u].push_back(v);
  adj[v].push_back(u);
}

static void build_graph()
{
  for(int x=0; x<n; x++)
    for(int y=0; y<n; y++) {
      if(x != n-1) {
        add_edge(x,y,x+1,y);
      }
      if(y != n-1) {
        add_edge(x,y,x,y+1);
      }
    }
  increase_length(sx1, sy1, sx2, sy2, TEMP_ID1);
  if(k == 2) {
    increase_length(tx1, ty1, tx2, ty2, TEMP_ID2);
  }
}

void traffic_init(int* N, int* K)
{
  read_input();
  build_graph();
  initialized = true;
  *N = n;
  *K = k;
}

static int dist[MAX_NN];
static int bfs(int s, int t)
{
  for(int i=0; i<MAX_NN; i++) {
    dist[i] = -1;
  }
  dist[s] = 0;

  deque<int> Q;
  Q.push_back(s);
  
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();

    if(u==t) {
      return dist[t];
    }
    
    int du = dist[u];
    int deg = adj[u].size();
    for(int i=0; i<deg; i++) {
      int v = adj[u][i];

      if(dist[v] == -1) {
        dist[v] = du+1;
        Q.push_back(v);
      }
    }
  }
  return -1;
}

int traffic_query(int x1, int y1, int x2, int y2)
{
  if(!initialized) {
    report_incorrect();
  }
  query_counter++;
  if(query_counter > MAX_QUERY) {
    report_incorrect();
  }
  
  x1--; y1--; x2--; y2--;
  int s = node_num(x1,y1);
  int t = node_num(x2,y2);
  int d = bfs(s,t);
  printf("query %d %d %d %d: %d\n", x1+1, y1+1, x2+1, y2+1, d);
  return d;
}

static void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

static void normalize_edge(int& u, int& v) {
  if(u > v) {
    swap(u,v);
  }
}

static bool same_edge(int au, int av, int su, int sv)
{
  normalize_edge(au,av);
  normalize_edge(su,sv);
  return (au == su) && (av == sv);
}

void traffic_report(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2)
{
  printf("%d %d %d %d\n%d %d %d %d\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
  exit(0);

  ax1--; ay1--; ax2--; ay2--;
  bx1--; by1--; bx2--; by2--;
  int au = node_num(ax1, ay1);
  int av = node_num(ax2, ay2);

  int su = node_num(sx1, sy1);
  int sv = node_num(sx2, sy2);
  
  if(k==1) {
    if(same_edge(au,av, su,sv)) {
      report_correct();
    } else {
      report_incorrect();
    }
  } else {
    int bu = node_num(bx1, by1);
    int bv = node_num(bx2, by2);
    int tu = node_num(tx1, ty1);
    int tv = node_num(tx2, ty2);

    if(same_edge(au,av, su,sv) && same_edge(bu,bv,tu,tv)) {
      report_correct();
    } else if(same_edge(au,av, tu,tv) && same_edge(bu,bv, su,sv)) {
      report_correct();
    } else {
      report_incorrect();
    }
  }
}

