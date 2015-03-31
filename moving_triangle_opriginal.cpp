#include <GL/glut.h>
float X = 0, Y = 0, Z = 0, theta=0.0;

void traingle(){
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 2.0f);
        glVertex2f( 0.01f, 0.0f);
        glVertex2f( -0.01f,  0.0f);
        glVertex2f(0.0f, 0.1f);
        glEnd();
}




void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.0f, 0.0f,1.0);
    glMatrixMode(GL_MODELVIEW);
 //   glLoadIdentity();
    glPushMatrix();
    glTranslatef(X,Y,Z);
    glRotatef(theta, 0.0f, 0.0f, 1.0f);
    traingle();
    glPopMatrix();
    glFlush();
}



float translate = 0.1f;
void keyboardown(int key, int x, int y)
{
    switch (key){
            case GLUT_KEY_RIGHT:
            X+=translate;;
            break;

        case GLUT_KEY_LEFT:
            X-=translate;;
        break;

        case GLUT_KEY_UP:
             Y+=translate;;
            break;

        case GLUT_KEY_DOWN:
            Y-=translate;;
        break;
        
    case GLUT_KEY_F1: // Rotate on z axis
   theta+= 90.0f;;
    break;
        default:
         break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hari's Triangle. Translate key-->LEFT, RIGHT,UP,DOWN and rotate kry --->F1");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboardown);
    glutMainLoop();
   
  
}
