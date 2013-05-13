#ifndef POINT3D_H
#define POINT3D_H

#include <math.h>
#include <QPoint>
#include <iostream>

template<typename T=double> class Point
{
public:
	T p[3];
	
	Point(T X=0, T Y=0, T Z=0) {p[0]=X; p[1]=Y; p[2]=Z;}
	Point<T>(QPoint P) {p[0]=P.x(); p[1]=P.y(); p[2]=0;}
	operator T*() {return p;}
	operator const T*() {return p;}
	
	Point<T> operator + (Point<T> p2);
	Point<T> operator - (Point<T> p2);
	Point<T> operator * (Point<T> p2); //Cross product
	T dot(Point<T> p2); 
	T operator | (Point<T> p2) {return dot(p2);} //Dot product
	
	Point<T> operator + (T c);
	Point<T> operator - (T c);
	Point<T> operator * (T c);
	Point<T> operator / (T c);
	
	void operator = (Point<T> p2);
	void operator += (Point<T> p2);
	void operator -= (Point<T> p2);
	void operator += (T c);
	void operator -= (T c);
	void operator *= (T c);
	void operator /= (T c);
	
	Point<T> operator -() {return -1*(*this);}
	bool operator == (Point<T> p2);
	
	double dist(Point<T> p2);
	double mag() {return dist(Point<T>(T(0), T(0),T(0)));}
	T linedist(Point<T> x0, Point<T> x1); 
	T raydist(Point<T> x0, Point<T> x1);
	T segdist(Point<T> x0, Point<T> x1);
	Point<T> linepointvec(Point<T> x0, Point<T> x1);
	Point<T> segpointvec(Point<T> x0, Point<T> x1);
	Point<T> raypointvec(Point<T> x0, Point<T> x1);
	Point<double> unit();
	Point<T> rotate(double theta, Point<T> u);
	Point<T> rotateZero(double theta);
	Point<T> reflect(double theta);
	T theta() {return atan2(p[0],p[1]);}   
	
	T& X() {return p[0];}
	T& Y() {return p[1];}
	T& Z() {return p[2];}
	
	T& operator[](unsigned int n) {return p[n];}
	//T& operator[] const(unsigned int n) {return p[n];}
	
	//friend ostream& operator<< (ostream &out, Point<T> &p) {out << p[0] << "\t" << p[1] << "\t" << p[2];	return out;}
};

template<typename T> Point<T> Point<T>::operator + (Point<T> p2) {return Point<T>(p[0]+p2.p[0],p[1]+p2.p[1],p[2]+p2.p[2]);}
template<typename T> Point<T> Point<T>::operator - (Point<T> p2) {return Point<T>(p[0]-p2.p[0],p[1]-p2.p[1],p[2]-p2.p[2]);}
template<typename T> Point<T> Point<T>::operator * (Point<T> p2) {return Point<T>(p[1]*p2.p[2]-p[2]*p2.p[1],p[2]*p2.p[0]-p[0]*p2.p[2],p[0]*p2.p[1]-p[1]*p2.p[0]);}
template<typename T> T Point<T>::dot(Point<T> p2) {return p[0]*p2.p[0]+p[1]*p2.p[1]+p[2]*p2.p[2];}

template<typename T> Point<T> Point<T>::operator + (T c) {return Point<T>(p[0]+c,p[1]+c,p[2]+c);}
template<typename T> Point<T> Point<T>::operator - (T c) {return Point<T>(p[0]-c,p[1]-c,p[2]-c);}
template<typename T> Point<T> Point<T>::operator * (T c) {return Point<T>(p[0]*c,p[1]*c,p[2]*c);}
template<typename T> Point<T> Point<T>::operator / (T c) {return Point<T>(p[0]/c,p[1]/c,p[2]/c);}

template<typename T> void Point<T>::operator = (Point<T> p2) {p[0]=p2.p[0];p[1]=p2.p[1];p[2]=p2.p[2];}
template<typename T> void Point<T>::operator += (Point<T> p2) {p[0]+=p2.p[0];p[1]+=p2.p[1];p[2]+=p2.p[2];}
template<typename T> void Point<T>::operator -= (Point<T> p2) {p[0]-=p2.p[0];p[1]-=p2.p[1];p[2]-=p2.p[2];}
template<typename T> void Point<T>::operator += (T c) {p[0]+=c;p[1]+=c;p[2]+=c;}
template<typename T> void Point<T>::operator -= (T c) {p[0]-=c;p[1]-=c;p[2]-=c;}
template<typename T> void Point<T>::operator *= (T c) {p[0]*=c;p[1]*=c;p[2]*=c;}
template<typename T> void Point<T>::operator /= (T c) {p[0]/=c;p[1]/=c;p[2]/=c;}

template<typename T> bool Point<T>::operator == (Point<T> p2) {return ((p[0]==p2.p[0])&&(p[1]==p2.p[1])&&(p[2]==p2.p[2]));}

template<typename T> double Point<T>::dist(Point<T> p2) {return sqrt((p[0]-p2.p[0])*(p[0]-p2.p[0])+(p[1]-p2.p[1])*(p[1]-p2.p[1])+(p[2]-p2.p[2])*(p[2]-p2.p[2]));}

template<typename T> T Point<T>::linedist(Point<T> x0, Point<T> x1)
{
	Point<T> M=(x1-x0);
	return (*this-(*this|M)).mag()/(M|M); //Underwent changes recently, needs *thorough* checking
}
template<typename T> T Point<T>::raydist(Point<T> x0, Point<T> x1) 
{
	Point<T> M=(x1-x0); 
	T t0=(M|(*this-x0))/(M|M);
	if(t0<=0.0) return (*this-x0).mag();
	return linedist(x0, x1);
} 
template<typename T> T Point<T>::segdist(Point<T> x0, Point<T> x1)
{
	Point<T> M=(x1-x0); 
	T t0=(M|(*this-x0))/(M|M);
	if(t0<=0.0) return (*this-x0).mag();
	if(t0>=1.0) return (*this-x1).mag();
	return linedist(x0, x1);
} 

template<typename T> Point<T> Point<T>::linepointvec(Point<T> x0, Point<T> x1)
{
	Point<T> M=(x1-x0); 
	T t0=(M|(*this-x0))/(M|M);
	return *this-(x0+M*t0);
} 

template<typename T> Point<T> Point<T>::segpointvec(Point<T> x0, Point<T> x1)
{
	Point<T> M=(x1-x0); 
	T t0=(M|(*this-x0))/(M|M);
	if(t0<=0.0) return (*this-x0);
	if(t0>=1.0) return (*this-x1);
	return *this-(x0+M*t0);
}

template<typename T> Point<T> Point<T>::raypointvec(Point<T> x0, Point<T> x1)
{
	Point<T> M=(x1-x0); 
	T t0=(M|(*this-x0))/(M|M);
	if(t0<=0.0) return (*this-x0);
	return *this-(x0+M*t0);
} 

template<typename T> Point<double> Point<T>::unit() {T m=this->mag(); if(m==0l) return *this; return (*this)/m;}

template<typename T> Point<T> Point<T>::rotate(double theta, Point<T> u)
{
	Point<T> U=u.unit();
	double c=cos(theta);
	return (*this)*c+U*(*this)*sin(theta)+U*(U|(*this))*(1.0-c);
}

template<typename T> Point<T> Point<T>::rotateZero(double theta)
{
	double c=cos(theta);
	double s=sin(theta);
	return Point<T>(c*p[0]-s*p[1],s*p[0]+c*p[1],p[2]);
}

template<typename T> Point<T> Point<T>::reflect(double theta)
{
	double s2=sin(2*theta);
	double c2=cos(2*theta);
	return Point<T>(c2*p[0]+s2*p[1],s2*p[0]-c2*p[1]);
}

typedef Point<double> point;

#endif

