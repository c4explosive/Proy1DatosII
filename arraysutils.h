#include <GL/freeglut.h>
#define NULL 0
#define clrscr() system("clear")
using namespace std;
/**********************************************ARRAYS*******************************************/

class arraysutils
{
    public:
	int i,j;
	void imp_array(int ** array, int n, int m)
	{
	     cout<<"ARRAY"<<endl;
	     for(i=0;i<n;i++)
	     {
		for(j=0;j<m;j++)
		    cout<<array[i][j]<<"\t";
		cout<<endl;
	     }
	}
	int ** init_array(int ** array,int n, int m)
	{
	    array=(int **)(malloc(n*sizeof(int *)));
	    for(i=0;i<n;i++)
		array[i]=(int *)(malloc(m*sizeof(int)));
	    return array;
	}
	void imp_array(GLfloat ** array, int n, int m)
	{
	     cout<<"ARRAY"<<endl;
	     for(i=0;i<n;i++)
	     {
		for(j=0;j<m;j++)
		    cout<<array[i][j]<<"\t";
		cout<<endl;
	     }
	}
	GLfloat ** init_array(GLfloat ** array,int n, int m)
	{
	    array=(GLfloat **)(malloc(n*sizeof(GLfloat *)));
	    for(i=0;i<n;i++)
		array[i]=(GLfloat *)(malloc(m*sizeof(GLfloat)));
	    return array;
	}

	void imp_vect(int * vector, int n)
	{
	     for(i=0;i<n;i++)
		cout<<vector[i]<<"\t";
	     cout<<endl;
	}
	
};

/**********************************************ARRAYS*******************************************/
