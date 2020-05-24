#include<stdio.h>

struct words           //an array of structure is defined to store each word of the file
{
    char a[100];
    int count;
}	words[100000];

int main()
{
    FILE *fp=NULL;
    int i=0,j=0,m=0,n=0,k,l,max,c;
    char b[100],ch;
    char temp[225];
    char tname[225][225];
 
    fp=fopen("data.txt","r");
    
	if(fp==NULL)
    {
        printf("File tidak ada\n");
        exit(0);
    }
    
	else
    {
        ch=tolower(fgetc(fp));  //tolower is used to convert every character to a lowercase letter
        while(ch!=EOF)
        {
            while(ch!=' '&&ch!='.'&&ch!=','&&ch!='!'&&ch!='('&&ch!=')'&&ch!=';'&&ch!=':'&&ch!='!'&&ch!='?'&&ch!='"'&&ch!=39&&ch!='\n'&&ch!='/'&&ch!=EOF)
            {
                words[i].a[j++]=ch;
                ch=tolower(fgetc(fp));
            }
            words[i].a[j]='\0';
            i++;
            j=0;
            ch=tolower(fgetc(fp));
        }
    }
    
	for(j=0;j<i;j++)
    {
        if(strcmp(words[j].a,"\0")!=0)
        {
            words[j].count=1;
            for(k=j+1;k<i;k++)
            {
                if(strcmp(words[j].a,words[k].a)==0)
                {
                    strcpy(words[k].a,"\0");    //Assigning value of '\0' eleminates the repetition of each word
                    words[j].count++;
                }
            }
        }
    }
    
   
	for(k=0;k<i;k++)
    {
        if(strcmp(words[k].a,"\0")!=0)
        {
            for(l=0;l<i;l++)             //This loop finds the first word whose count is not zero
            {                             //and assigns the value of it's index to max
                if(words[l].count!=0)
                {
                    max=l;
                    break;
                }
            }
            for(j=0;j<i;j++)
            {
                if(words[j].count > words[max].count){
					max=j;
					//if(words[j].count == words[max].count)
						
				}
                
            }
            printf("%d.  %s:  %d\n",k+1,words[max].a,words[max].count);
            
			words[max].count=0;
        }
    }

    return 0;
}





