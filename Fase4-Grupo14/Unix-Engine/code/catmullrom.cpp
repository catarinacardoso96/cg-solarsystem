#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <math.h>
#include <vector>
#include "catmullrom.h"

float up[3] = { 0, -1, 0 };
bool flag = true;

void buildRotMatrix(float *x, float *y, float *z, float *p, float *m) {

	m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
	m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
	m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
	m[12] = p[0]; m[13] = p[1]; m[14] = p[2]; m[15] = 1;
}


void cross(float *a, float *b, float *res) {

	res[0] = a[1] * b[2] - a[2] * b[1];
	res[1] = a[2] * b[0] - a[0] * b[2];
	res[2] = a[0] * b[1] - a[1] * b[0];
}


void normalize(float *a) {

	float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] = a[0] / l;
	a[1] = a[1] / l;
	a[2] = a[2] / l;
}

void multMatrixVector(float *m, float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j * 4 + k];
		}
	}

}

void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *pos, float *deriv) {

	// catmull-rom matrix
	float m[4][4] = { { -0.5f,  1.5f, -1.5f,  0.5f },
					{    1.0f, -2.5f,  2.0f, -0.5f },
					{   -0.5f,  0.0f,  0.5f,  0.0f },
					{    0.0f,  1.0f,  0.0f,  0.0f } };

	float px[4] = { p0[0], p1[0], p2[0], p3[0] };
	float py[4] = { p0[1], p1[1], p2[1], p3[1] };
	float pz[4] = { p0[2], p1[2], p2[2], p3[2] };

	// Compute A = M * P
	float ax[4];
	float ay[4];
	float az[4];

	multMatrixVector((float *)m, px, ax);
	multMatrixVector((float *)m, py, ay);
	multMatrixVector((float *)m, pz, az);

	// Compute pos = T * A
	float T[4] = { t*t*t, t*t, t, 1 };

	pos[0] = T[0] * ax[0] + T[1] * ax[1] + T[2] * ax[2] + T[3] * ax[3];
	pos[1] = T[0] * ay[0] + T[1] * ay[1] + T[2] * ay[2] + T[3] * ay[3];
	pos[2] = T[0] * az[0] + T[1] * az[1] + T[2] * az[2] + T[3] * az[3];

	// compute deriv = T' * A
	float TT[4] = { 3 * (t*t), 2 * t, 1, 0 };

	deriv[0] = TT[0] * ax[0] + TT[1] * ax[1] + TT[2] * ax[2] + TT[3] * ax[3];
	deriv[1] = TT[0] * ay[0] + TT[1] * ay[1] + TT[2] * ay[2] + TT[3] * ay[3];
	deriv[2] = TT[0] * az[0] + TT[1] * az[1] + TT[2] * az[2] + TT[3] * az[3];
}

// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv, float **p, int point_count) {

	float t = gt * point_count; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within the segment

	// indices store the points
	int indices[4];
	indices[0] = (index + point_count - 1) % point_count;
	indices[1] = (indices[0] + 1) % point_count;
	indices[2] = (indices[1] + 1) % point_count;
	indices[3] = (indices[2] + 1) % point_count;

	getCatmullRomPoint(t, p[indices[0]], p[indices[1]], p[indices[2]], p[indices[3]], pos, deriv);
}

void renderCatmullRomCurve(float **p, int point_count) {
	float pos[3];
	float deriv[3];
	
	float diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f },
		  ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f },
		  specular[4] = { 0.0f, 0.0f, 0.0f, 1.0f },
		  emission[4] = { 0.5f, 0.5f, 0.5f, 1.0f },
		  shininess[1] = { 128 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	// desenhar a curva usando segmentos de reta - GL_LINE_LOOP
	glBegin(GL_LINE_LOOP);
	for (float i = 0.0; i < 1.0; i += 0.001) {
		getGlobalCatmullRomPoint(i, pos, deriv, p, point_count);
		glVertex3f(pos[0], pos[1], pos[2]);
	}
	glEnd();
}

void transformCatmulRom(float t, float **p, int point_count) {
	if (flag) renderCatmullRomCurve(p, point_count);

	// apply transformations here
	float pos[3];
	float deriv[3];

	getGlobalCatmullRomPoint(t, pos, deriv, p, point_count);
	normalize(deriv);

	float z[3];
	cross(deriv, up, z);
	normalize(z);

	cross(z, deriv, up);
	normalize(up);

	float m[16];
	buildRotMatrix(deriv, up, z, pos, m);

	glMultMatrixf(m);
}