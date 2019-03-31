// C Program to illustrate
// OpenGL animation for revolution

// #include<stdio.h>
#include<GL/glut.h>
#include<iostream>
#include <string>
#include "Vehicle.h"
#include "Road.h"




// global declaration
int x, y;
float i, j;
int n_len=40;
int n_wid=25;

// Initialization function
void myInit (void)
{
    // Reset background color with black (since all three argument is 0.0)
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set picture color to green (in RGB model)
    // as only argument corresponding to G (Green) is 1.0 and rest are 0.0
    glColor3f(0.0, 1.0, 0.0);

    // Set width of point to one unit
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set window size in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}


// void draw_structure()
// {
//   glColor3f(0.0, 1.0, 0.0);
//   for(i=-road_len ; i<road_len; i++)
//   {
//     x=i;
//     glVertex2i(x,road_wid);
//     glVertex2i(x,-road_wid);
//   }
//   glColor3f(0.0, 1.0, 1.0);
//   for(i=-road_wid; i<road_wid+1; i++)
//   {
//     y=i;
//     glVertex2i(road_sig,y);
//   }

    void display(float k[],int count,Road r)
    // for (float k = -500; k < 421; k += 0.05)
    {
      glClear(GL_COLOR_BUFFER_BIT);
      glBegin(GL_POINTS);


      int xfac = 40;
      int yfac = 70;
      int car_len = 80;
      int bike_len= 80;
      int bike_wid= 25;
      int car_wid = 50;



        int road_len=r.Length*xfac;
        int road_wid=(r.Width+2)*yfac;
        int road_sig=r.Signal*xfac;


        //Loop is to draw the road
        glColor3f(1.0, 1.0, 1.0);
        for(i=-(road_len/2) ; i<road_len/2; i++)
        {
          x=i;
          glVertex2i(x,road_wid/2);
          glVertex2i(x,-road_wid/2);
        }
        if(r.SignalState.compare("GREEN")==0)
          glColor3f(0.0, 1.0, 0.0);
        else
          glColor3f(1.0, 0.0, 0.0);
        for(i=-(road_wid/2); i<road_wid/2+1; i++)
        {
          y=i;
          glVertex2i(-(road_len/2)+road_sig,y);
        }

        for(i=-(road_wid/2); i<road_wid/2+1; i++)
        {
          y=i;
          glVertex2i(-540,y);
        }

        for(i=-(road_wid/2); i<road_wid/2+1; i++)
        {
          y=i;
          glVertex2i(-500,y);
        }


        glColor3f(0.5, 0.1, 0.1);

          // if(r.VehicleList[m].Type.compare("Car")==0)
          // {
          //
          //   for(i= k[m]; i<(k[m]+(car_len)-1) ; i++)
          //   {
          //     x=i;
          //     glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)));
          //     glVertex2i(x,(road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10) + car_wid);
          //   }
          //   for(i=((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10));  i<((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)+ car_wid+1); i++)
          //   {
          //
          //     //cout<<i<<endl;
          //
          //     y=i;
          //     glVertex2i(k[m],y);
          //     glVertex2i(k[m]+car_len,y);
          //   }
          // }
          //
          // else if(r.VehicleList[m].Type.compare("bike")==0)
          // {
          //
          //   for(i= k[m]; i<(k[m]+(bike_len)-1) ; i++)
          //   {
          //     x=i;
          //     glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)));
          //     glVertex2i(x,(road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10) + bike_wid);
          //   }
          //   for(i=((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10));  i<((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)+ bike_wid+1); i++)
          //   {
          //
          //     //cout<<i<<endl;
          //
          //     y=i;
          //     glVertex2i(k[m],y);
          //     glVertex2i(k[m]+bike_len,y);
          //   }
          // }
          //
          // else if(r.VehicleList[m].Type.compare("Bus")==0)
          // {
          //
          //   for(i= k[m]; i<(k[m]+(n_len*r.VehicleList[m].Length)-1) ; i++)
          //   {
          //     x=i;
          //     // cout<<(n_wid*r.VehicleList[i].Width)<<endl;
          //     glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)));
          //     glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10) + (n_wid*r.VehicleList[m].Width)));
          //   }
          //   for(i=((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10));  i<((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)+ n_wid*r.VehicleList[m].Width+1); i++)
          //   {
          //
          //     //cout<<i<<endl;
          //
          //     y=i;
          //     glVertex2i(k[m],y);
          //     glVertex2i(k[m]+(n_len * r.VehicleList[m].Length),y);
          //   }
          // }
          for(int m=0; m<count; m++ )
          {

           if(r.VehicleList[m].Colour.compare("RED")==0)
              glColor3f(1, 0, 0);
          else if(r.VehicleList[m].Colour.compare("GREEN")==0)
                 glColor3f(0, 1, 0);
          else if(r.VehicleList[m].Colour.compare("BLUE")==0)
                    glColor3f(0, 0, 1);
          else
                    glColor3f(1,1,1);          

            for(i= k[m]; i<(k[m]+(n_len*r.VehicleList[m].Length)-1) ; i++)
            {
              x=i;
              // cout<<(n_wid*r.VehicleList[i].Width)<<endl;
              glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)));
              glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10) + (n_wid*r.VehicleList[m].Width)));
            }
            for(i=((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10));  i<((road_wid/2)-(r.VehicleList[m].Y)*(car_wid+10)+ n_wid*r.VehicleList[m].Width+1); i++)
            {

              //cout<<i<<endl;

              y=i;
              glVertex2i(k[m],y);
              glVertex2i(k[m]+(n_len * r.VehicleList[m].Length),y);
            }

        }
        // cout<<k[0]<<" "<<endl;
        // {
        //   for(i= k[0]; i<k[0]+79; i++)
        //   {
        //     x=i;
        //     glVertex2i(x,(road_wid/2)-10);
        //     glVertex2i(x,(road_wid/2)-60);
        //   }
        //   for(i=(road_wid/2)-60; i<(road_wid/2)-60+ 51; i++)
        //   {
        //     y=i;
        //     glVertex2i(k[0],y);
        //     glVertex2i(k[0]+80,y);
        //   }
        // }
        // glColor3f(0.1, 0.5, 0.2);
        // {
        //   for(i= k[1]; i<k[1]+79; i++)
        //   {
        //     x=i;
        //     glVertex2i(x,(road_wid/2)-10-70);
        //     glVertex2i(x,(road_wid/2)-60-70);
        //   }
        //   for(i=(road_wid/2)-60-70; i<(road_wid/2)-60-70 +51; i++)
        //   {
        //     y=i;
        //     glVertex2i(k[1],y);
        //     glVertex2i(k[1]+80,y);
        //   }
        // }
        glEnd();
        glFlush();
    }


// Driver Program
int main (int argc, char** argv)
{
    glutInit(&argc, argv);

    // Display mode which is of RGB (Red Green Blue) type
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Declares window size
    glutInitWindowSize(1360, 768);

    // Declares window position which is (0, 0)
    // means lower left corner will indicate position (0, 0)
    glutInitWindowPosition(0, 0);

    // Name to window
    glutCreateWindow("Traffic Simulations");

    // Call to myInit()
    myInit();
     //glutDisplayFunc(display);
    Road r(30,5,15,1);
    r.SignalState="GREEN";
    r.addVehicle("Car", 2, 2, 1, 1);
    r.VehicleList[0].Y= 1;
    r.addVehicle("bike",2,1,2,1);
    r.addVehicle("Bus", 3, 2, 1, 1);
    // r.VehicleList[1].X= 2;
    r.VehicleList[1].Y= 3;
    r.VehicleList[2].Y= 4;
    // for(float m=-340;m<278;m=m+0.01)
    // {
    //   display(m,r);
    // }
    // cout<<VehicleList[k].VX<<" ";
    float x[r.VehicleList.size()];
    float y[r.VehicleList.size()];
    x[0]=-540;
    x[1]=-500;
    x[2]=-340;
    r.update();
    r.update();
    r.update();
    r.update();
    r.update();
    r.update();
    r.update();

    // r.render();
    // cout<<"jncasnbbuabufbeufbkaebfkueabfukbeubaeufba"<<endl;
    // r.VehicleList[1].VX=2;
    // cout<<r.VehicleList[1].VX<<" fhisahfiuahfiah";
    // flush(stdout);



    for (int i=0; i<4000; i++)
    {
      for(int k=0;k<r.VehicleList.size();k++)
      {
      if(r.VehicleList[k].VX!=0)
          x[k]+=0.00025*r.VehicleList[k].VX*n_len;

        }
     display(x,r.VehicleList.size(),r);

    }
    r.update();
    for (int i=0; i<4000; i++)
    {
      for(int k=0;k<r.VehicleList.size();k++)
      {
      if(r.VehicleList[k].VX!=0)
          x[k]+=0.00025*r.VehicleList[k].VX*n_len;

        }
     display(x,r.VehicleList.size(),r);

    }

    glutMainLoop();
}
