#ifndef COMPLEX_H  // 包含保护防止重复包含
#define COMPLEX_H

#include<iostream>
using namespace std;
class Complex
{
    friend ostream& operator<<(ostream& os, const Complex& a);
private:
    double x;
    double y;
public:
    Complex():x(0),y(0){};
    Complex(double x,double y);
    ~Complex();
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    //计算复数的模
    double ABS() const;
    //计算共轭复数
    Complex converse() const;
    //与double数四则运算重载
    Complex operator+(const double& other) const;
    Complex operator-(const double& other) const;
    Complex operator*(const double& other) const;
    Complex operator/(const double& other) const;
    //算术运算符重载
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    //关系运算符重载
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>=(const Complex& other) const;
};

//输出重载
ostream& operator<<(ostream& os, const Complex& a);

#endif