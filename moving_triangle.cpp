#include <stdio.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <GL/glu.h>
#include <GL/gl.h>
GLfloat rotation = 5.0;
float posX = 0, posY = 0, posZ = 0, rotAngle=0.5,  Z=0;

void reshape(int width, int heigth){
    /* window ro reshape when made it bigger or smaller*/

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //clip the windows so its shortest side is 2.0
    if (width < heigth) {
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 2.0, 2.0);
    }
    else{
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth,2.0 , 2.0);
    }
    // set viewport to use the entire new window
    glViewport(0, 0, width, heigth);
}



void traingle(){
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);

        //Triangle
        glColor3f(0.0f, 0.0f, 2.0f);
        glVertex2f( 0.05f, 0.0f);
        glVertex2f( -0.05f,  0.0f);
        glVertex2f(0.0f, 0.2f);
        glEnd();
}




void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glRotated(Z, 0, 0, 1);	
    glTranslatef(posX,posY,posZ);
    glRotatef(Z, 0.0f, 0.0f, 1.0f);
    traingle();
    glPopMatrix();
    glFlush();
}


void init(){
    // set clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // set fill color to white
    glColor3f(1.0, 1.0, 1.0);

    //set up standard orthogonal view with clipping
    //box as cube of side 2 centered at origin
    //This is the default view and these statements could be removed
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

float rotat=0.1f;
float move_unit = 0.1f;
void keyboardown(int key, int x, int y)
{
    switch (key){
            case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;;
        break;
        
    case GLUT_KEY_F1: // Rotate on z axis
   Z += 5.0f;;
    break;
        default:
         break;
    }
    glutPostRedisplay();
}

//    void rotateScene(){
//             if GLUT_KEY_LEFT
//         angleX+=45;
//    else if keypress up
//         angleY+=45;
//        glRotatef(angleX,1,0,0);
//        glRotatef(angleY,0,1,0);
//    }
int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hari's Triangle. Translate key-->LEFT, RIGHT,UP,DOWN and rotate kry --->F1");
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(keyboardown);
    glutMainLoop();
   
  
    cout <<"Printed out variable x";
    cout<<"Printed out variable y";
    cout<<"Printed out variable z";
}
