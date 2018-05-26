#include "bezier.h"

float* bezier_point(float** controlPoints, int size, float u, float v) {

	float m[4][4] = { { -1.0f,  3.0f, -3.0f,  1.0f },
					  { 3.0f,  -6.0f,  3.0f,  0.0f },
					  { -3.0f,  3.0f,  0.0f,  0.0f },
					  { 1.0f,	0.0f,  0.0f,  0.0f } };

	float px[16], py[16], pz[16];

	for (int i = 0; i < size; i++) {
		px[i] = controlPoints[i][0];
		py[i] = controlPoints[i][1];
		pz[i] = controlPoints[i][2];
	}

	float U[4] = { u*u*u, u*u, u, 1 };
	float V[4] = { v*v*v, v*v, v, 1 };

	float mt_V[4]; multMatrixVector((float *)m, V, mt_V);

	float px_mt_V[4]; multMatrixVector(px, mt_V, px_mt_V);
	float py_mt_V[4]; multMatrixVector(py, mt_V, py_mt_V);
	float pz_mt_V[4]; multMatrixVector(pz, mt_V, pz_mt_V);

	float m_px_mt_V[4]; multMatrixVector((float *)m, px_mt_V, m_px_mt_V);
	float m_py_mt_V[4]; multMatrixVector((float *)m, py_mt_V, m_py_mt_V);
	float m_pz_mt_V[4]; multMatrixVector((float *)m, pz_mt_V, m_pz_mt_V);

	float *p = new float[3];
	p[0] = U[0] * m_px_mt_V[0] + U[1] * m_px_mt_V[1] + U[2] * m_px_mt_V[2] + U[3] * m_px_mt_V[3];
	p[1] = U[0] * m_py_mt_V[0] + U[1] * m_py_mt_V[1] + U[2] * m_py_mt_V[2] + U[3] * m_py_mt_V[3];
	p[2] = U[0] * m_pz_mt_V[0] + U[1] * m_pz_mt_V[1] + U[2] * m_pz_mt_V[2] + U[3] * m_pz_mt_V[3];

	return p;
}

float* bezier_normal(float** controlPoints, int size, float u, float v) {
	
	float m[4][4] = { { -1.0f,  3.0f, -3.0f,  1.0f },
					  {  3.0f, -6.0f,  3.0f,  0.0f },
					  { -3.0f,  3.0f,  0.0f,  0.0f },
					  {  1.0f,	0.0f,  0.0f,  0.0f } };

	float px[16], py[16], pz[16];

	for (int i = 0; i < size; i++) {
		px[i] = controlPoints[i][0];
		py[i] = controlPoints[i][1];
		pz[i] = controlPoints[i][2];
	}
	
	//derivação U
	float dU[4] = { 3*u*u, 2*u, 1, 0 };
	float V[4] = { v*v*v, v*v, v, 1 };

	float mt_V[4]; multMatrixVector((float *)m, V, mt_V);

	float px_mt_V[4]; multMatrixVector(px, mt_V, px_mt_V);
	float py_mt_V[4]; multMatrixVector(py, mt_V, py_mt_V);
	float pz_mt_V[4]; multMatrixVector(pz, mt_V, pz_mt_V);

	float m_px_mt_V[4]; multMatrixVector((float *)m, px_mt_V, m_px_mt_V);
	float m_py_mt_V[4]; multMatrixVector((float *)m, py_mt_V, m_py_mt_V);
	float m_pz_mt_V[4]; multMatrixVector((float *)m, pz_mt_V, m_pz_mt_V);

	float pU[3];
	pU[0] = dU[0] * m_px_mt_V[0] + dU[1] * m_px_mt_V[1] + dU[2] * m_px_mt_V[2] + dU[3] * m_px_mt_V[3];
	pU[1] = dU[0] * m_py_mt_V[0] + dU[1] * m_py_mt_V[1] + dU[2] * m_py_mt_V[2] + dU[3] * m_py_mt_V[3];
	pU[2] = dU[0] * m_pz_mt_V[0] + dU[1] * m_pz_mt_V[1] + dU[2] * m_pz_mt_V[2] + dU[3] * m_pz_mt_V[3];
	
	//derivação V
	float U[4] = { u*u*u, u*u, u, 1 };
	float dV[4] = { 3*v*v, 2*v, 1, 0 };

	float mt_dV[4]; multMatrixVector((float *)m, dV, mt_dV);

	float px_mt_dV[4]; multMatrixVector(px, mt_dV, px_mt_dV);
	float py_mt_dV[4]; multMatrixVector(py, mt_dV, py_mt_dV);
	float pz_mt_dV[4]; multMatrixVector(pz, mt_dV, pz_mt_dV);

	float m_px_mt_dV[4]; multMatrixVector((float *)m, px_mt_dV, m_px_mt_dV);
	float m_py_mt_dV[4]; multMatrixVector((float *)m, py_mt_dV, m_py_mt_dV);
	float m_pz_mt_dV[4]; multMatrixVector((float *)m, pz_mt_dV, m_pz_mt_dV);

	float pV[3];
	pV[0] = U[0] * m_px_mt_dV[0] + U[1] * m_px_mt_dV[1] + U[2] * m_px_mt_dV[2] + U[3] * m_px_mt_dV[3];
	pV[1] = U[0] * m_py_mt_dV[0] + U[1] * m_py_mt_dV[1] + U[2] * m_py_mt_dV[2] + U[3] * m_py_mt_dV[3];
	pV[2] = U[0] * m_pz_mt_dV[0] + U[1] * m_pz_mt_dV[1] + U[2] * m_pz_mt_dV[2] + U[3] * m_pz_mt_dV[3];

	//calculo da normal
	normalize(pU);
	normalize(pV);

	float *normal = new float[3];
	cross(pV, pU, normal);
	normalize(normal);

	return normal;
}

void bezier(int tess, char const *file_patch, char const *file_3d) {
	int i, j, k, nr_patches, nr_cpoints;

	std::vector<int>* patches;
	std::vector<float>* cpoints;

	FILE *read = fopen(file_patch, "r");
	FILE *write = fopen(file_3d, "w");

	char buff[100];

	fgets(buff, 100, read);
	nr_patches = atoi(buff);
	patches = new std::vector<int>[nr_patches];

	for (i = 0; i < nr_patches; i++) {
		fgets(buff, 100, read);
		char *token, *nexttoken = NULL;
		token = strtok(buff, " ,");
		while (token != NULL) {
			patches[i].push_back(atoi(token));
			token = strtok(NULL, " ,");
		}
	}

	fgets(buff, 100, read);
	nr_cpoints = atoi(buff);
	cpoints = new std::vector<float>[nr_cpoints];

	for (i = 0; i < nr_cpoints; i++) {
		fgets(buff, 100, read);
		char *token, *nexttoken = NULL;
		token = strtok(buff, " ,");
		while (token != NULL) {
			cpoints[i].push_back(atof(token));
			token = strtok(NULL, " ,");
		}
	}
	fclose(read);

	float nr = tess * tess * nr_patches * 6;

	fprintf(write, "%f\n", nr);

	float** control_points = new float*[nr_patches];
	for (i = 0; i < nr_patches; i++)
		control_points[i] = new float[3];


	float*** f = new float**[tess + 1];
	float*** r = new float**[tess + 1];

	for (i = 0; i < tess + 1; i++) {
		f[i] = new float*[tess + 1];
		r[i] = new float*[tess + 1];
		for (j = 0; j < tess + 1; j++){
			f[i][j] = new float[tess + 1];
			r[i][j] = new float[tess + 1];
		}
	}

	for (i = 0; i < nr_patches; i++) {
		int patch_size = patches[i].size();

		for (j = 0; j < patch_size; j++) {
			k = patches[i][j];
			control_points[j][0] = cpoints[k][0];
			control_points[j][1] = cpoints[k][1];
			control_points[j][2] = cpoints[k][2];
		}

		for (j = 0; j <= tess; j++) {
			for (k = 0; k <= tess; k++) {
				
				float* p = bezier_point(control_points, patch_size, (float)k / tess, (float)j / tess);
				f[j][k][0] = p[0]; f[j][k][1] = p[1]; f[j][k][2] = p[2];

				float* t = bezier_normal(control_points, patch_size, (float)k / tess, (float)j / tess);
				r[j][k][0] = t[0]; r[j][k][1] = t[1]; r[j][k][2] = t[2];		
			}
		}

		for (j = 0; j < tess; j++) {
			for (k = 0; k < tess; k++) {
				fprintf(write,"%f %f %f\n",f[j][k][0], f[j][k][1], f[j][k][2]);
				fprintf(write,"%f %f %f\n",r[j][k][0], r[j][k][1], r[j][k][2]);
				fprintf(write,"%f %f\n", (float)j / tess, (float)k / tess);

				fprintf(write,"%f %f %f\n",f[j + 1][k][0], f[j + 1][k][1], f[j + 1][k][2]);
				fprintf(write,"%f %f %f\n",r[j + 1][k][0], r[j + 1][k][1], r[j + 1][k][2]);
				fprintf(write,"%f %f\n", (float)(j+1) / tess, (float)k / tess);

				fprintf(write,"%f %f %f\n",f[j][k + 1][0], f[j][k + 1][1], f[j][k + 1][2]);
				fprintf(write,"%f %f %f\n",r[j][k + 1][0], r[j][k + 1][1], r[j][k + 1][2]);
				fprintf(write,"%f %f\n", (float)j / tess, (float)(k+1) / tess);

				fprintf(write,"%f %f %f\n",f[j + 1][k][0], f[j + 1][k][1], f[j + 1][k][2]);
				fprintf(write,"%f %f %f\n",r[j + 1][k][0], r[j + 1][k][1], r[j + 1][k][2]);				
				fprintf(write,"%f %f\n", (float)(j+1) / tess, (float)k / tess);

				fprintf(write,"%f %f %f\n",f[j + 1][k + 1][0], f[j + 1][k + 1][1], f[j + 1][k + 1][2]);
				fprintf(write,"%f %f %f\n",r[j + 1][k + 1][0], r[j + 1][k + 1][1], r[j + 1][k + 1][2]);				
				fprintf(write,"%f %f\n", (float)(j+1) / tess, (float)(k+1) / tess);
				
				fprintf(write,"%f %f %f\n",f[j][k + 1][0], f[j][k + 1][1], f[j][k + 1][2]);
				fprintf(write,"%f %f %f\n",r[j][k + 1][0], r[j][k + 1][1], r[j][k + 1][2]);
				fprintf(write,"%f %f\n", (float)j / tess, (float)(k+1) / tess);
			}
		}
	}

	fclose(write);
}