#include"dictionary.h"


void creatIndex(){//change k<,content
	FILE *fptxt;
	FILE *fpdat;

	char str[15][300]={'\0'};
	char tmp;
	int length=0;
	int flag=0;
	int content=0,catalog=0;
	int i=0,j=1,k=0;
	int infoNum=14;
	int materialNum;
	materialNum=count();
	content=locatecontent();
	

	fptxt=fopen("hazaTest.txt","r");
	fpdat=fopen("index.dat","wb");

	fseek(fpdat,content,SEEK_SET);
	fwrite(&materialNum,4,1,fpdat);   //save material num
	content=ftell(fpdat);

	for(k=0;k<materialNum;k++){
		i=0;
		j=1;
			//读取#物质名
		while((tmp=fgetc(fptxt))!='#');          
		while((str[0][i++]=fgetc(fptxt))!='\n'){
		}		
		str[0][i-1]='\0';
			//读取接下来的13个信息
		while((str[j][i]=fgetc(fptxt))!=':');
		do{
			i=0;
			flag=0;
			while((str[j][i]=fgetc(fptxt))!='@'){
				if(str[j][i]=='#'||str[j][i]==-1) {
					fseek(fptxt,-1,1);
					flag++;
					break;
				}
				i++;
			}
			str[j][i]='\0';
			j++;

		}while(flag==0);        //
		//printf("%s\n",str[0]);
		infoNum=j-1;

			//jump to write index
		fseek(fpdat,catalog,SEEK_SET);
		fwrite(str[0],strlen(str[0]),1,fpdat);		//save material name 
		fwrite("##",2,1,fpdat);
		fwrite(&content,4,1,fpdat); 				//save material offset
		fwrite("##",2,1,fpdat);
		catalog=ftell(fpdat);

			//jump to write content
		fseek(fpdat,content,SEEK_SET);

		length=strlen(str[0]);  
		fwrite(&length,4,1,fpdat);			//save length of material name			
		fwrite(str[0],length,1,fpdat);		//save material name

		fwrite(&infoNum,4,1,fpdat);  				//save information num

		for(i=1;i<15;i++){					//save other length and information
			length=strlen(str[i]);
			fwrite(&length,4,1,fpdat);						
			fwrite(str[i],length,1,fpdat);			
		}		
		content=ftell(fpdat);		
	}
	fclose(fptxt);
	fclose(fpdat);
	printf("create index.dat successfully\n");
}


int locatecontent(){
	int content=0;
	int i,j;
	char tmp;
	FILE *fp;
	char str[100]={'\0'};

	fp=fopen("hazaTest.txt","r");
	for(i=0;i<282;i++){//282
		j=0;
		while((tmp=fgetc(fp))!='#');           
		while((str[j++]=fgetc(fp))!='\n');
		str[j]='\0';
		content+=strlen(str);
	}
	return content+7*282;

}

int count(){
	FILE *fp;

	int infoNum=0;
	char tmp;
	fp=fopen("hazaTest.txt","r");
	while((tmp=fgetc(fp))!=EOF){
		if(tmp=='#') infoNum++;
	};

	fclose(fp);
	return infoNum;
}
