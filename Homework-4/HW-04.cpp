
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Triangle nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle>& v, int numberOfItems = 100)
{
	for(int i=0;i<100;i++)
	{
		default_random_engine engine(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int> rand(0, 100);

		Triangle rast;
		rast.a.x = rand(engine);
		rast.a.y = rand(engine);
		rast.b.x = rand(engine);
		rast.b.y = rand(engine);
		rast.c.x = rand(engine);
		rast.c.y = rand(engine);

		v.push_back(rast);
	}
}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Quadrilateral nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral>& v, int numberOfItems = 100)
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> rand(0, 100);

	Quadrilateral rast;
	rast.a.x = rand(engine);
	rast.a.y = rand(engine);
	rast.b.x = rand(engine);
	rast.b.y = rand(engine);
	rast.c.x = rand(engine);
	rast.c.y = rand(engine);
	rast.d.x = rand(engine);
	rast.d.y = rand(engine);

	v.push_back(rast);
}


/* Verilen Triangle veya Rectangle vektörününde çevre uzunluðu ve renk deðeri eþleþen ilk elemanýn indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template<class T>
int search(const vector<T>& v, const T& key)
{
	for (int i = 0; v.size(); ++i) 
	{
		if (v[i].getPerimeter() == key.getPerimeter() && v[i].getColorAsString() == key.getColorAsString())
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}


template<class T>
int sortByPerimeter(vector<T>& v)
{
	T temp;
	for(int i=0;i<v.size();++i)
	{
		for(int j=i+1;j<v.size();++j)
		{
			if(v[j].getPerimeter()<v[i].getPerimeter())
			{		
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;				
			}
		}
	}
}

int main()
{
	// Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	// Sample Quad and Triangle Objects
	auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 };
	cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

	auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15) };
	cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;


	// Filling vectors randomly
	auto vectorOfQuads = vector<Quadrilateral>{};
	auto vectorOfTriangles = vector<Triangle>{};

	fillTriangles(vectorOfTriangles);
	fillQuads(vectorOfQuads);

	// Search sample objects in the corresponding vectors
	cout << "Searching a triangle...\n";
	sampleTriangle.printInfo();
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;

	cout << "Searching a quadrilateral...\n";
	sampleQuad.printInfo();
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Add sample Triangle object to the vector and sort the vector
	vectorOfTriangles.push_back(sampleTriangle);
	sortByPerimeter(vectorOfTriangles);


	// Search sample item again. Now, you must have a hit.
	cout << "Searching a triangle...\n";
	sampleTriangle.printInfo();
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;



	// Add sample Quad object to the vector and sort the vector
	vectorOfQuads.push_back(sampleQuad);
	sortByPerimeter(vectorOfQuads);

	// Search sample item again. Now, you must have a hit.
	cout << "Searching a quadrilateral...\n";
	sampleQuad.printInfo();
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{4, 0},  Point{9, 0},  Point{14, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{4, 4},  Point{4, 4},  Point{4, 4} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{4, 0},  Point{4, 4},  Point{4, 14} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{3, 20}, Point{10, 20} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}