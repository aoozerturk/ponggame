#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define pi 3.141592
#define windowSizeX 1024
#define windowSizeY 768
#define clength 40  //controller length
#define cwidth 5    //controller width
#define radius 10   //ball radius
#define speed 1     //initial ball speed
#define speedrate 0.0005      //ball speed increase rate
#define cspeed 60             //controller speed

float p1Y=windowSizeY/2, p2Y=windowSizeY/2, ballX=windowSizeX/2, ballY=windowSizeY/2; //coordinates
float angle=pi/4;                                                                     //angle of ball
int balldirection=1;                                                                  //positive route
int p1score=0, p2score=0;                                                             //scores
float currentspeed=speed;                                                             //speed of ball

void score(int score, int x, int y) {                                                 //score drawing
     
     if(score==0)                                                          {
                                                                             glBegin (GL_LINE_LOOP);
                                                                             glVertex2i(x,y);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x,y+40);
                                                                             glEnd();
                                                                             }
    if(score==1)                                                           {
                                                                             glBegin (GL_LINES);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x+20,y+40);
                                                                             glEnd();
                                                                             }
    if(score==2)                                                           {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x,y+20);
                                                                             glVertex2i(x,y);
                                                                             glVertex2i(x+20,y);
                                                                             glEnd();
                                                                             }
    if(score==3)                                                           {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x,y+20);
                                                                             glEnd();
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x,y);
                                                                             glEnd();
                                                                             }
    if(score==4)                                                           {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x,y+20);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x+20,y+40);
                                                                             glEnd();
                                                                             glBegin (GL_LINES);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x+20,y);
                                                                             glEnd();
                                                                             }
    if(score==5)                                                           {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x,y+20);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x,y);
                                                                             glEnd();
                                                                             }
    if(score==6)                                                           {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x,y);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x+20,y+20);
                                                                             glVertex2i(x,y+20);
                                                                             glEnd();
                                                                             }
    if(score==7)                                                           {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x+20,y);
                                                                             glEnd();
                                                                             }
    if(score==8)                                                           {
                                                                             glBegin (GL_LINE_LOOP);
                                                                             glVertex2i(x,y);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x,y+40);
                                                                             glEnd();
                                                                             glBegin (GL_LINES);
                                                                             glVertex2i(x,y+20);
                                                                             glVertex2i(x+20,y+20);
                                                                             glEnd();
                                                                             }
    if(score==9)                                                             {
                                                                             glBegin (GL_LINE_STRIP);
                                                                             glVertex2i(x,y);
                                                                             glVertex2i(x+20,y);
                                                                             glVertex2i(x+20,y+40);
                                                                             glVertex2i(x,y+40);
                                                                             glVertex2i(x,y+20);
                                                                             glVertex2i(x+20,y+20);
                                                                             glEnd();
                                                                             }
}
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor (1.0, 1.0, 1.0, 0.0);

if((p1score<10)&&(p2score<10)) {  //controller 1  
    glPushMatrix();
    glTranslatef(cwidth, p1Y, 0);
    glColor3f(p1Y/windowSizeY,0.5,1-p1Y/windowSizeY);
    glBegin(GL_QUADS);
    glVertex2f(-cwidth, -clength);
    glVertex2f(-cwidth, clength);   
    glVertex2f(cwidth, clength);
    glVertex2f(cwidth, -clength);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();    //controller 2
    glTranslatef(windowSizeX-cwidth, p2Y, 0);
    glColor3f(p2Y/windowSizeY,0.5,1-p2Y/windowSizeY);
    glBegin(GL_QUADS);
    glVertex2f(-cwidth, -clength);
    glVertex2f(-cwidth, clength);   
    glVertex2f(cwidth, clength);
    glVertex2f(cwidth, -clength);
    glEnd();
    glPopMatrix();
    
    if((ballX-radius*2<=cwidth)&&(ballY-radius<=p1Y+clength)&&(ballY+radius>=p1Y-clength)) { //ball bouncing
                                                                             if(balldirection==1)    angle=angle+pi/2;
                                                                             else                    angle=angle-pi/2;
                                                                             }
    if((ballX+radius*2>=windowSizeX-cwidth)&&(ballY-radius<=p2Y+clength)&&(ballY+radius>=p2Y-clength)) { //ball bouncing
                                                                             if(balldirection==1)    angle=angle+pi/2;
                                                                             else                    angle=angle-pi/2;
                                                                             }
    if((ballY<=radius)||(ballY>=windowSizeY-radius))                         {                       //ball bouncing
                                                                             if(balldirection==1)    angle=angle+pi/2;
                                                                             else                    angle=angle-pi/2;                                                                             
                                                                             }
    if(ballX<radius)                                                         {                       //ball reset
                                                                             ballX=windowSizeX/2;
                                                                             ballY=windowSizeY/2;
                                                                             currentspeed=speed;
                                                                             p2score++;
                                                                             }
    if(ballX>windowSizeX-radius)                                             {                       //ball reset
                                                                             ballX=windowSizeX/2;
                                                                             ballY=windowSizeY/2;
                                                                             currentspeed=speed;
                                                                             p1score++;
                                                                             }
    glColor3f(p1Y/windowSizeY,0.5,1-p1Y/windowSizeY);
    score(p1score, 150, 50); //player 1 score
    glColor3f(p2Y/windowSizeY,0.5,1-p2Y/windowSizeY);
    score(p2score, windowSizeX-150, 50); // player 2 score
    ballX=ballX+currentspeed*cos(angle); //next move of ball
    ballY=ballY+currentspeed*sin(angle); //next move of ball
    currentspeed+=speedrate;             //speed increase
    
    glPushMatrix(); //ball
    glColor3f(ballX/windowSizeX,(ballX/windowSizeX+ballY/windowSizeY)/2,ballY/windowSizeY);
    glTranslatef(ballX, ballY, 0);
    glBegin(GL_TRIANGLE_FAN);
    for(int a=0; a < 360; a += 6) 
    glVertex2f(sin(a * pi / 180) * radius, cos(a * pi / 180) * radius);
    glEnd();
    glPopMatrix();
    
}
else {
     glColor3f(1,0,0);
     glBegin (GL_LINE_STRIP);              //P
     glVertex2i(200,windowSizeY-200);
     glVertex2i(200,windowSizeY-160);
     glVertex2i(220,windowSizeY-160);
     glVertex2i(220,windowSizeY-180);
     glVertex2i(200,windowSizeY-180);
     glEnd();
     
     glBegin (GL_LINE_STRIP);              //L
     glVertex2i(240,windowSizeY-160);
     glVertex2i(240,windowSizeY-200);
     glVertex2i(260,windowSizeY-200);
     glEnd();
     
     glBegin (GL_LINE_STRIP);              //A
     glVertex2i(280,windowSizeY-200);
     glVertex2i(290,windowSizeY-160);
     glVertex2i(300,windowSizeY-200);
     glEnd();
     glBegin (GL_LINES);
     glVertex2i(285,windowSizeY-180);
     glVertex2i(295,windowSizeY-180);
     glEnd();
     
     glBegin (GL_LINE_STRIP);              //Y
     glVertex2i(320,windowSizeY-160);
     glVertex2i(330,windowSizeY-180);
     glVertex2i(340,windowSizeY-160);
     glEnd();
     glBegin (GL_LINES);
     glVertex2i(330,windowSizeY-180);
     glVertex2i(330,windowSizeY-200);
     glEnd();
     
     glBegin (GL_LINE_STRIP);              //E
     glVertex2i(380,windowSizeY-160);
     glVertex2i(360,windowSizeY-160);
     glVertex2i(360,windowSizeY-200);
     glVertex2i(380,windowSizeY-200);
     glEnd();
     glBegin (GL_LINES);
     glVertex2i(360,windowSizeY-180);
     glVertex2i(380,windowSizeY-180);
     glEnd();
     
     glBegin (GL_LINE_STRIP);              //R
     glVertex2i(400,windowSizeY-200);
     glVertex2i(400,windowSizeY-160);
     glVertex2i(420,windowSizeY-160);
     glVertex2i(420,windowSizeY-180);
     glVertex2i(400,windowSizeY-180);
     glVertex2i(420,windowSizeY-200);
     glEnd();
     
     if(p1score>=10)     score(1,460,windowSizeY-200);  //1
     else                score(2,460,windowSizeY-200);  //2
     
     glBegin (GL_LINE_STRIP);                           //W
     glVertex2i(520,windowSizeY-160);
     glVertex2i(530,windowSizeY-200);
     glVertex2i(540,windowSizeY-160);
     glVertex2i(550,windowSizeY-200);
     glVertex2i(560,windowSizeY-160);
     glEnd();
     
     glBegin (GL_LINE_LOOP);                            //O
     glVertex2i(580,windowSizeY-160);
     glVertex2i(620,windowSizeY-160);
     glVertex2i(620,windowSizeY-200);
     glVertex2i(580,windowSizeY-200);
     glEnd();
     
     glBegin (GL_LINE_STRIP);                           //N
     glVertex2i(640,windowSizeY-200);
     glVertex2i(640,windowSizeY-160);
     glVertex2i(660,windowSizeY-200);
     glVertex2i(660,windowSizeY-160);
     glEnd();
     
     if(p1score>=10) {
                     score(1,330,windowSizeY-400);
                     score(0,370,windowSizeY-400);
                     score(p2score,510,windowSizeY-400);
                     }
     else            {
                     score(1,510,windowSizeY-400);
                     score(0,550,windowSizeY-400);
                     score(p1score,370,windowSizeY-400);
                     }
     glBegin (GL_LINES);
     glVertex2i(430,windowSizeY-380);
     glVertex2i(470,windowSizeY-380);
     glEnd();
     }
    glutSwapBuffers();
}

void resize(int width, int height)
{
     glViewport(0, 0, width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0, width, 0, height);
     glMatrixMode(GL_MODELVIEW);
}

static void idle(void)
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {        //Controls: Player 1: W to up, S to down, Player 2: O to up, L to down
if ((key=='w')&&(p1Y<=windowSizeY-cspeed))         p1Y+=cspeed;
if ((key=='s')&&(p1Y>=cspeed))                     p1Y-=cspeed;
if ((key=='o')&&(p2Y<=windowSizeY-cspeed))         p2Y+=cspeed;
if ((key=='l')&&(p2Y>=cspeed))                     p2Y-=cspeed;
                                               }
                                               
    
            
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowSizeX,windowSizeY);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Pong Game");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
    
}
   
