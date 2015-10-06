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
	void imp_vect(int * vector, int n)
	{
	     for(i=0;i<n;i++)
		cout<<vector[i]<<"\t";
	     cout<<endl;
	}
	
};

/**********************************************ARRAYS*******************************************/
