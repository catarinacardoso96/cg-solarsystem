#include "figures.h"
#include "bezier.h"
#include <string.h>

int main(int argc, char **argv){
	float x, y, z, w, q, k;
	int i = 1;

	if (strcmp(argv[i], "plane") == 0 && argc >= 4) {
		x = atof(argv[++i]);
		y = atof(argv[++i]);
		z = atof(argv[++i]);
		plane(x,y,z,argv[++i]);
	} else {
	
	if (strcmp(argv[i], "box")  == 0 && argc >= 5) {
		x = atof(argv[++i]);
		y = atof(argv[++i]);
		z = atof(argv[++i]);
		w = atof(argv[++i]);
		box(x,y,z,w,argv[++i]);
	} else {
	
	if (strcmp(argv[i], "sphere") == 0 && argc >= 4) {
		x = atof(argv[++i]);
		y = atof(argv[++i]);
		z = atof(argv[++i]);
		sphere(x,y,z,argv[++i]);
	} else {
	
	if (strcmp(argv[i], "cone")  == 0 && argc >= 5) {
	    x = atof(argv[++i]);
	    y = atof(argv[++i]);
	    z = atof(argv[++i]);
	    w = atof(argv[++i]);
	    cone(x,y,z,w,argv[++i]);
	} else {
	
	if (strcmp(argv[i], "cylinder") == 0 && argc >= 6){
		x = atof(argv[++i]);
	    y = atof(argv[++i]);
	    z = atof(argv[++i]);
	    w = atof(argv[++i]);
	    q = atof(argv[++i]);
	    cylinder(x,y,z,w,q,argv[++i]);
	} else {

	if (strcmp(argv[i], "torus") == 0 && argc >= 5){
		x = atof(argv[++i]);
	    y = atof(argv[++i]);
	    z = atof(argv[++i]);
	    w = atof(argv[++i]);
	    torus(x,y,z,w,argv[++i]);
	} else {

	if (strcmp(argv[i], "ellipsoid") == 0 && argc >= 6){
		x = atof(argv[++i]);
	    y = atof(argv[++i]);
	    z = atof(argv[++i]);
	    w = atof(argv[++i]);
	    q = atof(argv[++i]);
	    ellipsoid(x,y,z,w,q,argv[++i]);
	} else{
	
	if (strcmp(argv[i], "crown") == 0 && argc >= 4){
		x = atof(argv[++i]);
		y = atof(argv[++i]);
		z = atof(argv[++i]);
		crown(x,y,z,argv[++i]);
	} else{
	
	if (strcmp(argv[i], "belt") == 0 && argc >= 7){
		x = atof(argv[++i]);
		y = atof(argv[++i]);
		z = atof(argv[++i]);
	    w = atof(argv[++i]);
	    q = atof(argv[++i]);
	    k = atof(argv[++i]);
		belt(x,y,z,w,q,k,argv[++i]);
	} else {

	if (strcmp(argv[i], "bezier") == 0 && argc >= 3) {
		x = atoi(argv[++i]);
		bezier(x, argv[3], argv[4]);
	}}}}}}}}}}
	return 1;
}