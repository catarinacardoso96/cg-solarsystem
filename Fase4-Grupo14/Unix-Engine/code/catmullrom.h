void buildRotMatrix(float *x, float *y, float *z, float *m);
void cross(float *a, float *b, float *res);
void normalize(float *a);
float length(float *v);
void multMatrixVector(float *m, float *v, float *res);
void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *res, float *deriv);
void getGlobalCatmullRomPoint(float gt, float *res, float *deriv, float **p, int point_count);
void renderCatmullRomCurve(float **p, int point_count);
void transformCatmulRom(float t, float **p, int point_count);