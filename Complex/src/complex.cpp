#include<math.h>
#include "../include/complex.h"

using namespace std;

//构造析构取值设值
Complex::Complex(double x,double y)
{
    this->x=x;
    this->y=y;
}

Complex::~Complex()
{
    std::cout<<"复数"<<*this<<"已析构"<<endl;
}

double Complex::getX() const
{
    return this->x;
}

double Complex::getY() const
{
    return this->y;
}

void Complex::setX(double x)
{
    this->x=x;
}

void Complex::setY(double y)
{
    this->y=y;
}

//模运算用于大小比较
double Complex::ABS() const
{
    double mod=sqrt(getX()*getX() + getY()*getY());
    return mod;
}

//共轭复数
Complex Complex::converse() const
{
    Complex result(getX(), -getY());
    return result;
}

//输出重载
ostream& operator<<(ostream &os, const Complex &a) 
{
    if (a.getX() != 0)
    {
        if (a.getY() > 0)
        {
            if (a.getY() != 1)
                os << a.getX() << '+' << a.getY() << 'i';
            else   
                os << a.getX() << '+' << 'i';
        }
        else if (a.getY() == 0)
            os << a.getX();
        else
        {
            if (a.getY() != -1)
                os << a.getX() << a.getY() << 'i';
            else
                os << a.getX() << '-' << 'i';
        }
            
    }
    else
    {
        if(a.getY() == 0)
            os << '0';
        else
            os << a.getY() << 'i';
    }
    return os;
}



//与double数四则运算重载
Complex Complex::operator+(const double& other) const
{
    Complex result;
    result.setX(getX() + other);
    result.setY(getY());
    return result;
}

Complex Complex::operator-(const double& other) const
{
    Complex result;
    result.setX(getX() - other);
    result.setY(getY());
    return result;
}

Complex Complex::operator-() const
{
    Complex result(-getX(), -getY());
    return result;
}
Complex Complex::operator*(const double& other) const
{
    Complex result;
    result.setX(getX() * other);
    result.setY(getY() * other);
    return result;
}

Complex Complex::operator/(const double& other) const
{
    Complex result;
    result.setX(getX() / other);
    result.setY(getY() / other);
    return result;
}



//四则运算重载
Complex Complex::operator+(const Complex& other) const
{
    Complex result;
    result.setX(getX() + other.getX());
    result.setY(getY() + other.getY());
    return result;
}

Complex Complex::operator-(const Complex& other) const
{
    Complex result;
    result.setX(getX() - other.getX());
    result.setY(getY() - other.getY());
    return result;
}

Complex Complex::operator*(const Complex& other) const
{
    Complex result;
    result.setX(getX() * other.getX() - getY() * other.getY());
    result.setY(getX() * other.getY() + getY() * other.getX());
    return result;
}

Complex Complex::operator/(const Complex& other) const
{
    Complex result;
    Complex temp = (*this) * other.converse();
    result.setX(temp.getX() / (other.getX() * other.getX() + other.getY() * other.getY()));
    result.setY(temp.getY() / (other.getX() * other.getX() + other.getY() * other.getY()));
    return result;
}

void Complex::operator+=(const Complex& other)
{
    setX(getX() + other.getX());
    setY(getY() + other.getY());
}

void Complex::operator-=(const Complex& other)
{
    setX(getX() - other.getX());
    setY(getY() - other.getY());
}

void Complex::operator*=(const Complex& other)
{
    double x = getX();
    double y = getY();
    setX(x * other.getX() - y * other.getY());
    setY(x * other.getY() + y * other.getX());
}

void Complex::operator/=(const Complex& other)
{
    double temp = other.getX() * other.getX() + other.getY() * other.getY();
    (*this) *= other.converse();
    (*this) = (*this) / temp;
}

Complex Complex::pow(int exponent) const
{
    Complex result(1,0);
    if (exponent >= 0)
        for(int i=0;i<exponent;i++)
            result = result * (*this);
    else
        for(int i=exponent;i<0;i++)
            result = result * (*this);
    return result;
}

//关系运算符重载
bool Complex::operator<(const Complex& other) const
{
    return ABS() < other.ABS();
}

bool Complex::operator>(const Complex& other) const
{
    return ABS() > other.ABS();
}

bool Complex::operator==(const Complex& other) const
{
    return getX() == other.getX() && getY() == other.getY();
}

bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

bool Complex::operator<=(const Complex& other) const
{
    return ABS() <= other.ABS();
}

bool Complex::operator>=(const Complex& other) const
{
    return ABS() >= other.ABS();
}

int main()
{
    cout << "hello world!" << endl;
    Complex a(4,2);
    Complex b(1,1);
    Complex c = a / b;
    a /= b;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;
    cout << a * b << endl;
    return 0;
}