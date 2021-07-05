#include <iostream>
#include <string>

class Ball
{
    std::string m_color;
    double m_radius;

public:
    Ball(std::string str)
    {
        m_color = str;
        m_radius = 20.0;
    }

    Ball(double radius)
    {
        m_radius = radius;
        m_color = "Red";
    }

    Ball(const std::string& string, double radius)
    {
        m_color = string;
        m_radius = radius;
    }

    Ball()
    {
        m_color = "Red";
        m_radius = 20.0;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", " << "radius: " << m_radius << std::endl;
    }
};

int main()
{
    Ball def;
    def.print();

    Ball black("black");
    black.print();

    Ball thirty(30.0);
    thirty.print();

    Ball blackThirty("black", 30.0);
    blackThirty.print();

    return 0;
}