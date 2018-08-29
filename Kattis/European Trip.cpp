#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct Vec
{
    double x,y;
    Vec(double xx=0,double yy=0)
    {
        x=xx;
        y=yy;
    }
};

struct Point
{
    double x,y;
    Point(double xx=0,double yy=0)
    {
        x=xx;
        y=yy;
    }
};

double ddot(Vec A,Vec B)
{
    return A.x*B.x+A.y*B.y;
}
double getlen(Vec A)
{
    return sqrt(A.x*A.x+A.y*A.y);
}

double getlen(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

bool moreThan120(double xa,double ya,double xb,double yb,double xc,double yc)
{
    Vec ab(xb-xa,yb-ya),ac(xc-xa,yc-ya);
    if (ddot(ab,ac)/getlen(ab)/getlen(ac) < -0.5)
    {
        return true;
    }
    return false;
}//Test whether angle BAC is more than 120

inline void swap(double &a,double &b)
{
    double t;
    t=a;
    a=b;
    b=t;
}


Point getAnotherPoint(Point A,Point B,Point C)
{
    Point r,C1,C2;
    Vec AB(B.x-A.x,B.y-A.y);
    double len;
    double sqrt3=sqrt(3.0);
    Vec AB2,crossAB,crossAB2;
    
    AB2.x=AB.x/2; AB2.y=AB.y/2;
    crossAB.x=AB2.y; crossAB.y=-AB2.x;
    crossAB2.x=-AB2.y; crossAB2.y=AB2.x;
    
    len=getlen(AB2);
    
    crossAB.x*=sqrt3; crossAB.y*=sqrt3;
    crossAB2.x*=sqrt3; crossAB2.y*=sqrt3;
    
    C1.x=A.x+AB2.x+crossAB.x;C1.y=A.y+AB2.y+crossAB.y;
    C2.x=A.x+AB2.x+crossAB2.x;C2.y=A.y+AB2.y+crossAB2.y;
    
    if (getlen(C,C1)<getlen(C,C2))
    {
        return C2;
    }else
        return C1;
}


/*
 在平面内的两条直线AB,CD，求交点最直接的方法就是解下列的二元二次方程组：
 Ax + (Bx - Ax)i = Cx + (Dx - Cx) j
 Ay + (By - Ay)i = Cy + (Dy - Cy) j
 交点是:
 (Ax + (Bx - Ax) i, Ay + (By - Ay) i)
 即：
 Ax + (AAx)i = Bx + (BBx) j
 Ay + (AAy)i = By + (BBy) j
 交点是:
 (Ax + (AAx)i, Ay + (AAy)i)
 */

Point getCrossPoint(Point A,Point A1,Point B,Point B1)
{
    Point r;
    Vec AA(A1.x-A.x,A1.y-A.y),BB(B1.x-B.x,B1.y-B.y);
    double i,j,tmp,tmp2;
    double Ax=A.x,Ay=A.y,AAx=AA.x,AAy=AA.y,Bx=B.x,By=B.y,BBx=BB.x,BBy=BB.y;
    
    if (AAx==0)
    {
        j=(Ax-Bx)/BBx;
        i=(By+BBy*j-Ay)/AAx;
    }else if (BBx==0)
    {
        i=(Bx-Ax)/AAx;
    }else if (AAy==0)
    {
        j=(Ay-By)/BBy;
        i=(Bx-Ax-BBx*j)/AAx;
    }else if (BBy==0)
    {
        i=(By-Ay)/AAy;
    }
    else
    {
        tmp=AAx;
        tmp2=AAy;
        Ax*=AAy;AAx*=AAy;Bx*=AAy;BBx*=AAy;
        Ay*=tmp;AAy*=tmp;By*=tmp;BBy*=tmp;
        j=((Ax-Ay)-(Bx-By))/(BBx-BBy);
        i=(Bx+BBx*j-Ax)/AAx;
    }
    
    r.x=(Ax+AAx*i)/tmp2;
    r.y=(Ay+AAy*i)/tmp;
    return r;
}// return the cross point of A-A1 and B-B1

int main()
{
    
    double xa,ya,xb,yb,xc,yc;
    Point C1,A1,R;
    
    
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    cout.setf(ios::fixed);
    
    if (moreThan120(xa,ya,xb,yb,xc,yc))
    {
        cout<<setprecision(10)<<xa<<" "<<ya<<endl;
    }else if (moreThan120(xb,yb,xa,ya,xc,yc))
    {
        cout<<setprecision(10)<<xb<<" "<<yb<<endl;
    }else if (moreThan120(xc,yc,xa,ya,xb,yb))
    {
        cout<<setprecision(10)<<xc<<" "<<yc<<endl;
    }else
    {
        C1 = getAnotherPoint(Point(xa,ya),Point(xb,yb),Point(xc,yc));
        A1 = getAnotherPoint(Point(xc,yc),Point(xb,yb),Point(xa,ya));
        
        R = getCrossPoint(Point(xa,ya),A1,Point(xc,yc),C1);
        cout<<setprecision(10)<<R.x<<" "<<R.y<<endl;
    }
}

