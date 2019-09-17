#include"dictionary.h"

void indexTree(node *hazanode){

  FILE *fp;
  char readname[200]={'\0'};
  int readoffset;
  int i=0;
  int j=0;
  int MATNUM;
  MATNUM=count();

  fp=fopen("index.dat","rb");
  
    //read file to struct
  for(j=0;j<MATNUM;j++){
    i=0;  
    do{
      fread(&readname[i],1,1,fp);
    }while(readname[i++]!='#');    
    readname[i-1]='\0';
    strcpy(hazanode[j].name,readname);

    fseek(fp,1,SEEK_CUR);
    fread(&readoffset,4,1,fp);
    hazanode[j].offset=readoffset;
    fseek(fp,2,SEEK_CUR); 
    hazanode[j].left=NULL;
    hazanode[j].right=NULL;
  }

  //printf("%s",hazanode[1].name);
 // printf("%d",hazanode[1].offset);

  fclose(fp);
}

void printfTree2(node *root){
  if(root!=NULL){
    printf("%s\n",root->name);
    printf("%d\n",root->offset);
    printfTree2(root->left);
    printfTree2(root->right);
  }
}
int getHight(node* A){  //获取树高
  int hl,hr,max=0;
  if(A==NULL){
    return 0;
  }else{
    hl=getHight(A->left);
    hr=getHight(A->right);
    max=hl>hr?hl:hr;
    return(max+1);
  }
}
void leftRotate(node**A){  //左旋
  node* B =(*A)->right;
  (*A)->right=B->left;
  B->left=*A;
  *A=B;
  return;
}
void rightRotate(node**A){  //右旋
  node* B=(*A)->left;
  (*A)->left=B->right;
  B->right=*A;
  *A=B;
  return;
}
void rightLeftRotate(node**A){  //右左情况
  rightRotate(&((*A)->right));
  leftRotate(&(*A));
}
void leftRightRotate(node**A){  //左右情况
  leftRotate(&((*A)->left));
  rightRotate(&(*A));
  return;
}
void insertNode(node **root,node *newnode){
//for(int i=0;i<20;i++){
  if(*root==NULL){
    *root=newnode;
  }else{
    if(strcmp(newnode->name,(*root)->name)<0){
      insertNode(&((*root)->left),newnode);
      if(getHight((*root)->left)-getHight((*root)->right)==2){
        if(strcmp(newnode->name,(*root)->left->name)<0){
          rightRotate(&(*root));
        }else{
          leftRightRotate(&(*root));
        }
      }      
    }else{
      insertNode(&((*root)->right),newnode);
      if(getHight((*root)->right)-getHight((*root)->left)==2){
        if(strcmp(newnode->name,(*root)->right->name)<0){
          rightLeftRotate(&(*root));
        }else{
          leftRotate(&(*root));
        }
      }        
    }
  }
}
//newnode++;
//}
void findOffset(int offset){
  FILE *fp;    
  int length;
  int materialNum;
  int infoNum;

  char info[14][30]={"类别","检测项目:","检测仪器:","检测标准:","最低检出浓度:","采样体积（L）:","样品收集器:",
  "采样流量:","样品保留时间:","运输、保存条件:","检测室:","CMA认可:","备注:","吸收液/浸渍液:"};


  char str[200]={'\0'};
  int i;

  fp=fopen("index.dat","rb");
  fseek(fp,offset,SEEK_SET);
    //read material length and name 
  fread(&length,4,1,fp);
  fread(str,length,1,fp);
  printf("物质名:");
  printf("%s\n",str );
  fread(&infoNum,4,1,fp);//read information num

  for(i=0;i<infoNum;i++){
    fread(&length,4,1,fp);
    fread(str,length,1,fp);
    
    str[length]='\0';
    printf("%s",info[i]);
    printf("%s\n",str );
  }    
  fclose(fp);
}
void findTree(node *root,char *name,int* flag){
    if(root!=NULL){
        if(strcmp(root->name,name)==0){
          (*flag)++;
          findOffset(root->offset);
          //printf("%d\n",root->offset);
          } 
    findTree(root->left,&(*name),flag);
    findTree(root->right,&(*name),flag);
    }
}
void find2(void){
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
    printf("\n请输入查找内容名字(exit退出)：\n");
    scanf("%s",str);
    if(strcmp(str,"exit")==0)
      return;
    findTree(root,str,&flag);
    if(flag==0)
      printf("内容查找不到！\n可先输入exit 再输入./app -find2 -f 自定义文件名 进行查找\n或是查找其他单词。");   
    //printfTree2(root);
  }
}