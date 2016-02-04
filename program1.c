/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED 
 *
 */

/*
 * hello.c
 * This is a simple, introductory OpenGL program.
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float v[][2] = {{.65,.8},{.12,.15},{.9,.25}};
float p[] = {.25,.25};
int dim[] = {400,400};

void reshape(int w, int h){
   glViewport(0, 0, dim[0], dim[1]);

}

void keypress(unsigned char key, int x, int y){
   printf("%i\n", key);
   switch(key){
      case 27:
         glutDestroyWindow(glutGetWindow());
         break;
         
   }
}
void midpoint(float v[]){
   
   p[0] = (v[0] + p[0])/2;
   if(p[0] < 0) p[0] = p[0]*-1;

   p[1] = (v[1] + p[1])/2;
   if(p[1] < 0) p[1] = p[1]*-1;
}
void drawPoint(float vert[]){
   if(v[0] )
   glColor3f (1.0, 1.0, 1.0);
   glVertex2d (vert[0], vert[1]);
   
}
void chaosAlgorithm(){
      for (int i = 0; i < 30000; i++)
      {
         midpoint(v[rand() % 3]);
         glBegin(GL_POINTS);
            drawPoint(p);
         glEnd();
      }

}
void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw initial vector points
 */
   for (int i = 0; i < sizeof(v)/sizeof(v[0]); ++i)
   {
      glBegin(GL_POINTS);
         glColor3f (1.0, 0.0, 1.0);
         glVertex2d(v[i][0],v[i][1]);   
      glEnd();
   }
   glBegin(GL_POINTS);
         glColor3f (0.0, 1.0, 1.0);
         glVertex2d(p[0],p[1]);   
   glEnd();

   chaosAlgorithm();
   
   
/* don't wait!  
 * start processing buffered OpenGL routines 
 */
   glFlush ();
}


void init (void) 
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 1.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/* 
 * Declare initial window size, position, and display mode

 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutReshapeFunc(reshape);
   // glutInitWindowSize (250, 250); 
   // glutInitWindowPosition (100, 100);
   glutCreateWindow ("Choas Game: Leon");
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keypress);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
