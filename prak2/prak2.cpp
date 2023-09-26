// prak2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
class Point {
public:
    double x;
    double y;
    Point(double x1=0.0, double y1=0.0):x(x1),y(y1)
    {
       
    }
   
};
   class Triangle {
    
       Point* points;
    
   
    public:
        Triangle(Point& p1, Point& p2, Point &p3)
        {
            points = new Point[3]{ p1,p2,p3 };
            
        }
        double area() 
        {
            if (checking(points[0], points[1],points[2]))
            {
                double p = (distance(points[0], points[1]) + distance(points[0], points[2]) + distance(points[1], points[2])) / 2;
                return sqrt(p * (p - distance(points[0], points[1])) * (p - distance(points[0], points[2])) * (p - distance(points[1], points[2])));
            }
            else
            {
                std::cout<<"collinear lines"<<std::endl;
                return NULL;
            }
            }
   private:

       double distance(Point  &pp1, Point &pp2) 
       {
           return  sqrt( (pp1.x - pp2.x)* (pp1.x - pp2.x) + (pp1.y - pp2.y)* (pp1.y - pp2.y));

       }
        bool  checking(Point& pp1, Point& pp2, Point& pp3)
       {
           if ((pp1.x - pp2.x) / (pp1.y - pp2.y)== (pp1.x - pp3.x) / ((pp1.y - pp3.y)))
           {
               return false;
           }
           else
           {
               return true;
           }
       }

   };
int main()
{
    Point p1(1, 2), p2(3, 4), p3(5, 6);
    Triangle triangle(p1, p2, p3);
    double r = triangle.area();
    std::cout  <<r << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
