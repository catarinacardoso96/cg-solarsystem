#include "figures.h"

void plane (float x, float z, float d, char const *file) {
	if (x <= 0 || z <= 0 || d <= 0) {
		printf("Plane: invalid input\n");
		return;
	}

	FILE *fd = fopen(file,"w");
	float nr = d*d*6;
	fprintf(fd,"%f\n",nr);

	int i, j;

	for (i = 0; i < d; i++) {
		for (j = 0; j < d; j++) {

			fprintf(fd,"%f %f %f\n",-x / 2 + j*x / d, 0.0, -z / 2 + i*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", j/d, i/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + j*x / d, 0.0, -z / 2 + (i + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", j/d, (i+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (j+1)*x / d, 0.0, -z / 2 + i*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", (j+1)/d, i/d);

			fprintf(fd,"%f %f %f\n",-x / 2 + j*x / d, 0.0, -z / 2 + (i + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", j/d, (i+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (j+1)*x / d, 0.0, -z / 2 + (i+1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", (j+1)/d, (i+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (j + 1)*x / d, 0.0, -z / 2 + i*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", (j+1)/d, i/d);
		}
	}

	fclose(fd);
}


void box (float x, float y, float z, float d, char const *file) {
	if (x <= 0 || y <= 0 || z <= 0 || d <= 0) {
		printf("Box: invalid input\n");
		return;
	}

	FILE *fd = fopen(file,"w");
	float nr = 36*d*d;
	fprintf(fd,"%f\n",nr);

	int i, j;

	for (i = 0; i < d; i++) {
		for (j = 0; j < d; j++) {

			//face de baixo xz
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i+1)*x / d, -y / 2, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i+1)*x / d, -y / 2, -z / 2 + (j+1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);

			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2, -z / 2 + (j+1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, (j+1)/d);

			//face de cima xz
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, y / 2, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, y / 2, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, y / 2, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, j/d);

			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, y / 2, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, y / 2, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, y / 2, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);

			//face da frente xy
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2 + j*y / d, z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, 1.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2 + j*y / d, z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, 1.0);
			fprintf(fd,"%f %f\n", (i+1)/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2 + (j + 1)*y / d, z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, 1.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);

			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2 + j*y / d, z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, 1.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2 + (j + 1)*y / d, z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, 1.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2 + (j + 1)*y / d, z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, 1.0);
			fprintf(fd,"%f %f\n", i/d, (j+1)/d);

			//face de trás xy
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2 + j*y / d, -z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, -1.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2 + (j + 1)*y / d, -z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, -1.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2 + j*y / d, -z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, -1.0);
			fprintf(fd,"%f %f\n", (i+1)/d, j/d);

			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2 + j*y / d, -z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, -1.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + i*x / d, -y / 2 + (j + 1)*y / d, -z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, -1.0);
			fprintf(fd,"%f %f\n", i/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2 + (i + 1)*x / d, -y / 2 + (j + 1)*y / d, -z / 2);
			fprintf(fd,"%f %f %f\n", 0.0, 0.0, -1.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);

			//face da direita yz
			fprintf(fd,"%f %f %f\n",x / 2, -y / 2 + i*y / d, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",x / 2, -y / 2 + (i + 1)*y / d, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",x / 2, -y / 2 + i*y / d, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, (j+1)/d);

			fprintf(fd,"%f %f %f\n",x / 2, -y / 2 + i*y / d, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",x / 2, -y / 2 + (i + 1)*y / d, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", 1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, j/d);
			fprintf(fd,"%f %f %f\n",x / 2, -y / 2 + (i + 1)*y / d, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", 1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);

			//face de esquerda yz
			fprintf(fd,"%f %f %f\n",-x / 2, -y / 2 + i*y / d, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", -1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2, -y / 2 + i*y / d, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", -1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2, -y / 2 + (i + 1)*y / d, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", -1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);

			fprintf(fd,"%f %f %f\n",-x / 2, -y / 2 + i*y / d, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", -1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", i/d, j/d);
			fprintf(fd,"%f %f %f\n",-x / 2, -y / 2 + (i + 1)*y / d, -z / 2 + (j + 1)*z / d);
			fprintf(fd,"%f %f %f\n", -1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, (j+1)/d);
			fprintf(fd,"%f %f %f\n",-x / 2, -y / 2 + (i + 1)*y / d, -z / 2 + j*z / d);
			fprintf(fd,"%f %f %f\n", -1.0, 0.0, 0.0);
			fprintf(fd,"%f %f\n", (i+1)/d, j/d);
		}
	}

	fclose(fd);
}


void sphere (float r, float sl, float st, char const *file) {
	if (r <= 0 || sl < 2 || st < 2) {
		printf("Sphere: invalid input\n");
		return;
	}

	FILE *fd = fopen(file,"w");
	float nr = 6*sl*(st-1);
	fprintf(fd,"%f\n",nr);

	int i, j;
	float teta, fi;

	for (i = 0; i < st; i++) {
		for (j = 0; j < sl; j++) {
			
			if (i != st-1) {
				fi = i * M_PI / st;
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",r*cos(teta)*sin(fi), r*cos(fi), r*sin(teta)*sin(fi));
				fprintf(fd,"%f %f %f\n",cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
				fprintf(fd,"%f %f\n",j/sl, i/st);
				fi = (i + 1) * M_PI / st;
				teta = (j + 1) * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",r*cos(teta)*sin(fi), r*cos(fi), r*sin(teta)*sin(fi));
				fprintf(fd,"%f %f %f\n",cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
				fprintf(fd,"%f %f\n",(j+1)/sl, (i+1)/st);
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",r*cos(teta)*sin(fi), r*cos(fi), r*sin(teta)*sin(fi));
				fprintf(fd,"%f %f %f\n",cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
				fprintf(fd,"%f %f\n",j/sl, (i+1)/st);
			}

			if (i != 0) {
				fi = i * M_PI / st;
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",r*cos(teta)*sin(fi), r*cos(fi), r*sin(teta)*sin(fi));
				fprintf(fd,"%f %f %f\n",cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
				fprintf(fd,"%f %f\n",j/sl, i/st);
				teta = (j + 1) * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",r*cos(teta)*sin(fi), r*cos(fi), r*sin(teta)*sin(fi));
				fprintf(fd,"%f %f %f\n",cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
				fprintf(fd,"%f %f\n",(j+1)/sl, i/st);
				fi = (i + 1) * M_PI / st;
				fprintf(fd,"%f %f %f\n",r*cos(teta)*sin(fi), r*cos(fi), r*sin(teta)*sin(fi));
				fprintf(fd,"%f %f %f\n",cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
				fprintf(fd,"%f %f\n",(j+1)/sl, (i+1)/st);
			}
		}
	}

	fclose(fd);
}


void cone (float r, float a, float sl, float st, char const *file) {	
	if (r <= 0 || a <= 0 || sl < 2 || st < 2) {
		printf("Cone: invalid input\n");
		return;
	}

	FILE *fd = fopen(file,"w");
	float nr = 6*sl*st;
	fprintf(fd,"%f\n",nr);

	int i, j;
	float h, s, teta, m;

	for (i = 0; i < sl; i++) {
		fprintf(fd,"%f %f %f\n",0.0, 0.0, 0.0);
		fprintf(fd,"%f %f %f\n",0.0, -1.0, 0.0);
		fprintf(fd,"%f %f\n",0.5, 0.5);
		teta = i * 2 * M_PI / sl;
		fprintf(fd,"%f %f %f\n",r*cos(teta), 0.0, r*sin(teta));
		fprintf(fd,"%f %f %f\n",0.0, -1.0, 0.0);
		fprintf(fd,"%f %f\n",0.5 + 0.5 * cos(teta), 0.5 + 0.5 * sin(teta));
		teta = (i + 1) * 2 * M_PI / sl;
		fprintf(fd,"%f %f %f\n",r*cos(teta), 0.0, r*sin(teta));
		fprintf(fd,"%f %f %f\n",0.0, -1.0, 0.0);
		fprintf(fd,"%f %f\n",0.5 + 0.5 * cos(teta), 0.5 + 0.5 * sin(teta));
	}

	for (i = 0; i < st; i++) {
		for (j = 0; j < sl; j++) {

			if (i != st - 1) {
				h = i * a / st;
				s = (a - h)*r / a;
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/r, a/r, s*sin(teta)/m * a/r);
				fprintf(fd,"%f %f\n", j/sl, i/st);

				h = (i + 1) * a / st;
				s = (a - h)*r / a;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/r, a/r, s*sin(teta)/m * a/r);
				fprintf(fd,"%f %f\n", j/sl, (i+1)/st);
				
				teta = (j + 1) * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/r, a/r, s*sin(teta)/m * a/r);
				fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);
			}

				h = i * a / st;
				s = (a - h)*r / a;
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/r, a/r, s*sin(teta)/m * a/r);
				fprintf(fd,"%f %f\n", j/sl, i/st);
				
				h = (i + 1) * a / st;
				s = (a - h)*r / a;
				teta = (j + 1) * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/r, a/r, s*sin(teta)/m * a/r);
				fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);
				
				h = i * a / st;
				s = (a - h)*r / a;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/r, a/r, s*sin(teta)/m * a/r);
				fprintf(fd,"%f %f\n", (j+1)/sl, i/st);
		}
	}

	fclose(fd);
}


void cylinder (float br, float tr, float a, float sl, float st, char const *file) {
	if ((br == 0 && tr == 0) || tr < 0 || br < 0 || a <= 0 || sl < 2 || st < 2) {
		printf("Cylinder: invalid input\n");
		return;
	}

	FILE *fd = fopen(file,"w");
	float nr;
	if (br == 0 || tr == 0) 
		nr= 6*sl*st;
	else
		nr = 6 * sl + 6 * st*sl;
	fprintf(fd,"%f\n",nr);

	int i, j;
	float h, s, t, teta, m;

	if(br>tr)
		t = -a*br / (tr-br);
	else
		t = -a*tr / (br - tr);
	
	for (i = 0; i < sl; i++) {
		if (br != 0) {
			fprintf(fd,"%f %f %f\n",0.0, 0.0, 0.0);
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n",0.5, 0.5);

			teta = i * 2 * M_PI / sl;
			fprintf(fd,"%f %f %f\n",br*cos(teta), 0.0, br*sin(teta));
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n",0.5 + 0.5 * cos(teta), 0.5 + 0.5 * sin(teta));

			teta = (i + 1) * 2 * M_PI / sl;
			fprintf(fd,"%f %f %f\n",br*cos(teta), 0.0, br*sin(teta));
			fprintf(fd,"%f %f %f\n", 0.0, -1.0, 0.0);
			fprintf(fd,"%f %f\n",0.5 + 0.5 * cos(teta), 0.5 + 0.5 * sin(teta));
		}

		if (tr != 0) {
			fprintf(fd,"%f %f %f\n",0.0, a, 0.0);
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n",0.5, 0.5);
			teta = (i + 1) * 2 * M_PI / sl;

			fprintf(fd,"%f %f %f\n",tr*cos(teta), a, tr*sin(teta));
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n",0.5 + 0.5 * cos(teta), 0.5 + 0.5 * sin(teta));

			teta = i * 2 * M_PI / sl;
			fprintf(fd,"%f %f %f\n",tr*cos(teta), a, tr*sin(teta));
			fprintf(fd,"%f %f %f\n", 0.0, 1.0, 0.0);
			fprintf(fd,"%f %f\n",0.5 + 0.5 * cos(teta), 0.5 + 0.5 * sin(teta));
		}	
	}
	
	if (br > tr) {

		for (i = 0; i < st; i++) {
			for (j = 0; j < sl; j++) {
				if (tr != 0 || i != st - 1) {
					h = i*a / st;
					s = br - h*br / t;
					teta = j * 2 * M_PI / sl;
					fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
					m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
					fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/br, a/br, s*sin(teta)/m * a/br);
					fprintf(fd,"%f %f\n", j/sl, i/st);
					
					h = (i + 1)*a / st;
					s = br - h*br / t;
					fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
					m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
					fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/br, a/br, s*sin(teta)/m * a/br);
					fprintf(fd,"%f %f\n", j/sl, (i+1)/st);

					teta = (j + 1) * 2 * M_PI / sl;
					fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
					m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
					fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/br, a/br, s*sin(teta)/m * a/br);
					fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);

				}
				
				h = i*a / st;
				s = br - h*br / t;
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/br, a/br, s*sin(teta)/m * a/br);
				fprintf(fd,"%f %f\n", j/sl, i/st);

				h = (i + 1)*a / st;
				s = br - h*br / t;
				teta = (j + 1) * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/br, a/br, s*sin(teta)/m * a/br);
				fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);

				h = i*a / st;
				s = br - h*br / t;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/br, a/br, s*sin(teta)/m * a/br);
				fprintf(fd,"%f %f\n", (j+1)/sl, i/st);
			}
		}
	} else {

		for (i = 0; i < st; i++) {
			for (j = 0; j < sl; j++) {
				h = i*a / st;
				s = tr - (a - h)*tr / t;
				teta = j * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/tr, a/tr, s*sin(teta)/m * a/tr);
				fprintf(fd,"%f %f\n", j/sl, i/st);

				h = (i + 1)*a / st;
				s = tr - (a - h)*tr / t;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/tr, a/tr, s*sin(teta)/m * a/tr);
				fprintf(fd,"%f %f\n", j/sl, (i+1)/st);

				teta = (j + 1) * 2 * M_PI / sl;
				fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
				m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
				fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/tr, a/tr, s*sin(teta)/m * a/tr);
				fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);

				if (br != 0 || i != 0) {
					h = i*a / st;
					s = tr - (a - h)*tr / t;
					teta = j * 2 * M_PI / sl;
					fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
					m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
					fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/tr, a/tr, s*sin(teta)/m * a/tr);
					fprintf(fd,"%f %f\n", j/sl, i/st);

					h = (i + 1)*a / st;
					s = tr - (a - h)*tr / t;
					teta = (j + 1) * 2 * M_PI / sl;
					fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
					m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
					fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/tr, a/tr, s*sin(teta)/m * a/tr);
					fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);

					h = i*a / st;
					s = tr - (a - h)*tr / t;
					fprintf(fd,"%f %f %f\n",s*cos(teta), h, s*sin(teta));
					m = sqrt( ((s*cos(teta))*(s*cos(teta))) + ((s*sin(teta))*(s*sin(teta))) );
					fprintf(fd,"%f %f %f\n", s*cos(teta)/m * a/tr, a/tr, s*sin(teta)/m * a/tr);
					fprintf(fd,"%f %f\n", (j+1)/sl, i/st);
				}
			}
		}
	}

	fclose(fd);
}

void torus (float inr, float outr, float sides, float rings, char const *file) {
	if (inr == outr || sides < 3 || rings < 3) {
		printf("Torus: invalid input\n");
		return;
	}

	FILE *fd = fopen(file, "w");
	float nr = 6 * sides*rings;
	fprintf(fd, "%f\n", nr);

	int i, j;
	float teta, fi, R, r;
	float tb[3], ts[3], normal[3];
	
	R = (outr + inr) / 2;
	r = (outr - inr) / 2;

	for (i = 0; i < sides; i++) {
		for (j = 0; j < rings; j++) {

			teta = 2 * i * M_PI / sides;
			fi = 2 * j * M_PI / rings;
			fprintf(fd, "%f %f %f\n", (R + r*cos(teta))*cos(fi), r*sin(teta), (R + r*cos(teta))*sin(fi));
			tb[0] = -sin(fi); tb[1] = 0; tb[2] = cos(fi);
			ts[0] = cos(fi)*(-sin(teta)); ts[1] = cos(teta); ts[2] = sin(fi)*(-sin(teta));
			cross(ts, tb, normal);
			normalize(normal);
			fprintf(fd, "%f %f %f\n", normal[0], normal[1], normal[2]);
			fprintf(fd, "%f %f\n", j/rings, i/sides);

			teta = 2 * (i + 1) * M_PI / sides;
			fprintf(fd, "%f %f %f\n", (R + r*cos(teta))*cos(fi), r*sin(teta), (R + r*cos(teta))*sin(fi));
			tb[0] = -sin(fi); tb[1] = 0; tb[2] = cos(fi);
			ts[0] = cos(fi)*(-sin(teta)); ts[1] = cos(teta); ts[2] = sin(fi)*(-sin(teta));
			cross(ts, tb, normal);
			normalize(normal);
			fprintf(fd, "%f %f %f\n", normal[0], normal[1], normal[2]);fprintf(fd, "%f %f\n", j/rings, (i+1)/sides);

			fi = 2 * (j + 1) * M_PI / rings;
			fprintf(fd, "%f %f %f\n", (R + r*cos(teta))*cos(fi), r*sin(teta), (R + r*cos(teta))*sin(fi));
			tb[0] = -sin(fi); tb[1] = 0; tb[2] = cos(fi);
			ts[0] = cos(fi)*(-sin(teta)); ts[1] = cos(teta); ts[2] = sin(fi)*(-sin(teta));
			cross(ts, tb, normal);
			normalize(normal);
			fprintf(fd, "%f %f %f\n", normal[0], normal[1], normal[2]);fprintf(fd, "%f %f\n",  (j+1)/rings, (i+1)/sides);

			fprintf(fd, "%f %f %f\n", (R + r*cos(teta))*cos(fi), r*sin(teta), (R + r*cos(teta))*sin(fi));
			tb[0] = -sin(fi); tb[1] = 0; tb[2] = cos(fi);
			ts[0] = cos(fi)*(-sin(teta)); ts[1] = cos(teta); ts[2] = sin(fi)*(-sin(teta));
			cross(ts, tb, normal);
			normalize(normal);
			fprintf(fd, "%f %f %f\n", normal[0], normal[1], normal[2]);fprintf(fd, "%f %f\n", (j+1)/rings, (i+1)/sides);

			teta = 2 * i * M_PI / sides;
			fprintf(fd, "%f %f %f\n", (R + r*cos(teta))*cos(fi), r*sin(teta), (R + r*cos(teta))*sin(fi));
			tb[0] = -sin(fi); tb[1] = 0; tb[2] = cos(fi);
			ts[0] = cos(fi)*(-sin(teta)); ts[1] = cos(teta); ts[2] = sin(fi)*(-sin(teta));
			cross(ts, tb, normal);
			normalize(normal);
			fprintf(fd, "%f %f %f\n", normal[0], normal[1], normal[2]);fprintf(fd, "%f %f\n", (j+1)/rings, i/sides);
			
			teta = 2 * i * M_PI / sides;
			fi = 2 * j * M_PI / rings;
			fprintf(fd, "%f %f %f\n", (R + r*cos(teta))*cos(fi), r*sin(teta), (R + r*cos(teta))*sin(fi));
			tb[0] = -sin(fi); tb[1] = 0; tb[2] = cos(fi);
			ts[0] = cos(fi)*(-sin(teta)); ts[1] = cos(teta); ts[2] = sin(fi)*(-sin(teta));
			cross(ts, tb, normal);
			normalize(normal);
			fprintf(fd, "%f %f %f\n", normal[0], normal[1], normal[2]);fprintf(fd, "%f %f\n", j/rings, i/sides);
		}
	}

	fclose(fd);
}


void ellipsoid (float a, float b, float c, float sl, float st, char const *file) {
	if (a <= 0 || b <= 0 || c <= 0 || sl < 2 || st < 2) {
		printf("Ellipsoid: invalid input\n");
		return;
	}

	FILE *fd = fopen(file, "w");
	float nr = 6 * sl*(st - 1);
	fprintf(fd, "%f\n", nr);

	int i, j;
	float teta, fi;

	for (i = 0; i < sl; i++) {
		for (j = 0; j < st; j++) {

			if (j != st - 1) {
				teta = i * 2 * M_PI / sl;
				fi = j * M_PI / st;
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f\n", i/sl, j/st);

				teta = (i + 1) * 2 * M_PI / sl;
				fi = (j + 1) * M_PI / st;
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f\n", (i+1)/sl, (j+1)/st);

				teta = i * 2 * M_PI / sl;
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f\n", i/sl, (j+1)/st);
			}

			if (j != 0) {
				teta = i * 2 * M_PI / sl;
				fi = j * M_PI / st;
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f\n", i/sl, j/st);

				teta = (i + 1) * 2 * M_PI / sl;
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f\n", (i+1)/sl, j/st);

				fi = (j + 1) * M_PI / st;
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f %f\n", a*cos(teta)*sin(fi), b*cos(fi), c*sin(teta)*sin(fi));
				fprintf(fd, "%f %f\n", (i+1)/sl, (j+1)/st);
			}
		}
	}

	fclose(fd);
}



void crown(float inr, float outr, float sl, char const *file){
	if (inr <= 0 || outr <= inr || sl < 3) {
		printf("Crown: invalid input\n");
		return;
	}

	FILE *fd = fopen(file, "w");
	float nr = 12 * sl;
	fprintf(fd, "%f\n", nr);

	int i;
	float teta;

	for (i = 0; i < sl; i++) {
		teta = 2 * i*M_PI / sl;
		fprintf(fd, "%f %f %f\n", outr*cos(teta), 0.0f, outr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, -1.0, 0.0);
		fprintf(fd, "%f %f\n", 1.0, i/sl);

		teta = 2 * (i+1)*M_PI / sl;
		fprintf(fd, "%f %f %f\n", outr*cos(teta), 0.0f, outr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, -1.0, 0.0);
		fprintf(fd, "%f %f\n", 1.0, (i+1)/sl);

		fprintf(fd, "%f %f %f\n", inr*cos(teta), 0.0f, inr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, -1.0, 0.0);
		fprintf(fd, "%f %f\n", 0.0, (i+1)/sl);


		teta = 2 * i*M_PI / sl;
		fprintf(fd, "%f %f %f\n", outr*cos(teta), 0.0f, outr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, -1.0, 0.0);
		fprintf(fd, "%f %f\n", 1.0, i/sl);

		teta = 2 * (i + 1)*M_PI / sl;
		fprintf(fd, "%f %f %f\n", inr*cos(teta), 0.0f, inr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, -1.0, 0.0);
		fprintf(fd, "%f %f\n", 0.0, (i+1)/sl);

		teta = 2 * i*M_PI / sl;
		fprintf(fd, "%f %f %f\n", inr*cos(teta), 0.0f, inr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, -1.0, 0.0);
		fprintf(fd, "%f %f\n", 0.0, i/sl);


		teta = 2 * i*M_PI / sl;
		fprintf(fd, "%f %f %f\n", outr*cos(teta), 0.0f, outr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, 1.0, 0.0);
		fprintf(fd, "%f %f\n", 1.0, i/sl);

		teta = 2 * (i + 1)*M_PI / sl;
		fprintf(fd, "%f %f %f\n", inr*cos(teta), 0.0f, inr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, 1.0, 0.0);
		fprintf(fd, "%f %f\n", 0.0, (i+1)/sl);

		fprintf(fd, "%f %f %f\n", outr*cos(teta), 0.0f, outr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, 1.0, 0.0);
		fprintf(fd, "%f %f\n", 1.0, (i+1)/sl);


		teta = 2 * i*M_PI / sl;
		fprintf(fd, "%f %f %f\n", outr*cos(teta), 0.0f, outr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, 1.0, 0.0);
		fprintf(fd, "%f %f\n", 1.0, i/sl);

		teta = 2 * i*M_PI / sl;
		fprintf(fd, "%f %f %f\n", inr*cos(teta), 0.0f, inr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, 1.0, 0.0);
		fprintf(fd, "%f %f\n", 0.0, i/sl);

		teta = 2 * (i + 1)*M_PI / sl;
		fprintf(fd, "%f %f %f\n", inr*cos(teta), 0.0f, inr*sin(teta));
		fprintf(fd, "%f %f %f\n", 0.0, 1.0, 0.0);
		fprintf(fd, "%f %f\n", 0.0, (i+1)/sl);
	}

	fclose(fd);
}


void belt(float n, float r, float sl, float st, float inr, float outr, char const *file){
	if (n < 1 | r <= 0 | sl < 2 | st < 2 | inr < 0 | outr < inr){
		printf("Belt: invalid input\n");
		return;
	}
	FILE *fd = fopen(file,"w");
	float nr = 6*n*sl*(st-1);
	fprintf(fd,"%f\n",nr);

	int i, j, c = 0;
	float teta, fi, x, y, z;

	while (c <= n) {
		x = (rand() / (float)RAND_MAX) * outr*2 - outr;
		y = (rand() / (float)RAND_MAX) * r*4 - r*2;
		z = (rand() / (float)RAND_MAX) * outr*2 - outr;
		if (x*x + z*z > inr*inr && x*x + z*z < outr*outr) {
			c++;

			for (i = 0; i < st; i++) {
				for (j = 0; j < sl; j++) {

					if (i != st - 1) {
						fi = i * M_PI / st;
						teta = j * 2 * M_PI / sl;
						fprintf(fd, "%f %f %f\n", r*cos(teta)*sin(fi) + x, r*cos(fi) + y, r*sin(teta)*sin(fi) + z);
						fprintf(fd, "%f %f %f\n", cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
						fprintf(fd,"%f %f\n", j/sl, i/st);

						fi = (i + 1) * M_PI / st;
						teta = (j + 1) * 2 * M_PI / sl;
						fprintf(fd, "%f %f %f\n", r*cos(teta)*sin(fi) + x, r*cos(fi) + y, r*sin(teta)*sin(fi) + z);
						fprintf(fd, "%f %f %f\n", cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
						fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);

						teta = j * 2 * M_PI / sl;
						fprintf(fd, "%f %f %f\n", r*cos(teta)*sin(fi) + x, r*cos(fi) + y, r*sin(teta)*sin(fi) + z);
						fprintf(fd, "%f %f %f\n", cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
						fprintf(fd,"%f %f\n",j/sl, (i+1)/st);
					}
					if (i != 0) {
						fi = i * M_PI / st;
						teta = j * 2 * M_PI / sl;
						fprintf(fd, "%f %f %f\n", r*cos(teta)*sin(fi) + x, r*cos(fi) + y, r*sin(teta)*sin(fi) + z);
						fprintf(fd, "%f %f %f\n", cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
						fprintf(fd,"%f %f\n",j/sl, i/st);

						teta = (j + 1) * 2 * M_PI / sl;
						fprintf(fd, "%f %f %f\n", r*cos(teta)*sin(fi) + x, r*cos(fi) + y, r*sin(teta)*sin(fi) + z);
						fprintf(fd, "%f %f %f\n", cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
						fprintf(fd,"%f %f\n", (j+1)/sl, i/st);
						
						fi = (i + 1) * M_PI / st;
						fprintf(fd, "%f %f %f\n", r*cos(teta)*sin(fi) + x, r*cos(fi) + y, r*sin(teta)*sin(fi) + z);
						fprintf(fd, "%f %f %f\n", cos(teta)*sin(fi), cos(fi), sin(teta)*sin(fi));
						fprintf(fd,"%f %f\n", (j+1)/sl, (i+1)/st);
					}
				}
			}
		}
	}

	fclose(fd);
}

