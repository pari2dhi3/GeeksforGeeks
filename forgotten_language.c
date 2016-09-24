#include<stdio.h>
int main()
{
	int l,n,k,i,flag[100]={0},j,w,t;
	char a[100][6], b[6];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(i=0;i<n;i++)
		{
			scanf("%s", a[i]);
			flag[i]=0;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d", &l);
			for(j=0;j<l;j++)
			{
				scanf("%s", b);
				for(w=0;w<n;w++)
				{
					if(!strcmp(a[w],b) && !flag[w])
						flag[w]=1;
				}	
			}			
		}
		for(i=0;i<n;i++)
		{
			if(flag[i])
				printf("YES ");
			else
				printf("NO ");
		}		
	printf("\n");
	}
return 0;
}	
