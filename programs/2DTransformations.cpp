#include<iostream>  
#include<conio.h>  
#include<math.h>  
#include<stdlib.h>  
#include<conio.h>
#include<graphics.h>
using namespace std;  
class trans  
{  
    float x[20],y[20],xm,ym,ref[2][2],shx,shy;  
    int i,j,k,n;  
    float sx,sy,tx,ty,ang;  
    int gd,gm;  
    float xtmp [20],ytmp[20];  
    public:  
    void takeinput();  
    void menu();  
    void graphmode();  
    void mapgraph();  
    void plotint();  
    void translate();  
    void scale();  
    void rotate();  
    void reflect();  
    void shear();  
    void plotfinal();  
};  
int ch;  
void trans::takeinput()  
{  
    cout<<"ENTER THE NO OF VERTICES: ";  
    cin>>n;  
    for (i=0;i<n;i++)  
    {  
        cout<<"ENTER THE "<<i+1<<"th"<<" COORDINATES: ";  
        cin>>x[i]>>y[i];  
    }  
}  
void trans::menu()  
{  
    int kk;  
    cout<<"\n1:TRANSLATION";  
    cout<<"\n2:SCALING";  
    cout<<"\n3:ROTATION";  
    cout<<"\n4:REFLECTION";  
    cout<<"\n5:SHEARING";  
    cout<<"\n6:EXIT\n";  
    cin>>ch;  
    switch (ch)  
    {  
        case 1:  
            cout<<"\n ENTER TX AND TY: ";  
            cin>>tx>>ty;  
            break;  
        case 2:  
            cout<<"\n ENTER SX AND SY: ";  
            cin>>sx>>sy;  
            break;  
        case 3:  
            cout<<"\n ENTER ANGLE OF ROTATION: ";  
            cin>>ang;  
            break;  
        case 4:  
            cout<<"\n REFLECTION MENU";  
            cout<<"\n 1:X-PLANE";  
            cout<<"\n 2: Y-PLANE";  
            cout<<"\n 3: ORIGIN";  
            cout<<"\n 4: Y=X PLANE";  
            cout<<"\n 5: Y=-X PLANE";  
            cout<<"\n ENTER YOUR CHOICE: ";  
            cin>>kk;  
            switch (kk)  
            {  
                case 41:  
                         ref [0][0] =1;  
                    ref [0][1]=0;  
                    ref [1][0]=0;  
                    ref [1][1]=1;  
                    break;  
                case 42:  
                    ref [0][0]= -1;  
                    ref [0][1]=0;  
                    ref [1][0]=0;  
                    ref [1][1]=1;  
                    break;  
                case 43:  
                    ref [0][0]=-1;  
                    ref [0][1]=0;  
                    ref [1][0]=0;  
                    ref [1][1]=1;  
                    break;  
                case 44:  
                    ref [0][0]=0;  
                    ref [0][1]=1;  
                    ref [1][0] =1;  
                    ref [1][1]=0;  
                    break;  
                case 45:  
                    ref [0][0]=0;  
                    ref [0][1]=1;  
                    ref [1][0]=1;  
                    ref [1][1]=0;  
                    break;  
        case 5:  
            cout<< "\n SHEARING MENU";  
            cout<<"\n 1:X-DIR\n 2: Y-DIR \n 3: X-Y DIR\n ENTER YOUR CHOICE: ";  
            cin>>kk;  
            switch (kk)  
            {  
                case 51:  
                    cout<<"\n ENTER SHX: ";  
                    cin>> shx;  
                    ref[0][0] =1;  
                    ref [0][1]=0;  
                    ref [1][0]=shx;  
                    ref [1][1]=1;  
                    break;  
                case 52:  
                    cout<< "\n ENTER SHY: ";  
                    cin>>shy;  
                    ref [0][0]=1;  
                    ref [0][1]=shy;  
                    ref [1][0]=0;  
                    ref [1][1] =1;  
                    break;  
                case 53:  
                    cout<<"\n ENTER SHX: ";  
                    cin >> shx;  
                    cout<<"\n ENTER SHY: ";  
                    cin>> shy;  
                    ref [0][0] =1;  
                    ref [0][1] =shy;  
                    ref [1][0] =shx;  
                    ref [1][1] =1;  
                    break;  
                }  
                break;  
            }  
        }  
    }
    void trans::graphmode()  
    {  
        int gd=DETECT,gm;  
        initgraph (&gd, &gm,NULL);  
    }  
    void trans::mapgraph()  
    {  
        xm=getmaxx ()/2;  
        ym=getmaxy ()/2;  
        line (xm,0,xm,2*ym);  
        line (0,ym,2 * xm,ym);  
    }  
    void trans::plotint()  
    {  
        for(i=0;i<n-1;i++)  
        {  
            circle (x[i] +xm,-y[i]+ym,2);  
            circle (x [n-1]+xm,(-y[n-1]+ym),2);  
            line (x[i]+xm,(-y[i]+ym),x[i+1]+xm,(-y[i+1]+ym));  
        }  
        line (x[n-1]+xm,(-y[n-1]+ym),x[0]+xm,(-y[0]+ym));  
    }  
    void trans::translate()  
    {  
        for(i=0;i<n;i++)  
        {  
            xtmp[i]=x[i]+tx;  
            ytmp[i]=y[i]+ty;  
        }  
    }  
    void trans::plotfinal()  
    {  
        for (i=0;i<n-1;i++)  
        {  
            circle (xtmp[i]+xm, (-ytmp[i]+ym),2);  
            circle (xtmp[n-1]+xm,(-ytmp[n-1]+ym),2);  
            line (xtmp[i]+xm,(-ytmp[i]+ym),xtmp[i+1]+xm,(-ytmp[i+1]+ym));  
        }  
            line (xtmp[n-1]+xm,(-ytmp[n-1]+ym),xtmp[0]+xm,(-ytmp[0]+ym));  
    }  
    void trans::scale()  
    {  
        float s [2][2],mxy[7][2],rxy[7][2];  
        s [0][0]=sx;  
        s [0][1]=0;  
        s [1][0]=0;  
        s [1][1]=sy;  
        tx=-x[0];  
        ty=-y[0];  
        translate ();  
        k=0;  
        for(i=0;i<n;i++)  
        {  
            j=0;  
            mxy[i][j]=xtmp[k];  
            mxy[i][j+1]=ytmp[k];  
            k++;  
        }  
        for (i=0;i<n;i++)  
        {  
            for(j=0;j<2;j++)  
            {  
                rxy[i][j]=0;  
                for(k=0;k<2;k++)  
                {  
                    rxy[i][j]+=mxy[i][k]*s[k][j];  
                }  
            }  
        }  
                j=0;  
                k=0;  
        for(i=0;i<n;i++)  
        {  
            j=0;  
            x[k]=rxy[i][j];  
            y[k]=rxy[i][j+1];  
            k++;  
        }  
        tx=-tx;  
        ty=-ty;  
        translate();  
    }  
    void trans::rotate()  
    {  
        float r[2][2],mxy[7][2],rxy[7][2],tmp;  
        tmp=22/7;  
        tmp=(tmp*ang)/180;  
        r[0][0]=cos(tmp);  
        r[0][1]=sin(tmp);  
        r[1][0]=cos(tmp);  
        r[1][1]=sy;  
        tx=-x[0];  
        ty=-y[0];  
        translate ();  
        k=0;  
        for (i=0;i<n;i++)  
          {  
        j=0;  
        mxy[i][j]=xtmp[k];  
        mxy[i][j+1]=ytmp[k];  
        k++;  
          }  
    for (i=0;i<n;i++)  
    {  
        for (j=0;j<2;j++)  
        {  
            rxy[i][j]=0;  
            for (k=0;k<2;k++)  
            {  
                rxy[i][j]+=mxy[i][k]*r[k][j];  
            }  
        }  
    }  
        j=0;  
        k=0;  
    for(i=0;i<n;i++)  
    {  
        j=0;  
        x[k]=rxy[i][j];  
        y[k]=rxy[i][j+1];  
        k++;  
    }  
    tx=-tx;  
    ty=-ty;  
    translate();  
}  
void trans::reflect()  
{  
    float r[2][2],mxy[7][2],rxy[7][2],tmp; 
    tx=0;  
    ty=0;  
    translate();  
    k=0;  
    for(i=0;i<n;i++)  
    {  
        j=0;  
        mxy[i][j]=xtmp[k];  
        mxy[i][j+1]=ytmp[k];  
        k++;  
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<2;j++)  
        {  
            rxy[i][j]=0;  
            for(k=0;k<2;k++)  
            {  
                rxy[i][j]+=mxy[i][k]*r[k][j]; 
            }  
        }  
    }  
        j=0;  
        k=0;  
    for(i=0;i<n;i++)  
    {  
        j=0;  
        x[k]=rxy[i][j];  
        y[k]=rxy[i][j+1];  
        k++;  
    }  
    tx=-tx;  
    ty=-ty;  
    translate();  
}  
void trans::shear()  
{  
    float r[2][2],mxy[7][2],rxy[7][2],tmp; 
    tx=0;  
    ty=0;  
    translate ();  
    k=0;  
    for(i=0;i<n;i++)  
    {  
        j=0;  
        mxy[i][j]=xtmp[k];  
        mxy[i][j+1]=ytmp[k];  
        k++;  
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<2;j++)  
        {  
            rxy[i][j]=0;  
            for (k=0;k<2;k++)  
            {  
                rxy[i][j]+=mxy[i][k]*r[k][j];  
            }  
        }  
    }  
        j=0;  
        k=0;  
    for(i=0;i<n;i++)  
    {  
        j=0;  
        x[k]=rxy[i][j];  
        y[k]=rxy[i][j+1];  
        k++;  
    }  
    tx=-tx;  
    ty=-ty;  
    translate ();  
}  
int main()  
{  
    trans t1;  
    t1.takeinput ();  
    t1.menu ();  
    t1.graphmode ();  
    t1.mapgraph ();  
    t1.plotint ();  
    switch (ch)  
    {  
        case1:  
            t1.translate ();  
            break;  
        case2:  
            t1.scale ();  
            break;  
        case3:  
            t1.rotate ();  
            break;  
        case4:  
            t1.reflect ();  
            break;  
        case5:  
            t1.shear ();  
            break;  
        case6:  
            exit (0);  
        }  
        getch ();  
        t1.plotfinal ();  
        getch ();  
        closegraph ();  
}  