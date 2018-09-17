#include <iostream>
#include <cmath>
using namespace std;
struct Point{
    double x;
    double y;
};
int main()
{
    Point A1,A2,B1,B2,ACentral,BCentral;
    double Ax,Ay,Bx,By;
    int T;
    cin >> T;
    while(T--){
        cin >> A1.x >> A1.y >> A2.x >> A2.y >> B1.x >> B1.y >> B2.x >> B2.y;
        ACentral.x = (A1.x + A2.x)/2;
        ACentral.y = (A1.y + A2.y)/2;
        BCentral.x = (B1.x + B2.x)/2;
        BCentral.y = (B1.y + B2.y)/2;
        Ax = A2.x - A1.x;
        Ay = A2.y - A1.y;
        Bx = B2.x - B1.x;
        By = B2.y - B1.y;
        if (2*abs(ACentral.x - BCentral.x) > Ax + Bx){
            if (2*abs(ACentral.y - BCentral.y) > Ay + By){
                cout << "Apart" << endl;
            }
            else if (2*abs(ACentral.y - BCentral.y) == Ay + By){
                cout << "Apart" << endl;
            }
            else{
                cout << "Apart" << endl;
            }
        }
        else if (2*abs(ACentral.x - BCentral.x) == Ax + Bx){
            if (2*abs(ACentral.y - BCentral.y) > Ay + By){
                cout << "Apart" << endl;
            }
            else if (2*abs(ACentral.y - BCentral.y) == Ay + By){
                cout << "Point" << endl;
            }
            else{
                cout << "Line" << endl;
            }
        }
        else{
            if (2*abs(ACentral.y - BCentral.y) > Ay + By){
                cout << "Apart" << endl;
            }
            else if (2*abs(ACentral.y - BCentral.y) == Ay + By){
                cout << "Line" << endl;
            }
            else{
                cout << "Rectangle" << endl;
            }
        }
    }
    return 0;
}
