#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <IL/il.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "..\tinyxml\tinyxmlerror.cpp"
#include "..\tinyxml\tinyxmlparser.cpp"
#include "..\tinyxml\tinystr.cpp"
#include "..\tinyxml\tinyxml.cpp"
#include "..\tinyxml\tinyxml.h"

#include <vector>
#include <cstdio>
#include <fstream>
#include <iostream>

#include "catmullrom.h"
#include "classTag.h"


std::vector<Tag*> v;

float px = -132, py = 56, pz = -91;
float lx = 0, ly = 0, lz = 0;
float alfa = 0.95, teta = -0.4;
int frame = 0, telapse, timebase = 0;

GLenum mode = GL_FILL;
int nr_lights = 0;
extern bool flag;


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	// clear buffers
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	lx = px + 100*cos(alfa)*cos(teta);
	ly = py + 100 * sin(teta);
	lz = pz + 100*sin(alfa)*cos(teta);

	glLoadIdentity();
	gluLookAt(px, py, pz, 
		      lx, ly ,lz,
			  0.0f, 1.0f, 0.0f);

	// put the geometric transformations here
	glutPostRedisplay();
	glPolygonMode(GL_FRONT, mode);
	
	// put drawing instructions here
	int i;
	std::vector<Tag*>::iterator it;
	
	for (it = v.begin(), i = 0; it < v.end(); it++, i++)
		v[i]->draw(v[i]);
	
	char title[100];
	float fps;
	frame++;
	telapse = glutGet(GLUT_ELAPSED_TIME);
	if (telapse - timebase > 1000) {
		fps = frame * 1000.0 / (telapse - timebase);
		sprintf_s(title, sizeof(title), "CG-Grupo14     FPS: %.2f", fps);
		glutSetWindowTitle(title);
		timebase = telapse;
		frame = 0;
	}

	// End of frame
	glutSwapBuffers();
}


// write function to process keyboard events
void keys(unsigned char key, int x, int y) {
	switch (key) {
	case ('a'):case('A'):
		pz -= cos(alfa);
		px += sin(alfa);
		break;
	case ('d'):case('D'):
		pz += cos(alfa);
		px -= sin(alfa);
		break;
	case ('w'):case('W'):
		px += cos(alfa)*cos(teta);
		pz += sin(alfa)*cos(teta);
		py += sin(teta);
		break;
	case ('s'):case('S'):
		px -= cos(alfa)*cos(teta);
		pz -= sin(alfa)*cos(teta);
		py -= sin(teta);
		break;
	case ('1'):
		mode = GL_FILL;
		break;
	case ('2'):
		mode = GL_LINE;
		break;
	case ('3'):
		mode = GL_POINT;
		break;
	case ('4'):
		glEnable(GL_LIGHTING);
		break;
	case ('5'):
		glDisable(GL_LIGHTING);
		break;
	case ('6'):
		flag = false;
		break;
	case ('7'):
		flag = true;
	}
}

void specialkeys(int key_code, int x, int y) {
	switch (key_code) {
	case (GLUT_KEY_RIGHT):
		alfa += 0.1;
		break;
	case (GLUT_KEY_LEFT):
		alfa -= 0.1;
		break;
	case(GLUT_KEY_UP):
		if (teta < M_PI / 2 - M_PI / 20)
		teta += 0.1;
		break;
	case(GLUT_KEY_DOWN):
		if (teta > -M_PI / 2 + M_PI / 20)
		teta -= 0.1;
		break;
	case(GLUT_KEY_PAGE_UP):
		py += 0.4;
		break;
	case(GLUT_KEY_PAGE_DOWN):
		py -= 0.4;
		break;
	}
}


std::vector<Tag*> save_buffers;

//ler ficheiro .3d
void read_figure(const char* name, File fich) {
	FILE *fd;
	fopen_s(&fd, name, "r");

	if (!fd) {
		perror("Error");
		return;
	}

	std::vector<float> position;
	std::vector<float> normal;
	std::vector<float> texCoord;

	int i, nr;
	char *linha = new char[100];

	fgets(linha, 100, fd);
	nr = atoi(linha);

	for (i = 0; i < nr; i++){
		char *token, *nexttoken = NULL;

		fgets(linha, 100, fd);
		token = strtok_s(linha, " ", &nexttoken);
		while (token != NULL) {
			position.push_back(atof(token));
			token = strtok_s(NULL, " ", &nexttoken);
		}

		fgets(linha, 100, fd);
		token = strtok_s(linha, " ", &nexttoken);
		while (token != NULL) {
			normal.push_back(atof(token));
			token = strtok_s(NULL, " ", &nexttoken);
		}

		fgets(linha, 100, fd);
		token = strtok_s(linha, " ", &nexttoken);
		while (token != NULL) {
			texCoord.push_back(atof(token));
			token = strtok_s(NULL, " ", &nexttoken);
		}
	}
	fclose(fd);
	
	glGenBuffers(3, fich.buffers);

	glBindBuffer(GL_ARRAY_BUFFER, fich.buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(float), &(position[0]), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, fich.buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(float), &(normal[0]), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, fich.buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, texCoord.size() * sizeof(float), &(texCoord[0]), GL_STATIC_DRAW);
	
	fich.size = position.size();
	strcpy_s(fich.title, name);
	save_buffers.push_back(new File(fich));
	v.push_back(new File(fich));
}

int load_texture(const char* file) {
	unsigned int t, tw, th;
	unsigned char *texData;
	unsigned int texID;

	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	ilGenImages(1, &t);
	ilBindImage(t);
	ilLoadImage((ILstring) file);
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	texData = ilGetData();

	glGenTextures(1, &texID);

	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	return texID;
}

void xml_parser(TiXmlElement* elem) {
	if (!elem) return;

	std::string elemName = elem->Value();

	if (elemName == "scene"){
		xml_parser(elem->FirstChildElement());
	} else

	if (elemName == "group"){
		Matrix push; push.flag = true;
		Matrix pop; pop.flag = false;

		v.push_back(new Matrix(push));
		xml_parser(elem->FirstChildElement());
		v.push_back(new Matrix(pop));
	} else

	if (elemName == "translate"){	
		Translation translation;
		CatmullRom catmullrom;
		TiXmlElement* elem2;
		float x = 0, y = 0, z = 0;
		int time = 0;
		std::vector<float> points;

		elem->QueryFloatAttribute("X", &x);
		translation.x = x;

		elem->QueryFloatAttribute("Y", &y);
		translation.y = y;

		elem->QueryFloatAttribute("Z", &z);
		translation.z = z;

		if (x || y || z) v.push_back(new Translation(translation));

		elem->QueryIntAttribute("time", &time);
		catmullrom.time = time;
		
		elem2 = elem->FirstChildElement();
		while (elem2){
			if (!strcmp(elem2->Value(), "point")){
			
				elem2->QueryFloatAttribute("X", &x);
				points.push_back(x);

				elem2->QueryFloatAttribute("Y", &y);
				points.push_back(y);

				elem2->QueryFloatAttribute("Z", &z);
				points.push_back(z);			
			}
			elem2 = elem2->NextSiblingElement();
		}

		catmullrom.size = points.size()/3;
		catmullrom.points = new float*[catmullrom.size];
		for (int i = 0; i < catmullrom.size; i++)
			catmullrom.points[i] = new float[3];

		for (int i = 0, k = 0; k < catmullrom.size; k++) {
			catmullrom.points[k][0] = points[i++];
			catmullrom.points[k][1] = points[i++];
			catmullrom.points[k][2] = points[i++];
		}

		if (catmullrom.size >= 4) v.push_back(new CatmullRom(catmullrom));
	} else

	if (elemName == "scale"){
		Scale scale;
		float x = 1, y = 1, z = 1;

		elem->QueryFloatAttribute("X", &x);
		scale.x = x;

		elem->QueryFloatAttribute("Y", &y);
		scale.y = y;

		elem->QueryFloatAttribute("Z", &z);
		scale.z = z;

		v.push_back(new Scale(scale));
	} else

	if (elemName == "rotate"){
		Rotation rotation;
		Spin spin;
		float x = 0, y = 0, z = 0;
		int time = 0, angle = 0;

		elem->QueryIntAttribute("angle", &angle);
		rotation.angle = angle;

		elem->QueryFloatAttribute("axisX", &x);
		rotation.x = x; spin.x = x;

		elem->QueryFloatAttribute("axisY", &y);
		rotation.y = y; spin.y = y;

		elem->QueryFloatAttribute("axisZ", &z);
		rotation.z = z; spin.z = z;

		if (rotation.angle) v.push_back(new Rotation(rotation));

		elem->QueryIntAttribute("time", &time);
		spin.time = time; 

		if (spin.time) v.push_back(new Spin(spin));
	} else

	if (elemName == "lights"){
		Light light;
		const char* type;
		float x = 0, y = 0, z = 0;
		int angle = 0;
		TiXmlElement* elem2;
		elem2 = elem->FirstChildElement();
		while (elem2){
			if (nr_lights > 7) break;

			if (!strcmp(elem2->Value(), "light")) {

				type = elem2->Attribute("type");
				
				if (!strcmp(type, "point")) light.position[3] = 1.0;
				else if (!strcmp(type, "directional")) light.position[3] = 0.0;
				else if (!strcmp(type, "spotlight")) {
					light.position[3] = 1.0;
					light.flag = true;
				}

				light.number = GL_LIGHT0 + nr_lights;
				glEnable(GL_LIGHT0 + nr_lights++);

				elem2->QueryFloatAttribute("posX", &x);
				light.position[0] = x;

				elem2->QueryFloatAttribute("posY", &y);
				light.position[1] = y;

				elem2->QueryFloatAttribute("posZ", &z);
				light.position[2] = z;

				x = y = z = 0;

				elem2->QueryFloatAttribute("dirX", &x);
				light.direction[0] = x;

				elem2->QueryFloatAttribute("dirY", &y);
				light.direction[1] = y;

				elem2->QueryFloatAttribute("dirZ", &z);
				light.direction[2] = z;

				elem2->QueryIntAttribute("angle", &angle);
				light.angle = angle;

				v.push_back(new Light(light));

				x = y = z = 0;
				angle = 0;
			}
			elem2 = elem2->NextSiblingElement();
		}
	} else

	if (elemName == "models"){
		xml_parser(elem->FirstChildElement());
	} else

	if (elemName == "model"){
		File fich;
		float red = 0, green = 0, blue = 0;
		const char* file, *texture_file;
		int i, b = 0, shin = 128;
		std::vector<Tag*>::iterator it;
		
		file = elem->Attribute("file");

		elem->QueryFloatAttribute("diffR", &red);
		elem->QueryFloatAttribute("diffG", &green);
		elem->QueryFloatAttribute("diffB", &blue);
		
		if (red || green || blue) {
			fich.diffuse[0] = red;
			fich.diffuse[1] = green;
			fich.diffuse[2] = blue;
			red = green = blue = 0;
		}

		elem->QueryFloatAttribute("specR", &red);
		elem->QueryFloatAttribute("specG", &green);
		elem->QueryFloatAttribute("specB", &blue);
		
		if (red || green || blue) {
			fich.specular[0] = red;
			fich.specular[1] = green;
			fich.specular[2] = blue;
			red = green = blue = 0;
		}

		elem->QueryFloatAttribute("emisR", &red);
		elem->QueryFloatAttribute("emisG", &green);
		elem->QueryFloatAttribute("emisB", &blue);

		if (red || green || blue) {
			fich.emission[0] = red;
			fich.emission[1] = green;
			fich.emission[2] = blue;
			red = green = blue = 0;
		}

		elem->QueryFloatAttribute("ambiR", &red);
		elem->QueryFloatAttribute("ambiG", &green);
		elem->QueryFloatAttribute("ambiB", &blue);

		if (red || green || blue) {
			fich.ambient[0] = red;
			fich.ambient[1] = green;
			fich.ambient[2] = blue;
			red = green = blue = 0;
		}

		elem->QueryIntAttribute("shin", &shin);
		fich.shininess[0] = shin;

		texture_file = elem->Attribute("texture");
		
		if (texture_file) fich.texID = load_texture(texture_file);
		/*
		for (it = save_buffers.begin(), i = 0; it < save_buffers.end(); it++, i++){
			File& f = dynamic_cast<File&>(*save_buffers[i]);
			if (!strcmp(f.title, file)) {
				fich.buffers[0] = f.buffers[0];
				fich.buffers[1] = f.buffers[1];
				fich.buffers[2] = f.buffers[2];
				fich.size = f.size;
				v.push_back(new File(fich));
				b = 1;
				break;
			}
		}*/
		if (b == 0) read_figure(file, fich);
	}
	xml_parser(elem->NextSiblingElement());
}

//ler xml
void xml_reader(int argc, char** argv)
{
	if (argc > 1) {
		TiXmlDocument doc(argv[1]);
		doc.LoadFile();
		xml_parser(doc.FirstChildElement());

	}
	else if (argc <= 1) {
		printf("XML nao especificado! \n");
	}
}

void menu() {
	printf("  \tCamera commands:\n\n");
	printf("\tW \tMove forward.\n");
	printf("\tA \tMove Left.\n");
	printf("\tS \tMove backwards.\n");
	printf("\tD \tMove right.\n");
	printf("      PAGE UP \tMove upwards.\n");
	printf("    PAGE DOWN \tMove downwards.\n");
	printf("     UP ARROW \tRotate up.\n");
	printf("   DOWN ARROW \tRotate down.\n");
	printf("  RIGHT ARROW \tRotate right.\n");
	printf("   LEFT ARROW \tRotate left.\n\n");
	printf(" \tOther view options:\n\n");
	printf("\t1 \tGL_FILL.\n");
	printf("\t2 \tGL_LINE.\n");
	printf("\t3 \tGL_POINT.\n\n");
	printf("\t4 \tEnable Lighting.\n");
	printf("\t5 \tDisable Lighting.\n\n");
	printf("\t6 \tShow Catmull-Rom Trajectory.\n");
	printf("\t7 \tHide Catmull-Rom Trajectory.\n\n");
}


int main(int argc, char **argv) {
	
// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG-Grupo14");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// put here the registration of the keyboard callbacks
	glutKeyboardFunc(keys);
	glutSpecialFunc(specialkeys);

	#ifndef __APPLE__	
		glewInit();
	#endif
	ilInit();
	
//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_TEXTURE_2D);

	menu();
	xml_reader(argc, argv);
	printf("\tNo. lights activated: %d\n", nr_lights);

// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
