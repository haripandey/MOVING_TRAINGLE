#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <GL/glut.h>
#include <GL/gl.h>
float X = 0, Y = 0, Z = 0, theta=0.0f;


void traingle(){
//************************MOVING OBJECT*******************
        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(0.0f,  0.0f);
	glVertex2f(0.1f,   -0.1f);
	glVertex2f(0.0f,   0.2f);
	glVertex2f(-0.1f,   -0.1f); 
       	glEnd();
}



//****************GRID LINES******************************//
void pm(){

	 glBegin(GL_LINES);
    //***************X LINES***************************//
    for (float i=-10; i<=10; i+=0.1) {
      	glVertex2f(10, i);
      	glVertex2f(-10, i);
      	glVertex2f(i, i);
      	glVertex2f(-i, i);
      	glVertex2f(i, -i);
      	glVertex2f(-i, -i);
    	}
    //*************Y LINES**************************//
    for (float i=-10; i<=10; i+=0.1) {
      	glVertex2f(i, 10);
      	glVertex2f(i, -10);
      	glVertex2f(i, i);
      	glVertex2f(-i, i);
      	glVertex2f(i, -i);
      	glVertex2f(-i, -i);
    	}	
  	glEnd();
//********TEXT ************************************************//
//********************************NICE LOOKING 3D Background******//
    	glBegin(GL_TRIANGLE_STRIP);
    	glClearColor(0.25f,0.28f,0.01f,5.0); 
    	glColor3f(1.0f, 0.0f,1.0f);
    	glColor3f(1, 0, 1); glVertex3f(-1, 0, 1);
    	glColor3f(0, 0, 1); glVertex3f(1, 0, 1);
    	glColor3f(0, 1, 0); glVertex3f(0, 0, 0);
    	glColor3f(1, 0, 1); glVertex3f(0, 2, 0);
    	glColor3f(1, 0, 1); glVertex3f(-1, 0, 1);
	glEnd();
//*************** BASE QUADRELATERAL*****************************//
    	glBegin(GL_QUADS);
	glVertex2f(-2.0f,  0.0f);
	glVertex2f(2.0f,   0.0f);
	glVertex2f(2.0f,  -0.5f);
	glVertex2f(-2.0f, -0.5f);
        glEnd();
	}
//*************TEXT*******************************************//
void text(void){
    gluOrtho2D(0.0, 1200, 0.0, 800);
    glColor3f(1.0f, 1.0f, 1.0f);//needs to be called before RasterPos
    glRasterPos2i(20, 100);
    std::string s = "(1) press down key----->rotates. (2) press down key aggain -->move forward. Similar happens to up  right left keys.To take its test press : D,D,L,L,U,U,R,R,D,D. D=Down Key and so on.";
    void * font =GLUT_BITMAP_HELVETICA_12;

    for (std::string::iterator i = s.begin(); i != s.end(); ++i)
    {
        char c = *i;
        glutBitmapCharacter(font, c);
    }
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

    glutSwapBuffers();
   // glutPostRedisplay();
}

//********DISPLAY***********************************************//

	void display(){
 	
        glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

        glClearColor(0.25f,0.28f,0.01f,5.0);

	glMatrixMode(GL_MODELVIEW);
        pm();
        text();
        glLoadIdentity();
    	glPushMatrix();
    	glTranslatef( X, Y,Z);
    	glRotatef(theta, 0.0f, 0.0f, -16.0f);
    	traingle();
        glPopMatrix();
         

          
glFlush();
}
//**************KEY BINDINGS************************************//
	float translate = 0.1f;
	void keybinding(int key, int x, int y){
    		switch (key){
            		case GLUT_KEY_DOWN:
                	if (theta<=0.0)
               			{  theta+= 180.0f;}
                   	else{
                		 Y-=translate;;}
                  	if(theta>=450.0){
                    		theta-=270.0;}
                        else{
                		 Y-=translate;}    
                 	glutPostRedisplay();
                  	break;

        		case GLUT_KEY_LEFT:
                	if(theta<=180.0)
                		{ theta+=90.0f;}
                    	else{
                  		 X-=translate;}
                	glutPostRedisplay();
                	break;

           		case GLUT_KEY_UP:
              		if (theta<=270.0)
              		        {theta+=90.0f;}
                 	else{
                		Y+=translate;}
               		 glutPostRedisplay();
			break;

         		case GLUT_KEY_RIGHT:
              		if(theta<=360.0){
                		theta+=90.0; }
               		else{
                 		X+=translate;}
                	glutPostRedisplay();
			break;

         default:
         break;
}
}
//********************MAIN FUNCTION*************************************//

	int main(int argc, char** argv){
    	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    	glutInitWindowSize(1200,800);
    	glutInitWindowPosition(0, 0);
    	glutCreateWindow("Hari's Triangle. Translate key-->LEFT, RIGHT,UP,DOWN ");
        glutDisplayFunc(display);
    	glutSpecialFunc(keybinding);
        
        glutMainLoop();
   
  
}
