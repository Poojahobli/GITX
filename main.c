#include <stdio.h>
#include <stdlib.h>


char ip[30], stack[30];
int
main ()
{
  	char m[2][6][15] = { {"AbS", "E", "AbS", "E", "e", "n"},
    					{"a", "E", "cAd", "E", "E","E"}
 				   };
int size[2][6] = { 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1,1};
int i, j, k, n, row, col;
printf ("\n Enter the input string: ");
  	scanf ("%s", ip);
  	strcat (ip, "$");
 	n = strlen (ip);
stack[0] = '$';
stack[1] = 'S';
i = 1;
j = 0;
printf ("S$\t\t%s\n", ip);
while ((stack[i] != '$') && (ip[j] != '$'))
    	{
if (stack[i] == ip[j])
		{
	  		i--;
	 		j++;
	  		goto print;
}
      	switch (stack[i])
	{
		case 'S':
	 		 row = 0;
	  		 break;
case 'A':
	  		row = 1;
	  		break;
	}
      	switch (ip[j])
	{
		case 'a':
	  		col = 0;
	  		if (stack[i] == '$')
	    		{
	     			 printf ("error");
	      		      	 exit (0);
	 		}
	  	break;
		case 'b':
	  		col = 1;
	 		if (stack[i] == '$')
	    		{
	      			printf ("error");
exit (0);
	    		}
	  	break;
		case 'c':
	  		col = 2;
	  		if (stack[i] == '$')
	    		{
	     	 		printf ("error");
	      			exit (0);
}
	  	break;
		case 'd':
	  		col = 3;
	  		if (stack[i] == '$')
	    		{
	      			printf ("error");
	      			exit (0);
	    		}
	  	break;
		case 'e':
	 	 	col = 4;
	  		if (stack[i] == '$')
	    		{
printf ("error");
	     			exit (0);
	   		}
	  break;
	  case '$':
	  	col = 5;
	  	if (stack[i] == '$')
	    	{
	      		printf ("SUCCESS");
	      		exit (0);
	    	}
	  break;
	 default:
	 	 printf ("Unrecognized Terminal\nERROR\n");
	 exit (0);
}
if (m[row][col][0] == 'E')
{
	printf ("\nERROR");
	 exit (0);
}
else if (m[row][col][0] == 'n')
{
	printf ("ACTION:Using Production %c-->%s\n", stack[i],
		   m[row][col]);
i--;
}
else
{
	printf ("ACTION:Using Production %c-->%s\n", stack[i],
		   m[row][col]);
	for (k = size[row][col] - 1; k >= 0; k--)
	 {
	      stack[i] = m[row][col][k];
	      i++;
	}
	i--;
}
print:
for (k = i; k >= 0; k--)
printf ("%c", stack[k]);
printf ("\t\t");
for (k = j; k <= n; k++)
	printf ("%c", ip[k]);
printf ("\n");
}
if (stack[i] == '$' && ip[j] == '$')
     printf ("\nSUCCESS\n");
else
    printf ("ERROR\n");
}
