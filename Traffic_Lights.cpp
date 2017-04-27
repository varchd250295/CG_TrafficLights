#include <GL/glut.h>
#include <stdio.h>

int r=0,g=1;
float t=0.1,l=0.1;
float x1=-550,x2=-400,y1=400,y2=550;

void keyboard (unsigned char key, int x, int y) 
{
	if (key == 114)  // r PRESSED for RED
	{
		r=1; 
		g=0;
	}
	else
		if(key == 103)   // g PRESSED for GREEN
		{
			g=1;
			r=0;
		}
	glutPostRedisplay();
}

void init()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}

void display()
{
	glClear (GL_COLOR_BUFFER_BIT); 

	glColor3f(0.7,0.7,0.7); // left to right road
	glRectf(-500,-125,500,125);

	glColor3f(0.5,0.5,0.5); // top to bottom road
	glRectf(-125,-500,125,500);

	
	glColor3f(0,1,1);// left car
	glRectf(x1,-40,x2,40);	
	
	glColor3f(1,0,1);  // top car
	glRectf(-40,y1,40,y2);

	glColor3f(0,0,0);  // traffic light screen
	glRectf(-210,150,-150,250);

	glColor3f(0,0,0);  // traffic light stand
	glRectf(-190,125,-170,150);


	glColor3f(r,g,0);  // traffic light
	glRectf(-200,170,-160,230);

	if(r==1)                                  // MOVING LEFT CAR 
		if(x2<=-130 || x2>-125)
		{
			x1+=l;
			x2+=l;
		}
	if(g==1)
			if(y1>=125 || y2<=-125)
			{
				
				x1+=l;
				x2+=l;
			}
				else
					if(x2<=-130 || x1>=-125)
					{
						x1+=l;
						x2+=l;
					}

		if(g==1)                                 // MOVING TOP CAR
			if(y1>=130 || y1<125)
			{
				y1-=t;
				y2-=t;
			}
			
		if(r==1)
			if(x2<=-125 || x1>=125)
			{
				y1-=t;
				y2-=t;
			}
			else
				if(y1>=130 || y2<=-125)
				{
					y1-=t;
					y2-=t;
				}
	
		if(y2<-650) 
			{
				y2=650;
				y1=500;
		    }
		
		if(x2>650) 
			{
				x1=-650;
				x2=-500;
		    }
		
	glutSwapBuffers();
    glutPostRedisplay();	
}
			 
int main(int argc, char **argv)
{
	glutInit ( &argc, argv );
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (1000,1000); 
	glutInitWindowPosition (100,100);
	glutCreateWindow ( " Testing " );
	init();
	glutDisplayFunc (display);
	glutKeyboardFunc (keyboard);
	glutMainLoop ();
	return 0;
}