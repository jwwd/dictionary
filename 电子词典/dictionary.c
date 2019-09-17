
#include"dictionary.h"
extern char filename[40];

int main(int argc,char *argv[]){

   menu();

  /*进入两种模式*/
  if(argc==2)
  {
    /*如果进入文本文件查找就进行*/
    if(strcmp(argv[1],"-find1")==0)
    { 
        
       // menu();
        //printf("*进入文本文件进行查询 请输入查找内容：\n");
        find1();
    }
    /*或者进入二进制文本查询*/
    else if(strcmp(argv[1],"-find2")==0)
    {
        FILE *fp;

        //printf("*二进制文本查询  请输入查找内容：\n");

        if((fp=fopen("index.dat","rb"))==NULL){
          printf("请先生成index.dat文件（输入./app -index）\n");
        }else{
        //  menu();
          find2();
        }
        
    }
    /*或者选择建索引表进行查询*/
    else if(strcmp(argv[1],"-index")==0)
    {
        creatIndex();
    }
    /*输入其他则返回出现错误输入其他指令*/
    else
    {
      printf("Error!\n");
    }

  }
  /*进入用户模式*/
  else if(argc==4)
  { 
    strcpy(filename,argv[3]);
    /*先
    进行文本文件查找若找不到则使用用户新建文件*/
    if(strcmp(argv[1],"-find1")==0 && strcmp(argv[2],"-f")==0)
    {
      //printf("*厂家提供文件查询查询不到则自己创建信息 请输入查找内容：\n");
     // menu();
      addFind1();
    }
    /*先进行文本文件查找若找不到则使用用户新建文件*/
    else if(strcmp(argv[1],"-find2")==0 && strcmp(argv[2],"-f")==0)
    {
      FILE *fp;
        if((fp=fopen("index.dat","rb"))==NULL){
          printf("请先生成index.dat文件（输入./app -index）\n");
        }else{
          //printf("*厂家提供二进制文件查询，查询不到则自己创建信息 请输入查找内容：\n");
        //  menu();
          addFind2();
        }
    }
    else
    {
      printf("Error!\n");
    }
  }
  else
  {
    printf("Error!\n");

  }
  return 0;
 }

void menu(){
  //system("cls");  
        printf("\t\t           ╭═══════════■□■□═════╮\n");  
        printf("\t\t           │  电子词典管理系统  │\n");  
        //printf("\t\t           │  有害物质管理系统  │\n");  
        printf("\t\t           ╰══════■□■□══════════╯\n");  
        printf("\t\t   ╭────────────────────────────────────╮\n");  
        printf("\t\t   │ 利用文本文件进行信息查找：  \t│\n");
        printf("\t\t   │ ./app -find1            \t\t│\n"); 
        printf("\t\t   │ 利用二进制索引文件进行信息查找\t│\n");
        printf("\t\t   │ ./app -find2             \t\t│\n");  
        printf("\t\t   │ 用户自主添加词入电子词典信息  \t│\n");  
      //printf("\t\t   │ 用户自主添加有害物质名称信息  \t│\n");  
        printf("\t\t   │ ./app -find1 -f new.txt  \t \t│\n");  
        printf("\t\t   │ ./app -find2 -f new.txt  \t \t│\n");
        printf("\t\t   │ 建立二进制索引文件           \t│\n");  
        printf("\t\t   │ ./app -index \t\t\t│\n");  
        printf("\t\t   │ 退出程序       \t\t\t│\n");
        printf("\t\t   │ exit            \t\t\t│\n");  
        printf("\t\t   ╰────────────────────────────────────╯\n");  
        //printf("\t\┘t请您选择(0-6):");  


}