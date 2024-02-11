//
//  author: Saifur Rahman
//	last modified: 17 July, 2019
//
# include "iGraphics.h"
# include "gl.h"

#define N_PLANETS 9
//readimagefile("heic0406.jpg", 0, 0, 1300, 800);
int j;
int g_orbit = 0;
int planet_orbit=1;
int g_sunX, g_sunY, g_sunR;
int g_planetMajorAxisLen[N_PLANETS]={160, 200, 240, 280, 320, 360, 400, 440, 480};
int g_planetMinorAxisLen[N_PLANETS]={120, 150, 180, 210, 240, 270, 300, 330, 360};
int g_planetRadius[N_PLANETS]={5, 7, 8, 6, 14, 13, 10, 9, 6};
int g_planetSweepAngle[N_PLANETS]={0, 8, 2, 4, 6, 0, 7, 4, 7};
int g_planetDelSweepAngle[N_PLANETS]={3, 2, 1, 2, 3, 2, 1, 2, 1};
int planetorbita, planetorbitb;
int c1[]= {0, 200, 0, 200, 30, 10, 255, 240, 100};
int c2[]={155, 255, 0, 32, 45, 120, 130, 200, 100};
int c3[]={125, 200, 255, 49, 230, 210, 50, 160, 180};

int g_satelliteOrbitR, g_satelliteR[]={3, 4, 3}, g_satelliteSweepAngle[]={10, 0, 100};
void background(int a, int b, int c, int d){
    iSetColor(50, 50, 100);
     iFilledRectangle(a, b, c, d);
}


void drawStar(int x, int y, int r) {
    iSetColor(255, 250, 0);
    iFilledCircle(x, y, r);
}

void drawOrbit(int x, int y, int a, int b) {
    if(g_orbit%2==0){
    iSetColor(255, 50, 155);
    iEllipse(x, y, a, b);
    }
}

void drawPlanet(int x, int y, int orbitA, int orbitB, int planetR, int sweepAngle, int c1, int c2, int c3) {
    double pi = 2*acos(0);
    double sweepRadian = sweepAngle * pi / 180;
    int planetX = x + orbitA * cos(sweepRadian);
    int planetY = y + orbitB * sin(sweepRadian);

    iSetColor(c1, c2, c3);
    iFilledCircle(planetX, planetY, planetR);
    //iEllipse(planetX, planetY, planetorbita, planetorbitb);
}
void drawPlanetorbit(int x, int y, int orbitA, int orbitB, int planetR, int sweepAngle) {
    if(planet_orbit%2!=0){
    double pi = 2*acos(0);
    double sweepRadian = sweepAngle * pi / 180;
    int planetX = x + orbitA * cos(sweepRadian);
    int planetY = y + orbitB * sin(sweepRadian);

    iSetColor(200, 150, 0);
    //iFilledCircle(planetX, planetY, planetR);
    iEllipse(planetX, planetY, planetorbita, planetorbitb);
}
}
void drawSatellite(
    int x,
    int y,
    int planetOrbitA,
    int planetOrbitB,
    int planetSweepAngle,
    int satelliteOrbitR,
    int satelliteR,
    int satelliteSweepAngle) {
    double pi = 2*acos(0);
    double planetSweepRadian = planetSweepAngle * pi / 180;
    double satelliteSweepRadian = satelliteSweepAngle * pi / 180;

    int planetX = x + planetOrbitA * cos(planetSweepRadian);
    int planetY = y + planetOrbitB * sin(planetSweepRadian);

    int satelliteX = planetX + satelliteOrbitR * cos(satelliteSweepRadian);
    int satelliteY = planetY + satelliteOrbitR * sin(satelliteSweepRadian);

    iSetColor(100, 100, 100);
    iFilledCircle(satelliteX, satelliteY, satelliteR);
}
//void drawPlanetOrbit(int x, int y, int a) {
    //iSetColor(255, 0, 255);
    //icircle(x, y, r);


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	double centerX, centerY;
	int i;

	iClear();

	//
	// The sun is at the left focal point of the eliptical orbit. So, the center of orbit
	// needs to be translated appropriately.
	//

    background(0, 0, 1390, 1200);
    //iShowBMP(0, 0,"era.bmp");
	drawStar(g_sunX, g_sunY, g_sunR);

	for (i = 0; i < N_PLANETS; i++) {
        centerX = g_sunX + sqrt(pow(g_planetMajorAxisLen[i], 2) - pow(g_planetMinorAxisLen[i], 2));
        centerY = g_sunY;
        drawOrbit(centerX, centerY, g_planetMajorAxisLen[i], g_planetMinorAxisLen[i]);
        drawPlanet(
            centerX,
            centerY,
            g_planetMajorAxisLen[i],
            g_planetMinorAxisLen[i],
            g_planetRadius[i],
            g_planetSweepAngle[i],
            c1[i],
            c2[i],
            c3[i]
            );
        if (i == 2) {
                drawPlanetorbit(
            centerX,
            centerY,
            g_planetMajorAxisLen[i],
            g_planetMinorAxisLen[i],
            g_planetRadius[i],
            g_planetSweepAngle[i]
            );
                for(j=0;j<1;j++){
            drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i],
                g_planetMinorAxisLen[i],
                g_planetSweepAngle[i],
                g_satelliteOrbitR,
                g_satelliteR[j],
                g_satelliteSweepAngle[j]
                );
                }
        }
                if(i==3){
                drawPlanetorbit(
            centerX,
            centerY,
            g_planetMajorAxisLen[i],
            g_planetMinorAxisLen[i],
            g_planetRadius[i],
            g_planetSweepAngle[i]
            );
                  for(j=1;j<3;j++){
            drawSatellite(
                centerX,
                centerY,
                g_planetMajorAxisLen[i],
                g_planetMinorAxisLen[i],
                g_planetSweepAngle[i],
                g_satelliteOrbitR,
                g_satelliteR[j],
                g_satelliteSweepAngle[j]
                );
                }
                }
        }
	iSetColor(255, 255, 255);
	iText(40, 80, "Press p/P for pause, r/R for resume, END for exit.Press o/O and r/R and check out what is happening.Press z/Z for zooming in and m/M for zooming out");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p'|| key == 'P')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r'|| key == 'R')
	{
		iResumeTimer(0);
	}
	if(key == 'o'|| key == 'O')
	{
		//do something with 'q'
		g_orbit++;
	}
	if(key == 's'|| key == 'S')
	{
		//do something with 'q'
		planet_orbit++;
	}
	if(key=='z'|| key=='Z')
    {
        g_sunX*=1.2;
        g_sunY*=1.2;
        for (int i = 0; i < N_PLANETS; i++){
                g_planetMajorAxisLen[i]*=2;
                g_planetMinorAxisLen[i]*=2;
    }
    }
    if(key == 'm'||key == 'M')
    {
        g_sunX/=1.2;
        g_sunY/=1.2;
        for (int i = 0; i < N_PLANETS; i++){
                g_planetMajorAxisLen[i]/=2;
        g_planetMinorAxisLen[i]/=2;
    }
    }
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_RIGHT)
	{
		g_sunX-=30;
	}
	if(key == GLUT_KEY_UP)
	{
		g_sunY-=30;
	}
	if(key == GLUT_KEY_LEFT)
	{
		g_sunX+=30;
	}
	if(key == GLUT_KEY_DOWN)
	{
		g_sunY+=30;
	}
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

void movePlanets(){
    const int g_dSatelliteSweepAngle = 2;

    int i;

    for (i = 0; i < N_PLANETS; i++) {
        g_planetSweepAngle[i] = (g_planetSweepAngle[i] + g_planetDelSweepAngle[i])%360;
        for(j=0;j<3;j++){
        g_satelliteSweepAngle[j] = (g_satelliteSweepAngle[j] + g_dSatelliteSweepAngle)%360;
    }
    }
}

int main()
{
    const int CX_MAX = 1366;
    const int CY_MAX = 900;

    // Initialize Sun's position and size.
    g_sunX = 300;
    g_sunY = CY_MAX/1.9;
    g_sunR = 40;

    //g_planetMajorAxisLen[4] = {160, 200, 240, 280};
    //g_planetMinorAxisLen[4] = {120, 150, 180, 210};
    //g_planetRadius[4] = {7, 10, 13, 16};
    //g_planetSweepAngle[4] = {0, 5, , 4, 2};
    //g_planetDelSweepAngle[4] = {5, 1, 3, 4};

    //g_planetMajorAxisLen[1] = 200;
    //g_planetMinorAxisLen[1] = 150;
    //g_planetRadius[1] = 10;
    //g_planetSweepAngle[1] = 0;
    //g_planetDelSweepAngle[1] = 1;

    // Initialize moon's orbit and radius
    g_satelliteOrbitR = 15;
    planetorbita = 16;
    planetorbitb= 12;
//        g_satelliteR = 5;

	//place your own initialization codes here.
	iSetTimer(40, movePlanets);
	iInitialize(CX_MAX, CY_MAX, "Solar system!");

	return 0;
}


