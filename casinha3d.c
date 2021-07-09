#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float const house_x = 1.0, house_y = 1.0, house_z = 2.0, wall_width = 0.1,
chimney_width = 0.75, chimney_height = 1.5, offset = 0.01;



float posX=0.0,posY=0.0,posZ=0.0;
float transX=0.0,transY=0.0,transZ=0.0;

void movimento(int key,int x,int y){
    //Movimento
    switch (key){
        //movimento para direita
        case GLUT_KEY_RIGHT:
          posY += 0.5;
        break;
        //movimento para esquerda.
        case GLUT_KEY_LEFT:
          posY -= 0.5;
        break;
        //identifica o movimento para cima
        case GLUT_KEY_UP:
          posX += 0.5;
        break;
        //identifica o movimento para baixo.
        case GLUT_KEY_DOWN:
          posX -= 0.5;
        break;

        case GLUT_KEY_F1:
          transZ += 0.5;
        break;

        case GLUT_KEY_F2:
          transZ -= 0.5;
        break;

        case GLUT_KEY_F3:
          transY += 0.5;
        break;

        case GLUT_KEY_F4:
          transY -= 0.5;
        break;

        case GLUT_KEY_F5:
          transX += 0.5;
        break;

        case GLUT_KEY_F6:
          transX -= 0.5;
        break;

        case GLUT_KEY_F7:
          transX = 0.0;
          transY = 0.0;
          transZ = 0.0;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}

void desenha () {

    if (posX==360)
      posX=0;

    if (posY==360)
        posY=0;

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
      //movimentos de rotacao e translacao
      glRotatef(posX,1.0,0.0,0.0);
      glRotatef(posY,0.0,1.0,0.0);
      glTranslatef(transX, transY, transZ);
		
      //desenha telhado
      glPushMatrix();      
        glColor3f(0.6f, 0.0f, 0.0f);
        glScalef(house_x, house_y, house_z);
        glTranslatef(transX,transY+1,transZ);
        glRotatef(-90,1,0,0);
        glRotatef(-45,0,0,1);
        glutSolidCone(1.5,1,4,18);
      glPopMatrix();

      //desenha chaminé
      glPushMatrix();          
        glColor3f(0.3f, 0.0f, 0.0f);         
        glTranslatef(transX+chimney_width,transY+chimney_height,transZ-chimney_width);
        glScalef(1,3,1);
        glutSolidCube(.25);
      glPopMatrix();

      // desenha a porta
      glColor3f(0.2f, 0.1f, 0.0f);         
      glPushMatrix();      
        glTranslatef(transX+0.4,transY-0.14,transZ+house_z+0.25);
        glRotatef(120, 0, 1, 0);
        glScalef(house_x-0.70, house_y-0.15, wall_width/3);
        glutSolidCube(2);                 
      glPopMatrix();

      //desenha parede da frente com porta
      glColor3f(0.8f, 0.7f, 0.4f); 
      glPushMatrix();      
        glTranslatef(transX-0.65,transY,transZ+(house_z-wall_width));
        glScalef(house_x-0.65, house_y, wall_width);
        glutSolidCube(2);                 
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX+0.65,transY,transZ+(house_z-wall_width));
        glScalef(house_x-0.65, house_y, wall_width);
        glutSolidCube(2);                 
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX,transY+0.8,transZ+(house_z-wall_width));
        glScalef(house_x-wall_width*2, house_y-0.8, wall_width);
        glutSolidCube(2);                 
      glPopMatrix();

      //desenha parede do fundo
      glPushMatrix();      
        glTranslatef(transX,transY,transZ-(house_z-wall_width));
        glScalef(house_x, house_y, wall_width);
        glutSolidCube(2);                 
      glPopMatrix();        
      
      //desenha parede lateral 1
      glPushMatrix();      
        glTranslatef(transX+(house_x-wall_width),transY,transZ-1.6);
        glScalef(wall_width, house_y, house_z-1.6);
        glutSolidCube(2);
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX+(house_x-wall_width),transY,transZ+1.6);
        glScalef(wall_width, house_y, house_z-1.6);
        glutSolidCube(2);
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX+(house_x-wall_width),transY-0.7,transZ);
        glScalef(wall_width, house_y-0.7, house_z);
        glutSolidCube(2);
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX+(house_x-wall_width),transY+0.7,transZ);
        glScalef(wall_width, house_y-0.7, house_z);
        glutSolidCube(2);
      glPopMatrix();

      //desenha parede lateral 2
      glPushMatrix();      
        glTranslatef(transX-(house_x-wall_width),transY,transZ-1.6);
        glScalef(wall_width, house_y, house_z-1.6);
        glutSolidCube(2);
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX-(house_x-wall_width),transY,transZ+1.6);
        glScalef(wall_width, house_y, house_z-1.6);
        glutSolidCube(2);
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX-(house_x-wall_width),transY-0.7,transZ);
        glScalef(wall_width, house_y-0.7, house_z);
        glutSolidCube(2);
      glPopMatrix();

      glPushMatrix();      
        glTranslatef(transX-(house_x-wall_width),transY+0.7,transZ);
        glScalef(wall_width, house_y-0.7, house_z);
        glutSolidCube(2);
      glPopMatrix();

      //desenha chão da casa
      glPushMatrix();            
        glColor3f(0.2f,0.2f,0.3f);
        glTranslatef(transX,transY-(house_y-wall_width*2),transZ);
        glScalef(house_x-wall_width*2, wall_width, house_z-wall_width*2);
        glutSolidCube(2);
      glPopMatrix();

      // desenha janelao da lateral 1
      glColor4f(0.3f, 0.6f, 1.0f, 0.5f);         
      glPushMatrix();      
        glTranslatef(transX+(house_x-wall_width),transY,transZ);
        glScalef(wall_width-offset, house_y-offset, house_z-offset);
        glutSolidCube(2);
      glPopMatrix();

      // desenha janelao da lateral 1
      glPushMatrix();      
        glTranslatef(transX-(house_x-wall_width),transY,transZ);
        glScalef(wall_width-offset, house_y-offset, house_z-offset);
        glutSolidCube(2);
      glPopMatrix();

    glPopMatrix();

    /* flush drawing routines to the window */
    glFlush();
}

void inicializar(){

    // Habilita a definição da cor do material a partir da cor corrente
    //glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    //glEnable(GL_LIGHTING);  
    // Habilita a luz de número 0
    //glEnable(GL_LIGHT0);

    /* allow opacity */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //FovY, Aspect, zNear, ZFar
    gluPerspective(45,1,4,20);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	// eyeX, eyeY, eyeZ
	// Especifica a posicao do olho. Câmera
	//
	// centerX, centerY, centerZ
	// Especifica a posicao do ponto de referencia. Para onde a câmera aponta.
	//
	// upX, upY, upZ
	// Especifica a direção do vetor "Cima". Geralmente, Y.
    gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
}


int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
    /* create and set up a window */
    glutCreateWindow("Super Casa 3D");
    glutDisplayFunc(desenha);
    inicializar();
    glutSpecialFunc(movimento);
    glutMainLoop();
}
