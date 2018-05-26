#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <vector>
#include "catmullrom.h"

class Tag {
public:
	virtual void draw(Tag* tag) = 0;
};

class File : public Tag {
public:
	char title[15];
	int size;
	GLuint buffers[3];
	unsigned int texID = 0;

	float diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f },
		  ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f },
		  specular[4] = { 0.0f, 0.0f, 0.0f, 1.0f },
		  emission[4] = { 0.0f, 0.0f, 0.0f, 1.0f },
		  shininess[1] = { 128 };

	void draw(Tag* file) {
		File& f = dynamic_cast<File&>(*file);		

		glMaterialfv(GL_FRONT, GL_DIFFUSE, f.diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, f.ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, f.specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, f.emission);
		glMaterialfv(GL_FRONT, GL_SHININESS, f.shininess);

		glBindTexture(GL_TEXTURE_2D, f.texID);

		glBindBuffer(GL_ARRAY_BUFFER, f.buffers[0]);
		glVertexPointer(3, GL_FLOAT, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, f.buffers[1]);
		glNormalPointer(GL_FLOAT, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, f.buffers[2]);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
	
		glDrawArrays(GL_TRIANGLES, 0, f.size - 1);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
};

class Translation : public Tag {
public:
	float x, y, z;

	void draw(Tag* translation) {
		Translation& t = dynamic_cast<Translation&>(*translation);
		glTranslatef(t.x, t.y, t.z);
	}
};

class Rotation : public Tag {
public:
	float angle, x, y, z;

	void draw(Tag* rotate) {
		Rotation& r = dynamic_cast<Rotation&>(*rotate);
		glRotatef(r.angle, r.x, r.y, r.z);
	}
};

class Scale : public Tag {
public:
	float x, y, z;

	void draw(Tag* scale) {
		Scale& s = dynamic_cast<Scale&>(*scale);
		glScalef(s.x, s.y, s.z);
	}
};

class Matrix : public Tag {
public:
	bool flag;

	void draw(Tag* matrix) {
		Matrix& m = dynamic_cast<Matrix&>(*matrix);
		if (m.flag)
			glPushMatrix();
		else
			glPopMatrix();
	}
};

class CatmullRom : public Tag {
public:
	int time, size;
	float **points;

	void draw(Tag* catmullrom) {
		CatmullRom& c = dynamic_cast<CatmullRom&>(*catmullrom);
		float t;
		t = (glutGet(GLUT_ELAPSED_TIME) % (c.time * 100)) / (c.time*100.0);
		transformCatmulRom(t, c.points, c.size);
	}
};

class Spin : public Tag {
public:
	int time;
	float x, y, z;

	void draw(Tag* spin) {
		Spin& s = dynamic_cast<Spin&>(*spin);
		float t;
		t = glutGet(GLUT_ELAPSED_TIME) * 0.360 / s.time;
		glRotatef(t, s.x, s.y, s.z);
	}
};

class Light : public Tag {
public:
	GLenum number;
	float position[4];
	float direction[3];
	int angle;
	bool flag = false;

	void draw(Tag* light) {
		Light& l = dynamic_cast<Light&>(*light);
		glLightfv(l.number, GL_POSITION, l.position);
		
		if (flag) {
			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, l.direction);
			glLightf(l.number, GL_SPOT_CUTOFF, l.angle);
		}
	}
};