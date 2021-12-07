#include <iostream>
using namespace std;

struct fraction { int tu; int mau; };
void importfrac(fraction &x)
{
	do
	{
		cout << "nhap phan so: \n"; cin >> x.tu;
		cout << "--\n"; cin >> x.mau;
		if (x.mau == 0)
		{
			cout << "nhap lai\n";
		}
	} while (x.mau == 0);
}
void exportfrac(fraction x)
{
	if (x.mau == 1)
	{
		cout << x.tu << " ";
	}
	else if (x.mau == -1)
	{
		cout << -x.tu << " ";
	}
	else if (x.tu == x.mau)
	{
		cout << 1 << " ";
	}
	else if (x.tu == -x.mau)
	{
		cout << -1 << " ";
	}
	else if (x.mau<0)
	{
		cout << -x.tu << "/" << -x.mau << " ";
	}
	else
	{
		cout << x.tu << "/" << x.mau << " ";
	}
}
float frac(fraction x)
{
	return x.tu * 1.0 / x.mau;
}

void convert(fraction& a, fraction& b)
{
	fraction temp = a;
	a = b;
	b = temp;
}
void ascending(fraction x[], int n)
{
	for (int u = 1; u < n - 1; u++)
	{
		for (int v = u + 1; v < n; v++)
			if (frac(x[u]) > frac(x[v]))
			{
				convert(x[u], x[v]);
			}
	}
}
int gcd(int a, int b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
fraction sumfrac(fraction a, fraction b)
{
	int u = a.tu * b.mau + b.tu * a.mau, v = a.mau * b.mau;
	fraction s = { u/gcd(u,v), v/gcd(u,v) };
	return s;
}
int main()
{
	int i = 0, n = 0;
	fraction x[100];
	fraction s = {0,1};
	do
	{
		i++;
		importfrac(x[i]);
		n++;
		s = sumfrac(s, x[i]);
	} while (x[i].tu != 0);//nhap tu la 0 va mau la n de thuc hien phep tinh, voi n la so bat ki
	cout << fixed << "tong cac phan so da nhap: ";
	exportfrac(s);
	cout << endl;
	ascending(x, n);
	for (int i = 1; i <= n - 1; i++)
	{
		exportfrac(x[i]);
	}
	return 0;
}