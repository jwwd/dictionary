
#include"dictionary.h"



/**/
 void find1(){
        char name[1000];
        struct list *start=NULL;
        start =(struct list *)malloc(sizeof(struct list));
        /*创建链表*/
        create_list(start,NULL);
        /*输入查找名字*/
        while(1){

          printf("请输入查找的词(exit退出)：\n");
          gets(name);

          if(strcmp(name,"exit")==0)
              exit(0);
          /*返回查找的节点*/
         find_list(start,name);
    
        }
 }
/*创建链表*/
void create_list(struct list *node,struct list *temp)
{
  FILE *fp;
  //char tmp'0';
  int i=0,j=0,k=0;
  struct list *newnode;
  char *p;
  int length;
  newnode=node;

  fp=fopen("dict.txt","r");

  //int num=0;
        
  /*直到文件内容读取结束*/
  while(!feof(fp))
  {
    /*分别记录每个名字信息以及内容*/
    i=0;
    j=0;
    if(fgetc(fp)=='#')
    {  
      //num++;
      fseek(fp,-1,1);
      p=newnode->name;
        /*将文件最后转换为结束符号*/
      p=newnode->name;
      fgets(p,10000,fp);
      length=strlen(newnode->name);
      *(p+length-1)='\0';
      if(fgetc(fp)=='T')
      {
      fseek(fp,5,1);
        p=newnode->info;
        //*p='I';
        fgets((p),10000,fp);
        length=strlen(newnode->info);
        while((fgetc(fp)!='#')&&!feof(fp))
        {
          fseek(fp,-1,1);
             // *(p+length)='/n';
          fgets((p+length),10000,fp);
          length=strlen(newnode->info);
        }fseek(fp,-1,1);
            
        newnode->info[length]='@';
        newnode->info[length+1]='$';
      }
      newnode->next =(struct list *)malloc(sizeof(struct list));
      newnode = newnode->next;  
    }
      //printf("%d\n",num );
  }      
}


/*FIND*/
void find_list(struct list *node,char *findname)
{
     // char info[14][30]={"类别:","检测项目:","检测仪器:","检测标准:","最低检出浓度:","采样体积（L）:","样品收集器:",
 // "采样流量:","样品保留时间:","运输、保存条件:","检测室:","CMA认可:","备注:","吸收液/浸渍液:"};
    char info[14][30]={"Trans1:","Trans2:","Trans3:","Trans4:","Trans5:","Trans6:","Trans7:",
  "Trans8:","Trans9:"};
    struct list *mv=NULL;
    int flag=0;
    mv=node;
    char strinfo[1000]={'\0'};
   
    while(mv!=NULL){
      if((strcmp(mv->name,findname))==0 || (strcmp((mv->name+1),findname))==0){
       
       //printf("%s\n",mv->info );
       // /*
        strcpy(strinfo,mv->info);
        int i=0,j=0;
        while(strinfo[i]!='$')
        {
          printf("%s",info[j]);
          while(strinfo[i]!='@')
           {printf("%c",strinfo[i]);
            i++;}
            printf("\n");
            j++;
          i++;
        }
       // */
        mv=mv->next;
        flag=1;

      }
      else{
        mv=mv->next;
      }
  }
  if(flag==0){

    printf("没有要查询的词，请重新输入，或者尝试以下操作\n");
    printf("内容查找不到，请先输入exit 再输入./app -find2 -f 自定义文件名 进行查找 或者重新输入要查找的词\n");
    printf("\n");
  }
}
/**/
void addFind1(){
        char name[200];
        struct list *start=NULL;
        start =(struct list *)malloc(sizeof(struct list));
        /*创建链表*/
        create_list(start,NULL);
        /*输入查找名字*/
        while(1){

          printf("请输入查找的词(exit退出)：\n");
          gets(name);
          fflush(stdin);//清空输入缓存.

          if(strcmp(name,"exit")==0)
              exit(0);

          /*返回查找的节点*/
         find_list2(start,name);
    
        }
 }
void find_list2(struct list *node,char *findname)
{
    
  // char info[14][30]={"类别:","检测项目:","检测仪器:","检测标准:","最低检出浓度:","采样体积（L）:","样品收集器:",
 // "采样流量:","样品保留时间:","运输、保存条件:","检测室:","CMA认可:","备注:","吸收液/浸渍液:"};
  char info[14][30]={"Trans1:","Trans2:","Trans3:","Trans4:","Trans5:","Trans6:","Trans7:",
  "Trans8:","Trans9:"};
    struct list *mv=NULL;
    int flag=0;
    mv=node;
    char strinfo[1000]={'\0'};
   
    while(mv!=NULL){
      if((strcmp(mv->name,findname))==0 || (strcmp((mv->name+1),findname))==0){
       
       //printf("%s\n",mv->info );
       // /*
        strcpy(strinfo,mv->info);
        int i=0,j=0;
        while(strinfo[i]!='$')
        {
          printf("%s",info[j]);
          while(strinfo[i]!='@')
           {printf("%c",strinfo[i]);
            i++;}
            printf("\n");
            j++;
          i++;
        }
       // */
        mv=mv->next;
        flag=1;

      }
      else{
        mv=mv->next;
      }
  }
  if(flag==0){
    
      printf("原文件查找不到到用户新建文件查找\n");
      printf("\n");
      findf(findname);
  }
}
void findf(char *findname){
        char name[200];
        strcpy(name,findname);
        struct list *start=NULL;
        start =(struct list *)malloc(sizeof(struct list));
        /*创建链表*/
        create_list1(start);

          if(strcmp(name,"exit")==0)
              exit(0);
          /*返回查找的节点*/
         find_list1(start,name);
    
        //}
 }

/*FIND*/
void find_list1(struct list *node,char *findname)
{
    
 //   char info[14][30]={"类别:","检测项目:","检测仪器:","检测标准:","最低检出浓度:","采样体积（L）:","样品收集器:",
 // "采样流量:","样品保留时间:","运输、保存条件:","检测室:","CMA认可:","备注:","吸收液/浸渍液:"};
   char info[14][30]={"Trans1:","Trans2:","Trans3:","Trans4:","Trans5:","Trans6:","Trans7:",
  "Trans8:","Trans9:"};
    struct list *mv=NULL;
    int flag=0;
    mv=node;
    char strinfo[1000]={'\0'};
   
    while(mv!=NULL){
     // printf("dsjf\n");
      if((strcmp(mv->name,findname))==0 || (strcmp((mv->name+1),findname))==0){
       // printf("新建文件不包含内容\n");
     // printf("dsjf\n");
       
       //printf("%s\n",mv->info );
       // /*
        strcpy(strinfo,mv->info);
        int i=0,j=0;
        while(strinfo[i]!='$')
        {
          printf("%s",info[j]);
          while(strinfo[i]!='@')
           {printf("%c",strinfo[i]);
            i++;}
            printf("\n");
            j++;
          i++;
        }
       // */
        mv=mv->next;
        flag=1;

      }
      else{
        mv=mv->next;
      }
  }

  if(flag==0){
    insert(findname);
    //create_list1(node);
    return;
  }
}
/*创建链表*/
void create_list1(struct list *node)
{
  FILE *fp;
  //char tmp'0';
  int i=0,j=0,k=0;
  struct list *newnode;
  char *p;
  int length;
  newnode=node;
  char num[100];
  char a='\n';

  if((fp=fopen(filename,"r"))==NULL) //判断文件是否存在
  {
          printf("文件不存在是否需要创建文件 yes or no?\n");
          gets(num);
          if(strcmp(num,"yes")==0)
          {
            fp=fopen(filename,"w+"); //如果文件不存在，新建一个文件
            fputc(a,fp);
          }
          //printf("lmj\n");
          return ;
  }

        else{

            fp=fopen(filename,"r");
        }

  //int num=0;
        
  /*直到文件内容读取结束*/
  while(!feof(fp))
  {
    /*分别记录每个名字信息以及内容*/
    i=0;
    j=0;
    if(fgetc(fp)=='#')
    {  
      //num++;
      fseek(fp,-1,1);
      p=newnode->name;
        /*将文件最后转换为结束符号*/
      p=newnode->name;
      fgets(p,10000,fp);
      length=strlen(newnode->name);
      *(p+length-1)='\0';
      if(fgetc(fp)=='T')
      {
      fseek(fp,5,1);
        p=newnode->info;
        //*p='I';
        fgets((p),10000,fp);
        length=strlen(newnode->info);
        while((fgetc(fp)!='#')&&!feof(fp))
        {
          fseek(fp,-1,1);
             // *(p+length)='/n';
          fgets((p+length),10000,fp);
          length=strlen(newnode->info);
        }fseek(fp,-1,1);
            
        newnode->info[length]='@';
        newnode->info[length+1]='$';
      }
      newnode->next =(struct list *)malloc(sizeof(struct list));
      newnode = newnode->next;  
    }
      //printf("%s\n",newnode->name);
  }      
}

 /*insert*/
 void insert(char *findname){
 // char a[2]="\n\0";
  char a='\n';
  FILE *fp;
  char c[1000];
  char b[1000];
  char harm_name[10000];

  //char info[14][30]={"类别:","检测项目:","检测仪器:","检测标准:","最低检出浓度:","采样体积（L）:","样品收集器:",
  //"采样流量:","样品保留时间:","运输、保存条件:","检测室:","CMA认可:","备注:","吸收液/浸渍液:"};
   char info[14][30]={"Trans1:","Trans2:","Trans3:","Trans4:","Trans5:","Trans6:","Trans7:",
  "Trans8:","Trans9:"};
  int k;
  
  printf("\n词条内容不存在是否添加到新文件里面 yes or not?\n");
  scanf("%s",c);
  getchar();
  

  if(strcmp(c,"yes")==0){
  fp=fopen(filename,"a+");
  printf("\n请按照以下格式输入词条信息：#XXX\n");
  gets(harm_name);
  //fseek(fp,0,2);
  fputs(harm_name,fp);
  //fputs(a,fp);
  fputc(a,fp);
  
  printf("\n请按照以下格式输入词条释义的信息：\nTrans：XXX@XXX@XXX@……@XXX\n");
 // for(k=0;k<14;k++){
//    printf("%sXXX\n",info[k] );
//  }

  printf("请输入添加的词条释义的信息：\n");
  
  gets(b);

  printf("信息添加成功可再次输入要查找内容\n");
  printf("\n");

  fputs(b,fp);
  fputc(a,fp);
  fclose(fp);
   }
  return;
}

void addFind2(){
  int MATNUM;
  MATNUM=count();
  node hazanode[MATNUM];
  node *root=NULL;
  node *nodetmp;
  nodetmp=&hazanode[0];
  indexTree(nodetmp);

  int flag;
  for(int i=0;i<MATNUM;i++){
  insertNode(&root,nodetmp);
  nodetmp++;
  }
  char str[200]={'\0'};
  while(1){
    flag=0;
    printf("请输入要查询的词: \n");
    scanf("%s",str);
    if(strcmp(str,"exit")==0)
      return;
    findTree(root,str,&flag);
    if(flag==0)
      findf(str);     
  }
}
