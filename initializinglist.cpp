#include <iostream>
#include <cstdint>

class RGBA
{
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA(std::uint8_t r, std::uint8_t g,std::uint8_t b)
    : m_red{r}, m_green{g}, m_blue{b}
    {
    }

    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" <<
        static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << std::endl;
    }
};

int main()
{
    RGBA color(0, 135, 135);
    color.print();

    return 0;
}