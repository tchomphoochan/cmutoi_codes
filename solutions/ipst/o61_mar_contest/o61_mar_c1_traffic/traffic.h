#ifndef TRAFFIC_H_INCLUDED
#define TRAFFIC_H_INCLUDED

void traffic_init(int* N, int* K);
int traffic_query(int x1, int y1, int x2, int y2);
void traffic_report(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2);

#endif

