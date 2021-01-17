#include <bits/stdc++.h>
using namespace std;

class Dot
{
    public:
    int x;
    int y;
    bool left;

    Dot()
    {
        x = 0;
        y = 0;
        left = false;
    }

    Dot(int a, int b, bool d)
    {
        x = a;
        y = b;
        left = d;
    }

    // less than operator for sakes of sets (less is prioritized)
    // from left to right, form up to down
    bool operator<(const Dot &other) const
    {
        if (x < other.x)
            return true;
        else if (x > other.x)
            return false;
        
        if (y > other.y)
            return true;
        else if (y < other.y)
            return false;
        
        return (left && !other.left);
    }

    bool blankDot() const
    {
        return (x == 0 && y == 0 && left == false);
    }
};

class Line
{
    public:
    Dot left;
    Dot right;
    int height;

    Line(Dot &a, Dot &b)
    {
        left = a;
        right = b;
        height = a.y;
    }

    bool operator<(const Line &other) const
    {
        return left < other.left || right < other.right; 
    }

};

Dot getTopDotN(set<Dot> &dots, int x, int num)
{
    for (set<Dot>::iterator dt = dots.begin(); dt != dots.end(); dt++)
    {
        if (dt->x == x)
            if (--num == 0)
                return *dt;
    }

    Dot blank;
    return blank;
}

#define getTopDot(dots, x) getTopDotN(dots, x, 1)

int getTopLine(set<Line> &lines, int x)
{
    int max = 0;
    for (set<Line>::iterator lt = lines.begin(); lt != lines.end(); lt++)
    {
        Line line = *lt;
        if (line.left.x <= x && line.right.x > x && line.height > max)
        {
            max = line.height;
        }
    }
    return max;
}

#define print(x) cout << x << " "

int main()
{
    int n;
    cin >> n;
    set<Dot> dots;
    set<Line> lines;
    set<int> lengths;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        Dot dotL(a, b, true);
        Dot dotR(c, b, false);
        dots.insert(dotL);
        dots.insert(dotR);

        Line line(dotL, dotR);
        lines.insert(line);

        lengths.insert(a);
        lengths.insert(c);
    }

    int curX = 0;
    int curY = 0;

    for (set<int>::iterator lt = lengths.begin(); lt != lengths.end(); lt++)
    {
        int l = *lt;
        Dot topDot = getTopDot(dots, l);
        Dot topDot2 = getTopDotN(dots, l, 2);

        if (topDot.left && topDot.y >= curY)
        {
            if (curY != topDot.y)
            {
                if (curX != topDot.x)
                    print(topDot.x);
                print(topDot.y);
            }
            curX = topDot.x;
            curY = topDot.y;
        }
        else if (!topDot2.blankDot() && !topDot.left && topDot2.left)
        {
            curX = topDot2.x;
            curY = topDot2.y;
            print(curX);
            print(curY);
        }
        else if (!topDot.left && topDot.y == curY)
        {
            int topY = getTopLine(lines, l);
            if (topY != curY || topY == 0)
            {
                print(topDot.x);
                print(topY);
            }
            curX = topDot.x;
            curY = topY;
        }
    }
}