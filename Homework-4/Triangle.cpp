#include<iostream>
#include "Triangle.h"

static const map<Triangle::Color, string> colorToStringMap{{Triangle::Color::PINK,"Pink"},
{Triangle::Color::RED,"Red"},
{Triangle::Color::BLUE,"Blue"},
{Triangle::Color::WHITE,"White"},
{Triangle::Color::BLACK,"Black"},
{Triangle::Color::GREEN,"Green"}
};
Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	isValid();
}

Triangle::Triangle(const vector<Point>& pts, const Color& color) : pts{ pts[0] }
{
	
	isValid();
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	isValid();
}

Point Triangle::getA() const noexcept
{
	return a;
}

Point Triangle::getB() const noexcept
{
	return b;
}

Point Triangle::getC() const noexcept
{
	return c;
}

Triangle::Color Triangle::getColor() const noexcept
{
	return color;
}

string Triangle::getColorAsString() const noexcept
{
	return colorToStringMap.at(color);
}

double Triangle::getPerimeter() const noexcept
{
	return sqrt((a.x-b.x)*(a.x-b.x)+ (a.y - b.y) * (a.y - b.y))+
		sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y))+ 
		sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
}

bool Triangle::setA(const Point& pt)
{
	cin >> a.x >> a.y;

	return isValid();
}

bool Triangle::setB(const Point& pt)
{
	cin >> b.x >> b.y;
	
	return isValid();
}

bool Triangle::setC(const Point& pt)
{
	cin >> c.x >> c.y;

	return isValid();
}

bool Triangle::isValid() const
{
	double A = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	double B = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
	double C = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
	
	if(abs(A-B)<C<A+B && abs(A-C)<B<A+B && abs(B-C)<A<B+C && (a.x!=b.x && a.x!=c.x && b.x!=c.x)&& (a.y != b.y && a.y != c.y && b.y != c.y))
	{
		return true;
	}
	else
	{ 
		throw invalid_argument("Invalid Triangle!");
		return false;
	}
}

void Triangle::printInfo() const noexcept
{
	cout << "Triangle" << endl;
	cout << "Number of points: 3" << endl;
	cout << "Points: " << "(" << a.x << "," << a.y << ")" << ", "
		<< "(" << b.x << "," << b.y << ")" << ", "
		<< "(" << c.x << "," << c.y << ")" << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
	cout << "Color: " << colorToStringMap.at(color) << endl;
}
