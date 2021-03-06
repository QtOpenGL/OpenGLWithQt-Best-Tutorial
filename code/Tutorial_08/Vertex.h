/************************************************************************************

OpenGL with Qt - Tutorial
-------------------------
Autor      : Andreas Nicolai <andreas.nicolai@gmx.net>
Repository : https://github.com/ghorwin/OpenGLWithQt-Tutorial
License    : BSD License,
			 see https://github.com/ghorwin/OpenGLWithQt-Tutorial/blob/master/LICENSE

************************************************************************************/

#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>
#include <QColor>
#include <QtGui/qopengl.h> // for GLUint


/*! A container class to store data (coordinates, normals, textures, colors) of a vertex, used for interleaved
	storage. Expand this class as needed.

	Memory layout (each char is a byte): xxxxyyyyzzzzrrrrggggbbbbiiiijjjj = 8*4 = 32 Bytes

	You can define a vector<Vertex> and use this directly as input to the vertex buffer.

	Mind implicit padding by compiler! Hence, for allocation use:
	- sizeof(Vertex) as stride
	- offsetof(Vertex, r) as start offset for the color
	- offsetof(Vertex, i) as start offset for the texture coordinates

	This will only become important, if mixed data types are used in the struct.
	Read http://www.catb.org/esr/structure-packing/ for an in-depth explanation.
*/
struct Vertex {
	Vertex() {}
	Vertex(const QVector3D & coords, const QColor & col) :
		x(float(coords.x())),
		y(float(coords.y())),
		z(float(coords.z())),
		r(float(col.redF())),
		g(float(col.greenF())),
		b(float(col.blueF())),
		texi(0),
		texj(0),
		texID(0)
	{
	}
	Vertex(const QVector3D & coords, const QColor & col, float textureX, float textureY, GLint textureID = 0) :
		x(float(coords.x())),
		y(float(coords.y())),
		z(float(coords.z())),
		r(float(col.redF())),
		g(float(col.greenF())),
		b(float(col.blueF())),
		texi(textureX),
		texj(textureY),
		texID(textureID)
	{
	}

	float x,y,z;
	float r,g,b;
	float texi,texj;
	float texID;
};

#endif // VERTEX_H
