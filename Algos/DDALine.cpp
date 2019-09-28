#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int x1,x2;
int yr,y2;
void display(void){
	float step,x,y,Xinc,Yinc,k;
	float dx, dy; 
	dx = x2-x1; //Calculating dx and dy
	dy = y2-yr;
	// Calculate step
	if(abs(dx)>= abs(dy)){
		step = abs(dx);
	}
	else 
	{step = abs(dy);
	}
	//Calculating Increment Factor
	Xinc = dx/step;
	Yinc = dy/step;
	x = x1;//initialize
	y = yr;
	//Plotting the initial point
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	for(k = 0; k< step; k++){
		x = x + Xinc;
		y = y + Yinc;
		x = round(x);
		y = round(y);
		glBegin(GL_POINTS);
		glVertex2d(x,y);
		glEnd();
	}
	//glFlush();
}

void init(void)
{
glClearColor(0.0f,0.0f,0.0f,0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();//clears matrix
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&yr);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
