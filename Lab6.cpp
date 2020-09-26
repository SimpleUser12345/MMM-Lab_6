#include <iostream>
#include <cmath>

using namespace std;

float f(float x1, float x2)
{
	return x1*x1*x1*x1 + 24*x1*x1*x1 + 2*x1*x1*x2*x2 - 32*x1*x1*x2+344*x1*x1+24*x1*x2*x2-384*x1*x2+2396*x1+x2*x2*x2*x2-32*x2*x2*x2+456*x2*x2-3200*x2+9979;
}

float g1(float x1, float x2)
{
	return 4*x1*x1*x1+24*3*x1*x1+4*x1*x2*x2-64*x1*x2+688*x1+24*x2*x2-384*x2+2396;
}

float g2(float x1, float x2)
{
	return 4*x1*x1*x2-32*x1*x1+48*x1*x2-384*x1+4*x2*x2*x2-32*3*x2*x2+456*2*x2-3200;
}

float abs(float x1, float x2)
{
	return sqrtf(x1*x1+x2*x2);
}

float dist(float x1, float x2, float y1, float y2)
{
	return abs(x1-y1,x2-y2);
}

float step(float &x1, float &x2, float &a)
{
	float grad1 = g1(x1,x2), grad2=g2(x1,x2);
	float abs_grad = abs(grad1, grad2);
	
	float y1 = x1 - a*grad1/abs_grad;
	float y2 = x2 - a*grad2/abs_grad;

	float pf = f(x1,x2);
	float f1 = f(y1, y2);
	
	if(f1 < pf)
	{
		x1 = y1; x2 = y2;
		return f1;
	}
	else
	{
		a *= 0.5;
	}
	return pf;
}

float EPS = 1e-6;

int main()
{
	float x1 = 6, x2 = -6, px1, px2, func = 0, pfunc = 0;
	float h = 0.1;
	
	int i=0;
	do 
	{
		pfunc = func;
		px1 = x1; px2 = x2; 
		func = step(x1, x2, h);
		cout << i << ") x1 = " << x1 << ", x2 = " << x2 << " h = " << h << "; f = " << func << endl;
		i++;
	}
	while(dist(x1,x2, px1,px2) > EPS || fabs(func-pfunc) > EPS);
	
	cout << "X* = (" << x1 << ", " << x2 << ") f = " << func << endl;
}
