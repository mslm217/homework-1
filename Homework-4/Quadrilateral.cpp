#include<iostream>
#include "Quadrilateral.h"

static const map<Quadrilateral::Color, string> colorToStringMap{{Quadrilateral::Color::RED,"Red"},
{Quadrilateral::Color::BLUE,"Blue"},
{Quadrilateral::Color::WHITE,"White"},
{Quadrilateral::Color::BLACK,"Black"},
{Quadrilateral::Color::GREEN,"Green"}
};

Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color) 
{
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	b.y = a.y + width;
	b.x = a.x;

	c.y = a.y + width;
	c.x = a.x - height;

	d.y = a.y;
	d.x = a.x - height;
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	isValid();
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	isValid();
}

Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	return colorToStringMap.at(color);
}

double Quadrilateral::getPerimeter() const noexcept
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) +
		sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y)) +
		sqrt((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) +
		sqrt((d.x - c.x) * (d.x - c.x) + (d.y - c.y) * (d.y - c.y));
}

bool Quadrilateral::isValid() const
{
	double A = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	double B = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
	double C = sqrt((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y));
	double D = sqrt((d.x - a.x) * (d.x - a.x) + (d.y - a.y) * (d.y - a.y));
	
	if((a.x=!b.x && a.x!=c.x && a.x!=d.x && b.x!=c.x && b.x!=d.x && c.x!=d.x )
		&& (a.y = !b.y && a.y != c.y && a.y != d.y && b.y != c.y && b.y != d.y && c.y != d.y))
	{
		return true;
	}
	else
	{
		throw invalid_argument("Invalid Quadrilateral!");
		return false;
	}
}

bool Quadrilateral::setA(const Point& pt)
{
	cin >> a.x >> a.y;
	return isValid();
}

bool Quadrilateral::setB(const Point& pt)
{
	cin >> b.x >> b.y;
	return isValid();
}

bool Quadrilateral::setC(const Point& pt)
{
	cin >> c.x >> c.y;
	return isValid();
}

bool Quadrilateral::setD(const Point& pt)
{
	cin >> d.x >> d.y;
	return isValid();
}

void Quadrilateral::printInfo() const noexcept
{
	cout << "Rectangle" << endl;
	cout << "Number of points: 4" << endl;
	cout << "Points: " << "(" << a.x << "," << a.y << ")" << ", "
		<< "(" << b.x << "," << b.y << ")" << ", "
		<< "(" << c.x << "," << c.y << ")" << ","
		<< "(" << d.x << "," << d.y << ")" << endl;
	cout << "Perimeterer: " << getPerimeter() << endl;
	cout << "Color: " << colorToStringMap.at(color);
}
